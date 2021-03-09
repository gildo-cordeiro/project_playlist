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
    std::cout << "|11 - ADICIONAR LISTA DE MUSICAS                                |" << std::endl;
    std::cout << "|12 - REMOVER LISTA DE MUSICAS                                  |" << std::endl;
    std::cout << "|0  - SAIR                                                      |" << std::endl;
    std::cout << "*---------------------------------------------------------------*" << std::endl;

}

int main(){
    // Varias auxiliares para leitura de opções
    int qtd_pl = 0, option, index, resp, subResp;

    std::string nome_musica, nome_artista, nome_playlist;

    Musica musica;

    Lista* catalog = new Lista;

    // Vetor de Lista preenchida para as operações de junção e remoção listas em outras lista
    Lista* elementos = new Lista[3];  
    elementos->setSize(3);
    
    Musica music1, music2, music3, music4, music5;
    music1.setTitulo("Californication");
    music1.setArtista("Red Hot Chili Peppers");
    
    music2.setTitulo("Sunrise");
    music2.setArtista("Our Last Night ");

    music3.setTitulo("How To Save A Life");
    music3.setArtista("The Fray");

    elementos[0].insertEnd(music1);
    elementos[1].insertEnd(music2);
    elementos[2].insertEnd(music3);

    catalog->insertEnd(elementos);
 
    // Vetor de playlist
    PlayList* playlists = new PlayList[MAX_PL];
    
    //Funcação que contém o menu
    mostrarMenu();

    while(true){
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

                std:: cout << "Pressione ENTER para continuar..." << std::endl;                
                getchar();
                system("clear");
                mostrarMenu();
                break;
            case 2:
                if(catalog->getSize() > 0){
                    catalog->show();
                }else{ 
                    std::cout << "Não há musicas cadastradas" << std::endl;
                }
                std:: cout << "Pressione ENTER para continuar..." << std::endl;                
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 3:
                if(catalog->getSize() > 0){
                    
                    catalog->show();

                    std::cout << "Informe o numero da música que deseja remover" << std::endl;
                    std::cin >> index;
                    if(index >= 1 && index <= catalog->getSize()){

                        musica = *(catalog->searchByPosition(index - 1)->music);

                        for (int i = 0; i < qtd_pl; i++){
                            if(playlists[i].getList()->searchMusic(musica) != nullptr){
                                for(int j = 0; j < playlists[i].getList()->getSize(); j++){ // Percorre os elementos da playlist para achar a posição da música a ser apagada
                                    if(playlists[i].getList()->searchByPosition(j)->music->getTitulo() == musica.getTitulo() && playlists[i].getList()->searchByPosition(j)->music->getArtista() == musica.getArtista()){
                                        std::cout << "\nA música " << playlists[i].getList()->searchByPosition(j)->music->getTitulo() << " de " << playlists[i].getList()->searchByPosition(j)->music->getArtista() << " estava na posição " << j+1 <<  " da playlist " << playlists[i].getNome() << " e foi removida!" << std::endl;
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

                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 4:
                if(catalog->getSize() > 0){
                    std::cout << "Qual o titulo da musica? " << std::endl;
                    std::cin.ignore();
                    getline(std::cin, nome_musica);

                    std::cout << "Qual o nome do artista? " << std::endl;
                    std::cin.ignore();
                    getline(std::cin, nome_artista);
                    
                    musica.setTitulo(nome_musica);
                    musica.setArtista(nome_artista);

                    if(catalog->searchMusic(musica) != nullptr){
                        std::cout << "Música " << musica.getTitulo() << " do artista " << musica.getArtista() << " encontrada no catalogo." << std::endl;
                    }else{
                        std::cout << "Música não encontrada no catalogo" << std::endl;
                    }
                }else{
                    std::cout << "Não há musicas cadastradas" << std::endl;
                }
                std::cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                
                break;
            case 5:
                if(qtd_pl < MAX_PL){
                    std::cout << "Informe o titulo da Playlist" << std::endl;
                    std::cin.ignore();
                    getline(std::cin, nome_playlist);

                    bool aux = false;
                    for(int i = 0; i < qtd_pl; i++){ // Verifica se há uma playlist com o mesmo nome
                        if(nome_playlist.compare(playlists[i].getNome()) == 0){
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
                    std::cout << "Número maximo de Playlists alcançado" << std::endl;
                }
                std::cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
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
                std::cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 7:
                if(qtd_pl > 0){

                    for(int i = 0; i < qtd_pl; i++){
                        std::cout << i+1 << ". " << playlists[i].getNome() << std::endl;
                    }

                    std::cout << "\nDigite o número da playlist que deseja remover:" << std::endl;
                    std::cin >> index;
                    std::cin.ignore();

                    if(index >= 1 && index <= qtd_pl){

                        index--;
                        for(int i = index; i < qtd_pl - 1; i++){
                            playlists[i].setNome(playlists[i + 1].getNome());
                            playlists[i].setList(playlists[i + 1].getList());
                        }

                        playlists[qtd_pl - 1].setNome("");
                        playlists[qtd_pl - 1].setList(nullptr);

                        qtd_pl--;

                        std::cout << "\nPlaylist removida com sucesso!" << std::endl;

                    }else{
                        std::cout << "\nPosição inválida!" << std::endl;
                    }

                }else{
                    std::cout << "Não há nenhuma playlist cadastrada!" << std::endl;
                }
                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 8:
               if(qtd_pl > 0){
                    int position = 0, position_pl = 0;
                    for(int i = 0; i < qtd_pl; i++){
                        std::cout << i+1 << " - " << playlists[i].getNome() << std::endl;
                    }

                    do{
                        std::cout << "\nDigite o número da playlist que deseja abrir:" << std::endl;
                        std::cin >> position_pl;
                        std::cin.ignore();
                        if(position_pl < 1 || position_pl > qtd_pl){
                            std::cout << "Playlist inválida! Escolha novamente!" << std::endl;
                        }
                    }while(position_pl < 1 || position_pl > qtd_pl);

                    position_pl--; 

                    if(catalog->getSize() > 0){
                        std::cout << "Música disponíveis:" << std::endl;
                        catalog->show();

                        std::cout << "informa o digito corresponde a música que a ser adicionada em " << playlists[position].getNome() << ":" << std::endl;
                        std::cin >> position;
                        std::cin.ignore();

                        if(position > 0 && position <= catalog->getSize()){

                            musica = *catalog->searchByPosition(position - 1)->music;

                            if(playlists[position].getList()->searchMusic(musica) == nullptr){
                                if(playlists[position_pl].addEnd(musica)){ 
                                    std::cout << "Música adicionada na playlist com sucesso!" << std::endl;

                                }else{
                                    std::cout << "Erro ao adicionar música na playlist!" << std::endl;
                                }

                            }else{
                                std::cout << "Esta música já está na playlist!" << std::endl;
                            }
                        }else{
                            std::cout << "Posição inválida!" << std::endl;
                        }

                    }else{
                        std::cout << "Não há músicas cadastradas no sistema!" << std::endl;
                    }
                }else{
                    std::cout << "Não há Playlists no catalogo" << std::endl;
                }

                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 9:
                if(qtd_pl > 0){
                    int position_pl = 0;
                    for(int i = 0; i < qtd_pl; i++){
                        std::cout << i+1 << " - " << playlists[i].getNome() << std::endl;
                    }

                    do{
                        std::cout << "\nDigite o número da playlist que deseja abrir:" << std::endl;
                        std::cin >> position_pl;
                        std::cin.ignore();
                        if(position_pl < 1 || position_pl > qtd_pl){
                            std::cout << "Playlist inválida! Escolha novamente!" << std::endl;
                        }
                    }while(position_pl < 1 || position_pl > qtd_pl);

                    position_pl--; 
                    if(playlists[position_pl].getList()->getSize() > 0){ 
                        playlists[position_pl].show(playlists[position_pl].getList()->searchByPosition(0), 1);
                        std::cout << std::endl;

                    }else{
                        std::cout << "Não há nenhuma música nessa playlist!" << std::endl;
                    }
                }else{
                    std::cout << "Não há Playlists no catalogo" << std::endl;
                }

                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                
                break;
            case 10:
                if(qtd_pl > 0){
                    Musica* next_music;
                    int position_pl;
                    
                    for(int i = 0; i < qtd_pl; i++){
                        std::cout << i+1 << " - " << playlists[i].getNome() << std::endl;
                    }

                    do{
                        std::cout << "Digite o número da playlist que deseja reproduzir:" << std::endl;
                        std::cin >> position_pl;
                        std::cin.ignore();
                        if(position_pl < 1 || position_pl > qtd_pl){
                            std::cout << "Playlist inválida! Escolha novamente!";
                        }
                    }while(position_pl < 1 || position_pl > qtd_pl);

                    position_pl--;

                    if(playlists[position_pl].getList()->getSize() > 0){ 
                        
                        next_music = playlists[position_pl].nextMusic(); 
                        if(next_music != nullptr){
                            std::cout << "Tocando " << next_music->getTitulo() << " - " << next_music->getArtista() << " da playlist " << playlists[position_pl].getNome() << "!" << std::endl;
                        }else{
                            std::cout << "Você terminou de escutar essa playlist!" << std::endl << std::endl;
                        }
                    }else{
                        std::cout << "Não há nenhuma música nessa playlist para tocar!" << std::endl;
                    }

                }else{
                    std::cout << "Nenhuma playlist cadastrada!" << std::endl << std::endl;
                }
                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 11:
                std::cout << "Escolha a opção: \n(1) Informar lista de musicas \n(2) Utilizar lista pre existente" << std::endl;
                std::cin >> resp;
                if(resp == 1){
                    int qtd_music;
                    
                    std::cout << "Digite o número de músicas que deseja adicionar:" << std::endl;
                    std::cin >> qtd_music;
                    if(qtd_music > 0){
                        Lista* listaMusics = new Lista[qtd_music];
                        listaMusics->setSize(qtd_music);
                        
                        for (int i = 0; i < qtd_music; i++){
                            std::cout << "Qual o titulo da musica? " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, nome_musica);

                            std::cout << "Qual o nome do artista? " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, nome_artista);

                            if(nome_musica != "" && nome_artista != ""){
                                musica.setTitulo(nome_musica);
                                musica.setArtista(nome_artista);

                                listaMusics[i].insertEnd(musica);
                                listaMusics[i].setSize(listaMusics->getSize()/qtd_music);
                            }else{
                                std::cout << "Informe o titulo e artista para nova musica." << std::endl;
                            }
                        }

                        if(catalog->insertEnd(listaMusics)){
                            std::cout << "Lista de musica adicionadas ao catalago." << std::endl;
                        }
                        
                    }else{
                        std::cout << "Informe a quantidade de musicas, por favor." << std::endl << std::endl;
                    }
                }else if(resp == 2){
                    system("clear");
                    std::cout << "Musicas da lista" << std::endl << std::endl;

                    for (int i = 0; i < elementos->getSize()-1; i++){
                        std::cout << i+1 << ". "<< elementos[i].getCurrentMusic()->getTitulo() << " - " << elementos->getCurrentMusic()->getArtista()<< std::endl;
                    }

                    std::cout << "Deseja adicionar essa lista ao catalogo?\n 1.Sim | 2.Não" << std::endl;
                    std::cin >> subResp;
                    if(subResp == 1){
                        catalog->insertEnd(elementos) 
                        ? std::cout << "Lista de musica adicionadas ao catalago." << std::endl 
                        : std::cout << "Erro ao adicionar lista." << std::endl;
                    }else{
                        std::cout << "Operação encerrada" << std::endl;
                    }

                }else{
                    std::cout << "\nOpção invalida" << std::endl << std::endl;
                }
                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 12:
                std::cout << "Escolha a opção: \n(1) Informar lista de musicas para remover \n(2) Utilizar lista pre existente" << std::endl;
                std::cin >> resp;
                if(resp == 1){
                    int qtd_music;
                    
                    std::cout << "Digite o número de músicas que deseja remover:" << std::endl;
                    std::cin >> qtd_music;
                    if(qtd_music > 0){
                        Lista* listaMusics = new Lista[qtd_music];
                        listaMusics->setSize(qtd_music);
                        
                        for (int i = 0; i < qtd_music; i++){
                            std::cout << "Qual o titulo da musica? " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, nome_musica);

                            std::cout << "Qual o nome do artista? " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, nome_artista);

                            if(nome_musica != "" && nome_artista != ""){
                                musica.setTitulo(nome_musica);
                                musica.setArtista(nome_artista);

                                if(catalog->search(musica) != nullptr){
                                    listaMusics[i].insertEnd(musica);
                                    listaMusics[i].setSize(listaMusics->getSize()/qtd_music);
                                }else{
                                    std::cout << "Música não encontrada no catalogo" << std::endl;
                                }

                            }else{
                                std::cout << "Informe o titulo e artista para nova musica." << std::endl;
                            }
                        }

                        if(listaMusics != nullptr){
                            catalog->deleteMusic(listaMusics);
                            std::cout << "Musicas removidas com sucesso" << std::endl;
                        }
                        
                    }else{
                        std::cout << "Informe a quantidade de musicas, por favor." << std::endl << std::endl;
                    }
                }else if(resp == 2){
                    system("clear");
                    std::cout << "Musicas da lista" << std::endl << std::endl;

                    for (int i = 0; i < elementos->getSize()-1; i++){
                        std::cout << i+1 << ". "<< elementos[i].getCurrentMusic()->getTitulo() << " - " << elementos->getCurrentMusic()->getArtista()<< std::endl;
                    }

                    std::cout << "Deseja remover essa lista do catalogo?\n 1.Sim | 2.Não" << std::endl;
                    std::cin >> subResp;
                    if(subResp == 1){
                        catalog->deleteMusic(elementos);
                        std::cout << "Lista removida com sucesso." << std::endl;
                    }else{
                        std::cout << "Operação encerrada" << std::endl;
                    }
                }else{
                    std::cout << "\nOpção invalida" << std::endl << std::endl;
                }
                std:: cout << "Pressione ENTER para continuar..." << std::endl;
                getchar();
                std::cin.ignore();
                system("clear");
                mostrarMenu();
                break;
            case 0:
                delete catalog;
                delete[] playlists;
                delete[] elementos;
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
