
// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
// nó da lista
struct Node {
    int data;
    Node* next;
};

/*
** file: main-isll.cpp
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2000563 - Mário Carvalho
*/

//   Não utilize variáveis globais
#include <iostream>
#include "isll.h"
using namespace std;

//void searchNode(int);
//void insertAtBeginning(int);
//void insertAtEnd(int);
//void insertAtPosition(int, int);
//void updateNode(int, int);
//void deleteNode(int);
//void displayList();


// apontador para o primeiro nó da lista
Node* head = nullptr;

// contador de nós
int C = 0;

// funções para manipulação da lista
void searchNode(int val) {
    if (head == nullptr) {
        cout << "Lista vazia\n";
        return;
    }

    Node* curr = head;
    int pos = 0;
    bool found = false;

    while (curr != nullptr) {
        if (curr->data == val) {
            found = true;
            break;
        }
        curr = curr->next;
        pos++;
    }

    if (found) {
        cout << "Valor " << val << " encontrado na posição " << pos << endl;
    } else {
        cout << "Valor não encontrado\n";
    }
}

void insertNode(int val, int pos) {
    if (pos < 0 || pos > C) {
        cout << "Posição inválida\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    C++;
}
insertAtBeginning
        insertAtEnd
insertAtPosition
void insertNodeEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    C++;
}

void updateNode(int val, int pos) {
    if (pos < 0 || pos >= C) {
        cout << "Posição inválida\n";
        return;
    }

    Node* curr = head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }

    curr->data = val;
}

void deleteNode(int val) {
    if (head == nullptr) {
        cout << "Lista vazia\n";
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Valor não encontrado\n";
        return;
    }

    if (prev == nullptr) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    C--;
}

void displayList(int val) {

}

int main(){
   ISll list;   // exemplo
    int choice, data, position, newData;

    while (true) {
        cout << "Selecione uma opcao:" << endl;
        cout << "1. Inserir no inicio da lista" << endl;
        cout << "2. Inserir no fim da lista" << endl;
        cout << "3. Inserir em uma posicao especifica" << endl;
        cout << "4. Remover um no" << endl;
        cout << "5. Procurar um no" << endl;
        cout << "6. Atualizar um no" << endl;
        cout << "7. Mostrar lista" << endl;
        cout << "8. Sair" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> data;
                insertAtBeginning(data);
                break;
            case 2:
                cout << "Digite o valor a ser inserido: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Digite o valor a ser inserido: ";
                cin >> data;
                cout << "Digite a posicao da lista para inserir: ";
                cin >> position;
                insertAtPosition(data, position);
                break;
            case 4:
                cout << "Digite o valor a ser removido: ";
                cin >> data;
                deleteNode(data);
                break;
            case 5:
                cout << "Digite o valor a ser procurado: ";
                cin >> data;
                searchNode(data);
                break;
            case 6:
                cout << "Digite o valor a ser atualizado: ";
                cin >> data;
                cout << "Digite o novo valor: ";
                cin >> newData;
                updateNode(data, newData);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
    return 0;
}

// EOF
