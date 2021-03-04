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
    // bool adicionaMusicaPos(int posicao, Musica musica);
    //void removeMusicPosition(int posicao);
    void moveMusica(int pos_inicial, int pos_final);
    void show(Node* node, int contador);
    Musica *proxMusica();
    Lista* getLista();
    void setLista(Lista* lista);
    std::string getNome();
    void setNome(std::string);

};
