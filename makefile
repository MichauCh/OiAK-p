all:
	gcc main.cpp natural.cpp sm.cpp -Wall -lstdc++ -std=c++11 -O3 -pg -o sign-module
