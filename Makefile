all: compile

compile: asgn2.cpp man.cpp box.cpp
	@g++ -o A22 asgn2.cpp box.cpp man.cpp room.cpp -lglut -lGLU
