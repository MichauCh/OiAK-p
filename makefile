all:
	#gcc main.cpp natural.cpp sm.cpp -Wall -lgtest -lgtest_main -lstdc++ -O3 --fast-math -o sign-module
	gcc main.cpp natural.cpp sm.cpp -Wall -lgtest -lgtest_main -lstdc++ -O3 --fast-math -pg -o sign-module