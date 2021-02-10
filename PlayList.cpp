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
void PlayList::currentMusic(){
    cout << "Tocando a primeira musica:" << endl;
    cout << lista.getCurrentMusic()->getTitulo() << endl;
}