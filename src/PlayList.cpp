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

// Adiciona uma música no fim da playlist
bool PlayList::addEnd(Musica musica){
    return playlist->insertEnd(musica); // Retorna código retornado pela função da classe Lista
}

// // Adiciona uma música em uma posição específica da playlist
// bool PlayList::adicionaMusicaPos(int pos, Musica musica){
//     return playlist->inserePos(pos, musica); // Retorna código retornado pela função da classe Lista
// }

// // Remove uma música em uma posição específica da playlist
// void PlayList::removeMusicaPos(int posicao){
//     playlist->removePos(posicao); // Retorna código retornado pela função da classe Lista
// }

// Move uma música dentro da playlist
void PlayList::moveMusica(int pos_inicial, int pos_final){

    Musica musica;// Variável a receber as informações da musica a ser movida

    // Copia as informações da música a ser movida
    musica.setTitulo(playlist->searchByPosition(pos_inicial - 1)->music->getTitulo());
    musica.setArtista(playlist->searchByPosition(pos_inicial - 1)->music->getArtista());

    playlist->deleteMusic(pos_inicial); // Remove a música da posição atual
    playlist->insereInPosition(pos_final, musica); // Insere a música na posição para qual o usuário deseja movê-la
}

// Imprime as músicas da playlist recursivamente
void PlayList::show(Node* node, int cont){
    if(node == nullptr){ // Verifica se a lista já chegou ao fim
        return;
    }
    std::cout << cont << ". " << node->music->getTitulo() << " - " << node->music->getArtista() << std::endl;
    show(node->next, cont + 1); // Faz a chamada recursiva para a immressão do próximo node 
}

// Retorna a próxima música a ser tocada
Musica* PlayList::proxMusica(){

    Node *node = playlist->searchByPosition(next); // Recebe o node que armazena a próxima música a ser tocada

    if(node != nullptr){ // Verifica se ainda há música para tocar
        next++;
        return node->music; // Retorna a música 
    }

    return nullptr; // A reprodução das músicas chegou ao fim
}

// Retorna a playlist
Lista* PlayList::getLista(){
    return playlist;
}

// Descarta a lista antiga e faz uma cópia da lista recebida
void PlayList::setLista(Lista* lista){

    int tamanho_pl = playlist->sizeContent(); // Recebe o tamanho da playlist a ser redefinida

    for (int i = 0; i < tamanho_pl; i++){ // Remove todos os elementos antigos
        playlist->deleteMusic(0);
    }

    if(lista != nullptr){ // Verifica se o ponteiro não é nulo
        tamanho_pl = lista->sizeContent(); // Recebe o tamanho da nova lista

        for (int i = 0; i < tamanho_pl; i++){ // Insere todos os elementos da nova lista na lista original
            playlist->insertEnd(*lista->searchByPosition(i)->music);
        }
    }    
}

// Define o nome da playlist
void PlayList::setNome(std::string nome){
    this->titulo = nome;
}

// Retorna o nome da playlist
std::string PlayList::getNome(){
    return titulo;
}
