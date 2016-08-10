SRC_FILES=utils.cpp kmeans.cpp main.cpp
SRC_FOLDER=./src/
SRC=$(addprefix $(SRC_FOLDER),$(SRC_FILES))
OBJ=$(SRC:.cpp=.o)
CC=g++
CCFLAGS=-Wall -std=c++11 -O3
LDLIBS=-fopenmp -I /usr/local/include/eigen3/
EXEFLAGS=-xHost
OBJFLAGS=-c
EXE=kmeans

$(VERBOSE).SILENT:

all: $(SRC) $(EXE)
	rm -f $(SRC_FOLDER)*.o

.cpp.o:
	$(CC) $(OBJFLAGS) $(CCFLAGS) $(LDLIBS) $< -o $@

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LDLIBS) $(EXEFLAGS) -o $(EXE)

clean:
	rm -f $(SRC_FOLDER)*.o $(EXE)
