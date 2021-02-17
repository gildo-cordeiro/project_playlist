#include <iostream>
#include <stdlib.h>
#include "Lista.h"
#include "Musica.h"
#include "PlayList.h"
#include "PlayLists.h"

using namespace std;

int main(){

    PlayList* catalog = new PlayList();    
    PlayLists* catalog_playlists = new PlayLists();
    Musica* music_aux = new Musica();
    PlayList* play_aux = new PlayList();

    int resp, id = 1, find_id;
    string nome, artista;
    
    while(true){
        cout << endl << "-------------------------------------------------------" << endl;
        cout << "                                                               " << endl;
        cout << "1 - Adicionar Musica                                           " << endl;
        cout << "2 - Mostrar Musicas                                            " << endl;
        cout << "3 - Remover Musica                                             " << endl;
        cout << "4 - Buscar Musica                                              " << endl;
        cout << "5 - Adicionar Playlist                                         " << endl;
        cout << "6 - Mostrar playlists                                          " << endl;
        cout << "7 - Remover playlist                                           " << endl;
        cout << "8 - Adicionar musica a playlist                                " << endl;
        cout << "9 - Mostrar musicas da playlist                                " << endl;
        cout << "10 - Play                                                       " << endl;
        cout << "0 - Sair                                                       " << endl;
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
                
                if(nome != ""){
                    music_aux = catalog->findByTitulo(nome);
                    if(music_aux != nullptr){
                        catalog->deleteMusic(music_aux);
                        //catalog_playlists->romoveMusicFromAllPlayLists(music_aux);
                    }else
                        cout << "Musica não encontrada!" << endl;
                }else{ 
                    cout << "Informe um titulo!" << endl;
                }
                break;
            case 4:
                cout << "Qual o titulo da musica?" << endl;
                cin.ignore();
                getline(cin, nome);

                if(nome != ""){
                    music_aux = catalog->findByTitulo(nome);

                    if(music_aux != nullptr){
                        cout << "Musica encontrada: " << music_aux->getTitulo() << endl;
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
                cin >> find_id;

                if(find_id > 0)
                    catalog_playlists->removerPlayList(find_id);
                else   
                    cout << "Informe o nome da PlayList!" << endl;
                break;
            case 8:
                cout << "-------------------------------------------" << endl;
                cout << "Escolha a playlist que deseja adicionar uma musica (utilize o id):" << endl;
                catalog_playlists->showPlayLists();

                cin >> find_id;
                
                if(id != 0){
                    play_aux = catalog_playlists->findById(find_id);
                    if(play_aux != nullptr){
                        string titulo = play_aux->getTitulo();
                        cout << "Escolha a musica para adicionar a playlist " << titulo << ": "<< endl;
                        catalog->showPlaylist();

                        cout << "Qual o nome da musica?" << endl;
                        cin.ignore();
                        getline(cin, nome);
                        
                        play_aux->insertMusic(catalog->findByTitulo(nome)); 
                        play_aux->showPlaylist();                       
                    }else{
                        cout << "PlayList não encontrada!" << endl;
                    }
                }
                break;
            case 9:
                cout << "-------------------------------------------" << endl;
                cout << "Escolha a playlist que deseja mostar as musicas (utilize o id):" << endl;
                catalog_playlists->showPlayLists();
                
                cin >> find_id;

                if(find_id != 0){
                    play_aux = catalog_playlists->findById(find_id);
                    if(play_aux != nullptr){
                        play_aux->showPlaylist();
                    }
                }

                break;
            case 10:
                cout << "-------------------------------------------" << endl;
                cout << "Escolha a playlist que deseja tocar (utilize o id):" << endl;
                catalog_playlists->showPlayLists();
                
                cin >> find_id;
                int r;
                if(find_id != 0){
                    play_aux = catalog_playlists->findById(find_id);
                    if(play_aux != nullptr){
                        cout << "Tocando: " << play_aux->getCurrentMusic()->getTitulo() << endl;
                        cout << "Deseja tocar a proxima? sim (1), não (2)" << endl;
                    
                        cin >> r;
                    
                        if(r == 1){
                            play_aux->playNextMusic(play_aux->getCurrentMusic());
                        }else if(2){
                            cout << "Tocando... " << play_aux->getCurrentMusic()->getTitulo() << endl;
                        }else {   
                            cout << "Escolha um opção (1 ou 2)!" << endl;
                        }
                    }
                }

                break;
            case 0:
                break;
        }
    }
    

    // cout << "Tocando agora " << music_1->getTitulo() << endl;
    // cout << "Preparando a proxima..." << endl;
    // p->lista.playNext(music_1);
    cout << endl;
    return 0;
}
