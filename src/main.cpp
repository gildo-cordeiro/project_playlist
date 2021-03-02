#include <iostream>
#include <stdlib.h>
#include "Lista.hpp"
#include "Musica.hpp"
#include "PlayList.hpp"
#include "PlayLists.hpp"
#include <cstdlib>
#include <thread>
#include <chrono>

using std::this_thread::sleep_for;
using namespace std::chrono_literals;

void mostrarMenu(){
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                                                                " << std::endl;
    std::cout << "1  - Adicionar Musica                                           " << std::endl;
    std::cout << "2  - Mostrar Musicas                                            " << std::endl;
    std::cout << "3  - Remover Musica                                             " << std::endl;
    std::cout << "4  - Buscar Musica                                              " << std::endl;
    std::cout << "5  - Adicionar Playlist                                         " << std::endl;
    std::cout << "6  - Mostrar playlists                                          " << std::endl;
    std::cout << "7  - Remover playlist                                           " << std::endl;
    std::cout << "8  - Adicionar musica a playlist                                " << std::endl;
    std::cout << "9  - Mostrar musicas da playlist                                " << std::endl;
    std::cout << "10 - Play                                                       " << std::endl;
    std::cout << "0  - Sair                                                       " << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

}

int main(){

    // Objetos auxiliares
    PlayList* catalog = new PlayList();  

    PlayLists* catalog_playlists = new PlayLists();
    PlayList* play_aux = new PlayList();
    Musica* music_aux = new Musica();

    // Variaveis auxiliares
    int resp, id = 1, find_id, id_music = 1;
    std::string nome, artista;
    
    while(true){
        mostrarMenu();
        std::cin >> resp;
        system("clear");
        switch (resp){
            case 1:
                std::cout << "Qual o titulo da musica? " << std::endl;
                std::cin.ignore();
                getline(std::cin, nome);

                std::cout << "Qual o nome do artista? " << std::endl;
                std::cin.ignore();
                getline(std::cin, artista);

                if(nome != "" && artista != ""){
                    Musica* music = new Musica(nome, artista, id_music++);
                    
                    catalog->insertMusic(music);
                    std::cout << "Musica adicionada ao catalogo." << std::endl;
                }else{
                    std::cout << "Informe o titulo e artista para nova musica." << std::endl;
                }

                sleep_for(3s);
                system("clear");
                break;
            case 2:
                std::cout << "Mostrando todas as musicas..." << std::endl;
                catalog->showPlaylist();

                sleep_for(3s);
                system("clear");
                break;
            case 3:
                std::cout << "Qual o titulo da musica? " << std::endl;
                std::cin.ignore();
                getline(std::cin, nome);
                
                if(nome != ""){
                    music_aux = catalog->findByTitulo(nome);
                    if(music_aux != nullptr){
                        catalog->deleteMusic(music_aux);
                        //catalog_playlists->romoveMusicFromAllPlayLists(music_aux);
                    }else
                        std::cout << "Musica não encontrada!" << std::endl;
                }else{ 
                    std::cout << "Informe um titulo!" << std::endl;
                }

                sleep_for(3s);
                system("clear");
                break;
            case 4:
                std::cout << "Qual o titulo da musica?" << std::endl;
                std::cin.ignore();
                getline(std::cin, nome);

                if(nome != ""){
                    music_aux = catalog->findByTitulo(nome);

                    if(music_aux != nullptr){
                        std::cout << "Musica encontrada: " << music_aux->getTitulo() << std::endl;
                    }else{
                        std::cout << "Musica não encontrada" << std::endl;
                    }
                }else{
                    std::cout << "Informe o titulo da musica" << std::endl;
                }

                sleep_for(3s);
                system("clear");
                break;
            case 5:
                std::cout << "Qual o titulo da PlayList?" << std::endl;
                std::cin.ignore();
                getline(std::cin, nome);

                if(nome != ""){
                    PlayList* lista = new PlayList(nome);
                    catalog_playlists->insertPlayList(lista, id++);
                    std::cout << "PlayList criada com sucesso" << std::endl;
                }else{ 
                    std::cout << "Informe um nome para PlayList!" << std::endl;
                }
                break;
            case 6:
                std::cout << "Mostrando todas as PlayLists..." << std::endl;
                catalog_playlists->showPlayLists();

                sleep_for(3s);
                system("clear");
                break;
            case 7:
                std::cin >> find_id;

                if(find_id > 0)
                    catalog_playlists->removerPlayList(find_id);
                else   
                    std::cout << "Informe o nome da PlayList!" << std::endl;

                sleep_for(3s);
                system("clear");
                break;
            case 8:
                if(catalog_playlists->size() > 0){
                    std::cout << "-------------------------------------------" << std::endl;
                    std::cout << "Escolha a playlist que deseja adicionar uma musica (utilize o id):" << std::endl;
                    catalog_playlists->showPlayLists();

                    std::cin >> find_id;
                    
                    if(id != 0){   
                        PlayList* p = new PlayList();
                        p = catalog_playlists->findById(find_id);
                        if(p != nullptr){
                            std::string titulo = p->getTitulo();
                            std::cout << "Escolha a musica para adicionar a playlist " << titulo << ": "<< std::endl;
                            catalog->showPlaylist();

                            std::cout << "Qual a musica escolhida (use o id)?" << std::endl;
                            std::cin >> find_id;

                            Musica* music = catalog->findById(find_id);

                            std::cout << music->getTitulo() << std::endl;
                            
                            p->insertMusic(music); 
                            p->showPlaylist();                       
                        }else{
                            std::cout << "PlayList não encontrada!" << std::endl;
                        }
                    }
                }else{
                    std::cout << "Adicione alguma playlist antes!" << std::endl;
                }

                sleep_for(3s);
                system("clear");
                
                break;
            case 9:
                if(catalog_playlists->size() > 0){
                    std::cout << "-------------------------------------------" << std::endl;
                    std::cout << "Escolha a playlist que deseja mostar as musicas (utilize o id):" << std::endl;
                     catalog_playlists->showPlayLists();
                
                    std::cin >> find_id;

                    if(find_id != 0){
                        play_aux = catalog_playlists->findById(find_id);
                        if(play_aux != nullptr){
                            play_aux->showPlaylist();
                        }
                    }
                }else{
                    std::cout << "Adicione alguma playlist antes!" << std::endl;
                }

                sleep_for(3s);
                system("clear");
                
                break;
            case 10:
                if(catalog_playlists->size() > 0){
                   std::cout << "-------------------------------------------" << std::endl;
                    std::cout << "Escolha a playlist que deseja tocar (utilize o id):" << std::endl;
                    catalog_playlists->showPlayLists();
                    
                    std::cin >> find_id;
                    int r;
                    if(find_id != 0){
                        play_aux = catalog_playlists->findById(find_id);
                        if(play_aux != nullptr){
                            std::cout << "Tocando: " << play_aux->getCurrentMusic()->getTitulo() << std::endl;
                            std::cout << "Deseja tocar a proxima? sim (1), não (2)" << std::endl;
                        
                            std::cin >> r;
                        
                            if(r == 1){
                                play_aux->playNextMusic(play_aux->getCurrentMusic());
                            }else if(2){
                                std::cout << "Tocando... " << play_aux->getCurrentMusic()->getTitulo() << std::endl;
                            }else {   
                                std::cout << "Escolha um opção (1 ou 2)!" << std::endl;
                            }
                        }
                    } 
                }else{
                    std::cout << "Adicione alguma playlist antes!" << std::endl;
                }

                sleep_for(3s);
                system("clear");
                
                break;
            case 0:
                std::cout << "Encerrando..." << std::endl;
                break;
            default:
                std::cout << "Comando não identificado" << std::endl;
                break;
        }
        if(resp == 0)
            break;
    }
    

    // std::cout << "Tocando agora " << music_1->getTitulo() << std::endl;
    // std::cout << "Preparando a proxima..." << std::endl;
    // p->lista.playNext(music_1);
    std::cout << std::endl;
    return 0;
}
