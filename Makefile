
MAKE = g++ -std=c++11 

PROJECT_DIR = /home/holynerd/Desktop/theValleyProject/

#Field simulation dir
EXE_FS = $(PROJECT_DIR)
SOURCE_FS = $(PROJECT_DIR)FieldSimulation/Source/
INCLUDE_FS = $(PROJECT_DIR)FieldSimulation/Include/
HEADER_FS = $(PROJECT_DIR)FieldSimulation/Headers/
SHADER = $(PROJECT_DIR)FieldSimulation/Shaders/
LIB = $(PROJECT_DIR)Libs/

#GUI simulation dir
EXE_GUI = $(PROJECT_DIR)/GUI/
SOURCE_GUI = $(PROJECT_DIR)/GUI/Source/
INCLUDE_GUI = $(PROJECT_DIR)/GUI/Include/
HEADER_GUI = $(PROJECT_DIR)/GUI/Headers/
LIB = $(PROJECT_DIR)/Libs/

#PARSER simulation dir
EXE_PARSER = $(PROJECT_DIR)/Parser/
SOURCE_PARSER = $(PROJECT_DIR)/Parser/Source/
HEADER_PARSER = $(PROJECT_DIR)/Parser/Headers/

#Opengl, sdl libs
LIB_LINK = -lGL -lGLEW -lSDL2  #-ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGL -lpthread

#COMPILE ALL
all: $(EXE_FS)main $(EXE_GUI)GUI $(EXE_PARSER)Parser

#FIELD_SIMULATION_COMPILE
main: $(EXE_FS)main 

$(EXE_FS)main: $(SOURCE_FS)grid.o $(HEADER_FS)grid.h $(HEADER_FS)color.h $(SOURCE_FS)charge.o $(HEADER_FS)charge.h $(SOURCE_FS)object.o $(SOURCE_FS)vertex.o $(HEADER_FS)vertex.h $(HEADER_FS)object.h $(SOURCE_FS)application.o $(SOURCE_FS)mainProgram.o  $(SOURCE_FS)shader.o $(HEADER_FS)application.h $(HEADER_FS)mainProgram.h  $(HEADER_FS)shader.h 
	$(MAKE) -o $(EXE_FS)main $(SOURCE_FS)grid.o $(SOURCE_FS)charge.o $(SOURCE_FS)shader.o $(SOURCE_FS)vertex.o $(SOURCE_FS)object.o  $(SOURCE_FS)application.o $(SOURCE_FS)mainProgram.o -I$(INCLUDE_FS) -I$(HEADER_FS) -L$(LIB) $(LIB_LINK) 

$(SOURCE_FS)mainProgram.o: $(SOURCE_FS)mainProgram.cpp $(HEADER_FS)application.h $(HEADER_FS)mainProgram.h $(SHADER)*glsl
	$(MAKE) -c $(SOURCE_FS)mainProgram.cpp -o $(SOURCE_FS)mainProgram.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)application.o: $(SOURCE_FS)application.cpp $(HEADER_FS)application.h
	$(MAKE) -c $(SOURCE_FS)application.cpp -o $(SOURCE_FS)application.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)shader.o: $(SOURCE_FS)shader.cpp $(HEADER_FS)shader.h
	$(MAKE) -c $(SOURCE_FS)shader.cpp -o $(SOURCE_FS)shader.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)vertex.o: $(SOURCE_FS)vertex.cpp $(HEADER_FS)vertex.h
	$(MAKE) -c $(SOURCE_FS)vertex.cpp -o $(SOURCE_FS)vertex.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)object.o: $(SOURCE_FS)object.cpp $(HEADER_FS)object.h
	$(MAKE) -c $(SOURCE_FS)object.cpp -o $(SOURCE_FS)object.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)charge.o: $(SOURCE_FS)charge.cpp $(HEADER_FS)charge.h
	$(MAKE) -c $(SOURCE_FS)charge.cpp -o $(SOURCE_FS)charge.o -I$(INCLUDE_FS) -I$(HEADER_FS)

$(SOURCE_FS)grid.o: $(SOURCE_FS)grid.cpp $(HEADER_FS)grid.h
	$(MAKE) -c $(SOURCE_FS)grid.cpp -o $(SOURCE_FS)grid.o -I$(INCLUDE_FS) -I$(HEADER_FS)


#GUI_COMPILE
GUI: $(EXE_GUI)GUI

$(EXE_GUI)GUI: $(SOURCE_GUI)main.o 
	$(MAKE) -o $(EXE_GUI)GUI $(SOURCE_GUI)main.o -I$(INCLUDE_GUI) -I$(HEADER_GUI) -L$(LIB) $(LIB_LINK) 

$(SOURCE_GUI)main.o: $(SOURCE_GUI)main.cpp 
	$(MAKE) -c $(SOURCE_GUI)main.cpp -o $(SOURCE_GUI)main.o -I$(INCLUDE_GUI) -I$(HEADER_GUI)

#PARSER_COMPILE
Parser: $(EXE_PARSER)Parser

$(EXE_PARSER)Parser: $(SOURCE_PARSER)main.o 
	$(MAKE) -o $(EXE_PARSER)Parser $(SOURCE_PARSER)main.o -I$(HEADER_PARSER) 

$(SOURCE_PARSER)main.o: $(SOURCE_PARSER)main.cpp 
	$(MAKE) -c $(SOURCE_PARSER)main.cpp -o $(SOURCE_PARSER)main.o -I$(HEADER_PARSER)


clean:
	rm -f $(SOURCE_FS)*.o $(SOURCE_GUI)*.o $(SOURCE_PARSER)*.o
