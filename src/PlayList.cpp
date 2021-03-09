#include "PlayList.hpp"

// Construtor
PlayList::PlayList(){
    playlist = new Lista;
    next = 0;
}

// Destrutor
PlayList::~PlayList(){
    delete playlist;
}

/**
* Função: addEnd
* parametros:
* - Musica musica: representa uma musica.
* Descrição: adiciona a musica no fim da playlist
*/
bool PlayList::addEnd(Musica musica){
    return playlist->insertEnd(musica);
}

/**
* Função: removeMusicPosition
* parametros:
* - int position: representa a posição da musica que sera removida da playlist.
* Descrição: remove a musica da playlist a partir da  posição informada.
*/
void PlayList::removeMusicPosition(int posicao){
    playlist->deleteMusic(posicao);
}

/**
* Função: show
* parametros:
* - Node* node: representa o objeto Node que contem a musica
* - int cont: contador
* Descrição: metodo recursivo utilizado para mostrar todas as musicas.
*/
void PlayList::show(Node* node, int cont){
    if(node == nullptr){
        return;
    }
    std::cout << cont << ". " << node->music->getTitulo() << " - " << node->music->getArtista() << std::endl;
    show(node->next, cont + 1); 

}

/**
* Função: nextMusic
* parametros:
* - 
* Descrição: metodo responsavel por tocar a proxima musica
*/
Musica* PlayList::nextMusic(){

    Node *node = playlist->searchByPosition(next); 

    if(node != nullptr){
        next++;
        return node->music; 
    }

    return nullptr; 
}

/**
* Função: getList
* parametros:
* - 
* Descrição: retorna a playlist
*/
Lista* PlayList::getList(){
    return playlist;
}

/**
* Função: setList
* parametros:
* - 
* Descrição: armazena playlist
*/
void PlayList::setList(Lista* lista){

    int tamanho_pl = playlist->getSize();

    for (int i = 0; i < tamanho_pl; i++){
        playlist->deleteMusic(0);
    }

    if(lista != nullptr){
        tamanho_pl = lista->getSize();

        for (int i = 0; i < tamanho_pl; i++){
            playlist->insertEnd(*lista->searchByPosition(i)->music);
        }
    }    
}

// Modificadores de acesso dos atributos privados da classe
void PlayList::setNome(std::string nome){
    this->titulo = nome;
}

std::string PlayList::getNome(){
    return titulo;
}
