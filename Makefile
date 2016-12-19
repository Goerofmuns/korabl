all: osx

linux:
	clang++ --std=c++11 src/main.cpp src/vessel.cpp src/player.cpp src/texture_manager.cpp src/game.cpp \
		-o korabl \
		-I./src/ \
		-lsfml-graphics -lsfml-window -lsfml-system \
		-Wall

osx:
	clang++ --std=c++11 src/main.cpp src/vessel.cpp src/player.cpp src/texture_manager.cpp src/game.cpp \
		-o korabl \
		-I./src/ -I /usr/local/include \
		-L ./libsfml \
		-lsfml-graphics -lsfml-window -lsfml-system \
		-Wall

clean:
	rm ./korabl
