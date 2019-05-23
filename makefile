all:
	gcc main.cpp natural.cpp sm.cpp -Wall -lgtest -lgtest_main -lstdc++ -O3 -pg -o sign-module