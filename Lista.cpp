#include "Lista.h"

Lista::Lista(){
    head = nullptr;
    tail = nullptr;
}

Lista::Lista(string titulo, string artista){
    head = new Musica(titulo, artista);
    tail = head;
}

Lista::~Lista(){
    delete head;
}

void Lista::showLista(){
    
    Musica* list = head;
    
    if(empityList()){
        cout << "A lista NAO possui elementos!!\n";
    }else{
        while(list){
            cout << list->getTitulo() << " - " << list->getArtista()  << endl;
            list = list->getNext();
        }
        cout << endl;
    }
}

bool Lista::empityList(){
    return (head == NULL);
}

void Lista::insertBegin(Musica* m){
    Musica* new_music = m;

    if(empityList()){
        head = new_music;
        tail = new_music;
    }else{
        new_music->setNext(head);
        head = new_music;
    }
}

void Lista::insertEnd(Musica* m){
    Musica* new_music = m;

    if(empityList()){
        head = new_music;
        tail = new_music;
    }else{
        tail->setPrev(tail);
        tail->setNext(new_music);
        tail = new_music;
    }
}


bool Lista::exist(Musica* m){
    Musica* music = head;

    while (music){

        if(music->getTitulo() == m->getTitulo())
            return true;
        
        music = music->getNext();
    }

    return false;
    
}

void Lista::playNext(Musica* m){
    Musica* music = head;
    if(m->getTitulo() == music->getTitulo() && m->getArtista() == music->getArtista()){
        cout << "Tocando " << m->getNext()->getTitulo() << endl;
    }
}
Musica* Lista::getCurrentMusic(){
    return head;
}