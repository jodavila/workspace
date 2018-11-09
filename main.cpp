/*
 * ============================================================================
 *	 Nome do Arquivo:   main.cpp
 *
 *		   Descricao:	Pode ser lida da descricao do trabalho.
 *
 *        		Data:	09/11/2018 23:30
 *        Compilador:	gcc
 *
 *   		   Curso:   Ciencia da Computacao @ UFRGS
 *
 *         	 Autores:   Consultar o arquivo membro.txt
 * ============================================================================
 */

#include<stdio.h>
#define MAX 200
/*************************** FUNCOES AUXILIARES ************************************/
//  Nome da funcao: ImprimeAdjacentes
//        Objetivo: Mostrar os vertices adjacentes do vertice informado
//         Entrada: (int) matriz - a matriz com todos os dados
//                  (int) ponto - o vertice
//                  (int) total - a quantidade de itens que estou lidando
//           Saida: (char) a impressao do valor correspondente ao adjacente

void ImprimeAdjacentes(int matriz[MAX][MAX], int ponto, int total){
	printf("Adjacentes de %d \n",ponto);
	for (int i = 0; i < total; ++i)
	{
    	if ((matriz[ponto][i]>0)||(matriz[ponto][i] == -1))
			printf("%d ",i);
	}
	printf("\n");
}

//  Nome da funcao: exibe
//        Objetivo: Imprimir uma lista de numeros
//         Entrada: (int) vetor - a lista
//                  (int) qtd - a quantidade de itens a ser impressa
//           Saida: (char) o valor contido na lista

void exibe(int lista[MAX], int qtd){
	int i;
	for ( i=1; i < qtd; i++ )
   		printf("%d:[%d] ",i, lista[i]);
   	printf("\n");
}

//  Nome da funcao: EstaNaLista
//        Objetivo: Verifica se um valor esta no vetor
//         Entrada: (int) lista - um vetor
//                  (int) valor - valor a ser procurado
//           Saida: (int) um valor inteiro (0,1)

int EstaNaLista(int lista[MAX], int valor){
	int i = 1;

	while( lista[i] > 0 ){
		if ( lista[i] == valor)
		{
			return 1;
		}
		i++;
	}
	return 0;
}

/*************************** FUNCOES PRINCIPAIS ************************************/
//  Nome da funcao: Prim
//        Objetivo: Dado um grafo G, cria uma AGM de G
//        Entradas: (tipo) nome - o que é -- na definição é
//                 
//          Saida: AGM

/*
tipo nome(parametros){
    corpo;
    return 0;
}
*/

//  Nome da funcao: main
//        Objetivo: Chamar as funcoes necessarias para o funcionamento
//                  ler as entradas
//         Entrada: (int) campus - quantidade de testes 
//                  (int) conexoes - informacoes das distancias -- mat
//                  (int) dispositivos - dispositivos limitados
//                  (int) limitados - lista de disp limitados
//          Saida: nenhuma

int main(){
    
    // Variaveis
    int num = 0;
    
	// Variaveis Auxiliares
    int k;
  	
  	// Leitura da Quantidade de Campus
	
	while(num>k){

        // Inicialização // das variveis e da estrutura de dados
        
   	    // Leitura da Quantidade de Dispositivos

	    // Leitura das Conexoes

	    // Leitura da Quantidade de Dispositivos Limitados

	    // Leitura dos Dispositivos Limitados
        
    	// SAIDA
		printf("Caso %d: ",k+1);
		//chama função que ira retornar o total
        k++;
	}
	return 0;
}