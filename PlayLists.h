#ifndef PlayLists_h
#define PlayLists_h

#include "PlayList.h"

using namespace std;

class PlayLists{
private:
    PlayList* head;
    PlayList* tail;

public:
    PlayLists();
    ~PlayLists();
    void insertPlayList(PlayList* list, int id);
    void showPlayLists();
    void removerPlayList(string name);
    PlayList* findByName(string name, PlayList* list);
    PlayList* findById(int id);
    PlayList lista;
   
};

#endif