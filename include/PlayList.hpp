#pragma once

#include <iostream>
#include "Lista.hpp"

class PlayList{
private:
    std::string titulo;
    PlayList* next;
    int id;
    
public:
    PlayList();
    PlayList(std::string titulo);
    ~PlayList();
    void setTitulo(std::string titulo);
    std::string getTitulo();
    void insertMusic(Musica* music);
    void showPlaylist();
    Musica* getCurrentMusic();
    void playNextMusic(Musica *m);
    void deleteMusic(Musica* music);
    PlayList* getNext();
    void setNext(PlayList* list);
    Musica* findByTitulo(std::string titulo);
    Musica* findById(int id);
    void setId(int id);
    int getId();
    Lista lista;
};
