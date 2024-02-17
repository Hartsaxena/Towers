CC=g++
STD_OPT=-g -Wall
MAIN=main.cpp
INC_SRC=front.cpp render.cpp
INC_DIR=-Iinclude
SDL_LIB=-Ilibraries\SDL\Include -Llibraries\SDL\lib
INC=$(INC_DIR) $(SDL_LIB)
SDL_OPT=-lmingw32 -lSDL2main -lSDL2
OUTPUT_DIR=bin
OUTPUT_EXEC=$(OUTPUT_DIR)\\main


bin\\main: main.cpp front.cpp render.cpp
	$(CC) $(INC) $(STD_OPT) -o $@ $^ $(SDL_OPT)

run: bin\\main
	$<

clean:
	del $(OUTPUT_DIR)\\**.exe