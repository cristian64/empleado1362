CC = g++
LDFLAGS = -LBullet/BulletDynamics -LBullet/BulletMultiThreaded -LBullet/BulletSoftBody -LBullet/LinearMath -LBullet/BulletCollision -L/usr/lib \
		-lglut -lGLU -lGL -lm -lBulletDynamics -lLinearMath -lBulletSoftBody -lBulletMultiThreaded -lBulletCollision 
IFLAGS  = -I/usr/include -IBullet
CCFLAGS = -g -Wall -O2

EXENAME = main

TARGETS = main.cpp

default:
	$(CC) $(TARGETS) $(CCFLAGS) $(IFLAGS) $(LDFLAGS) -o $(EXENAME)

.PHONY: clean

clean:
	rm -f main

