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

// Funções para manipulação da lista:

/* 1. Inserir no inicio da lista */
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

/* 2. Inserir no fim da lista */
void ISll::insert_end(string argumentos) {
    stringstream ssItems(argumentos);
    int item;
    while(ssItems >> item) {           // Para ler os argumentos de cada comando à vez
        INode *newNode = new INode;    // cria o novo nó
        newNode->item = item;          // define o valor do novo nó
        newNode->next = nullptr;       // faz o novo nó apontar para nullptr, já que será o último da lista

        if (head == nullptr) {         // verifica se a lista está vazia
            head = newNode;            // faz a head apontar para o novo nó
            tail = newNode;            // faz a tail apontar para o novo nó
        } else {
            tail->next = newNode;      // faz o antigo último nó apontar para o novo nó
            tail = newNode;            // atualiza a variável tail para apontar para o novo nó
        }
        tail = newNode;                // atualiza a variável tail para apontar para o novo nó no inivio
        n++;                           // aumenta o contador que serve de leitura do tamanho
    }
}

/* 3. Imprimir item do início da lista */
void ISll::print_0(string cmd){
    if (verificarListaVazia(cmd) == false){// Verifica se a lista está vazia
        cout << "Lista(0)= "<<  head->item   << " \n" << endl;
    }
}

/* 4. Imprimir item do fim da lista */
void ISll::print_end(string cmd){
    if (verificarListaVazia(cmd) == false){// Verifica se a lista está vazia
        INode *atual = head;               // Cria um ponteiro "atual" que aponta para o primeiro elemento da lista (head)
        while (atual->next != nullptr) {   // Percorre a lista até encontrar o último elemento (cujo próximo ponteiro é nulo)
            atual = atual->next;
        }
        /* Para imprimir tail apenas segundo as condições */
        cout << "Lista(end)= "<<  atual->item << " \n" << endl;// Imprime o valor do último elemento da lista
    }
}

/* 5. Imprimir toda lista */
void ISll::print(string cmd) {
    if (verificarListaVazia(cmd) == false){// Verifica se a lista está vazia
        INode *atual = head;               // Cria um ponteiro "atual" que aponta para o primeiro elemento da lista (head)
        if(head != NULL) {                 // Se não estiver vazia, continua a imprimir list até ao fim
            cout << "Lista= ";             // Imprimir a palavra pretendida
            while (atual != NULL) {        // Percorre a lista enquanto o nó atual não for nulo
                cout << atual->item << " ";// Imprime o valor atual começando no nó inicial
                atual = atual->next;       // Move o ponteiro para o próximo nó da lista
            }
            cout <<"\n"<<endl;             // Quebra de linha para separar a impressão da lista de outras saídas
        };
    };
}

/* 6. Remover o nó do início da lista. Apenas e necessário verificar se a lista está vazia ou não*/
void ISll::delete_0(string cmd) {
    if (verificarListaVazia(cmd) == false) {   // Verifica se a lista está vazia
        INode *p;                       // Criar novo nó
        p = head->next;                 // p fica com o próximo valor
        delete head;                    // elimina o valor de head
        head = p;                       // head fica com o valor seguinte que estava em p
    }
    n--;
}

/* 7. Remover um nó do fim da lista */
void ISll::delete_end(string cmd) {
    if(verificarListaVazia(cmd) == false) {// Verifica se a lista está vazia antes de tentar remover um elemento
        if (head == tail) {               // Se a lista tem apenas um elemento, remove e atualiza head e tail
            //delete head;                // Remove head
            //delete tail;                // Remove tail
            head = tail = nullptr;        // Atualiza head e tail
            n = 0;                        // Atualiza contador
        }else{
            /* Criar nós temporários, que são usados para repor o valor assim que o último é apagado */
            INode *inicio = head;         // Cria um ponteiro "inicio" que aponta para o primeiro elemento da lista (head)
            INode *anterior = NULL;       // Cria um ponteiro "anterior" que apontará para o elemento anterior ao último
            while (inicio->next != NULL) {// Percorre a lista enquanto o nó seguinte não for nulo
                anterior = inicio;        // Guarda o nó anterior
                inicio = inicio->next;    // Move o ponteiro para o próximo nó da lista
            }
            anterior->next = NULL;        // Atribui NULL ao ponteiro next do penúltimo elemento
            tail = anterior;              // Para declarar que o ultimo elemento não se perde
            delete inicio;                // Elimina o último elemento da lista
            n--;                          // Decrementa o número de elementos da lista
        }
    }
}

