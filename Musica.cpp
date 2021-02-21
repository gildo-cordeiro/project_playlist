#include "Musica.h"

/**
* Construtor parametrizado
* parametros:
* - string titulo: titulo para nova musica.
* - string artista: nome do artista da musica
* - int id: utilizado como auxiliar para identificação da musica em operações futuras
* Descrição: utilizado para criar objetos Musica preenchidos com os valores dos parametros
*/
Musica::Musica(std::string titulo, std::string artista, int id){
    this->titulo = titulo;
    this->artista = artista;
    this->next = nullptr;
    this->id = id;
}

// Construtor padrão    
Musica::Musica(){
    this->titulo  = "";
    this->artista = "";
    this->next = nullptr;
    this->id = 0;
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

Musica* Musica::getNext(){
    return this->next;
}

void Musica::setNext(Musica* music){
    this->next = music;
}

std::string Musica::getArtista(){
    return this->artista;
}

void Musica::setArtista(std::string artista){
    this->artista = artista;
}

void Musica::setId(int id){
    this->id = id;
}

int Musica::getId(){
    return this->id;
}