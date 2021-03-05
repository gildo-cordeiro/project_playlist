all: dir main

dir:
	mkdir -p bin

bin/Musica.o: src/Musica.cpp
	g++ src/Musica.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Musica.o

bin/Node.o: src/Node.cpp bin/Musica.o
	g++ src/Node.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Node.o

bin/Lista.o: src/Lista.cpp bin/Musica.o bin/Node.o
	g++ src/Lista.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Lista.o

bin/PlayList.o: src/PlayList.cpp bin/Musica.o bin/Node.o bin/Lista.o
	g++ src/PlayList.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/PlayList.o

bin/main.o: src/main.cpp bin/Musica.o bin/Node.o bin/Lista.o bin/PlayList.o
	g++ src/main.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/main.o

main: bin/Musica.o bin/Node.o bin/Lista.o bin/PlayList.o bin/main.o
	g++ bin/*.o -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -o main

run: all
	./main

clean:
	rm -rf bin main