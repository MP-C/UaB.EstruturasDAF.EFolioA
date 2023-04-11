
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
#include <iostream> // std::cout
#include <fstream>  // std::files
#include <sstream>  // std::stringstream
#include <string>   // std::string
#include "isll.h"
using namespace std;

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


// apontador para o primeiro nó da lista
Node* head = nullptr;
// contador de nós
int C = 0;

/* Função para verificar se o input introduzido é comentário ou é um cmd válido*/
string validarComando(string cmd){
    if(cmd.length() == 0){ // Critério para garantir que existe um cmd
        return "Introduzir um comando valido";
    }else{
        return cmd;         // Devolve o cmd, e continua a executar
    }
}

/* Função para ler cada linha do ficheiro, e executar o comando respetivo */
void executarComando(string comando, string argumentos, ISll& list) {
    /* Em função do comando introduzido, a função deve ser executada corretamente */
    if (comando[0] == '#' ) {   // Se o cmd for comentario e
        while(comando== "#") {  // o resto da linha é completamente ignorada, pois é um linha de comentário
        // Consideram-se que todas as restantes hipóteses serão comandos, que ainda assim serão processados na proxima iteração
        }
    }
    else if (comando == "insert_0") {       // Insere no início da lista um novo nó
        list.insert_0(argumentos);
    }
    else if (comando == "insert_end"){      // Insere no fim da lista um novo nó
        list.insert_end(argumentos);
    }
    else if (comando == "print_0") {        // Imprime apenas o nó do início da lista
        list.print_0(comando);
    }
    else if (comando == "print_end"){       // Imprime apenas o nó do fim da lista
        list.print_end(comando);
    }
    else if (comando == "print") {          // Imprime todos os nós da lista
        list.print(comando);
    }
    else if (comando == "delete_0"){        // Apaga apenas o nó do início da lista
        list.delete_0(comando);
    }
    else if (comando == "delete_end"){      // Apaga apenas o nó do fim da lista
        list.delete_end(comando);
    }
    else if (comando == "dim"){             // Imprime o número total de itens na lista.
        list.dim(comando);
    }
    else if (comando == "clear") {          //  Remove todos os nós da lista
        list.clear(comando);
    }
    else if (comando == "find") {           // Procura a primeira ocorrência do item na lista e imprime a sua posição
        list.find(comando,argumentos);
    }
    else if (comando == "find_max") {       // Procura a primeira ocorrência do maior item na lista e imprime a sua posição
        list.find_max(comando,argumentos);
    }
    else if (comando == "delete_pos") {     // Remove um nó da posição pos da lista
        list.delete_pos(comando, argumentos);
    }
    else if (comando == "invert_range") { // Inverte a ordem dos itens a partir da posição pos1 até à posição pos2 (inclusive) da lista
        list.invert_range(comando, argumentos);
    }
    else {
        cout << "O comando introduzido nao e invalido.\n" << endl;
    }
    return;
}


int main(){
    ISll list; // Para utilizar os nós de list
    string input, cmd, listaArgumentos;

    /* Para que seja lida cada linha introduzida de maneira individual */
    while(getline(cin/*testes*/, input)) {
        /* Para extrair o comando */
        stringstream ssInput(input);
        ssInput >> cmd;

        /* Verifica que o comando introduzido é válido*/
        string comandoValido = validarComando(cmd);

        /* Associa o resto da lista aos diferentes itens */
        string item;
        while (ssInput >> item) {
            listaArgumentos += item + " ";
        }

        /* Procurar e executar cada comando valido com os respetivos argumentos guardados em input */
        executarComando(comandoValido, listaArgumentos, list);
        /* Para limpar a lista de argumentos antes de continuar e não misturar com os existentes */
        listaArgumentos="";
    }
    return 0;
}

// EOF
