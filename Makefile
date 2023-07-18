all:
		g++ -o Main.exe Src/Main.cpp Src/SnakeGame.cpp Src/Snake.cpp Src/Wall.cpp Src/Board.cpp Src/CollisionManager.cpp Src/Gate.cpp Src/Item.cpp Src/ItemManager.cpp -lncurses