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
    void playNext(Musica* m);
    Musica* getCurrentMusic();
};

#endif