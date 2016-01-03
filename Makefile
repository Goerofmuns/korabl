all:
	clang++ --std=c++11 src/main.cpp src/vessel.cpp src/player.cpp src/texture_manager.cpp src/game.cpp -o korabl -I./src/ -lsfml-graphics -lsfml-window -lsfml-system -g

gcc:
	g++ --std=c++11 main.cpp vessel.cpp player.cpp -o Vessel -I. -lsfml-graphics -lsfml-window -lsfml-system -g

clean:
	rm ./korabl
