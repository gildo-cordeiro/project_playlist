#include "Musica.hpp"

// Construtor padrão    
Musica::Musica(){
    this->titulo  = "";
    this->artista = "";
}

// Destrutor padrão
Musica::~Musica(){
    
}

// Modificadores de acesso dos atributos privados da classe
std::string Musica::getTitulo(){
    return this->titulo;
}

void Musica::setTitulo(std::string titulo){
    this->titulo = titulo;
}

std::string Musica::getArtista(){
    return this->artista;
}

void Musica::setArtista(std::string artista){
    this->artista = artista;
}
