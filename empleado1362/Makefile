.PHONY = doc clean all dist

LIBS = OGRE OIS
CXX = g++
CXXFLAGS = $(shell pkg-config --cflags $(LIBS)) $(DEFINES)
LD = g++
LDFLAGS = $(shell pkg-config --libs $(LIBS))
OPTIONS= -g -Wall
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= InterfazGFX.o InterfazIA.o InterfazPSX.o InterfazINF.o InterfazSND.o ManejadorEventos.o Juego.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))



#all: main

#main: ./src/main.cc $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) ./src/main.cc $(OBJ) -o main
	
	
all: clean ./src/main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(LDFLAGS) -I$(INCLUDEDIR) ./src/main.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CXX) $(CXXFLAGS) $(DEBUG) $(LDFLAGS) -c -I$(INCLUDEDIR) -o $@ $<
	
doc:
	doxygen
	
dist: clean
	rm -f juego.tgz
	tar cvzf juego.tgz *
	        
clean:
	rm -f main *.log ./*/*.o ./*/*~ *~


