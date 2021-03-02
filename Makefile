all: create_dir main

# Cria pasta para armazenar os arquivos objetos
create_dir:
	mkdir -p bin

bin/Musica.o: src/Musica.cpp include/Musica.hpp
	g++ -c -Wall -Iinclude -O0 -Wextra -pedantic -o bin/Musica.o src/Musica.cpp

bin/Lista.o: src/Lista.cpp include/Lista.hpp
	g++ -c -Wall -Iinclude -O0 -Wextra -pedantic -o bin/Lista.o src/Lista.cpp

bin/PlayList.o: src/PlayList.cpp include/PlayList.hpp
	g++ -c -Wall -Iinclude -O0 -Wextra -pedantic -o bin/PlayList.o src/PlayList.cpp

bin/PlayLists.o: src/PlayLists.cpp include/PlayLists.hpp
	g++ -c -Wall -Iinclude -O0 -Wextra -pedantic -o bin/PlayLists.o src/PlayLists.cpp

bin/main.o: src/main.cpp
	g++ -c -Wall -Iinclude -O0 -Wextra -pedantic -o bin/main.o src/main.cpp

main: bin/Musica.o bin/Lista.o bin/PlayList.o bin/PlayLists.o bin/main.o
	g++ bin/Musica.o bin/Lista.o bin/PlayList.o bin/PlayLists.o bin/main.o -o main
run: all
	./main

clean: clean
	rm -rf bin main