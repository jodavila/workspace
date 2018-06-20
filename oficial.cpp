/*
 * ============================================================================
 *	 Nome do Arquivo:	main.cpp
 *
 *		   Descricao:	Pode ser lida da descricao do trabalho.
 *
 *        		Data:	17/06/201 19:08:27
 *        Compilador:	gcc
 *
 *   		Curso	:  Ciencia da Computacao @ UFRGS
 *
 *         	Autores	:
 * 						Joana DAvila
 * 						Marcelo Prado
 * 						Genesio Moraes
 * 						Juan Acari 	
 * 
 * ============================================================================
 */

#include<stdio.h>
#define max_loc 100
/*************************** FUNCOES AUXILIARES ************************************/
//  Nome da funcao: ImprimeAdjacentes
//        Objetivo: Mostrar os vertices adjacentes do vertice informado
//         Entrada: (int) matriz - a matriz com todos os dados
//                  (int) ponto - o vertice
//                  (int) total - a quantidade de itens que estou lidando
//           Saida: (char) a impressao do valor correspondente ao adjacente

void ImprimeAdjacentes(int matriz[max_loc][max_loc], int ponto, int total){
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

void exibe(int lista[max_loc], int qtd){
	int i;
	for ( i=1; i < qtd; i++ )
   		printf("%d:[%d] ",i, lista[i]);
   	printf("\n");
}

//  Nome da fucao: mostraMapa
//       Objetivo: Exibir a matriz na configuracaoo: localizacao - distancia entre - localizacao
//        Entrada: (int) matriz - matriz com todos os dados
//  		   (int) r - quantidades de ruas
//                 (int) l - quantidade de localidades
//          Saida: (char) uma string

void mostraMapa(int matriz[100][100], int r, int l){
	int i;
	int j;
	int peso;

	printf("exibindo cidade \n");
  	for ( i=0; i<r; i++ )
  	{	for ( j=0; j<l; j++ )
    	{
    		peso = matriz[i][j];
    		if ((peso>0)||(peso == -1))
	       		printf ("%d - ( %d ) - %d\n", i,peso,j);
   		}
	}
}

/*************************** FUNCOES PRINCIPAIS *************************************/
//  Nome da funcaoo: sos
//         Objetivo: Exibe quais pontos do vetor sao menores ou igual a um valor
//          Entrada: (int) vetor - uma lista de valores
//                   (int) valor - peso a ser comparado
//                   (int) flag - um valor que servira de parada
//            Saida: (char) uma string

void sos(int lista[max_loc], int valor, int flag){
	int i = 1;
	while( i < flag ){
		if ( lista[i] <= valor)
		{
			printf("%d ",i);
		}
		i++;
	}
}

//  Nome da funcao: EstaNaLista
//        Objetivo: Verifica se um valor esta no vetor
//         Entrada: (int) lista - um vetor
//                  (int) valor - valor a ser procurado
//           Saida: (int) um valor inteiro (0,1)

int EstaNaLista(int lista[max_loc], int valor){
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

//  Nome da funcao: areasRiscos
//        Objetivo: Salvar num vetor o valor da distancia de cada vertice para um vertice indicado.
//                  [Implementacao do algoritmo de dijkstra com algumas modificacoes]
//         Entrada: (int) matriz - todos os dados
//                  (int) l - qtd de localidades
//		    (int) b - posicao da bomba, vertice indicado
//                  (int) a  - alcance da bomba
//           Saida: (char) um caracter de quebra de linha

void areasRiscos(int matriz[max_loc][max_loc], int l, int b, int a){
	int cont = 0;
	int visitar[max_loc];
	int dist[max_loc];
	int fixo[max_loc];
	int posicao = 0;
	int x = 0;
	int y = 0;
	int k = 2;

	l = l + 1;

	for(int i = 1; i < l; i++)	{
	  visitar[i] = -1;
	 	 dist[i] = -1;
		 fixo[i] = -1;
	}

	fixo[1] = b;

	for (int i = 1; i < l; ++i)	{
    	if (matriz[b][i]>0)	{
			cont++;
			fixo[cont+1] = i;
			visitar[cont] = i;
			dist[i] = matriz[b][i];
		}
	}

	posicao = cont+1;
	dist[b] = 0;

	while(k < l){
		cont = 0;
		y = fixo[k];

		for (int i = 1; i < l; ++i)	{
			visitar[i]=-1;
			if (matriz[y][i]>0)	{
				cont++;
				visitar[cont] = i;
			}
		}

		for (int i = 1; visitar[i] > 0; i++)	{
			x = visitar[i];
			if (EstaNaLista(fixo,x) == 0) {
				dist[x] = matriz[y][x] + dist[y];
				posicao+=1;
				fixo[posicao] = x;
			} else	{
				if(dist[x] == -1){
					dist[x] = matriz[y][x] + dist[y];
				}
			}
		}
		k++;
	}
	sos(dist,a,l);
	printf("\n");
}

//  Nome da funcao: main
//        Objetivo: Chamar as funcoes necessarias para o funcionamento, ler as entradas
//         Entrada: (int) quantidade de testes
//                  (int) .. - informacoes da rua
//                  (int) .. - informacoes da bomba
//          Saida: nenhuma

int main(){
    
    // total de teste
	int num;	
	
	// Informacoes do mapa
    int loc;
	int ruas;

	// Informacoes da rua: x <---(d)----> y
  	int x; 
  	int y;
  	int d;

  	// Informacoes da Bomba
  	int bomb;
  	int raio;

	// Variaveis Auxiliares
  	int i;
  	int j;
  	int k = 0;
	int cidade[max_loc][max_loc];

  	// Quantidade de Testes
	//printf("qtd testes:");
	scanf("%d",&num);

	while(num>k){

        x = 0;
		y = 0;
    
        for(i=0;i<max_loc;i++)
        {
            for(j=0;j<max_loc;j++)
            {
                cidade[i][j]=-1;
            }   
        }

		ruas = 0;
		bomb = 0;
		raio = 0;
		loc = 0;
		d = 0;

	// Leitura do Mapa
		scanf("%d %d",&loc, &ruas);

		for (i = 0; i < ruas; ++i)
		{
			scanf("%d %d %d",&x, &y, &d);
			cidade[x][y] = d;
			cidade[y][x] = d;
		}

	// ONDE ESTA A BOMBA
    	scanf("%d %d",&bomb, &raio);
		cidade[bomb][bomb] = 0;

		printf("Caso %d: ",k+1);
		areasRiscos(cidade,loc,bomb,raio);
		k++;
	}
	return 0;
}
