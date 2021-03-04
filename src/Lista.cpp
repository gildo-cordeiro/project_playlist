#include "Lista.hpp"

// Construtor padrão
Lista::Lista(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destrutor padrão
Lista::~Lista(){
   
    if(size == 0){
        return;
    }else{
        Node* current = head;

        while (current != nullptr){
            Node* temp = current->next;
            delete current->music;
            delete current;
            current = temp;
        }
    }
}

/**
* Função: showLista
* parametros:
* - 
* Descrição: Utilizada para mostrar as musicas contidas na lista.
*/
void Lista::show(){

    Node* list = head;
    
    if(list != nullptr){
        std::cout << "A LISTA NÃO POSSUI ELEMENTOS!!\n";
    }else{
        for(int i = 0; i < size; i++){
            std::cout << i+1 << ". " << list->music->getTitulo() << " - " << list->music->getArtista()  << std::endl;
            list = list->next;
        }
        std::cout << std::endl;
    }
}

/**
* Função: insertEnd
* parametros:
* - Musica musica: representa uma uma musica.
* Descrição: insere a musica no final da lista encadeada.
*/
bool Lista::insertEnd(Musica music){
    
    if(search(music) == nullptr){
        if(head == nullptr){

            head = new Node;
            head->music = new Musica;

            head->music->setTitulo(music.getTitulo());
            head->music->setArtista(music.getArtista());
            head->next = nullptr;

            tail = head;
            size++;

        }else{

            Node *temp = new Node;
            temp->music = new Musica();

            temp->music->setTitulo(music.getTitulo());
            temp->music->setArtista(music.getArtista());
            temp->next = nullptr;

            tail->next = temp;
            tail = temp;

            size++;
        }
        return true;
    }

    return false;
}

/**
* Função: search
* parametros:
* - Musica m: representa a referencia de uma musica.
* Descrição: verifica se a musica passada por parametro existe na lista.
*/
Node* Lista::search(Musica music){

    Node *current = head;

    while(current != nullptr){
        if(current->music->getTitulo() == music.getTitulo() && current->music->getArtista() == music.getArtista()){
            return current; 
        }else{
            current = current->next;
        }
    }
    return nullptr;
}

void Lista::deleteMusic(int position){
    Node *current  = head;
    Node *prev = nullptr;

    for(int i = 1; i < position; i++){ 
        prev = current;
        current  = current->next;
    }

    if(current == head){
        head = head->next;
    }else{
        if(current == tail){
            prev->next = nullptr;
            tail = prev;
        }else{
            prev->next = current->next;
        }
    }
    
    size--; 

    delete current->music;
    delete current;
}
// Verifica se uma determinada música está cadastrada no sistema por sua posição (retorna ponteiro de Node)
Node* Lista::searchByPosition(int posicao){

    if(posicao >= 0 && posicao < size){ // Verifica se a posição é válida

        Node *temp = head; // Objeto a receber os elementos da lista durante as iterações do laço

        for(int i = 0; i < posicao; i++){ // Percorre a lista até chegar no elemento desejado
            temp = temp->next;
        }

        return temp; // Retorna o ponteiro para o Node
    }

    return nullptr; // Posição inválida
}

Musica* Lista::searchMusic(Musica musica){
    
    Node *atual = head; // Objeto a receber os elementos da lista durante as iterações do laço

    while(atual != nullptr){
        if(atual->music->getTitulo() == musica.getTitulo() && atual->music->getArtista() == musica.getArtista()){
            // Achou a música no sistema
            return atual->music; // Retorna o ponteiro para o node que armazena a música buscada
        }else{
            atual = atual->next; // Pula para o pŕoximo node
        }
    }

    return nullptr; // A música não está no sistema
}

bool Lista::insereInPosition(int posicao, Musica musica){

    posicao--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)

    if(posicao == 0){ // Verifica se é na primeira posição
        if(size == 0){
            return insertEnd(musica); // Retorna código retornado pela função chamada
        }// }else{
        //     return insereInicio(musica); // Retorna código retornado pela função chamada
        // }
    }else{
        if(posicao == size){ // Verifica se é na última posição
            return insertEnd(musica); // Retorna código retornado pela função chamada

        }else{
            // A inserção é no meio da lista 

            if(search(musica) == nullptr){ // Verifica se a música já está cadastrada
                // A música não está cadastrada

                Node* temp = new Node;
                temp->music = new Musica;
                Node* atual = head;
                Node* anterior = nullptr;

                int contador = 0;

                while (contador < posicao){ // Percorre a lista até alcançar o node da posição desejada
                    anterior = atual;
                    atual = atual->next;                
                    contador++;
                }

                // Copia informações da música para tempo
                temp->music->setTitulo(musica.getTitulo());
                temp->music->setArtista(musica.getArtista());

                temp->next = atual; // Define o next da posição anterior
                anterior->next = temp; // Atualiza o next da posição anterior
                size++; // Incrementa o tamanho

                return true; // Retrona código de sucesso
                
            }      
        }
    }
    return false;
}


/**
* Função: size
* parametros:
* - 
* Descrição: retorna o tamanho da lista.
*/
int Lista::sizeContent(){    
    return size;
}