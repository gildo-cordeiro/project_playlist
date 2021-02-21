#include "PlayLists.h"

// Construtor padrão
PlayLists::PlayLists(){
    this->head = nullptr;
    this->tail = nullptr;
}

// Construtor padrão
PlayLists::~PlayLists(){
    delete head;
}

/**
* Função: insertPlayList
* parametros:
* - PlayList* list: representa a referencia de uma PlayList.
* Descrição: insere na lista encadeada de playlists a playlist passada por parametro junto com um id.
*/
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

/**
* Função: showPlayLists
* parametros:
* - 
* Descrição: mostra todas as playlists contidas na lista encadeada.
*/
void PlayLists::showPlayLists(){
    PlayList* list = head;
    
    if(head == nullptr){
        std::cout << "A lista NAO possui elementos!!\n";
    }else{
        while(list){
            std::cout << "ID: " << list->getId() << " - " << list->getTitulo() << std::endl;
            list = list->getNext();
        }
        std::cout << std::endl;
    }
}

/**
* Função: findById
* parametros:
* - int id: id que representa uma determinada playlist dentro da lista encadeada de playlists
* Descrição: procura pela playlist que possui o id passado por parametro.
*/
PlayList* PlayLists::findById(int id){
    PlayList* lista = head;

    while(lista){
        if(lista->getId() == id)
            return lista;
        lista = lista->getNext();
    }

    return nullptr;
}

/**
* Função: findById
* parametros:
* - int id: id que representa uma determinada playlist dentro da lista encadeada de playlists
* Descrição: procura pela playlist que possui o id passado por parametro e romove da lista encadeada.
*/
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

/**
* Função: findById
* parametros:
* - 
* Descrição: retorna o tamanho da lista encadeada.
*/
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
