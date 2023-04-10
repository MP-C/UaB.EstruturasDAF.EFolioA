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
// 1. Inserir no inicio da lista // TODO : quase OK!!
void ISll::insert_0(string argumentos) {
    /* Para extrair os argumentos de cada comando*/
    stringstream ssItems(argumentos);   // Para ler os argumentos de cada comando à vez
    int item;
    while(ssItems >> item) {
        INode* newNode = new INode;     // cria o novo nó
        newNode->item = item;           // define o valor do novo nó
        newNode->next = head;           // faz o novo nó apontar para o antigo primeiro nó
        head = newNode;                 // faz a cabeça da lista apontar para o novo nó
        if(tail == nullptr){            // Se tail estiver vazia, vai ficar com o mesmo valor de head
            tail = newNode;
        }
        n++;                            // aumenta o contador
    }
}

// 2. Inserir no fim da lista // TODO problema insere no fim, mas não apaga o que ficou em memória, e no proximo insertXX insere os novos e anteriores
void ISll::insert_end(string argumentos) {
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {                // Para ler os argumentos de cada comando à vez
        //cout << "item " << item << endl;
        INode *newNode = new INode;         // cria o novo nó
        newNode->item = item;               // define o valor do novo nó
        newNode->next = nullptr;            // faz o novo nó apontar para nullptr, já que será o último da lista

        if (head == nullptr) {              // verifica se a lista está vazia
//            head = newNode;                 // faz a cabeça da lista apontar para o novo nó
            tail = newNode;                 // faz a tail apontar para novo nó
        } else {
//            tail->next = newNode;           // faz a cabeça da lista apontar
//            tail = newNode;
            INode* lastNode = tail;         // inicia a busca pelo último nó a partir da cabeça da lista
            while (lastNode->next != nullptr) { // TODO SO PEGAR NO TAIL??
                lastNode = lastNode->next;  // avança para o próximo nó até chegar ao último
            }
            lastNode->next = newNode;       // faz o antigo último nó apontar para o novo nó
        }
        n++;                                // aumenta o contador que serve de leitura do tamanho
    }
}
/*INode *newNode = new INode(value, nullptr);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;*/

// 3. Imprimir item do início da lista //TODO: OK!
void ISll::print_0(string cmd){
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        if (head != NULL) {
            cout << "Lista(0)= "<<  head->item   << " \n" << endl; // TODO problema está a imprimir o local e não o item
        }
    }
}

// 4. Imprimir item do fim da lista //TODO OK!
void ISll::print_end(string cmd){
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        INode *atual = head;            // Cria um ponteiro "atual" que aponta para o primeiro elemento da lista (head)
        while (atual->next != nullptr) {// Percorre a lista até encontrar o último elemento (cujo próximo ponteiro é nulo)
            atual = atual->next;
        }                               // tail imprimir!!
        cout << "Lista(end)= "<<  atual->item << " \n" << endl;// Imprime o valor do último elemento da lista
    }
}

// 5. Imprimir toda lista //TODO OK!
void ISll::print(string cmd) {
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        INode *atual = head;               // Cria um ponteiro "atual" que aponta para o primeiro elemento da lista (head)
        if(head != NULL) {                 // Se não estiver vazia, continua a imprimir list até ao fim
            cout << "Lista= ";             // Imprimir a palavra pertendida
            while (atual != NULL) {        // Percorre a lista enquanto o nó atual não for nulo
                cout << atual->item << " ";// Imprime o valor atual começando no nó inicial
                atual = atual->next;       // Move o ponteiro para o próximo nó da lista
            }
            //atual->next=NULL;
            cout <<"\n"<<endl;                  // Quebra de linha para separar a impressão da lista de outras saídas
        };
    };
}

/* 6. Remover o nó do início da lista. Apenas e necessário verificar se a lista está vazia ou não*/
void ISll::delete_0(string cmd) {       //TODO problema : Apaga sempre mais do que o primeiro elemento (ou tudo) ou não apaga nada apos vários inserts
    if (verificarListaVazia(cmd) == false) {   // Verifica se a lista está vazia
        INode *p;                       // Criar novo nó
        p = head->next;                 // p fica com o próximo valor
        delete head;                    // elimina o valor de head
        head = p;                       // head fica com o valor seguinte que estava em p
    }
    n--;
}
//    INode *ptr = head;
//    if(ptr == head) {
//        head = ptr->next;//        return;
//    }
//    INode *atual = head;
//    INode *anterior = head;
//    while(atual) {
//        if(atual == ptr) {
//            anterior->next = atual->next;
//            return;
//        }
//        anterior = atual;
//        atual = atual->next;
//    }