/* 8. Imprimir o número total de itens na lista */
void ISll::dim(string cmd) {                         // verifica qual é o tamanho da lista, e devolve o respetivo tamanho
    /* Não precisa de verificar que a lista está vazia, simplesmente imprime a lista, e será "0" se não tiver valores */
    cout << "Lista tem "<<  n << " itens\n" << endl; // Imprime o contador "tamanho" atualizado da quantidade de nós contados na lista
}

/* 9. Remover os nós da lista */
void ISll::clear(string cmd) {
    if (verificarListaVazia(cmd) == false){ // Verifica se a lista está vazia
        /* E apaga de forma recursiva toda e qualquer informação que tenha, começado no "head" e indo até "tail" */
        n = 0;                                  // Repor valores a zero
        head = NULL;                            // Repor valores a vazio
        tail = NULL;                            // Repor valores a vazio
    }
}

/* 10. Procurar a primeira ocorrência do item na lista e imprimir posição */
void ISll::find(string cmd, string argumentos) {
    stringstream ssItems(argumentos);               // Cria uma stringstream com os argumentos
    int item;                                       // Variável para armazenar os itens lidos

    while(ssItems >> item) {                        // Enquanto houver itens a serem lidos da stringstream
        int pos = 0;                                // Variável para representar a posição do item na lista
        INode *atual = head;                        // Ponteiro para o primeiro elemento da lista (head)

        while (atual != NULL) {                     // Enquanto o ponteiro atual não for nulo, ou seja, enquanto houver nós na lista
            if (atual->item == item) {              // Se o item do nó atual for igual ao item buscado
                cout << "Item " << item << " na posicao " << pos << endl; // Imprime a posição do item na lista
                return;                             // Retorna da função
            }

            atual = atual->next;                    // Move o ponteiro para o próximo nó da lista
            pos++;                                  // Incrementa a variável de posição
        }
        cout << "Item " << item << " nao encontrado!\n" << endl; // Se chegou aqui, o item não foi encontrado na lista
    }
}


/* 11. Procurar a primeira ocorrência do maior item na lista e imprimir posição */
void ISll::find_max(string cmd, string argumento){
    if(verificarListaVazia(cmd) == false) {
        int pos = 0;                        // Inicia a contagem das posições a partir de 1
        int posMax = 0;
        int valorMaximo = head->item;       // Inicia o valor máximo com o primeiro valor da lista
        INode* atual = head->next;          // Começa a procurar pelo valor máximo a partir do segundo elemento da lista
        while (atual != NULL) {
             pos++;                         // Atualiza a posição do elemento atual
            if (atual->item > valorMaximo) {
                valorMaximo = atual->item;  // Atualiza o valor máximo encontrado
                posMax = pos;               // Atualiza a posição do valor máximo encontrado
            }
            atual = atual->next;            // Avança para o próximo elemento da lista
        }
        cout << "Max Item " << valorMaximo << " na posicao " << posMax << "!\n" << endl; // Imprime o valor máximo e sua posição na lista
    }
}

