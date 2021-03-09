#pragma once

#include <iostream>
#include "Lista.hpp"

class PlayList{
private:
    std::string titulo;
    Lista* playlist;
    int next;
    
public:
    PlayList();
    ~PlayList();

    bool addEnd(Musica musica);
    void removeMusicPosition(int posicao);
    void show(Node* node, int contador);
    Musica *nextMusic();
    Lista* getList();
    void setList(Lista* lista);
    std::string getNome();
    void setNome(std::string);

};
