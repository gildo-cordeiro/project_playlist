#include "PlayList.h"


PlayList::PlayList(){
    
}

PlayList::~PlayList(){
    
}

PlayList::PlayList(string titulo){
    this->titulo = titulo;
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
    //lista.delete_first();
}

void PlayList::deleteMusic(Musica *music){
    lista.delete_position(music);
}

Musica* PlayList::findByTitulo(string titulo){
    return lista.findByTitulo(titulo);
}

PlayList* PlayList::getNext(){
    return this->next;
}
void PlayList::setNext(PlayList* list){
    this->next = list;
}
PlayList* PlayList::getPrev(){
    return this->prev;
}
void PlayList::setPrev(PlayList* list){
    this->prev = list;
}
void PlayList::setId(int id){
    this->id = id;
}

int PlayList::getId(){
    return this->id;
}