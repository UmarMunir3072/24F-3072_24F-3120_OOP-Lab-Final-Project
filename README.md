# Stronghold Kingdom Management Simulator

This is a C++ Object-Oriented Programming (OOP) project for simulating the management of a medieval kingdom. The simulation includes managing resources, population, military, economy, and leadership, with a save/load game state system.

## 🛠 Features

- **Object-Oriented Design**: Each module (e.g., Economy, Military, Leadership) is implemented using classes.
- **Social Classes**: Includes population stratification into Nobles and Peasants.
- **Text-Based Menu Interface**: Navigate through options like viewing and updating kingdom stats.
- **Game Save/Load System**: Automatically loads the previous game state from a file (`game_save.txt`).
- **Turn-Based Simulation**: Option to simulate kingdom development over turns.

## 📁 Project Structure

```
├── Bank.cpp
├── Economy.cpp
├── EventHandler.cpp
├── Kingdom.cpp
├── KingdomEntity.cpp
├── Leadership.cpp
├── Main.cpp
├── Military.cpp
├── Population.cpp
├── Stronghold.h
├── game_save.txt
```

## 🧩 Key Classes

- **Kingdom**: Central controller class managing all subsystems.
- **Bank, Economy, Military, Leadership, Population**: Each implements specific kingdom aspects.
- **SocialClass (Peasants, Nobles)**: Represents different population tiers with behaviors.

## 🚀 How to Run

### Prerequisites
- A C++ compiler (e.g., `g++`)

### Compilation

```bash
g++ *.cpp -o StrongholdSim
```

### Run

```bash
./StrongholdSim
```

### Sample Menu

```
===== Stronghold Management Menu =====
1. View Resources
2. View Population
3. View Military
4. View Economy
5. View Leadership
6. Simulate Turn
7. Update Resources
0. Exit
```

## 💾 Save File

The game saves and loads progress from `game_save.txt`. Ensure this file is in the same directory as the executable.

## 👨‍💻 Authors

- **24F-3072**
- **24F-3120**

## 📜 License

This project is for educational purposes.