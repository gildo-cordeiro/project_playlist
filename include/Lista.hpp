#pragma once

#include <iostream>
#include "Musica.hpp"

class Lista{
private:
    Musica* head;
    Musica* tail;

public:
    Lista(std::string titulo, std::string artista, int id);
    Lista();
    ~Lista();
    void showLista();
    bool empityList();
    void insertEnd(Musica* m);
    bool exist(Musica* m);
    Musica* playNext(Musica* m);
    void playPrev(Musica* m);
    void deleteMusic(Musica* m);
    Musica* getCurrentMusic();
    Musica* findByTitulo(std::string titulo);
    Musica* findById(int id);
    int size();
};
