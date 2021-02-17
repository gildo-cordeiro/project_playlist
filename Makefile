all: main

main: Musica.o Lista.o PlayList.o PlayLists.o main.o 
	g++ Musica.o Lista.o PlayList.o PlayLists.o main.o -o main

Musica.o: Musica.cpp Musica.h
	g++ -c -Wall -Wextra -pedantic -o Musica.o Musica.cpp

Lista.o: Lista.cpp Lista.h
	g++ -c -Wall -Wextra -pedantic -o Lista.o Lista.cpp

PlayList.o: PlayList.cpp PlayList.h
	g++ -c -Wall -Wextra -pedantic -o PlayList.o PlayList.cpp

PlayLists.o: PlayLists.cpp PlayLists.h
	g++ -c -Wall -Wextra -pedantic -o PlayLists.o PlayLists.cpp

main.o: main.cpp
	g++ -c -Wall -Wextra -pedantic -o main.o main.cpp 

clean: clean
	rm *.o 