# MyTop

**MyTop** is a command-line application inspired by the Linux `top` command. It provides a real-time overview of the system’s resource usage, including running processes, CPU, memory usage, and more. This tool allows you to monitor system performance and identify resource-intensive processes.

## Features
- Display CPU usage, memory usage, and swap usage.
- List running processes with detailed information like PID, CPU usage, memory usage, and more.
- Update in real-time to reflect system changes.

## Installation
1. Clone the repository :
   ```bash
   git clone git@github.com:Say-Goodbi/Projects.My.git Projects.My
2. Enter the MyTop directory :
   ```bash
   cd Projects.My/MyTop
3. Build the project using Make :
   ```bash
   make 

## Usage
1. How to use it :
   ```bash
   ./my_top
2. There's also another version of it within the bonus directory, and supports the U, d and n options,
   but is experimental and can take a lot of time to actually refresh.
   ```bash
   cd bonus && make
   ./my_top -U <user> -d <delay in seconds> -n <number of frames before closing the interface>

## Clean the repository
1. When you're done using the command, execute the following to clean the directory :
   ```bash
   make fclean

## About the project
1. It uses a Terminal User Interface with the Ncurses library, in C langage.
2. Done alone within 2 weeks.
