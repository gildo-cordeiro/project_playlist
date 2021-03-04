#include <iostream>
#include <stdlib.h>
#include "Lista.hpp"
#include "Musica.hpp"
#include "PlayList.hpp"
#include <cstdlib>
#include <thread>
#include <chrono>

#define MAX_PL 20

void mostrarMenu(){
    std::cout << "*---------------------------------------------------------------*" << std::endl;
    std::cout << "|                      PROJETO PLAYLISTS                        |" << std::endl;
    std::cout << "*---------------------------------------------------------------*" << std::endl;
    std::cout << "|1  - ADICIONAR MÚSICA                                          |" << std::endl;
    std::cout << "|2  - MOSTRAR MÚSICA                                            |" << std::endl;
    std::cout << "|3  - REMOVER MÚSICA                                            |" << std::endl;
    std::cout << "|4  - BUSCAR MUSICA                                             |" << std::endl;
    std::cout << "|5  - ADICIONAR PLAYLIST                                        |" << std::endl;
    std::cout << "|6  - MOSTRAR PLAYLISTS                                         |" << std::endl;
    std::cout << "|7  - REMOVER PLAYLIST                                          |" << std::endl;
    std::cout << "|8  - ADICIONAR MÚSICA A PLAYLIST                               |" << std::endl;
    std::cout << "|9  - MOSTRAR MÚSICA DA PLAYLIST                                |" << std::endl;
    std::cout << "|10 - PLAY                                                      |" << std::endl;
    std::cout << "|0  - SAIR                                                      |" << std::endl;
    std::cout << "*---------------------------------------------------------------*" << std::endl;

}

int main(){
    int qtd_pl = 0, posicao_pl, option, index;

    std::string nome_musica, nome_artista, nome_playlist;

    Musica musica;
    
    Musica* prox_musica;

    Lista* catalog = new Lista;

    PlayList* playlists = new PlayList[MAX_PL];
    
    while(true){
        mostrarMenu();
        std::cin >> option;
        system("clear");
        switch (option){
            case 1:
                std::cout << "Qual o titulo da musica? " << std::endl;
                std::cin.ignore();
                getline(std::cin, nome_musica);

                std::cout << "Qual o nome do artista? " << std::endl;
                std::cin.ignore();
                getline(std::cin, nome_artista);

                if(nome_musica != "" && nome_artista != ""){
                    musica.setTitulo(nome_musica);
                    musica.setArtista(nome_artista);
                    
                    catalog->insertEnd(musica);
                    std::cout << "Musica adicionada ao catalogo." << std::endl;
                }else{
                    std::cout << "Informe o titulo e artista para nova musica." << std::endl;
                }

                std::cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 2:
                if(catalog->sizeContent() > 0)
                    catalog->show();
                else 
                    std::cout << "Não há musicas cadastradas" << std::endl;
                
                std:: cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 3:
                if(catalog->sizeContent() > 0){
                    
                    catalog->show();

                    std::cout << "Informe o numero da música que deseja remover" << std::endl;
                    std::cin >> index;

                    if(index >= 1 && index < catalog->sizeContent()){

                        musica = *(catalog->searchByPosition(index - 1)->music);

                        for (int i = 0; i < qtd_pl; i++){
                            if(playlists[i].getLista()->searchMusic(musica) != nullptr){
                                for(int j = 0; j < playlists[i].getLista()->sizeContent(); j++){ // Percorre os elementos da playlist para achar a posição da música a ser apagada
                                    if(playlists[i].getLista()->searchByPosition(j)->music->getTitulo() == musica.getTitulo() && playlists[i].getLista()->searchByPosition(j)->music->getArtista() == musica.getArtista()){
                                        std::cout << "\nA música " << playlists[i].getLista()->searchByPosition(j)->music->getTitulo() << " de " << playlists[i].getLista()->searchByPosition(j)->music->getArtista() << " estava na posição " << j+1 <<  " da playlist " << playlists[i].getNome() << " e foi removida!" << std::endl;
                                        playlists[i].removeMusicPosition(j + 1); // Apaga a música da playlist
                                    }
                                }
                            }
                        }
                        catalog->deleteMusic(index); // Remove a música do sistema
                        std::cout << "A Música foi removida do catalogo!" << std::endl;
                    }else{
                        std::cout << "Posição inválida!" << std::endl;
                    }
                }else{
                    std::cout << "Não há musicas cadastradas" << std::endl;
                }

                std:: cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 4:
                std:: cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 5:
                if(qtd_pl < MAX_PL){
                    std::cout << "Informe o titulo da Playlist" << std::endl;
                    std::cin.ignore();
                    getline(std::cin, nome_playlist);

                    bool aux = false;
                    for(int i = 0; i < qtd_pl; i++){ // Verifica se há uma playlist com o mesmo nome
                        if(nome_playlist == playlists[i].getNome()){
                            aux = true;
                        }
                    }

                    if(!aux){
                        playlists[qtd_pl].setNome(nome_playlist);
                        std::cout << "\nPlaylist " << playlists[qtd_pl].getNome() << " adicionada com sucesso!" << std::endl;
                        qtd_pl++;
                    }else{
                        std::cout << "\nEsta playlist já existe!" << std::endl;
                    }
                }else{

                }
                std::cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 6:
                if(qtd_pl > 0){
                    for(int i = 0; i < qtd_pl; i++){
                        std::cout << i+1 << ". " << playlists[i].getNome() << std::endl;
                    }
                    std::cout << std::endl;

                }else{
                    std::cout << "Não há nenhuma playlist cadastrada!" << std::endl << std::endl;
                }

                std::cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 7:
                if(qtd_pl > 0){ // Verifica se há playlists cadastradas

                    for(int i = 0; i < qtd_pl; i++){ // Exibe as playlists cadastradas
                        std::cout << i+1 << ". " << playlists[i].getNome() << std::endl;
                    }

                    std::cout << "\nDigite o número da playlist que deseja remover:" << std::endl;
                    std::cin >> index;
                    std::cin.ignore();

                    if(index >= 1 && index <= qtd_pl){ // Verifica se a posição é válida

                        index--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)
                        for(int i = index; i < qtd_pl - 1; i++){ // Percorre o array realocando as posições
                            playlists[i].setNome(playlists[i + 1].getNome());
                            playlists[i].setLista(playlists[i + 1].getLista());
                        }

                        playlists[qtd_pl - 1].setNome("");
                        playlists[qtd_pl - 1].setLista(nullptr);

                        qtd_pl--; // Atualiza o tamanho da playlist

                        std::cout << "\nPlaylist removida com sucesso!" << std::endl;

                    }else{
                        std::cout << "\nPosição inválida!" << std::endl;
                    }

                }else{
                    std::cout << "Não há nenhuma playlist cadastrada!" << std::endl;
                }
                std:: cout << "Pressione qualquer tecla para continuar..." << std::endl;
                getchar();
                system("clear");
                break;
            case 8:
               
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 0:
                std::cout << "Encerrando..." << std::endl;
                break;
            default:
                std::cout << "Comando não identificado" << std::endl;
                break;
        }
        if(option == 0)
            break;
    }
    std::cout << std::endl;
    return 0;
}
