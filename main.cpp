#include <iostream>
#include <stdlib.h>
#include "Lista.h"
#include "Musica.h"
#include "PlayList.h"

using namespace std;

int main(int argc, char const *argv[]){

    Musica* music_1  = new Musica("If You Were Mine", "Thompson Acoustic Remix");
    Musica* music_2  = new Musica("Holly Ground", "Taylor Swift");
    Musica* music_3  = new Musica("Closer, Faster", "Against The Current");
    Musica* music_4  = new Musica("Children In The Dark", "Tristam");
    Musica* music_5  = new Musica("Pompei - Remix", "Bastile, Kat Krazy");

    Musica* music_6  = new Musica("The Days", "Avicii");
    Musica* music_7  = new Musica("Need Your Love (With Noah Kahan)", "Gryffin, Seven Lions, Noah kahan");
    Musica* music_8  = new Musica("Without You (feat. Sandro Cavazza)", "Avicii, Sandro Cavazza");
    Musica* music_9  = new Musica("Bad Reputation (feat. Joe Janiak)", "Avicii, Joe Janiak");
    Musica* music_10 = new Musica("Fade Into The Darkness", "Avicii");

    PlayList* p = new PlayList("POP");
    PlayList* e = new PlayList("ELETRONICA");

    p->insertMusic(music_1);
    p->insertMusic(music_2);
    p->insertMusic(music_3);
    p->insertMusic(music_4);
    p->insertMusic(music_5);

    e->insertMusic(music_6);
    e->insertMusic(music_7);
    e->insertMusic(music_8);
    e->insertMusic(music_9);
    e->insertMusic(music_10);

    int resp;

    cout << endl << "----------------------------PLAYLISTS----------------------------" << endl;
    cout<< "(1)" << p->getTitulo() << endl;
    cout<< "(2)" << e->getTitulo() << endl;
    cout << endl << "-----------------------------------------------------------------" << endl;
    
    cout << "Qual Playlist deseja ouvir (informe o numero)?"<<endl;
    cin >> resp;
    if(resp == 1){
        p->showPlaylist();
        p->currentMusic();
    }else{
        e->showPlaylist();
        e->currentMusic();
    }
    
    // cout << "Tocando agora " << music_1->getTitulo() << endl;
    // cout << "Preparando a proxima..." << endl;
    // p->lista.playNext(music_1);
    cout << endl;
    return 0;
}
