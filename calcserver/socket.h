#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

#include <sstream>
#include <thread>
#include <fstream>

#include "calc.h"

using namespace std;

int new_socket;

bool sending = false;

void sendMessage(string s)
{
    send(new_socket, s.c_str(), s.length(), 0);
}

// void flopVillainStream(string flop, string hero)
// {
//     int i = 0;
//     std::ifstream fin;
//     fin.open("data/flop/" + flop + ".txt");
//     for (int i = 0; i < 169 && sending; i++)
//     {
//         std::string hand;
//         double equity, dummy;
//         fin >> hand >> equity >> dummy >> dummy >> dummy;
//         PREFLOP_EQUITY[PREFLOP_HAND_ID[hand]] = equity;
//         if (consistent(hand, flop) && consistent(hand, hero))
//         {
//             sendMessage(hand + " " + to_string(getEquity(hand, hero, flop).equity[0]));
//         }
//     }
//     fin.close();
// }

void sendVillains(string hero, string board)
{
    string ret = "";
    if (hero == "random" && board.length() == 6)
    {
        std::ifstream fin;
        fin.open("data/flop/" + board + ".txt");
        while (fin.good())
        {
            std::string hand;
            double equity, dummy;
            fin >> hand >> equity >> dummy >> dummy >> dummy;
            if (hand.length())
            {
                ret += hand;
                ret += " ";
                ret += to_string(equity);
                ret += "\n";
            }
        }
        fin.close();
    }
    else
    {
        auto data = getVillains(hero, board);
        for (auto datum : data)
        {
            ret += datum.first;
            ret += " ";
            ret += to_string(datum.second.equity[0]);
            ret += "\n";
        }
    }

    sendMessage(ret);
}

void handleMessage(string s)
{
    cout << "CALCSERV: received " << s << endl;
    stringstream ss;
    ss << s;
    int i = 0;
    string words[10];
    while (!ss.eof())
    {
        ss >> words[i++];
    }
    if (words[0] == "STREAM")
    {
        // if (words[1] == "FLOPVILLAIN")
        // {
        //     sending = true;
        //     thread t(flopVillainStream, words[2], words[3]);
        //     t.detach();
        // }
    }
    else if (words[0] == "STOP")
    {
        sending = false;
        sendMessage("STOPACK");
    }
    else if (words[0] == "REQUEST")
    {
        if (words[1] == "VILLAINS")
        {
            sendVillains(words[2], words[3]);
        }
    }
}

void awaitMessage()
{
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    handleMessage(string(buffer));
}

void initializeSocket(int port)
{
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        cout << ("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        cout << ("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        cout << ("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        cout << ("listen");
        exit(EXIT_FAILURE);
    }
    cout << "CALCSERV: waiting for client connection on port " << port << endl;
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        cout << ("accept");
        exit(EXIT_FAILURE);
    }
    cout << "CALCSERV: client connected" << endl;
}