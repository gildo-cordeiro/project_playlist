#include "Lista.hpp"
#include "Node.hpp"
#include <ostream>

Lista aux;

// Construtor padrão
Lista::Lista(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Contrutor copia
Lista::Lista(const Lista &lista){
    this->head = lista.head;
    this->tail = lista.tail;
    this->size = lista.size;   
}

// Destrutor padrão
Lista::~Lista(){
   
    if(size == 0){
        return;
    }else{
        Node* current = head;

        while (current != nullptr){
            Node* temp = current->next;
            delete current->music;
            delete current;
            current = temp;
        }
    }
}

/**
* Função: show
* parametros:
* - 
* Descrição: Utilizada para mostrar as musicas contidas na lista.
*/
void Lista::show(){

    Node* list = head;
    
    if(list == nullptr){
        std::cout << "A LISTA NÃO POSSUI ELEMENTOS!!\n";
    }else{
        for(int i = 0; i < getSize() && list != nullptr; i++){
            std::cout << i+1 << ". " << list->music->getTitulo() << " - " << list->music->getArtista()  << std::endl;
            list = list->next;
        }
        std::cout << std::endl;
    }
}



/**
* Função: insertEnd
* parametros:
* - Musica musica: representa uma uma musica.
* Descrição: insere a musica no final da lista encadeada.
*/
bool Lista::insertEnd(Musica music){
    
    if(search(music) == nullptr){
        if(head == nullptr){

            head = new Node;
            head->music = new Musica;

            head->music->setTitulo(music.getTitulo());
            head->music->setArtista(music.getArtista());
            head->next = nullptr;

            tail = head;
            size++;

        }else{

            Node *temp = new Node;
            temp->music = new Musica();

            temp->music->setTitulo(music.getTitulo());
            temp->music->setArtista(music.getArtista());
            temp->next = nullptr;

            tail->next = temp;
            tail = temp;

            size++;
        }
        return true;
    }

    return false;
}

/**
* Função: insertEnd
* parametros:
* - Lista *&list: um array de listas
* Descrição: função sobrecarregada utilizada para inserir o array de listas no fim da lista atual
*/
bool Lista::insertEnd(Lista*&list){
    for (int i = 0; i < 3; i++){
       this->insertEnd(*list[i].head->music);
    }       
    return true;
}


/**
* Função: search
* parametros:
* - Musica music: representa a ma musica.
* Descrição: busca na lista a musica passada por parametro e retorna uma referencia de Node
*/
Node* Lista::search(Musica music){

    Node *current = head;

    while(current != nullptr){
        if(current->music->getTitulo() == music.getTitulo() && current->music->getArtista() == music.getArtista()){
            return current; 
        }else{
            current = current->next;
        }
    }
    return nullptr;
}

/**
* Função: deleteMusic
* parametros:
* - int position: contem a posição da musica que deve ser removida
* Descrição: busca na lista a musica que esta na posição contida no parametro
*/
void Lista::deleteMusic(int position){
    Node *current  = head;
    Node *prev = nullptr;

    for(int i = 1; i < position; i++){ 
        prev = current;
        current  = current->next;
    }

    if(current == head){
        head = head->next;
    }else{
        if(current == tail){
            prev->next = nullptr;
            tail = prev;
        }else{
            prev->next = current->next;
        }
    }
    
    size--; 

    delete current->music;
    delete current;
}

/**
* Função: deleteMusic
* parametros:
* - Lista *&list: contem uma lista de musicas que devem ser removidas
* Descrição: percorre a lista buscando a musicas contidadas no parametro e as remove
*/
void Lista::deleteMusic(Lista*&list){
    for (int i = 0; i < list->getSize()-1; i++){
        if(list[i].head->music->getTitulo() == this->head->music->getTitulo()
            && list[i].head->music->getArtista() == this->head->music->getArtista()){
            Node *current  = head;
            Node *prev = nullptr;

            if(current == head){
                head = head->next;
            }else{
                if(current == tail){
                    prev->next = nullptr;
                    tail = prev;
                }else{
                    prev->next = current->next;
                }
            }
            
            size--; 

            delete current->music;
            delete current;
        }
    }
}

/**
* Função: searchByPosition
* parametros:
* - int position: contem a posição da musica na lista
* Descrição: busca na lista a musica que esta na posição contida no parametro e retorna o seu Node
*/
Node* Lista::searchByPosition(int posicao){

    if(posicao >= 0 && posicao < size){

        Node *temp = head; 
        for(int i = 0; i < posicao; i++){ 
            temp = temp->next;
        }

        return temp;
    }

    return nullptr;
}

/**
* Função: searchMusic
* parametros:
* - Musica music: representa a ma musica.
* Descrição: busca na lista a musica passada por parametro e retorna uma referencia de Musica
*/
Musica* Lista::searchMusic(Musica musica){
    
    Node *current = head;

    while(current != nullptr){
        if(current->music->getTitulo() == musica.getTitulo() && current->music->getArtista() == musica.getArtista()){
            return current->music; 
        }else{
            current = current->next;
        }
    }

    return nullptr;
}

/**
* Função: getCurrentMusic
* parametros:
* - 
* Descrição: retorna a musica atual
*/
Musica* Lista::getCurrentMusic(){
    Node* list = head;

    return list->music;
}

/**
* Função: getSize
* parametros:
* - 
* Descrição: retorna o tamanho da lista.
*/
int Lista::getSize(){    
    return size;
}

/**
* Função: setSize
* parametros:
* - 
* Descrição: armazena o tamanho da lista.
*/
void Lista::setSize(int size){
    this->size = size;
}