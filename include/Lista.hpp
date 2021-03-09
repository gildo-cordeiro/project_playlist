#pragma once

#include <iostream>
#include "Node.hpp"

class Lista{
private:
    Node* head, *tail;
    int size;

public:
    Lista();
    /*construtor copia*/
    Lista(const Lista &list);
    ~Lista();

    bool insertEnd(Musica music);
    bool insertEnd(Lista *&list);
    void deleteMusic(int position);
    void deleteMusic(Lista *&list);
    Node* search(Musica music);  
    Node* searchByPosition(int position); 
    Musica* searchMusic(Musica music); 
    Musica* getCurrentMusic();
    int getSize();
    void setSize(int size);
    void show();
};
