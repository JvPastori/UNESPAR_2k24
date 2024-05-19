#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// função para fazer a verificação da palavra digitada pelo usuario
bool verificar_palavra(int estado_inicial, int estados_finais[], int qtd_estados_finais, int qtd_simbolos, char alfabeto[], int tabela_transicao[][10], char palavra[]) {
    int estado_atual = estado_inicial;

    // laço de repetição para procurar a palavra no meio do alfabeto
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice_simbolo = -1;
        for (int j = 0; j < qtd_simbolos; j++) {
            if (palavra[i] == alfabeto[j]) {
                indice_simbolo = j;
                break;
            }
        }
        // if feito para ver se o simbolo está ou não no alfabeto
        if (indice_simbolo == -1) {
            printf("Palavra contem símbolo invalido.\n");
            return false;
        }
        
        // atualizamos o estado atual conforme a transição é feita
        estado_atual = tabela_transicao[estado_atual - 1][indice_simbolo];
    }
        // for e if feito para ver os estados finais, e fazer a comparação entre estado atual e final, caso forem iguais ele retorna como true
    for (int i = 0; i < qtd_estados_finais; i++) {
        if (estado_atual == estados_finais[i]) {
            return true;
        }
    }

    return false;
}
 

int main() {
    int estado_inicial, qtd_estados, qtd_estados_finais, qtd_simbolos;
    char alfabeto[10];
    int estados_finais[100], tabela_transicao[100][10];


    printf("\n------Linguagens Formais, Automatos e Computabilidade------\n");
    printf("\nAluno:Joao Vitor Pastori Leme Batista\n");



    printf("\n-------AUTOMATO FINITO DETERMINISTICO-------\n");

    
    // Pedir informacoes ao usuario
    printf("Digite o estado inicial (q1): ");
    scanf("%d", &estado_inicial);

    printf("Digite a quantidade de estados: ");
    scanf("%d", &qtd_estados);

    printf("Digite a quantidade de estados finais: ");
    scanf("%d", &qtd_estados_finais);

    printf("Digite os estados finais:");
    for (int i = 0; i < qtd_estados_finais; i++) {// for usado para pegar os estados finais, rodando o tanto de vez que o usuario definir
        scanf("%d", &estados_finais[i]); 
    }

    printf("Digite a quantidade de simbolos do alfabeto: ");
    scanf("%d", &qtd_simbolos);

    printf("Digite os simbolos do alfabeto (sem espaços): ");
    for (int i = 0; i < qtd_simbolos; i++) { // for para pegar os  simbolos, conforme o usuario define a quantidade
        scanf(" %c", &alfabeto[i]); 
    }

    // Preencher a tabela de transicao
    printf("Preencha a tabela de transicao (estado x símbolo):\n"); 
    for (int i = 0; i < qtd_estados; i++) {
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("(Q%d, %c): ", i + 1, alfabeto[j]); // i+1 para começar do 1 e não do 0
            scanf("%d", &tabela_transicao[i][j]); 
        }
    }

    // Imprimir a tabela de transicao
    printf("\n========TABELA DE TRANSIÇÃO:========\n");
    printf("Estado   ");
    for (int i = 0; i < qtd_simbolos; i++) {
        printf("| %c ", alfabeto[i]);
    }
    printf("\n");
    for (int i = 0; i < qtd_estados; i++) {
        printf("q%d        ", i + 1);
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("| %d ", tabela_transicao[i][j]);
        }
        printf("\n");
    }

    // Verificar palavra
    char palavra[100];
    printf("\nDigite a palavra a ser verificada: ");
    scanf("%s", palavra);

    // verificamos se a funcao verificar palavra é verdadeira, caso for sera impressa a mensagem que ela é aceita, caso não, ela não é aceita.
    if (verificar_palavra(estado_inicial, estados_finais, qtd_estados_finais, qtd_simbolos, alfabeto, tabela_transicao, palavra)) {
        printf("A palavra \"%s\" é aceita pelo AFD.\n", palavra);
    } else {
        printf("A palavra \"%s\" não é aceita pelo AFD.\n", palavra);
    }

    return 0;
}