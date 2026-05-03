# powerMonitoring
This repo is C project works as an automated analysis tool for electrical engineering csv file 
Description
This project is a C program developed for a software design coursework. It demonstrates modular programming with separate header and source files, dynamic memory allocation, file input/output operations, and data analysis functions.

Project Structure
text
project/
├── main.c            # Main program entry point
├── io.h              # Input/Output function declarations
├── io.c              # File reading and writing implementation
├── waveform.h        # Data structure and function declarations
├── waveform.c        # Calculation functions implementation
├── CMakeLists.txt    # CMake build configuration
└── README.md         # This file
Requirements
C compiler (GCC recommended)

CLion IDE (latest version)

CMake (included with CLion)

Getting Started
Clone or Download
Download the project files and open in CLion.

Open in CLion
Launch CLion

Click File → Open

Browse to the project folder and select it

CLion will automatically detect and load the CMake project

Build and Run
Wait for CMake to finish indexing

Go to Run → Edit Configurations

Add any Program arguments if needed (input filename)

Click Apply then OK

Build: Build → Build Project (or Ctrl+F9)

Run: Click green Run button (or Shift+F10)

Running Without Arguments
If the program requires arguments and none provided:

The program may show usage instructions

Add arguments via Run → Edit Configurations → Program arguments

Features
Reads data from external files

Processes and analyzes data

Outputs results to text file

Modular code structure

Dynamic memory management

Build Output
After successful compilation:

Executable located in cmake-build-debug/ folder

Output files generated in project root directory

Green Run button greyed out	Check Run → Edit Configurations has valid configuration
Author
(Ali M E S A M Ashkanani)

Date
3 May 2026

License
This project is for educational purposes.
