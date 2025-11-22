# 99-Game

A console-based implementation of the classic card game "99". The objective of the game is for players to add card values to a running total, aiming not to surpass 99, while utilizing special card effects to influence gameplay.

## Features

- Supports 2 to 4 players.
- Each player starts with 5 cards and 0 points.
- Special cards and suits have unique effects according to game rules.
- Card operations are visualized in ASCII format.
- Interactive turn-based gameplay with player input.
- Handles shuffling, dealing, and elimination.

## Gameplay

### Game Rules

- **Initial Setup:**
  - Each player starts at 0 points.
  - 2–4 players allowed.
  - Hand size: 5 cards/player.

- **Turn Mechanics:**
  - On each turn, players play a card to alter the total sum.
  - If the sum exceeds 99, the player loses.
  - Certain cards have special effects:
    - Ace of Spades: Resets the total to zero.
    - Ace: +1
    - 2: +2
    - 3: +3
    - 4: Rotate (four-player games) or +4 (otherwise).
    - 5: Designate a player to jump to.
    - 6–9: Add their number.
    - 10: ±10 (player chooses).
    - Jack: Skip the next player's turn.
    - Queen: ±20 (player chooses).
    - King/Joker: Special effects (see code for details).

### Card Suits and Kinds

Cards use ASCII-based visualization for both suits and numbers. Suits include Clubs, Diamonds, Hearts, and Spades.

### Example Turn Sequence

1. Shuffle deck and deal cards.
2. Players take turns playing cards.
3. Card effects are resolved, and total is updated.
4. If a player's move causes total to exceed 99, they are eliminated.
5. Continue until one player remains.

## Build and Run

### Prerequisites

- Compiler supporting C++11 or later.
- Windows console (uses `<windows.h>` for timing).

### Build Instructions

```shell
g++ main.cpp -o 99_Game
```

### Run

```shell
./99_Game
```

## Code Structure

- `main.cpp` — Entry point, initializes and starts game loop.
- `Game_99.hpp` — Handles game initialization, rule enforcement, player turn logic.
- `Player.hpp` — Represents a player; manages hand, points, status.
- `Deck.hpp` — Manages deck operations: shuffling, dealing, buffer.
- `Card.hpp` — Card class, ASCII rendering, suit/number logic.
- `Define.h` — Game constants, enums for suits/numbers/rules.

## Example Rule Summary

```
- Ace of Spades: Zero the sum.
- Ace: Add 1.
- 2: Add 2.
- 3: Add 3.
- 4: Rotate (or add 4).
- 5: Jump to designated player.
- 6–9: Add card value.
- 10: Add or subtract 10.
- Jack: Skip a round.
- Queen: Add or subtract 20.
- King, Joker: Special rules.
```

See full rules prompt at game start.

## Credits

Developed by [YuminChiang](https://github.com/YuminChiang).

## License

Specify license here if available.