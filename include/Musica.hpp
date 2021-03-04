#pragma once

#include <iostream>

class Musica{
    private:
        std::string artista;
        std::string titulo;
    
    public:
        Musica();
        ~Musica();
        
        Musica(std::string titulo, std::string artista);

        void setTitulo(std::string titulo);
        std::string getTitulo();

        void setArtista(std::string artista);
        std::string getArtista();
};
