
LIBS:=-lopengl32 -lglu32 -lglut32 -lglut32 -lwinmm -gdi32

TargetDir:=./Debug
OBJSDir:=$(TargetDir)/src
SRCDir:=./src

CXX:=g++

Kube : main.o Constants.o Cube.o GLColor.o GLFace.o GLShape.o GLVertex.o GLWorld.o Layer.o m4.o Kube.o
	$(CXX) -g -o $(TargetDir)/Kube.exe $(OBJSDir)/main.o $(OBJSDir)/Constants.o $(OBJSDir)/Cube.o $(OBJSDir)/GLColor.o $(OBJSDir)/GLFace.o $(OBJSDir)/GLShape.o $(OBJSDir)/GLVertex.o $(OBJSDir)/GLWorld.o $(OBJSDir)/Layer.o $(OBJSDir)/m4.o $(OBJSDir)/Kube.o $(LIBS)

main.o : $(SRCDir)/main.cpp
	$(CXX) -c $(SRCDir)/main.cpp -o $(OBJSDir)/main.o
		
Constants.o : $(SRCDir)/Constants.cpp
	$(CXX) -c $(SRCDir)/Constants.cpp  -o $(OBJSDir)/Constants.o

Cube.o : $(SRCDir)/Cube.cpp
	$(CXX) -c $(SRCDir)/Cube.cpp  -o $(OBJSDir)/Cube.o
	
GLColor.o : $(SRCDir)/GLColor.cpp
	$(CXX) -c $(SRCDir)/GLColor.cpp  -o $(OBJSDir)/GLColor.o
	
GLFace.o : $(SRCDir)/GLFace.cpp
	$(CXX) -c $(SRCDir)/GLFace.cpp  -o $(OBJSDir)/GLFace.o
	
GLShape.o : $(SRCDir)/GLShape.cpp
	$(CXX) -c $(SRCDir)/GLShape.cpp  -o $(OBJSDir)/GLShape.o

GLVertex.o : $(SRCDir)/GLVertex.cpp
	$(CXX) -c $(SRCDir)/GLVertex.cpp  -o $(OBJSDir)/GLVertex.o
	
GLWorld.o : $(SRCDir)/GLWorld.cpp
	$(CXX) -c $(SRCDir)/GLWorld.cpp  -o $(OBJSDir)/GLWorld.o
	
Layer.o : $(SRCDir)/Layer.cpp
	$(CXX) -c $(SRCDir)/Layer.cpp  -o $(OBJSDir)/Layer.o
	
m4.o : $(SRCDir)/m4.cpp
	$(CXX) -c $(SRCDir)/m4.cpp  -o $(OBJSDir)/m4.o
	
Kube.o : $(SRCDir)/Kube.cpp
	$(CXX) -c $(SRCDir)/Kube.cpp  -o $(OBJSDir)/Kube.o
		
clean : 
	rm $(TargetDir)/*.exe $(OBJSDir)/*.o
	rm -r $(OBJSDir)
	rm -r $(TargetDir)
	mkdir $(TargetDir)
	mkdir $(OBJSDir)