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
void ISll::insert_0(string argumentos) { // TODO : FUNCIONA !!
    /* Para extrair os argumentos de cada comando*/
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {
        INode* newNode = new INode;     // cria o novo nó
        newNode->item = item;           // define o valor do novo nó
        newNode->next = head;           // faz o novo nó apontar para o antigo primeiro nó
        head = newNode;                 // faz a cabeça da lista apontar para o novo nó
        n++;                            // aumenta o contador
    }
    argumentos="";// TODO problema NÃO FUNCIONA
}

// 2. Inserir no fim da lista
void ISll::insert_end(string argumentos) { // TODO problema insere no fim, mas não apaga o que ficou em memória, e no proximo insertXX insere os novos e anteriores
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {
        ///cout << "item " << item << endl;
        INode *newNode = new INode;         // cria o novo nó
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
    argumentos="";      // TODO problema NÃO FUNCIONA
}
/*INode *newNode = new INode(value, nullptr);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;*/

// 3. Imprimir item do início da lista //TODO: só funciona à primeira vez que ativo, se for apos print=> ARDEU
void ISll::print_0(string cmd){
    if (verificarListaVazia(cmd) == false){
        if (head != NULL) {

            cout << "Lista(0)= "<<  head->item   << " \n" << endl; // TODO problema está a imprimir o local e não o item
        }
    }
}
    /*INode *newNode = new INode(value, head);
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        n++;*/

// 4. Imprimir item do fim da lista
void ISll::print_end(string cmd){ //TODO parece que está a imprimir OK! mas após print já não funciona
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        INode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        cout << "Lista(end)= "<<  current->item << " \n" << endl;
    }
}

// 5. Imprimir toda lista //TODO corrigir: após primeira leitura a impressão não fica correta; na segunda vez, diz que a lista está vazia, mesmo não estando
void ISll::print(string cmd) {
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        /*INode *cur = head;
        cout<< "head "<< head->item;*/
        if(head != NULL) {                 // Se não estiver vazia, continua a imprimir list até ao fim
            cout << "Lista= ";             // Imprimir a palavra pertendida
            while (head != NULL) {         // Percorre a lista enquanto o nó atual não for nulo
                cout<< head->item << " "; // Imprime o valor atual começando no nó inicial
                head = head->next;         // Move o ponteiro para o próximo nó da lista
//
//                  Esta parte imprimi em continuo e não para!!!
//                for (cur = head; cur != 0; cur = cur->next)
//                {
//                    cout << cur->item << " ";
//                }
            }
            /*head = cur->item;  //TODO repor o valor inicial          // Para voltar a fazer com que o head aponte de novo para atual
            cout<< "head "<< head;*/
            // Quebra de linha para separar a impressão da lista de outras saídas
            cout << endl;

        }
    };
}

/* 6. Remover o nó do início da lista. Apenas e necessário verificar se a lista está vazia ou não*/
void ISll::delete_0(string cmd) { //TODO problema : Apaga sempre mais do que o primeiro elemento (ou tudo) ou não apaga nada apos vários inserts
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        INode* p;
        p = head->next; // p fica com o próximo valor
        delete head;    // elimina o valor de head
        head = p;       // head fica com o valor seguinte que estava em p
    }
    n--;
//    INode *ptr = head;
//    if(ptr == head) {
//        head = ptr->next;
//        return;
//    }
//    INode *cur = head;
//    INode *prev = head;
//    while(cur) {
//        if(cur == ptr) {
//            prev->next = cur->next;
//            return;
//        }
//        prev = cur;
//        cur = cur->next;
//    }
}

// 7. Remover um nó do fim da lista
void ISll::delete_end(string cmd) { //TODO parece que está a funcionar. São precisos mais testes quando o print funcionar corretamente => atualemnte está a apgar a lista
    if(verificarListaVazia(cmd) == false) {
        //int elemento = head->item;
        INode* tmp = head;
        if (head == tail)
            head = tail = 0;
        else head = head->next;
        delete tmp;
        n--;
        //return elemento;
    }
}

