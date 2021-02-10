#ifndef PlayList_h
#define PlayList_h

#include <iostream>
#include <vector>
#include "Lista.h"

using namespace std;

class PlayList{
private:
    string titulo;
    
public:
    PlayList(string titulo);
    ~PlayList();
    void setTitulo(string titulo);
    string getTitulo();
    void insertMusic(Musica* music);
    void showPlaylist();
    void currentMusic();
    Lista lista;
};


#endif