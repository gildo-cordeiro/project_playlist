#pragma once

#include <iostream>
#include "Node.hpp"

class Lista{
private:
    Node* head, *tail;
    int size;

public:
    Lista();
    ~Lista();

    bool insertEnd(Musica music);
    void deleteMusic(int position);
    bool insereInPosition(int position, Musica music);
    Node* search(Musica music);  
    Node* searchByPosition(int position); 
    Musica* searchMusic(Musica music); 
    int sizeContent();
    void show();

};
