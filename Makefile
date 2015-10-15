all:
	clang++ --std=c++11 main.cpp vessel.cpp player.cpp texture_manager.cpp game.cpp -o Vessel -I. -lsfml-graphics -lsfml-window -lsfml-system -g
	./Vessel

gcc:
	g++ --std=c++11 main.cpp vessel.cpp player.cpp -o Vessel -I. -lsfml-graphics -lsfml-window -lsfml-system -g
