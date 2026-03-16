# Buckshot Roulette Clone (C)

### 🎓 Context
This project is a CLI (Command Line Interface) adaptation of the viral horror game **Buckshot Roulette**. Developed in collaboration with [@ycborg](https://github.com/ycborg), it focuses on game logic, state management, and probability-based decision-making.

### 🚀 Features
* **Probability Engine:** Real-time calculation of hit chances based on remaining shells in the magazine.
* **Smart-ish BOT:** An automated opponent that makes decisions (shooting itself or the player) based on randomized AI logic.
* **Health System:** Implementation of life points for both player and bot, managing the game loop until a "Game Over" state.
* **Randomized Rounds:** Each round reloads the shotgun with a random number of live and blank shells, mimicking the original game's tension.

### 🛠️ Technical Details
* **Pseudo-randomness:** Extensive use of `srand(time(0))` and `rand()` to ensure unpredictable gameplay.
* **Game State Control:** Managed through nested loops and conditional logic to handle turn-switching and chamber depletion.
* **Cross-platform Clears:** System calls optimized for both Windows (`cls`) and Linux/macOS (`clear`).

### 💻 How to run
1. **Compile** using the provided Makefile:
   ```bash
   make all

2. **Run** the executable:
   ```bash
   ./buckshot
### 🔗 Credits
* Inspired by the original game by **Mike Klubnika**.
* Check the original game on [Steam](https://store.steampowered.com/app/2835570/Buckshot_Roulette/).
