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
        while(list != nullptr){
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
        tail->setPrev(head);
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
    if(m->getNext() != nullptr){
        if(m->getTitulo() == head->getTitulo() && m->getArtista() == head->getArtista())
            cout << "Tocando: " << m->getNext()->getTitulo() << endl;
        
        head->setPrev(head);
        head = m->getNext();
        head->setNext(head->getNext());  
    }else{

    }
}

void Lista::playPrev(Musica* m){

    if(m->getTitulo() == head->getTitulo() && m->getArtista() == head->getArtista())
        cout << "Tocando: " << m->getPrev()->getTitulo() << endl;

    head->setNext(head);
    head = m->getPrev();
    head->setPrev(head->getPrev());  
    
}

Musica* Lista::getCurrentMusic(){
    return head;
}

void Lista::delete_first(){  
    Musica *temp = new Musica();
    temp = head;
    head = head->getNext();
    delete temp;
}

void Lista::delete_position(Musica* m) {
    Musica *current = new Musica();
    Musica *previous = new Musica();
    current = head;

    while(current->getTitulo() != m->getTitulo()){
        previous = current;
        current  = current->getNext();
    }
    
    previous->setNext(current->getNext());
}

Musica* Lista::findByTitulo(string titulo){
    while(head){
       int pos = head->getTitulo().find(titulo);
        if(pos != -1)
            return head;

        head = head->getNext();
    }

    return nullptr;
}