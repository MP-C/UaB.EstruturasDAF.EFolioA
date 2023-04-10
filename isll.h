/*
** file: isll.h
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2000563 - Mário Carvalho
*/

// Defina:
// em file.h as classes da estrutura de dados
// em file.cpp a implementação dos métodos das classes da estrutura de dados

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// definir nó
struct INode {
   // atributos obrigatórios
   int item;             // informação em cada nó
   INode *next;          // ponteiro do nó que aponta para o nó seguinte
   // outros atributos e métodos (protótipos) livres
   INode(){
       item = 0;
       next = NULL;
   }
};

// definir lista simplesmente ligada
class ISll {
private:
   // atributos obrigatórios
   int n;                // dimensão atual da lista
   // outros atributos e métodos (protótipos) livres
    INode* head;         // ponteiro do inicial de lista
    INode* tail;         // ponteiro do fim da lista
    // metodos atributos a corrigir

public:
    // construtor do nó com contador
    ISll(){
        n = 0;
        head = NULL;
        tail = NULL;
    }
    void insert_0(string);
    void insert_end(string);
    void print_0(string);
    void print_end(string);
    void print(string);
    void delete_0(string);
    void delete_end(string);
    void dim(string);
    void clear(string);
    void find(string, string);
    void find_max(string, string);
    void delete_pos(string, string);
    void invert_range(string, string);
    void verificarListaTamanho(string cmd); // verifica qual é o tamanho da lista, e devolve o respetivo tamanho
    bool verificarListaVazia(string); // verifica se a lista esta vazia e devolve frase de erro
    bool verificarPosicao(string, ISll, int); // verifica se a posicao não existe e devolve frase de erro
    int extrairItens(string);
};

// EOF

