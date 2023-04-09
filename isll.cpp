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
void ISll::insert_0(string argumentos) {
    /* Para extrair os argumentos de cada comando*/
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {
        ////cout << "inside NODE com item: " << item <<endl;
        INode* newNode = new INode;     // cria o novo nó
        newNode->item = item;           // define o valor do novo nó
        newNode->next = head;           // faz o novo nó apontar para o antigo primeiro nó
        head = newNode;                 // faz a cabeça da lista apontar para o novo nó
        n++;                            // aumenta o contador
    }
    argumentos="";
}

// 2. Inserir no fim da lista
void ISll::insert_end(string argumentos) {
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {
        ///cout << "item " << item << endl;
        INode* newNode = new INode;         // cria o novo nó
        newNode->item = item;               // define o valor do novo nó
        newNode->next = nullptr;            // faz o novo nó apontar para nullptr, já que será o último da lista

        if (head == nullptr) {              // verifica se a lista está vazia
            head = newNode;                 // faz a cabeça da lista apontar para o novo nó
        } else {
            INode* lastNode = head;         // inicia a busca pelo último nó a partir da cabeça da lista
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;  // avança para o próximo nó até chegar ao último
            }
            lastNode->next = newNode;       // faz o antigo último nó apontar para o novo nó
        }
        n++;                                // aumenta o contador que serve de leitura do tamanho
    }
    argumentos="";
}
/*INode *newNode = new INode(value, nullptr);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;*/

// 3. Imprimir item do início da lista
void ISll::print_0(string cmd){
    if (verificarListaVazia(cmd) == false){
        if (head != NULL) {
            cout << "Lista(0)= "<<  head->item   << " \n" << endl;
        }
    }
}
    /*INode *newNode = new INode(value, head);
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;*/

//// 4. Imprimir item do fim da lista
//void ISll::print_end(){
//    int pos = 3;
//    cout << "Lista(end)= "<<  pos << " \n" << endl;
//}

// 5. Imprimir toda lista
void ISll::print(string cmd) {
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        if(head != NULL) {                 // Se não estiver vazia, continua a imprimir list até ao fim
            cout << "Lista= ";             // Imprimir a palavra pertendida
            while (head != NULL) {         // Percorre a lista enquanto o nó atual não for nulo
                cout << head->item << " "; // Imprime o valor atual começando no nó inicial
                head = head->next;         // Move o ponteiro para o próximo nó da lista
            }
            // Quebra de linha para separar a impressão da lista de outras saídas
            cout << endl;
        }
    };
}

/* 6. Remover o nó do início da lista. Apenas e necessário verificar se a lista está vazia ou não*/
void ISll::delete_0() {
    if (head == NULL) {
        return;
    }
    INode *ptr = head;
    if(ptr == head) {
        head = ptr->next;
        return;
    }
    INode *cur = head;
    INode *prev = head;
    while(cur) {
        if(cur == ptr) {
            prev->next = cur->next;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    n--;
}

//// 7. Remover um nó do fim da lista
//void ISll::delete_end() {
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

// 8. Imprimir o número total de itens na lista
void ISll::dim(string cmd) {
    //if(verificarListaVazia(cmd) == false){
        cout << "Lista tem "<<  n << " itens\n" << endl;
    //}
}

// 9. Remover os nós da lista
void ISll::clear(string cmd) {
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        n = 0;                             // Repor valores a zero
        head = NULL;                       // Repor valores a vazio
        tail = NULL;                       // Repor valores a vazio
    }
}
    /*int val = 0;
    if (head == nullptr) {
        cout << "Lista vazia\n";
        return;
    }

    INode *curr = head;
    INode *prev = nullptr;

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
    n--;

}
*/

//}
// 10. Procurar a primeira ocorrência do item na lista e imprimir posição
void ISll::find(string cmd, string argumentos) {
    stringstream ssItems(argumentos);
    int item;
    int pos = 0;
    while(ssItems >> item) {
        INode* current = head;
        while (current != NULL) {
            if (current->item == item) {
                cout << "Item " << item << " na posicao " << pos << endl;
            }
            current = current->next;
            pos++;
        }
        cout << "Item " << item << " não encontrado!\n" << endl;// se chegou aqui, o item não foi encontrado
    }
}
//// 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
//void ISll::find_max(){
//    int val = 0;
//    int pos = 0;
//    cout << "Max Item " << val << " na posicao!\n" << pos << endl;
//}

//// 12. Remover um nó da posição da lista
//void ISll::delete_pos(int pos){
// }

//// 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
//void ISll::invert_range(string cmd, int val, int pos1, int pos2){
//}


/* Para verificar se a lista esta vazia */
    bool ISll::verificarListaVazia(string cmd){
        /* Se a lista não está vazia, é porque tem pelo menos 1 nó.
         * Se unico, então é primeiro e último ao mesmo tempo */

        if(head == NULL /*|| tail == NULL*/){                // Se aponta para null
            cout << "Comando " << cmd << ": Lista vazia!\n" << endl;
            return true;
        }else {
            return false;
        }
    }

    bool ISll::verificarPosicao(string cmd, ISll list, int pos) {
        INode *head;
        INode* current = head;
        int i = 1;
        while (current != nullptr && i < pos) {
            current = current->next;
            i++;
        }
        cout << "Comando " << cmd << ": Posicao invalida!\n" << endl;
        return (current != nullptr);
    }

    int ISll::extrairItens(string argumentos){
        stringstream ssInput(argumentos);
        /* Para extrair os argumentos de cada comando*/
        int item;
        while (ssInput >> item){
            cout<< "item " << endl;
            return item;
        };
    }
// EOF