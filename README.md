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
