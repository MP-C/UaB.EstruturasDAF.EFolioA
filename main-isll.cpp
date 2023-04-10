
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

#include <ctype.h>
#include <iostream> // std::cout
#include <fstream>  // std::files
#include <sstream>  // std::stringstream
#include <string>   // std::string
#include <stdlib.h>
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

////* Para garantir que no caso do utilizador tenha introduzido um caracter maiúsculo por engano
 /* esta função permite transformar a entrada em minusculas */
string transformarMinusculas(string comando) {
    string result="";
    for (int i = 0; i < comando.length(); i++) {
        result[i] = tolower(comando[i]);// Lê cada letra do comando de forma interária até terminar a string
        cout<<result[i]<< endl;
    }
    return result;
}

/* Função para verificar se o input introduzido é comentário ou é um cmd válido*/
string validarComando(string cmd){
    if(cmd.length() == 0){ // Critério para garantir que existe um cmd
        return "Introduzir um comando valido";
    }else{
        ////string minusculas = transformarMinusculas(cmd);
        return cmd;         // Devolve o cmd, e continua a executar
    }
}

/* Função para ler cada linha do ficheiro, e executar o comando respetivo */
void executarComando(string comando, string argumentos, ISll& list) {
    /* Para garantir que todas as letras introduzidas, sejam minúsculas */

    //cout << "lista de argumentos que nao esta a ser apagada depois de usada: " << argumentos << endl;

    /* Em função do comando introduzido, a função deve ser executada corretamente */
    if (comando[0] == '#' ) {   // Se o cmd for comentario
        while(comando== "#") {  // Linha a ignorar, pois é um linha de comentário
            //continue;           // Consideram-se que as restantes hipóteses serão comandos, que ainda assim será processado na proxima função
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
    argumentos = ""; // Para limpar os argumentos e não as misturar assim que são guardados
}


int main(){
    ISll list;   // exemplo
    string input, cmd, listaArgumentos;
//    ifstream testes("testes.txt"); //Escolher ficheiro de testes
//    if (!testes.is_open()) {
//        cout << "Erro ao abrir o arquivo" << endl;
//        return 1;
//    }
    /* Para que seja lida cada linha introduzida de maneira individual */
    while(getline(cin/*testes*/, input)) {
        /* Para extrair o comando */
        stringstream ssInput(input);
        ssInput >> cmd;
        string item;
        while (ssInput >> item) {
            listaArgumentos += item + " ";
        }
        /* Verifica que o comando introduzido é válido*/
        string comandoValido = validarComando(cmd);

        /* Procurar e executar cada comando valido com os respetivos argumentos guardados em input */
        executarComando(comandoValido, listaArgumentos, list);
        listaArgumentos="";     // Para limpar a lista de argumentos antes de continuar e não misturar com os existentes
    }
    return 0;
}

// EOF
