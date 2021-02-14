#include <iostream>
#include <stdlib.h>
#include "Lista.h"
#include "Musica.h"
#include "PlayList.h"
#include "PlayLists.h"

using namespace std;

int main(){

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


    PlayLists* ps = new PlayLists();
    ps->insertPlayList(p, 0);
    ps->insertPlayList(e, 1);
    
    PlayList* catalog = new PlayList();    
    PlayLists* catalog_playlists = new PlayLists();

    int resp, id = 1, find_id;
    string nome, artista;
    
    while(true){
        cout << endl << "-------------------------------------------------------" << endl;
        cout << "                                                               " << endl;
        cout << "1 - Adicionar Musica                                           " << endl;
        cout << "2 - Mostrar Musicas                                            " << endl;
        cout << "3 - Remover Musica                                             " << endl;
        cout << "4 - Buscar Musica                                             " << endl;
        cout << "5 - Adicionar Playlist                                         " << endl;
        cout << "6 - Mostrar playlists                                          " << endl;
        cout << "7 - Remover playlist                                           " << endl;
        cout << "8 - Adicionar musica a playlist                                " << endl;
        cin >> resp;
        switch (resp){
            case 1:
                cout << "Qual o titulo da musica? " << endl;
                cin.ignore();
                getline(cin, nome);

                cout << "Qual o nome do artista? " << endl;
                cin.ignore();
                getline(cin, artista);

                if(nome != "" && artista != ""){
                    catalog->insertMusic(new Musica(nome, artista));
                    cout << "Musica adicionada ao catalogo." << endl;
                }else{
                    cout << "Informe o titulo e artista para nova musica." << endl;
                }
                break;
            case 2:
                cout << "Mostrando todas as musicas..." << endl;
                catalog->showPlaylist();
                break;
            case 3:
                cout << "Qual o titulo da musica? " << endl;
                cin.ignore();
                getline(cin, nome);
                
                if(nome != "")
                    if(catalog->findByTitulo(nome) != nullptr)
                        catalog->deleteMusic(catalog->findByTitulo(nome));
                    else
                        cout << "Musica não encontrada!" << endl;
                else   
                    cout << "Informe um titulo!" << endl;
                break;
            case 4:
                cout << "Qual o titulo da musica?" << endl;
                cin.ignore();
                getline(cin, nome);
                if(nome != ""){
                    if(catalog->findByTitulo(nome) != nullptr){
                        cout << "Musica encontrada: " << catalog->findByTitulo(nome)->getTitulo() << endl;
                    }else{
                        cout << "Musica não encontrada" << endl;
                    }
                }else{
                    cout << "Informe o titulo da musica" << endl;
                }
                break;
            case 5:
                cout << "Qual o titulo da PlayList?" << endl;
                cin.ignore();
                getline(cin, nome);

                if(nome != "")
                    catalog_playlists->insertPlayList(new PlayList(nome), id++);
                else 
                    cout << "Informe um nome para PlayList!" << endl;
                break;
            case 6:
                cout << "Mostrando todas as PlayLists..." << endl;
                catalog_playlists->showPlayLists();
                break;
            case 7:
                cin.ignore();
                getline(cin, nome);

                if(nome !=  "")
                    catalog_playlists->removerPlayList(nome);
                else   
                    cout << "Informe o nome da PlayList!" << endl;
                break;
            case 8:
                cout << "-------------------------------------------" << endl;
                cout << "Escolha a playlist que deseja adicionar uma musica (utilize o id):" << endl;
                catalog_playlists->showPlayLists();

                cin >> find_id;
                
                if(id != 0){
                    if(catalog_playlists->findById(find_id) != nullptr){
                        string titulo = catalog_playlists->findById(find_id)->getTitulo();
                        cout << "Escolha a musica para adicionar a playlist " << titulo << ": "<< endl;
                        catalog->showPlaylist();

                        cout << "Qual o nome da musica?" << endl;
                        cin.ignore();
                        getline(cin, nome);
                        
                        catalog_playlists->findById(find_id)->insertMusic(catalog->findByTitulo(nome)); 
                        catalog_playlists->findById(find_id)->showPlaylist();                       
                    }else{
                        cout << "PlayList não encontrada!" << endl;
                    }
                }
                break;
        }
        if(resp == 0)
            break;
    }
    

    // cout << "Tocando agora " << music_1->getTitulo() << endl;
    // cout << "Preparando a proxima..." << endl;
    // p->lista.playNext(music_1);
    cout << endl;
    return 0;
}
