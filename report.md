Pokerbot Project Report<br>
Game Theory<br>
Instructed by Pingzhong Tang<br>

Hubert Yuan<br/>
June 21, 2020

# Architecture

A working instance of the bot consists of two components: a _game client_ written in Javascript and a _calculation server_ written in C++. These components communicate with each other over a TCP socket. Their responsibilities are divided as such:
- The game client connects to the game server and the calculation server, and implements the overall strategy.
- The calculation server takes intensive computation requests from the game client and returns the results. 

The motivation for this design is twofold. First, communication protocols and strategy logic is very convenient to write in a higher-level language, and only speed-sensitive common procedures like equity calculation need to be implemented in C++. Second, the separation of the calculation server implies that it could be hosted on a remote provider and it could service many game clients implementing different strategies. This theoretically offers some benefits like mutual speedups via caching of shared calculations and dynamic adjustment of compute as required. To an extent decouples an explicit strategy from the amount of compute it requires. The calculation server implements some support for streaming partial results for a client as they are obtained, allowing the client to use the partial results before a timeout. In practice, the actual strategy we implement uses only results that have already been precomputed and cached to disk, so the main benefits of the two-component architecture are not realized in this particular case. However, future extensions of the strategy may rely on nontrivial computations performed in real-time.

# Strategy

## Overview

The preflop strategy is hardcoded and nonadaptive, based on guidelines for human play. Ranges receive an adjustment based on opponent bet size when applicable.

From the small blind:
- Initially, raise to 300 with the top 80% of hands ranked by equity and fold the rest.
- Faced with a re-raise from the opponent, call with the top 30% of hands and fold the rest.

From the big blind:
- Faced with an initial call from the opponent, always call.
- Faced with initial raise from the opponent, re-raise to 1000 with the top 20% of hands, call with the next 40% of hands, and fold the rest.
- Faced with a re-re-raise from the opponent, call with the top 10% of hands, and fold the rest.

Postflop strategy works as follows:
- Obtain a _preflop posterior_ distribution **p_1** over all opponent hands from the Preflop Tracker (described later)
- Compute a _postflop posterior_ distribution **p_2** over all opponent hands based on the postflop history (described later)
- Request a _villain equity_ distribution **v** over all hands from the calculation server mapping opponent hands to the chance the opponent wins the pot given the own hand and the board state.
- Multiply **p_1** and **p_2** elementwise, normalize, multiply by **e_v**, and take the sum over all hands to estimate the probability the opponent wins the pot. Subtracting that from 1 yields an estimate of the player's equity.
- Use the estimated equity to compute the expected value of folding and calling. If folding is better than calling, fold with probability linear with the expected loss and call otherwise. If our hand has greater than 0.5 equity, we raise half the pot with probability equal to the equity; if greater than 0.8 equity, twice the pot instead. Also, we raise twice the pot 10% of the time when we would otherwise call on the flop only.

## Computation of **p_1**
**p_1** represents the opponent hand distribution given his preflop actions. The Preflop Tracker object receives a report for every completed preflop round and maintains an exponential moving average of the rate at which the opponent takes sequences of actions. We convert the rates into hand ranges and estimate that a in-range action has 3 times the density of an out-of-range action.

## Computation of **p_2**
**p_2** represents the opponent hand distribution given his postflop actions. We estimate the opponent's expectation of his own equity given he has a particular hand using the equity of that hand against a random hand given the board state. Then we can compute if each action the opponent takes (call/raise) is positive EV. We estimate that a positive EV call has 5 times the density of a negative EV call. If the opponent raised, we estimate that a positive EV raise has 10 times the density of a negative EV raise and also adjust the equity threshold up to 0.9 based on the raise size compared to the pot.

## Computation of equities
An equity is the probability a hand has to win given an information set. We use the C++ [OMPEval](https://github.com/zekyll/OMPEval) library to completely enumerate outcomes on the calculation server. The equity each hand has against a random hand for each flop is already precomputed and stored in the ``data/`` directory.

# Possible Improvements and Extensions
- The preflop strategy is completely static and deterministic and therefore may be theoretically very exploitable. It could be improved to adapt to the opponent's preflop strategy and play hands probabilistically.
- The Preflop Tracker currently does not take into account the amount the opponent raises preflop, only the action sequence. It also does not track the actual hands the opponent plays which is sometimes revealed at showdown. It could be extended to use this information to compute a smarter prior.
- Instead of the ad-hoc estimation for **p_2**, we could explicitly simulate how the strategy would respond in the opponent's position and use that to compute densities. A recursive depth limit would need to be set.
- We simply bluff 10% of the time on the flop only. Bluffing strategy could be significantly developed, based on the character of the flop and the estimated strength of the opponent's hand.
