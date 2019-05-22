all:
	#g++ main.cpp natural.cpp sm.cpp -o sign-module 
	#-lgtest -lgtest_main
	gcc main.cpp natural.cpp sm.cpp -Wall -lgtest -lgtest_main -lstdc++ -O3 --fast-math -o sign-module