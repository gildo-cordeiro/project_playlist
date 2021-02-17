#include "Musica.h"

Musica::Musica(string titulo, string artista){
    this->titulo = titulo;
    this->artista = artista;
    this->next = nullptr;
}
    
Musica::Musica(){
    this->titulo  = "";
    this->artista = "";
    this->next = nullptr;
}

string Musica::getTitulo(){
    return this->titulo;
}

void Musica::setTitulo(string titulo){
    this->titulo = titulo;
}

Musica* Musica::getNext(){
    return this->next;
}

void Musica::setNext(Musica* music){
    this->next = music;
}

string Musica::getArtista(){
    return this->artista;
}

void Musica::setArtista(string artista){
    this->artista = artista;
}