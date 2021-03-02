#pragma once

#include "PlayList.hpp"

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
