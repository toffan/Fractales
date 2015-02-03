all:
	g++ -Wall -Wextra -pedantic -std=c++14 -lsfml-graphics -lsfml-system -lsfml-window -o window main.cpp window.cpp clo.cpp

release:
	g++ -O3 -Wall -Wextra -pedantic -std=c++14 -lsfml-graphics -lsfml-system -lsfml-window -o window main.cpp window.cpp clo.cpp
