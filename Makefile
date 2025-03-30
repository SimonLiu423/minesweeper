.PHONY: clean

main.out: src/game.o src/main.o
	g++ -o main.out src/main.o src/game.o

game.o: src/game.h src/game.cpp
	g++ -c src/game.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm -f main.out src/*.o