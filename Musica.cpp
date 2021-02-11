#include "Musica.h"
#include "string.h"

Musica::Musica(string titulo, string artista){
    this->titulo = titulo;
    this->artista = artista;
    this->next = nullptr;
    this->prev = nullptr;
}
Musica::Musica(){
    this->titulo  = "";
    this->artista = "";
    this->prev = nullptr;
    this->next = nullptr;
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

Musica* Musica::getPrev(){
    return this->prev;
}

void Musica::setPrev(Musica* music){
    this->prev = music;
}

void Musica::setArtista(string artista){
    this->artista = artista;
}

string Musica::getArtista(){
    return this->artista;
}