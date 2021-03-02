#include "Lista.hpp"

// Construtor padrão
Lista::Lista(){
    head = nullptr;
    tail = nullptr;
}

/**
* Construtor parametrizado
* parametros:
* - string titulo: titulo para nova musica.
* - string artista: nome do artista da musica
* - int id: utilizado como auxiliar para identificação da musica em operações futuras
*/
Lista::Lista(std::string titulo, std::string artista, int id){
    head = new Musica(titulo, artista, id);
    tail = head;
}

// Destrutor padrão
Lista::~Lista(){
    delete head;
}

/**
* Função: showLista
* parametros:
* - 
* Descrição: Utilizada para mostrar as musicas contidas na lista.
*/
void Lista::showLista(){
    
    Musica* list = head;
    
    if(empityList()){
        std::cout << "A lista NAO possui elementos!!\n";
    }else{
        while(list != nullptr){
            std::cout << "ID: (" << list->getId() << ")" << list->getTitulo() << " - " << list->getArtista()  << std::endl;
            list = list->getNext();
        }
        std::cout << std::endl;
    }
}

/**
* Função: empityList
* parametros:
* - 
* Descrição: Verificar se a lista está vazia.
*/
bool Lista::empityList(){
    return (head == NULL);
}

/**
* Função: insertEnd
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: insere a musica no final da lista encadeada.
*/
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

/**
* Função: exist
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: verifica se a musica passada por parametro existe na lista.
*/
bool Lista::exist(Musica* m){
    Musica* music = head;

    while (music){

        if(music->getTitulo() == m->getTitulo())
            return true;
        
        music = music->getNext();
    }

    return false;
    
}

/**
* Função: playNext
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: retorna a proxima musica da lista.
*/
Musica* Lista::playNext(Musica* m){   
    return m->getNext() != nullptr ? head->getNext() : nullptr;
}

/**
* Função: getCurrentMusic
* parametros:
* - 
* Descrição: retorna a musica atual (head).
*/
Musica* Lista::getCurrentMusic(){
    return head;
}

/**
* Função: getCurrentMusic
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: deleta a musica recebida por parametro.
*/
void Lista::deleteMusic(Musica* m) {

    if(head->getNext() != nullptr && size() > 1){
        while(head->getTitulo() != m->getTitulo()){
            head = head->getNext();
        }
        head->setNext(head->getNext()->getNext());
    }else{
        head = nullptr;
    }
}

/**
* Função: findByTitulo
* parametros:
* - string titulo: string que representa o titulo de uma musica
* Descrição: procura na lista uma musica com o mesmo titulo que foi informado no parametro.
*/
Musica* Lista::findByTitulo(std::string titulo){
    while(head){
       int pos = head->getTitulo().find(titulo);
        if(pos != -1)
            return head;

        head = head->getNext();
    }

    return nullptr;
}

/**
* Função: size
* parametros:
* - 
* Descrição: retorna o tamanho da lista.
*/
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

/**
* Função: findById
* parametros:
* - int id: representa o id de uma musica
* Descrição: procura na lista uma musica com o mesmo id que foi informado no parametro.
*/
Musica* Lista::findById(int id){
    Musica* lista = head;
    while(lista != nullptr){
        if(lista->getId() == id){
            return lista;
        }
        lista = lista->getNext();
    }

    return nullptr;
}