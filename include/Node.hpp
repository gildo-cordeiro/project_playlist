#pragma once

#include "Musica.hpp"

class Node{
    
public:
    Musica* music;
    Node* next;

    Node();
    ~Node();
};