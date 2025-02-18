# MyRadar

**MyRadar** is a 2D simulation of an air traffic control panel that visualizes the movement of planes based on coordinates provided in a configuration file. It renders planes on a radar screen, updating their positions and making the ones that collide disappear. However, there are control towers that can avoid planes collision as long as they're within the tower area.

## Features
- Visualize aircrafts on a 2D radar screen.
- Import coordinates from a configuration file for custom scenarios.
- Checking collisions between rectangle and circle shapes.

## Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:Say-Goodbi/Projects.My.git Projects.My
2. Enter the MyRadar directory :
   ```bash
   cd Projects.My/MyRadar
3. Build the project using Make :
   ```bash
   make

## Usage
1. How to see the controls :
   ```bash
   ./my_radar -h
2. Files that can be used to run the script are located within the "./examples/" directory :
   ```bash
   ./my_radar examples/15000_planes_35_towers.rdr

## Clean the repository
1. When you're done using the command, execute the following to clean the directory :
   ```bash
   make fclean

## About the project
1. It uses the CSFML library, in C language.
2. Done alone within 1 week.
