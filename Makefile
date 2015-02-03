all:
	g++ -Wall -std=c++11 -lsfml-graphics -lsfml-system -lsfml-window -o window main.cpp maths.cpp window.cpp clo.cpp

release:
	g++ -O3 -Wall -std=c++11 -lsfml-graphics -lsfml-system -lsfml-window -o window main.cpp maths.cpp window.cpp clo.cpp
