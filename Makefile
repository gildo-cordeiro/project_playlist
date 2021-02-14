all: main

main: Musica.o Lista.o PlayList.o PlayLists.o main.o 
	g++ Musica.cpp Lista.cpp PlayList.cpp PlayLists.cpp main.cpp -o main

musica.o: g++ -Wall -Wextra -pedantic Musica.h


clean: clean
	rm *.o 