/*
** file: isll.cpp
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

#include "isll.h"

// Funções para manipulação da lista
// 1. Inserir no inicio da lista
void ISll::insert_0(int val, int contador) {
    INode* newNode = new INode;
    newNode->item = val;

    cout << "inside NODE " << endl;
    if (val == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        INode* atual = head;
        for (int i = 0; i < val - 1; i++) {
            atual = atual->next;
        }
        newNode->next = atual->next;
        atual->next = newNode;
    }
    contador ++;
}
//// 2. Inserir no fim da lista
//void insert_end(int val) {
//    Node* newNode = new Node;
//    newNode->data = val;
//    newNode->next = nullptr;
//
//    if (head == nullptr) {
//        head = newNode;
//    } else {
//        Node* curr = head;
//        while (curr->next != nullptr) {
//            curr = curr->next;
//        }
//        curr->next = newNode;
//    }
//
//    C++;
//}

//// 3. Imprimir item do início da lista
//void print_0(){
//    int pos = 0;
//    cout << "Lista(0)= "<<  pos << " \n" << endl;
//}

//// 4. Imprimir item do fim da lista
//void print_end(){
//    int pos = 3;
//    cout << "Lista(end)= "<<  pos << " \n" << endl;
//}

// 5. Imprimir toda lista
void ISll::print(int valor, int pos){
    cout << "Lista= "<< pos << valor << " \n" << endl;
}
//// 6. Remover um nó do início da lista
//void delete_0() {
//    int val = 0;
//    if (head == nullptr) {
//        cout << "Lista vazia\n";
//        return;
//    }
//
//    Node* curr = head;
//    Node* prev = nullptr;
//
//    while (curr != nullptr && curr->data != val) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == nullptr) {
//        cout << "Valor não encontrado\n";
//        return;
//    }
//
//    if (prev == nullptr) {
//        head = curr->next;
//    } else {
//        prev->next = curr->next;
//    }
//
//    delete curr;
//    C--;
//}
//// 7. Remover um nó do fim da lista
//void delete_end() {
//    int val = 0;
//    if (head == nullptr) {
//        cout << "Lista vazia\n";
//        return;
//    }
//
//    Node* curr = head;
//    Node* prev = nullptr;
//
//    while (curr != nullptr && curr->data != val) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == nullptr) {
//        cout << "Valor não encontrado\n";
//        return;
//    }
//
//    if (prev == nullptr) {
//        head = curr->next;
//    } else {
//        prev->next = curr->next;
//    }
//
//    delete curr;
//    C--;
//}
//// 8. Imprimir o número total de itens na lista
//void dim() {
//    int pos = 0;
//    cout << "Lista tem "<<  pos << " itens\n" << endl;
//}
//// 9. Remover os nós da lista
//void clear() {
//    int val = 0;
//    if (head == nullptr) {
//        cout << "Lista vazia\n";
//        return;
//    }
//
//    Node* curr = head;
//    Node* prev = nullptr;
//
//    while (curr != nullptr && curr->data != val) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == nullptr) {
//        cout << "Valor não encontrado\n";
//        return;
//    }
//
//    if (prev == nullptr) {
//        head = curr->next;
//    } else {
//        prev->next = curr->next;
//    }
//
//    delete curr;
//    C--;
//}
//// 10. Procurar a primeira ocorrência do item na lista e imprimir posição
//void find(int val) {
//    if (head == nullptr) {
//        cout << "Lista vazia\n";
//        return;
//    }
//
//    Node* curr = head;
//    int pos = 0;
//    bool found = false;
//
//    while (curr != nullptr) {
//        if (curr->data == val) {
//            found = true;
//            break;
//        }
//        curr = curr->next;
//        pos++;
//    }
//
//    if (found) {
//        cout << "Item " << val << " na posicao " << pos << endl;
//    } else {
//        cout << "Item " << val << " não encontrado!\n" << endl;
//    }
//}
//// 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
//void find_max(){
//    int val = 0;
//    int pos = 0;
//    cout << "Max Item " << val << " na posicao!\n" << pos << endl;
//}
//// 12. Remover um nó da posição da lista
//void delete_pos(int pos){}
//// 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
//void invert_range(string cmd, int val, int pos1, int pos2){
//}
//// Para verificar se a lista esta vazia
//void verificarLista(string choice){
//
//    cout << "Comando " << choice << ": Lista vazia!\n" << endl;
//}
//
//
//



// EOF

