#pragma once

#include <iostream>

class Musica{
    private:
        int id;
        std::string artista;
        std::string titulo;
        Musica* next;
    
    public:
        Musica();
        ~Musica();
        Musica(std::string titulo, std::string artista, int id);
        std::string getTitulo();
        void setTitulo(std::string titulo);
        Musica* getNext();
        void setNext(Musica* music);
        void setArtista(std::string artista);
        std::string getArtista();
        void setAtista();
        void setId(int id);
        int getId();
};
