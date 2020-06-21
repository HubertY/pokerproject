The poker bot is split into two parts:
- A Node.js Javascript client which communicates with the remote game server
- A local C++ calculation server which takes requests from the client

The Javascript client will not establish a connection with the game server until it has confirmed that the calculation server is up and running. If the calculation server unexpectedly cannot be reached bad things will happen.

IP configurations are in ``config.json``. The calculation server is intended to run locally; the port can be freely changed. The calculation server supports only one connection.

## How to run
1. Install Node.js ``sudo apt-get install nodejs``
2. Install CMake ``sudo apt-get install cmake``
3. Compile the calculation server ``./build.sh``
3. Edit ``config.json`` so it has the correct port number for the game server. The port number for the calculation server can be reassigned as well (default ``1337``).
4. Run ``./start.sh``

``config.json`` is fragile, so be careful not to mess up the whitespace.
If the client can't connect to the calculation server, try killing processes on the calculation server port ``fuser 1337 /tcp -k`` and running ``start.sh`` again.
