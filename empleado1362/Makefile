.PHONY = doc clean all dist

LIBS = OGRE OIS
CXX = g++
CXXFLAGS = $(shell pkg-config --cflags $(LIBS)) $(DEFINES)
LD = g++
LDFLAGS = $(shell pkg-config --libs $(LIBS)) \
	-Llib/irrKlang -lIrrKlang \
	-Llib/Bullet/BulletDynamics -Llib/Bullet/LinearMath -Llib/Bullet/BulletCollision \
	-lBulletDynamics -lLinearMath -lBulletCollision

OPTIONS= -g -Wall -O2
DEBUG=#-D DEBUG
LIBDIR=src
INCLUDEDIR=include
INCLUDEFLAGS=-Ilib/irrKlang -Ilib/Bullet
_OBJ= InterfazGFX.o InterfazIA.o InterfazPSX.o InterfazINF.o InterfazSND.o Nivel.o Pantalla.o Juego.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))



#all: main

#main: ./src/main.cc $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) ./src/main.cc $(OBJ) -o main
	
	
all: clean ./src/main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(DEBUG) -I$(INCLUDEDIR) $(INCLUDEFLAGS) ./src/main.cpp $(OBJ) $(LDFLAGS) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c -I$(INCLUDEDIR) $(INCLUDEFLAGS) -o $@ $<
	
doc:
	doxygen
	
dist: clean
	rm -f juego.tgz
	tar cvzf juego.tgz *
	        
clean:
	rm -f main *.log ./*/*.o ./*/*~ *~

