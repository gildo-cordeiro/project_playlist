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

Musica* Lista::playNext(Musica* m){   
    return m->getNext() != nullptr ? head->getNext() : nullptr;
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

    if(head->getNext() != nullptr && size() > 1){
        while(head->getTitulo() != m->getTitulo()){
            head = head->getNext();
        }
        head->setNext(head->getNext()->getNext());
    }else{
        head = nullptr;
    }
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

int Lista::size(){
    
    if(empityList())
        return 0;

    Musica* music = head;

    int size = 0;
    while(music){
        music = music->getNext();
        size++;
    }
    
    return size;
}
