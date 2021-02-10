#include "Musica.h"
#include "string.h"

Musica::Musica(string titulo, string artista){
    this->titulo = titulo;
    this->artista = artista;
    this->next = nullptr;
}

Musica::~Musica(){
    
}

string Musica::getTitulo(){
    return this->titulo;
}

Musica* Musica::getNext(){
    return this->next;
}

void Musica::setNext(Musica* music){
    this->next = music;
}

void Musica::setArtista(string artista){
    this->artista = artista;
}

string Musica::getArtista(){
    return this->artista;
}