#compile tool
CC=g++

INCLUDE_DIR=-linclude 
LIBS=-lSDL -lSDLmain

TARGET=tenine

CFLAGS=-Wall -o3
#CFLAGS=-Wall -ansi -pedantic -g -O2
#%.o:%.cpp
#    $(CC) -c $(FLAGS) $(INCLUDE_DIR) $< -o $@

EXEC=tengine
OBJS=SDLWrapper.o main.o

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
                         
%.o : %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

