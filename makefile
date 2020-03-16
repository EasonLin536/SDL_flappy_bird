#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp \
	   src/Pipe.cpp src/BackGround.cpp src/Bird.cpp \
	   src/Menu.cpp src/Page.cpp src/Button.cpp src/Tutorial.cpp src/Gameover.cpp
# OBJS = 31_scrolling_backgrounds.cpp
#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS="-I/d/src/SDL/include/SDL2"

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS="-L/d/src/SDL/lib"

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean : $(OBJS)
	rm -f $(OBJ_NAME).exe	