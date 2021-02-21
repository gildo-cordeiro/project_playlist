#ifndef PlayLists_h
#define PlayLists_h

#include "PlayList.h"

class PlayLists{
private:
    PlayList* head;
    PlayList* tail;

public:
    PlayLists();
    ~PlayLists();
    void insertPlayList(PlayList* list, int id);
    void showPlayLists();
    void removerPlayList(int id);
    PlayList* findById(int id);
    PlayList lista;
    int size();
   
};

#endif