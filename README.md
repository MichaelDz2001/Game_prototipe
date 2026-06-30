# Description
C++ game/application built with SFML.

# Build
Compile source files into object files:

g++ -g -O0 main.cpp character.cpp player.cpp playercontroller.cpp walls.cpp collision.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

Link:
g++ -g -O0 main.o character.o player.o playercontroller.o walls.o collision.o -o main \
   -lsfml-graphics -lsfml-window -lsfml-system

# Run
./main

# Author
MichaelDz2001

# Acknowledgements
 - Parts of the project (up to ~90% of some files, and ~10–50% of others) were adapted from another GitHub repository.
 - Fragments from that source were integrated where applicable; some files were written entirely by me.
Original source: https://github.com/DaniilUbica/toffi
