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
    if(lista.playNext(m) != nullptr)
        cout << "Tocando... " << lista.playNext(m)->getTitulo() << endl;
    else
        cout << "Não há proxima musica!" << endl;
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

void PlayList::setId(int id){
    this->id = id;
}

int PlayList::getId(){
    return this->id;
}