/* 
 * ============================================================================
 *	 Nome do Arquivo:  save.cpp
 *
 *		   Descricao: Dada uma matriz, um ponto e um valor. Retorna uma lista
 *	com todos os vertices que tem valor menor ou igual ao valor informado em
 *	relacao ao ponto.
 *
 *        		Data:  17/06/201 19:08:27
 *        Compilador:  gcc
 *
 *         	Autor	:  Joana DAvila (00274739) - joana.davila@inf.ufrgs.br
 *   		Curso	:  Ciencia da Computacao
 * ============================================================================
 */

#include<stdio.h>
#define max_loc 100
/*************************** FUNCOES AUXILIARES ************************************/
//  Nome da função: ImprimeAdjacentes
//  Objetivo: mostrar todos os valores diretamente ligados a um vertice
//  Entrada: uma matriz, um ponto e o total de itens
//  Saida: uma string

void ImprimeAdjacentes(int matriz[max_loc][max_loc], int ponto, int total){
	printf("Adjacentes de %d \n",ponto);
	for (int i = 0; i < total; ++i)
	{	
    	if ((matriz[ponto][i]>0)||(matriz[ponto][i] == -1))
			printf("%d ",i);
	}
	printf("\n");
}

//  Nome da função: exibe
//  Objetivo: Imprime na tela, uma lista de numeros
//  Entrada: um vetor de inteiros
//  Saida: uma string 

void exibe(int lista[max_loc], int qtd){
	int i; 
	for ( i=1; i < qtd; i++ )
   		printf("%d:[%d] ",i, lista[i]);
   	printf("\n");
}

//  Nome da função: mostraMapa
//  Objetivo: Exibir a matriz na configuração: localizacao - distancia entre - localizacao
//  Entrada: matriz(*)[100] - matriz quadrada no formato int de tamanho 100,
//  		int r - quantidades de ruas, int l - quantidade de localidades
//  Saida: uma string

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
//  Nome da função: sos
//  Objetivo: Exibe quais pontos do vetor são menores ou igual a um valor
//  Entrada: um vetor, um valor a ser comparadp, um valor que servira de parada
//  Saida: uma string

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
//  Nome da função: EstaNaLista
//  Objetivo: Verifica se um valor esta no vetor
//  Entrada: um vetor, um valor
//  Saida: um valor inteiro (0,1)

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

//  Nome da função: areasRiscos
//  Objetivo: 
//  Entrada: matriz, l (qtd de localidades),
//		b (posicao da bomba), a (alcance da bomba)
//  Saida: uma string 

void areasRiscos(int matriz[max_loc][max_loc], int l, int b, int a){
	int cont = 0;
	int visitar[max_loc];
	int dist[max_loc];
	int fixo[max_loc];
	int posicao = 0;
	int x = 0;
	int y = 0;
	int k = 2; // pois fixo[1] é da bomba
	
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
		
//		printf("dist:");exibe(dist,l);	printf("\n");
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
	exibe(dist,l);
}

int main(){
	// Definições de todas as variaveis locais (do main) 
	int num;	// total de teste
	int loc;	// vertices - quantidade de localidades 
	int ruas;	// arestas -- quantidade de ruas
  
	// Representação da rua: x <---(d)----> y
	// Uma rua = x,y,d.  onde
  	int x;    // um dos extremos da rua
  	int y;    // outro extremo da rua
  	int d;    // valor/peso da aresta
  
  	// Informações da Bomba
  	int bomb;	// A localidade da bomba é um valor entre 0 a loc
  	int raio;	// Raio de destruição

	// Variaveis Auxiliares
  	int i;
  	int k = 0;
	int cidade[max_loc][max_loc];

  	// Quantidade de Testes
	//printf("qtd testes:");
	scanf("%d",&num);

	while(num>k){

		for(i = 0; i < max_loc; i++)
		{
		    cidade[x][y] = -1;
		    cidade[y][x] = -1;
		}

		ruas = 0;
		bomb = 0;
		raio = 0;
		loc = 0;
		x = 0;
		y = 0; 
		d = 0;
		i = 0;

	// Leitura do Mapa
	//	printf("qtd de localidade e ruas: ");
		 scanf("%d %d",&loc, &ruas);
			  
		for (i = 0; i < ruas; ++i)
		{
	//		printf("> %d : ",i+1);
			scanf("%d %d %d",&x, &y, &d);

	// Duplo salvamento de distancias para garantir a pesquisa depois 
		    cidade[x][y] = d;
		    cidade[y][x] = d;
		}

	// ONDE ESTA A BOMBA
		printf("onde esta a bomba e seu raio: "); 
		scanf("%d %d",&bomb, &raio);
		cidade[bomb][bomb] = -1;

	// mostraMapa(cidade, ruas, loc);

		printf("Caso %d: ",k+1); 
		areasRiscos(cidade,loc,bomb,raio);
		printf("\n");
		k++;
	}

	return 0;	  
}