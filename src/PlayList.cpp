#include "PlayList.hpp"

PlayList::PlayList(std::string titulo){
    this->titulo = titulo;
}

// Construtor padrão
PlayList::PlayList(){
    
}

// Destrutor padrão
PlayList::~PlayList(){
    
}

/**
* Função: insertMusic
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: faz a conexão entre o metodo de inserir musica na lista encadeada com o parametro
* m que representa a musica que deve ser inserida na lista.
*/
void PlayList::insertMusic(Musica* music){
    
    if(music != nullptr){
        lista.insertEnd(music);
    }else{
        std::cout << "Insira uma musica!" << std::endl;
    }
}

/**
* Função: showPlaylist
* parametros:
* - 
* Descrição: faz a conexão entre o metodo showPlaylist na lista encadeada.
*/
void PlayList::showPlaylist(){
    lista.showLista();
}

/**
* Função: getCurrentMusic
* parametros:
* - 
* Descrição: faz a conexão entre o metodo getCurrentMusic na lista encadeada.
*/
Musica* PlayList::getCurrentMusic(){
    return lista.getCurrentMusic();
}

/**
* Função: playNextMusic
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: faz a conexão entre o metodo playNext na lista encadeada e antes de passar a referencia adiante
* verifica se está adequada.
*/
void PlayList::playNextMusic(Musica* m){
    if(lista.playNext(m) != nullptr)
        std::cout << "Tocando... " << lista.playNext(m)->getTitulo() << std::endl;
    else
        std::cout << "Não há proxima musica!" << std::endl;
}

/**
* Função: deleteMusic
* parametros:
* - Musica* m: representa a referencia de uma musica.
* Descrição: faz a conexão entre o metodo deleteMusic na lista encadeada e passa a referencia da  musica.
*/
void PlayList::deleteMusic(Musica *music){
    lista.deleteMusic(music);
}

/**
* Função: findById
* parametros:
* - int id: representa o id da musica.
* Descrição: faz a conexão entre o metodo deleteMusic na lista encadeada e passa por paramentro o id da 
* musica a ser removida.
*/
Musica* PlayList::findById(int id){
    return lista.findById(id);
}

/**
* Função: findByTitulo
* parametros:
* - string titulo: representa o titulo da musica.
* Descrição: faz a conexão entre o metodo findByTitulo na lista encadeada e passa por paramentro o titulo
* da musica a ser encontrada.
*/
Musica* PlayList::findByTitulo(std::string titulo){
    return lista.findByTitulo(titulo);
}

// Modificadores de acesso dos atributos privados da classe
PlayList* PlayList::getNext(){
    return this->next;
}

void PlayList::setTitulo(std::string titulo){
    this->titulo = titulo;
}

std::string PlayList::getTitulo(){
    return this->titulo;
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