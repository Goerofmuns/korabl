all:
	clang++ --std=c++11 main.cpp vessel.cpp -o Vessel -I. -lsfml-graphics -lsfml-window -lsfml-system 
