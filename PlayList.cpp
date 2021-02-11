#include "PlayList.h"


PlayList::PlayList(string titulo){
    this->titulo = titulo;
}

PlayList::~PlayList(){
    
}

void PlayList::setTitulo(string titulo){
    this->titulo = titulo;
}

string PlayList::getTitulo(){
    return this->titulo;
}

void PlayList::insertMusic(Musica* music){
    
    if(music != nullptr){
        lista.insertEnd(music);
    }else{
        cout << "Insira uma musica!" << endl;
    }
}

void PlayList::showPlaylist(){
    lista.showLista();
}

Musica* PlayList::getCurrentMusic(){
    return lista.getCurrentMusic();
}

void PlayList::playNextMusic(Musica* m){
    lista.playNext(m);
}

void PlayList::playPrevMusic(Musica* m){
    lista.playPrev(m);
}

void PlayList::delete_first(){
    lista.delete_first();
}
