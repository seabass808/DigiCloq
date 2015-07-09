all: main

main: main.o
	g++ -std=c++14 -o main main.o -lglut -lGLU -lGL
	
main.o: main.cpp
	g++ -c -std=c++14 main.cpp -lglut -lGLU -lGL

clean:
	rm -rf*o main












