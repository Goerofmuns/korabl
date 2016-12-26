OS := $(shell uname)

ifeq ($(OS), Darwin)
osx:
	#we osx
	clang++ --std=c++11 src/main.cpp src/vessel.cpp src/player.cpp src/texture_manager.cpp src/game.cpp src/module.cpp \
		-o korabl \
		-I./src/ -I /usr/local/include \
		-L ./libsfml \
		-lsfml-graphics -lsfml-window -lsfml-system \
		-Wall \
		-g

else
linux:
	#we linux
	clang++ --std=c++11 src/main.cpp src/vessel.cpp src/player.cpp src/texture_manager.cpp src/game.cpp \
		-o korabl \
		-I./src/ \
		-lsfml-graphics -lsfml-window -lsfml-system \
		-Wall

endif

clean:
	rm ./korabl
	rm -r ./korabl.dSYM
