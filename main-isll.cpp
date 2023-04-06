
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

/* Para garantir que no caso do utilizador tenha introduzido um caracter maiúsculo por engano
 * esta função permite transformar a entrada em minusculas */
string transformarMinusculas(string comando) {
    string result="";
    for (int i = 0; i < comando.length(); i++) {
        result[i] = tolower(comando[i]);// Lê cada letra do comando de forma interária até terminar a string
        cout<<result[i]<< endl;
    }
    return result;
}

/* Função para verificar se o input introduzido é comentário ou é um comando válido*/
string validarComando(string comando){
    if (comando[0] == '#' ) { // Se o comando for comentario
        cout << "comentario"<< endl;
        return "#"; // Linha a ignorar, pois é um linha de comentário
    }else if(comando.length() == 0){ // Critério para garantir que existe um comando
        return "comando não valido";
    }else{ // Consideram-se que as restantes hipóteses serão comando, que ainda assim será processado na proxima função
        //string minusculas = transformarMinusculas(comando);
        return comando; // Devolve o comando, e continua a executar
    }
};

/* Função para ler cada linha do ficheiro, e executar o comando respetivo */
void executarComando(string comando, ISll& list){
    /* Para garantir que todas as letras introduzidas, sejam minúsculas */
    char comandoValido; // Variavél para transformar o comando em mininusculas e garnatir que o comando é realizado

    /* Em função do comando introduzido, a função deve ser executada corretamente */
    if (comando == "insert_0") {
        cout << "insert_0 inserido" << endl;
        list.insert_0(1, C);
        list.insert_0(3, C);
        list.insert_0(2, C);
        list.insert_0(5, C);
    }
    else if (comando == "insert_end") {
        cout << "insert_end inserido" << endl;
        //insert_end(newData);
    }
    else if (comando == "print_0") {
        cout << "print_0 inserido" << endl;
        //print_0();
    }
    else if (comando == "print_end") {
        cout << "print_end inserido" << endl;
        //print_end();
    }
    else if (comando == "print") {
        cout << "print inserido" << endl;
        list.print(1, 2);
    }
    else if (comando == "delete_0") {
        cout << "delete_0 inserido" << endl;
        //delete_0();
    }
    else if (comando == "delete_end") {
        cout << "delete_end inserido" << endl;
        //delete_end();
    }
    else if (comando == "dim") {
        cout << "dim inserido" << endl;
        //dim();
    }
    else if (comando == "clear") {
        cout << "clear inserido" << endl;
        //clear();
    }
    else if (comando == "find") {
        cout << "find inserido" << endl;
        //find(newData);
    }
    else if (comando == "find_max") {
        cout << "find_max inserido" << endl;
        //find_max();
    }
    else if (comando == "delete_pos") {
        cout << "delete_pos inserido" << endl;
        //delete_pos(newData);
    }
    else if (comando == "invert_range") {
        cout << "invert_range inserido" << endl;
        //invert_range(comandoValido, newData, position1, position2);
    }
    else {
        cout << "Comando " << comandoValido << ": Posicao invalida!\n" << endl;
    }
}


int main(){
   ISll list;   // exemplo
    string comando = "";
    //ifstream cin1("testes.txt"); //Escolher ficheiro de testes
    //cin>>comando;

    while(getline(cin, comando)) {
        string comandoValido = validarComando(comando);
        cout << "Comando obtido: " << comandoValido << endl;
        executarComando(comandoValido, list);
    }
    return 0;
}

// EOF
