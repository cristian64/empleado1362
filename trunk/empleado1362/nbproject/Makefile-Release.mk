#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/InterfazIA.o \
	${OBJECTDIR}/src/Nivel.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/Juego.o \
	${OBJECTDIR}/src/InterfazSND.o \
	${OBJECTDIR}/src/InterfazPSX.o \
	${OBJECTDIR}/src/Pantalla.o \
	${OBJECTDIR}/src/InterfazGFX.o \
	${OBJECTDIR}/src/InterfazINF.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/empleado1362

dist/Release/GNU-Linux-x86/empleado1362: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/empleado1362 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/InterfazIA.o: nbproject/Makefile-${CND_CONF}.mk src/InterfazIA.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/InterfazIA.o src/InterfazIA.cpp

${OBJECTDIR}/src/Nivel.o: nbproject/Makefile-${CND_CONF}.mk src/Nivel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Nivel.o src/Nivel.cpp

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/Juego.o: nbproject/Makefile-${CND_CONF}.mk src/Juego.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Juego.o src/Juego.cpp

${OBJECTDIR}/src/InterfazSND.o: nbproject/Makefile-${CND_CONF}.mk src/InterfazSND.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/InterfazSND.o src/InterfazSND.cpp

${OBJECTDIR}/src/InterfazPSX.o: nbproject/Makefile-${CND_CONF}.mk src/InterfazPSX.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/InterfazPSX.o src/InterfazPSX.cpp

${OBJECTDIR}/src/Pantalla.o: nbproject/Makefile-${CND_CONF}.mk src/Pantalla.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Pantalla.o src/Pantalla.cpp

${OBJECTDIR}/src/InterfazGFX.o: nbproject/Makefile-${CND_CONF}.mk src/InterfazGFX.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/InterfazGFX.o src/InterfazGFX.cpp

${OBJECTDIR}/src/InterfazINF.o: nbproject/Makefile-${CND_CONF}.mk src/InterfazINF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/InterfazINF.o src/InterfazINF.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/empleado1362

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
