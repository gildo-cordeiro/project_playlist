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
    void removerPlayList(int id);
    PlayList* findByName(string name, PlayList* list);
    PlayList* findById(int id);
    void romoveMusicFromAllPlayLists(Musica* music);
    PlayList lista;
    int size();
   
};

#endif