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
    void insert_0(string);                  // 1. Inserir argumentos no inicio da lista
    void insert_end(string);                // 2. Inserir argumentos no fim da lista
    void print_0(string);                   // 3. Imprimir item do início da lista
    void print_end(string);                 // 4. Imprimir item do fim da lista
    void print(string);                     // 5. Imprimir toda lista
    void delete_0(string);                  // 6. Remover o nó do início da lista. Apenas e necessário verificar se a lista está vazia ou não
    void delete_end(string);                // 7. Remover um nó do fim da lista
    void dim(string);                       // 8. Imprimir o número total de itens na lista
    void clear(string);                     // 9. Remover os nós da lista
    void find(string, string);              // 10. Procurar a primeira ocorrência do item na lista e imprimir posição
    void find_max(string, string);          // 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
    void delete_pos(string, string);        // 12. Remover um nó da posição da lista
    void invert_range(string, string);      // 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
    bool verificarListaVazia(string);       // Verifica se a lista esta vazia e devolve frase de erro
    bool posicaoValida(string, int, int);   // Verifica se a posicao não existe e devolve frase de erro
};
// EOF