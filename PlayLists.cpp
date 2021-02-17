#include "PlayLists.h"
#include <string.h>


PlayLists::PlayLists(){
    this->head = nullptr;
    this->tail = nullptr;
}

PlayLists::~PlayLists(){
    delete head;
}

void PlayLists::insertPlayList(PlayList* list, int id){
    PlayList* new_list = list;
    
    list->setId(id);
    if(head ==  nullptr){
        head = new_list;
        tail = new_list;
    }else{
        tail->setNext(new_list);
        tail = new_list;
    }
}

void PlayLists::showPlayLists(){
    PlayList* list = head;
    
    if(head == nullptr){
        cout << "A lista NAO possui elementos!!\n";
    }else{
        while(list){
            cout << "ID: " << list->getId() << " - " << list->getTitulo() << endl;
            list = list->getNext();
        }
        cout << endl;
    }
}

PlayList* PlayLists::findByName(string name, PlayList* lista){

    while(lista){
       int pos = lista->getTitulo().find(name);
        if(pos != -1)
            return lista;

        lista = lista->getNext();
    }

    return nullptr;
}

PlayList* PlayLists::findById(int id){
    PlayList* lista = head;

    while(lista){
        if(lista->getId() == id)
            return lista;
        lista = lista->getNext();
    }

    return nullptr;
}

void PlayLists::removerPlayList(int id){

    if(head->getNext() != nullptr && size() > 1){
        while(head->getId() != id){
            head = head->getNext();
        }
        head->setNext(head->getNext()->getNext());
    }else{
        head = nullptr;
    }
}

void PlayLists::romoveMusicFromAllPlayLists(Musica* music){
    PlayList *current = new PlayList();
    PlayList *previous = new PlayList();
    
    current = head;
    while (current){
        head->lista.delete_position(music);

        previous = current;
        current  = current->getNext();
    }    
    previous->setNext(current->getNext());
}

int PlayLists::size(){
    
    if(head == nullptr)
        return 0;

    PlayList* list = head;

    int size = 0;
    while(list){
        list = list->getNext();
        size++;
    }
    
    return size;
}