/* 12. Remover um nó da posição da lista */
void ISll::delete_pos(string cmd, string argumentos){
    stringstream ssItems(argumentos);
    int pos;
    while(ssItems >> pos) {
        if(verificarListaVazia(cmd) == false ) {
            if(posicaoValida(cmd, pos, n) == true) {
                INode *inicio = head;       // Ponteiro para percorrer a lista
                INode *anterior = NULL;     // Ponteiro para guardar o nó anterior
                int i = 0;                  // Índice interador para percorrer a lista

                /* Percorre a lista até chegar ao nó anterior ao nó que deve ser removido */
                while (i < pos) {          // Percorre a lista até encontrar a posição desejada (pos)
                    anterior = inicio;     // Atualiza o ponteiro para o nó anterior
                    inicio = inicio->next; // Move o ponteiro para o próximo nó da lista
                    i++;                   // Incrementa o índice do iterador
                }

                /* Atualiza o ponteiro do nó anterior para apontar para o nó seguinte do nó a ser removido */
                if (anterior == NULL) {     // Se o nó a ser removido for o primeiro da lista
                    head = inicio->next;
                } else {
                    anterior->next = inicio->next;
                }
                delete inicio;              // Remove o nó
                n--;                        // Atualiza o tamanho da lista
            };
        }
    }
}
// Função auxiliar que recebe o início e o fim de uma sublista e inverte a ordem dos seus nós
static INode* reverse(INode *start, INode *end)
{
    INode *prev = nullptr, *current = start, *next = nullptr;
    // percorre os nós da sublista, invertendo a direção dos seus ponteiros next
    while (current != end) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // atualiza o ponteiro next do último nó invertido para o nó seguinte
    end->next = prev;
    // devolve o novo primeiro nó da sublista invertida
    return end;
}

// Função que inverte a ordem dos nós de uma sublista, definida pelos argumentos "pos1" e "pos2"
void ISll::invert_range(string cmd, string argumentos) {
    stringstream ssItems(argumentos);
    int pos1, pos2;
    // percorre os argumentos, que representam as posições "pos1" e "pos2" de cada sublista a ser invertida
    while (ssItems >> pos1 >> pos2) {
        if (verificarListaVazia(cmd) == false) {
            if (pos1 == pos2)
                return;

            // procura o primeiro nó a ser invertido, e seu nó anterior (se existir)
            INode *rev_start = head, *rev_start_prev = nullptr;
            for (int i = 1; i < pos1; i++) {
                rev_start_prev = rev_start;
                rev_start = rev_start->next;
            }

            // procura o último nó a ser invertido, e seu nó seguinte (se existir)
            INode *rev_end = rev_start;
            for (int i = pos1; i < pos2; i++) {
                rev_end = rev_end->next;
            }
            INode *rev_end_next = rev_end->next;

            // chama a função "reverse" para inverter os nós da sublista definida pelos nós "rev_start" e "rev_end"
            reverse(rev_start, rev_end);

            // interliga os nós invertidos na lista original
            if (rev_start_prev != nullptr) {
                rev_start_prev->next = rev_end;
            } else {
                head = rev_end;
            }
            rev_start->next = rev_end_next;
        }
    }
}

/* Para verificar se a lista esta vazia, com devolução de um booleano: "True" se estiver vazia, "False" se estiver preenchida */
bool ISll::verificarListaVazia(string cmd){
    /* Se a lista não está vazia, é porque tem pelo menos 1 nó.
     * Se unico, então é primeiro e último ao mesmo tempo e nesse
     * caso não está vazia mas com um elemento */
    if(head == NULL ){                  // Se head está vazia,
        cout << "Comando " << cmd << ": Lista vazia!\n" << endl; // Então imprime mensagem de erro
        return true;                    // Devolve true => lista vazia
    }else {                             // Se lista não está vazia
        return false;                   // Apenas devolve falso => lista ocupada
    }
}

/* Para verificar se a posicao que está a ser procurada existe (devolvendo booleano "True"), se não for encontrada, devolve frase de erro */
bool ISll::posicaoValida(string cmd, int posicao, int tamanho) {
    if(posicao >= 0 && posicao < tamanho){ // Verifica se a posição está dentro dos limites válidos da lista
        return true;                       // Retorna verdadeiro se a posição é válida
    } else {
        cout << "Comando " << cmd << " : Posicao invalida!\n" << endl; // Imprime uma mensagem de erro indicando a posição inválida
        return false;                      // Retorna falso se a posição é inválida
    }
}


// EOF