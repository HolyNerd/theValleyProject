
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
all: $(EXE_FS)Application $(EXE_GUI)GUI $(EXE_PARSER)Parser

#FIELD_SIMULATION_COMPILE
FieldSimulation: $(EXE_FS)Application 

$(EXE_FS)Application: $(SOURCE_FS)Application.o $(HEADER_FS)Application.h $(SOURCE_FS)FieldSimulation.o $(HEADER_FS)FieldSimulation.h $(SHADER)*glsl
	$(MAKE) -o $(EXE_FS)Application $(SOURCE_FS)Application.o $(SOURCE_FS)FieldSimulation.o -I$(INCLUDE_FS) -I$(HEADER_FS) -L$(LIB) $(LIB_LINK) 

$(SOURCE_FS)FieldSimulation.o: $(SOURCE_FS)FieldSimulation.cpp $(HEADER_FS)Application.h $(HEADER_FS)FieldSimulation.h $(SHADER)*glsl
	$(MAKE) -c $(SOURCE_FS)FieldSimulation.cpp -o $(SOURCE_FS)FieldSimulation.o -I$(INCLUDE_FS) -I$(HEADER_FS)
$(SOURCE_FS)Application.o: $(SOURCE_FS)Application.cpp $(HEADER_FS)Application.h
	$(MAKE) -c $(SOURCE_FS)Application.cpp -o $(SOURCE_FS)Application.o -I$(INCLUDE_FS) -I$(HEADER_FS)

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