// 7. Remover um nó do fim da lista //TODO parece OK!
void ISll::delete_end(string cmd) {
    if(verificarListaVazia(cmd) == false) {// Verifica se a lista está vazia antes de tentar remover um elemento
        //int elemento = head->item;
        INode *temporario = head;              // Criar nó temporário, que é usado para repor o valor assim que o último é apagado
        if (head == tail) {                    // Se a lista tem apenas um elemento, remove e atualiza head e tail
            //delete head;                       // Remove head
            //delete tail;                       // Remove tail
            head = tail = nullptr;             // Atualiza head e tail
            n = 0;                             // Atualiza contador
        }else{
            /*
            // Se a lista tem mais de um elemento, percorre a lista até chegar ao penúltimo elemento
            while(temporario->next != tail) {
                temporario = temporario->next;
            }
            // e atualiza tail para o penúltimo elemento, removendo o último elemento
            delete tail;                       // Remove tail
            tail = temporario;                 // Atualiza tail
            tail->next = NULL;                 // Atualiza tail
            delete temporario;                 // Apaga o temporário para libertar memória
            n--;                               // Atualiza contador
             */
            INode *p = head;                // Cria um ponteiro "p" que aponta para o primeiro elemento da lista (head)
            INode *q = NULL;                // Cria um ponteiro "q" que apontará para o elemento anterior ao último
            while (p->next != NULL) {       // Percorre a lista enquanto o nó seguinte não for nulo
                q = p;                      // Guarda o nó anterior
                p = p->next;                // Move o ponteiro para o próximo nó da lista
            }
            q->next = NULL;                 // Atribui NULL ao ponteiro next do penúltimo elemento
            delete p;                       // Elimina o último elemento da lista
            n--;                            // Decrementa o número de elementos da lista
        }
    }
}

// 8. Imprimir o número total de itens na lista //TODO: OK!!
void ISll::dim(string cmd) {
    //if(verificarListaVazia(cmd) == false){ // Verifica se a lista está vazia
        cout << "Lista tem "<<  n << " itens\n" << endl; // Imprime o contador atualizado da quantidade de nós contados na lista
    //}
}

// 9. Remover os nós da lista //TODO: OK!!
void ISll::clear(string cmd) {
    if (verificarListaVazia(cmd) == false){   // Verifica se a lista está vazia
        n = 0;                 // Repor valores a zero
        head = NULL;           // Repor valores a vazio
        tail = NULL;           // Repor valores a vazio
    }
}

// 10. Procurar a primeira ocorrência do item na lista e imprimir posição// TODO não encontra o que deveira, faz uma procura constante sem
void ISll::find(string cmd, string argumentos) {
    // TODO Esta lista deveria apenas entrar com um elemento o de FIND!! mas não vem com isso e vem com isso e o que vinha de traz
    stringstream ssItems(argumentos);
    int item;

    while(ssItems >> item) {
        int pos = 0;
        INode* atual = head;
        while (atual != NULL) {
            if (atual->item == item) {
                cout << "Item " << item << " na posicao " << pos << endl;
                return;
            }
            atual = atual->next;
            pos++;
        }
        cout << "Item " << item << " não encontrado!\n" << endl;// se chegou aqui, o item não foi encontrado
    }
}

// 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição
void ISll::find_max(string cmd, string argumento){ //TODO devia estar a funcionar..mas não está! as vezes bate certo...aaaaaaahhhhhh!
    if(verificarListaVazia(cmd) == false) {
        int pos = 1;
        int max_val = head->item; // começa com o primeiro valor
        INode* atual = head->next;
        while (atual != NULL) {
            if (atual->item > max_val) {
                max_val = atual->item;
                pos++;
            }
            atual = atual->next;
            pos++;
        }
        cout << "Max Item " <<  max_val << " na posicao " << pos << "!\n" << endl;
    }
}

// 12. Remover um nó da posição da lista
void ISll::delete_pos(string cmd, string argumentos){
    stringstream ssItems(argumentos);
    int pos;
    while(ssItems >> pos) {
        if(verificarListaVazia(cmd) == false && pos>= 0 && pos < n ) {
            /*INode* atual = head;
            INode* anterior = nullptr;

            while(ssItems >> item) {
                while (atual != nullptr) {
                    if (atual->item == item) {
                        if (anterior == nullptr) { // O valor está no primeiro nó
                            head = atual->next;   // Avança
                        } else {
                            anterior->next = atual->next;// O valor não está no primeiro nó
                        }
                        delete atual;
                        return;
                    }
                    anterior = atual;
                    atual = atual->next;
                }
            }*/
            INode *p = head;                // Ponteiro para percorrer a lista
            INode *q = NULL;                // Ponteiro para guardar o nó anterior
            int i = 0;                      // Índice para percorrer a lista

            // Percorre a lista até chegar ao nó anterior ao nó que deve ser removido
            while (i < pos) {
                q = p;
                p = p->next;
                i++;
            }

            // Atualiza o ponteiro do nó anterior para apontar para o nó seguinte do nó a ser removido
            if (q == NULL) {                // Se o nó a ser removido for o primeiro da lista
                head = p->next;
            } else {
                q->next = p->next;
            }

            delete p;                       // Remove o nó
            n--;                            // Atualiza o tamanho da lista
        }
        }
    }

