all:
	#g++ main.cpp natural.cpp sm.cpp -o sign-module
	gcc main.cpp natural.cpp sm.cpp -Wall -lstdc++ -O3 -o sign-module