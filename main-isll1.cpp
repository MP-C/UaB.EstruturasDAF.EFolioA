
// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   nó da lista
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

// Funções para manipulação da lista
// 1. Inserir no inicio da lista
void insert_0(int i, int i1) {
    int val = 0;
    if (i < 0 || i > C) {
        cout << "Posição inválida\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = val;

    if (i == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        for (int i = 0; i < i - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    C++;
}
// 2. Inserir no fim da lista
void insert_end(int val) {
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
// 3. Imprimir item do início da lista
void print_0(){
    int pos = 0;
    cout << "Lista(0)= "<<  pos << " \n" << endl;
}
// 4. Imprimir item do fim da lista
void print_end(){
    int pos = 3;
    cout << "Lista(end)= "<<  pos << " \n" << endl;
}
// 5. Imprimir toda lista
void print(){
    int pos = 0;
    cout << "Lista(0)= "<<  pos << " \n" << endl;
}
// 6. Remover um nó do início da lista
void delete_0() {
    int val = 0;
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
// 7. Remover um nó do fim da lista
void delete_end() {
    int val = 0;
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
// 8. Imprimir o número total de itens na lista
void dim() {
    int pos = 0;
    cout << "Lista tem "<<  pos << " itens\n" << endl;
}
// 9. Remover os nós da lista
void clear() {
    int val = 0;
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
// 10. Procurar a primeira ocorrência do item na lista e imprimir posição
void find(int val) {
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
        cout << "Item " << val << " na posicao " << pos << endl;
    } else {
        cout << "Item " << val << " não encontrado!\n" << endl;
    }
}
// 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
void find_max(){
    int val = 0;
    int pos = 0;
    cout << "Max Item " << val << " na posicao!\n" << pos << endl;
}
// 12. Remover um nó da posição da lista
void delete_pos(int pos){}
// 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
void invert_range(string cmd, int val, int pos1, int pos2){
}

// Para verificar se a lista esta vazia
void verificarLista(string choice){

    cout << "Comando " << choice << ": Lista vazia!\n" << endl;
}

int main(){
   ISll list;   // exemplo
    int newData, position1, position2;
    string choice;

    while (true) {
        cout << "Selecione um comando para:" << endl;
        cout << " 1. Inserir no inicio da lista -> insert_0 item" << endl;
        cout << " 2. Inserir no fim da lista -> insert_end item" << endl;
        cout << " 3. Imprimir item do inicio da lista: -> print_0" << endl;
        cout << " 4. Imprimir item do fim da lista: -> print_end" << endl;
        cout << " 5. Imprimir toda a lista: -> print" << endl;
        cout << " 6. Remover um no do inicio da lista: -> delete_0" << endl;
        cout << " 7. Remover um no do fim da lista: -> delete_end" << endl;
        cout << " 8. Imprimir o numero total de itens na lista: -> dim" << endl;
        cout << " 9. Remover os nos da lista: -> clear" << endl;
        cout << "10. Procurar a primeira ocorrencia do item na lista e imprimir posicao: -> find item" << endl;
        cout << "11. Procurar a primeira ocorrencia do maior item na lista e imprimir posicao: -> find_max" << endl;
        cout << "12. Remover um no da posicao da lista: -> delete_pos " << endl;
        cout << "13. Inverter a ordem dos itens da lista a partir da posicao 1 ate a posicao indicada: -> invert_range pos1 pos2" << endl;
        cout << "Escolher a opcao: " << endl;
        cin >> choice;

        switch (choice) {
            case 'insert_0': // 1. Inserir no inicio da lista -> insert_0 item
                insert_0(newData);
                break;
            case 'insert_end': //2. Inserir no fim da lista -> insert_end item
                insert_end(newData);
                break;
            case 'print_0': //3. Imprimir item do início da lista: -> print_0
                print_0();
                break;
            case 'print_end': //4. Imprimir item do fim da lista: -> print_end
                print_end();
                break;
            case 'print': //5. Imprimir toda a lista: -> print
                print();
                break;
            case 'delete_0': //6. Remover um nó do inicio da lista: -> delete_0
                delete_0();
                break;
            case 'delete_end': //7. Remover um nó do fim da lista: -> delete_end
                delete_end();
                break;
            case 'dim': //8. Imprimir o número total de itens na lista: -> dim"
                dim();
                break;
            case 'clear': //9. Remover os nós da lista: -> clear
                clear();
                break;
            case 'find': //10. Procurar a primeira ocorrência do item na lista e imprimir posição: -> find item
                find(newData);
                break;
            case 'find_max': //11. Procurar a primeira ocorrência do maior item na lista e imprimir posição: -> find_max
                find_max();
                break;
            case 'delete_pos': //12. Remover um nó da posição da lista: -> delete_pos
                delete_pos(newData);
                break;
            case 'invert_range': //13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada: -> invert_range pos1 pos2
                invert_range(choice, newData, position1, position2);
                break;
            default:
                cout << "Comando " << choice << ": Posicao invalida!\n" << endl;
                break;
            }

        string filename = "testes.txt"; //Escolher ficheiro de testes
        ifstream file(filename);
        if (!file.is_open()) {  // Abrir ficheiro
            cout << "Erro a abrir ficheiro " << filename << endl; // Alertar para erro
            return;
        }
        string line;
        while (getline(file, line)) {    // conteúdo é lido linha por linha
            cout << line << endl;       // Para imprimir cada linha
        }
        file.close();
        }



    /* Para guardar os argumentos recebidos de forma isolada a partir do método de extração
        * realizado de seguinda */
    /*char separator = ' ';                     //separar argumentos do comando
    string args;           // Guardar os numeros em Int depois de transformados
    stringstream ssLinha(input);
    cout<< "comandoLinha " <<input<< endl;
    ssLinha >> args;
    cout<< "args " <<args<< endl;
    string argString[input.length()];  // Guarda os numeros provenientes de char
    int argumentos[input.length()];
    int posicaoArgs = 0;
    for (int i = 1; i < comandoLinha.length(); i++) {
        if (comandoLinha[i] == separator) {
            posicaoArgs++;
        } else {
            argString[posicaoArgs] += comandoLinha[i];
            argumentos[posicaoArgs] = stoi(argString[posicaoArgs]); //Transforma a string em inteiro guardando os dados de cada argumento
            cout << "Argumento " << argumentos[posicaoArgs] << endl; // Usar o índice posicaoArguments
        }
    }
    //extractor com ss int temporario com args[i]
*/

    return 0;
}

// EOF