// 13. Inverter a ordem dos itens da lista a partir da posição 1 até à posição indicada
void ISll::invert_range(string cmd, string argumentos){ //TODO Atribuir oss valores paara cada posião e t
    stringstream ssItems(argumentos);
    int pos1;
    int pos2;
    while(ssItems >> pos1 >> pos2) {
        if(verificarListaVazia(cmd) == false) {
            if (pos1 > pos2) {  // Se a posição 1 é maior que a posição 2, troca as posições
                int temp = pos1;
                pos1 = pos2;
                pos2 = temp;
            }
            INode *p1 = head;  // Criar ponteiro p1 e inicializá-lo para o head da lista
            INode *prev1 = NULL;  // Criar ponteiro prev1 e inicializá-lo para NULL
            for (int i = 1; i < pos1 && p1 != NULL; i++) { // Percorre a lista até a posição 1
                prev1 = p1;  // Armazena o valor atual de p1 em prev1
                p1 = p1->next; // Move o ponteiro p1 para o próximo nó da lista
            }
            INode *p2 = p1; // Criar ponteiro p2 e inicializá-lo para p1
            INode *prev2 = prev1; // Criar ponteiro prev2 e inicializá-lo para prev1
            for (int i = pos1; i < pos2 && p2 != NULL; i++) { // Percorre a lista até a posição 2
                prev2 = p2;  // Armazena o valor atual de p2 em prev2
                p2 = p2->next;  // Move o ponteiro p2 para o próximo nó da lista
            }
            if (p1 != NULL && p2 != NULL) {  // Se p1 e p2 forem diferentes de NULL
                if (prev1 != NULL) {  // Se prev1 for diferente de NULL, atualiza o ponteiro next de prev1
                    prev1->next = p2;
                } else {  // Caso contrário, atualiza head para p2
                    head = p2;
                }
                if (prev2 != NULL) {  // Se prev2 for diferente de NULL, atualiza o ponteiro next de prev2
                    prev2->next = p1;
                } else {  // Caso contrário, atualiza head para p1
                    head = p1;
                }
                INode *temp = p2->next;  // Criar ponteiro temporário e inicializá-lo para o próximo nó após p2
                p2->next = p1->next;  // Atualiza o ponteiro next de p2 para o próximo nó após p1
                p1->next = temp;  // Atualiza o ponteiro next de p1 para o ponteiro temporário
            }
        }
//        if (pos1 >= pos2 || pos1 < 0 || pos2 >= size) {
//            cout << "Posicoes invalidas." << endl;
//            return;
//        }
//
//        // Navegar ate pos1 e guardar referencia do no anterior
//        INode* atual = head;
//        INode* anterior = NULL;
//        int pos = 0;
//        while (pos < pos1) {
//            anterior = atual;
//            atual = atual->next;
//            pos++;
//        }
//
//        // Criar lista auxiliar
//        ISll auxList;
//
//        // Remover itens do intervalo [pos1, pos2] da lista original e inserir na lista auxiliar
//        while (pos <= pos2) {
//            INode* next = atual->next;
//            auxList.insert(atual->item, 0);
//            remove(atual);
//            atual = next;
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
}

/* Para verificar se a lista esta vazia, com devolução de um booleano */
    bool ISll::verificarListaVazia(string cmd){ //TODO problema se comandos : insert_end 0 1 2;  print ; dim => diz que a lista está vazia, no entanto está com items
        /* Se a lista não está vazia, é porque tem pelo menos 1 nó.
         * Se unico, então é primeiro e último ao mesmo tempo e nesse
         * caso não está vazia mas com um elemento */
        if(head == NULL ){                // Se head está vazia,
            cout << "Comando " << cmd << ": Lista vazia!\n" << endl; // Então imprime mensagem de erro
            return true;
        }else {                           // Se lista não está vazia
            return false;                 // Apenas devolve falso
        }
    }


    ////*  NÃO UTILIZADOS */
//TODO a implementar se necessário para encontrar posição para o Find, item OU Delete_pos => MENSSAGEM DE APARECER!!
// Mas a messagem também pode apareccer de outra maneira
    bool ISll::verificarPosicao(string cmd, ISll list, int pos) {
        INode *head;
        INode* atual = head;
        int i = 1;
        while (atual != nullptr && i < pos) {
            atual = atual->next;
            i++;
        }
        cout << "Comando " << cmd << ": Posicao invalida!\n" << endl;
        return (atual != nullptr);
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