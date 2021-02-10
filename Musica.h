#ifndef Musica_h
#define Musica_h

#include <iostream>
using namespace std;

class Musica{
    private:
        string artista;
        string titulo;
        Musica* next;
        Musica* prev;
    
    public:
        Musica();
        Musica(string titulo, string artista);
        ~Musica();
        string getTitulo();
        Musica* getNext();
        void setNext(Musica* music);
        Musica* getPrev();
        void setPrev(Musica* music);
        void setArtista(string artista);
        string getArtista();

};


#endif