// 8. Imprimir o número total de itens na lista
int ISll::dim(string cmd) { //TODO: se a lista não tiver sido registada como apagada, funciona OK!!
    if(verificarListaVazia(cmd) == false){
        return head == 0;
    }else{
        cout << "Lista tem "<<  n << " itens\n" << endl;
    }
}

// 9. Remover os nós da lista
void ISll::clear(string cmd) { //TODO: parece que funiona OK!!
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        n = 0;                             // Repor valores a zero
        head = NULL;                       // Repor valores a vazio
        tail = NULL;                       // Repor valores a vazio
    }
}

// 10. Procurar a primeira ocorrência do item na lista e imprimir posição
void ISll::find(string cmd, string argumentos) { // TODO não encontra o que deveira, faz uma procura constante sem
    stringstream ssItems(argumentos); // TODO Esta lista deveria apenas entrar com um elemento o de FIND!! mas não vem com isso e vem com isso e o que vinha de traz
    int item;

    while(ssItems >> item) {
        int pos = 0;
        INode* current = head;
        while (current != NULL) {
            if (current->item == item) {
                cout << "Item " << item << " na posicao " << pos << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Item " << item << " não encontrado!\n" << endl;// se chegou aqui, o item não foi encontrado
    }
}


// 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
void ISll::find_max(string cmd, string argumento){ //TODO devia estar a funcionar..mas não está! as vezes bate certo...aaaaaaahhhhhh!
    if(verificarListaVazia(cmd) == false) {
        int pos = 0;
        int max_val = head->item; // começa com o primeiro valor
        INode* current = head->next;
        while (current != NULL) {
            if (current->item > max_val) {
                max_val = current->item;
                pos++;
            }
            current = current->next;
        }
        cout << "Max Item " <<  max_val << " na posicao " << pos << "!\n" << endl;
    }
}

// 12. Remover um nó da posição da lista
void ISll::delete_pos(string cmd, string argumentos){
    stringstream ssItems(argumentos);
    int item;
    if(verificarListaVazia(cmd) == false) {
        INode* current = head;
        INode* previous = nullptr;

        while(ssItems >> item) {
            while (current != nullptr) {
                if (current->item == item) {
                    if (previous == nullptr) { // O valor está no primeiro nó
                        head = current->next;   // Avança
                    } else {
                        previous->next = current->next;// O valor não está no primeiro nó
                    }
                    delete current;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
    }
 }

// 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
void ISll::invert_range(string cmd, string argumentos){ //TODO Atribuir oss valores paara cada posião e t
    if(verificarListaVazia(cmd) == false) {
//        if (pos1 >= pos2 || pos1 < 0 || pos2 >= size) {
//            cout << "Posicoes invalidas." << endl;
//            return;
//        }
//
//        // Navegar ate pos1 e guardar referencia do no anterior
//        INode* current = head;
//        INode* prev = NULL;
//        int pos = 0;
//        while (pos < pos1) {
//            prev = current;
//            current = current->next;
//            pos++;
//        }
//
//        // Criar lista auxiliar
//        ISll auxList;
//
//        // Remover itens do intervalo [pos1, pos2] da lista original e inserir na lista auxiliar
//        while (pos <= pos2) {
//            INode* next = current->next;
//            auxList.insert(current->item, 0);
//            remove(current);
//            current = next;
//            pos++;
//        }
//
//        // Reinserir itens na lista original
//        while (!auxList.is_empty()) {
//            insert(auxList.get_head()->get_data(), pos1);
//            pos1++;
//        }
//    }
}


/* Para verificar se a lista esta vazia */
    bool ISll::verificarListaVazia(string cmd){ //TODO problema se comandos : insert_end 0 1 2;  print ; dim => diz que a lista está vazia, no entanto está com items
        /* Se a lista não está vazia, é porque tem pelo menos 1 nó.
         * Se unico, então é primeiro e último ao mesmo tempo e nesse
         * caso não está vazia mas com um elemento */
        if(head == NULL || tail == NULL){                // Se aponta para null
            cout << "Comando " << cmd << ": Lista vazia!\n" << endl;
            return true;
        }else {
            return false;
        }
    }

//TODO a implementar se necessário para encontrar posição para o Find, item OU Delete_pos => MENSSAGEM DE APARECER!!
// Mas a messagem também pode apareccer de outra maneira
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