PROJECT(EMPLEADO1362)
cmake_minimum_required(VERSION 2.4)

SET(NOMBRE_DIRECTORIO G4G)
SET(DIST INSTALL)

# #####################################
# Para compilar ejecutar:
# WINDOWS: cmake -G "Visual Studio 9 2008" .
# LINUX: cmake .
# ##################################### 

# Definiciones generales a la hora de compilar
if(UNIX)
	ADD_DEFINITIONS( "-Wall -g -DTIXML_USE_STL -DPCRE_DEFINITION" ) # -w) # -DmodeDebug")
elseif(WIN32)
	ADD_DEFINITIONS( "-Wall -g -DTIXML_USE_STL -DPCRE_DEFINITION -DG4GWIN32") 
endif(UNIX)

# Especificamos donde se generan los .lib
SET(LIBRARY_OUTPUT_PATH ${EMPLEADO1362_SOURCE_DIR}/lib)

# Espeficicamos los directorios con los .h
include_directories(${EMPLEADO1362_SOURCE_DIR}/include
)

# Especificamos los directorios con los .h de las librerías auxiliares
if(UNIX)
	include_directories(/usr/local/lib)
	include_directories(/usr/local/lib)
	include_directories(/usr/lib)
	include_directories(/usr/include/GL)
	include_directories(/usr/include/SDL)
	include_directories(/usr/include/AL)
	include_directories(/usr/local/include/CEGUI/RendererModules/OpenGLGUIRenderer)
	include_directories(/usr/local/include/CEGUI)
	include_directories(/usr/include/CEGUI)
	include_directories(/usr/include/CEGUI/RendererModules/OpenGLGUIRenderer)
elseif(WIN32)
	include_directories(C:\\LibEquipoME)
	include_directories(C:\\LibEquipoME\\irrKlang)
	include_directories(C:\\LibEquipoME\\BOOST)	
	include_directories(C:\\LibEquipoME\\SDL\\include)
	include_directories(C:\\LibEquipoME\\SDL\\SDL_IMAGE)
	include_directories(C:\\LibEquipoME\\GLUT)
	include_directories(C:\\LibEquipoME\\CEGUI\\include)
	include_directories(C:\\LibEquipoME\\CEGUI\\RendererModules\\OpenGLGUIRenderer)
	include_directories(C:\\LibEquipoME\\CEGUI\\include\\elements)
endif(UNIX)

# Especificamos los directorios con los .lib
link_directories(${GUERRASCUARTAGENERACION_SOURCE_DIR}/lib)
if(UNIX)
	link_directories(${EMPLEADO1362_SOURCE_DIR}/Bullet)
	link_directories(${EMPLEADO1362_SOURCE_DIR}/irrKlang)
	link_directories(/usr/lib)
	link_directories(/usr/local/lib)
elseif(WIN32)
	link_directories(C:\\LibEquipoME\\IL)
	link_directories(C:\\LibEquipoME\\irrKlang)
	link_directories(C:\\LibEquipoME\\BOOST\\lib)	
	link_directories(C:\\LibEquipoME\\SDL\\lib)
	link_directories(C:\\LibEquipoME\\SDL\\SDL_IMAGE)
	link_directories(C:\\LibEquipoME\\SDL\\irrKlang)
	link_directories(C:\\LibEquipoME\\GLUT)
	link_directories(C:\\LibEquipoME\\CEGUI\\lib)
	link_directories(${EMPLEADO1362_SOURCE_DIR}/Bullet)
endif(UNIX)

# Especificamos los subdirectorios
ADD_SUBDIRECTORY(src)

# Generamos el ejecutable del juego
ADD_EXECUTABLE(main ${EMPLEADO1362_SOURCE_DIR}/src/main)
TARGET_LINK_LIBRARIES(main Juego)

# Hacemos el paquete
if(${DIST} STREQUAL "INSTALL")
	message("Generando paquete de instalación.")
	if(WIN32)
		install(DIRECTORY  "${EMPLEADO1362_SOURCE_DIR}/Release/"
			DESTINATION ${NOMBRE_DIRECTORIO}
			REGEX ".idb" EXCLUDE
		)		
	elseif(UNIX)
		install(FILES main DESTINATION .)

elseif(${DIST} STREQUAL "COPY")
	message("Generando paquete de copia de los ficheros del proyecto.")
	install(DIRECTORY  "${EMPLEADO1362_SOURCE_DIR}/src/"
		DESTINATION src
		PATTERN ".svn" EXCLUDE
		PATTERN ".dir$" EXCLUDE
		PATTERN "CMakeFiles" EXCLUDE
		PATTERN "Makefile" EXCLUDE
		REGEX ".user$" EXCLUDE
		REGEX ".vcproj$" EXCLUDE
		REGEX ".cmake$" EXCLUDE
		REGEX ".dir$" EXCLUDE
		REGEX ".log$" EXCLUDE
	)
	install(DIRECTORY "${EMPLEADO1362_SOURCE_DIR}/include/"
		DESTINATION include
		PATTERN ".svn" EXCLUDE
		PATTERN ".dir$" EXCLUDE
		PATTERN "CMakeFiles" EXCLUDE
		PATTERN "Makefile" EXCLUDE
		REGEX ".user$" EXCLUDE
		REGEX ".vcproj$" EXCLUDE
		REGEX ".cmake$" EXCLUDE
		REGEX ".dir$" EXCLUDE
		REGEX ".log$" EXCLUDE
	)
	if(WIN32)
		install(DIRECTORY  "${EMPLEADO1362_SOURCE_DIR}/Release/"
			DESTINATION .
			REGEX ".idb" EXCLUDE
		)
	elseif(UNIX)
		install(FILES main DESTINATION .)
	endif(WIN32)
	install(DIRECTORY "${EMPLEADO1362_SOURCE_DIR}/lib/"
		DESTINATION lib
		PATTERN "DEBUG" EXCLUDE
		PATTERN "CEGUI" EXCLUDE
		PATTERN "BOOST" EXCLUDE	
		PATTERN "SDL" EXCLUDE
		PATTERN "GLUT" EXCLUDE
		PATTERN "RELEASE" EXCLUDE
		REGEX ".a$" EXCLUDE
	)
	install(FILES CMakeLists.txt DESTINATION .)
endif(${DIST} STREQUAL "INSTALL")

set(CPACK_PACKAGE_NAME "EMPLEADO1362")
set(CPACK_PACKAGE_VENDOR "Equipo ME")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Empleado 1362 - Instalación")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_VENDOR}")
SET(CPACK_CREATE_DESKTOP_LINK_CMakeSetup ON)
SET(CPACK_RESOURCE_FILE_LICENSE "${EMPLEADO1362_SOURCE_DIR}/Licencia.txt")

SET(CPACK_NSIS_CREATE_ICONS_EXTRA "
	SetOutPath \\\"$INSTDIR\\\\Empleado1362\\\"
	CreateShortCut \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Empleado 1362.lnk\\\" \\\"$INSTDIR\\\\${NOMBRE_DIRECTORIO}\\\\empleado1362.exe\\\"
	CreateShortCut \\\"$DESKTOP\\\\Empleado 1362.lnk\\\" \\\"$INSTDIR\\\\${NOMBRE_DIRECTORIO}\\\\empleado1362.exe\\\"
")

SET(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS ${CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS} "
	Delete \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\${CPACK_PACKAGE_VENDOR}\\\\Empleado 1362.lnk\\\"
	Delete \\\"$DESKTOP\\\\Empleado 1362.lnk\\\"
	#MessageBox MB_OK \\\"$DESKTOP\\\\Empleado 1362.lnk\\\"
")

include(CPack)
