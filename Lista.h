#ifndef Lista_h
#define Lista_h

#include <iostream>
#include "Musica.h"

using namespace std;

class Lista{
private:
    Musica* head;
    Musica* tail;

public:
    Lista(string titulo, string artista);
    Lista();
    ~Lista();
    void showLista();
    bool empityList();
    void insertBegin(Musica* m);
    void insertEnd(Musica* m);
    bool exist(Musica* m);
    Musica* playNext(Musica* m);
    void playPrev(Musica* m);
    void delete_first();
    void delete_position(Musica* m);
    Musica* getCurrentMusic();
    Musica* findByTitulo(string titulo);
    int size();
};

#endif