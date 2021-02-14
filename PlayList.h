#ifndef PlayList_h
#define PlayList_h

#include <iostream>
#include <vector>
#include "Lista.h"

using namespace std;

class PlayList{
private:
    string titulo;
    PlayList* next;
    PlayList* prev;
    int id;
    
public:
    PlayList();
    PlayList(string titulo);
    ~PlayList();
    void setTitulo(string titulo);
    string getTitulo();
    void insertMusic(Musica* music);
    void showPlaylist();
    Musica* getCurrentMusic();
    void playNextMusic(Musica *m);
    void playPrevMusic(Musica* m);
    void delete_first();
    void deleteMusic(Musica* music);
    PlayList* getNext();
    void setNext(PlayList* list);
    PlayList* getPrev();
    void setPrev(PlayList* list);
    Musica* findByTitulo(string titulo);
    void setId(int id);
    int getId();
    Lista lista;
};


#endif