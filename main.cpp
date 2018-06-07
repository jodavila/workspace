#include<stdio.h>

/*
  Nome da função: ..
  Objetivo: ..
  Entrada: ..
  Saida: .. 
*/

/*
tipo nome(parametros)
{
  intruções;
  retorno/
}
*/
/****************************************************************/

/*
  Nome da função: exibe
  Objetivo: Imprime na tela, uma lista de numeros
  Entrada: um vetor de inteiros
  Saida: uma string 
*/

void exibe(int lista[100])
{
	int i; 

	for ( i=0; lista[i]>0; i++ )
   		printf("%d ",lista[i]);

   printf("\n");
}
/****************************************************************/

/*
  Nome da função: mostraMapa
  Objetivo: Exibir a matriz na configuração localizacao - distancia entre - localizacao
  Entrada:	matriz(*)[100] - matriz quadrada no formato int de tamanho 100,
  			int r - quantidades de ruas,
  			int l - quantidade de localidades
  Saida: uma string
*/
void mostraMapa(int matriz[100][100], int r, int l)
{
	int i;
	int j;
	int peso;

	printf("exibindo cidade \n");
  	for ( i=0; i<r; i++ )
  		for ( j=0; j<l; j++ )
    	{
    		peso = matriz[i][j];
    		if (peso>0)
	       	printf ("%d - ( %d ) - %d\n", i,peso,j);
   		}
}

/****************************************************************/

/*
	Nome da função: areasRiscos
	Objetivo: Analizar o alcance do raio de destruição da bomba e
	identifcar quais os pontos precisam ser evacuados. 
	Entrada:	matriz quadrada de tamanho 100, 
				a quantidade de localidades,
	  			a localizacao da bomba,
	  			o alcance da bomba,
	Saida: um vetor 
*/
 
void areasRiscos(int matriz[100][100], int l, int bomba, int raio, int p)
{
	int i=0;
	int evc[100];
	int peso;
	int n; 

// adiciona a lista de evacuacao o loc ond a bomba esta
	evc[0] = bomba;

/*    
	Se distancia entre onde esta a bomba (bomb) e localidade (loc) 
    for menor ou igual ao raio então a localidade precisa ser evacuada
*/
   for ( i; i<l; i++ ){
   	peso = matriz[bomba][i];
    if (peso>0 && peso<=raio){
    	evc[n] = i;
    	n++;
    }
   }

/*
	percorrer o caminho de bomb a loc, se peso das arestas <= raio
	loc entra para lugares a ser evacuados
*/

/*
	chamar busca, e verificar a lista, 
   	-> se não estiver na lista inclui,
   	-> se estiver em frente
*/

   evc[n+1] = -1; // coloca um "fim" na lista

   // Ordenamento -> evc = radix(evc);
   // Exibicao da saida -> 
   exibe(evc);
   // exibicao ordenada (radix(evc));

}
/****************************************************************/
/*
  Nome da função: ..
  Objetivo: ..
  Entrada: ..
  Saida: .. 

  Procedimento radix SortLSD(A,D)
 
	// A: array de entrada
	// D: numero de digitos
*/

/*
void ordena(int lista[100],int x)
radix(int array[], int digitos)
{	
	int d;
	int dj;

	int B[100] = array;
	int C[100];


	for (d=digitos-1; d>0; d--)
	{
		// Counting Sort analisando d-esimo digito
		
		for (i=0; i<9; i++)
			C[i] = 0;

		for (i=1; i</*length(A)*/ //; i++)
/*		{
			dj = digito(A[j],d) ;
		
			C[dj] = C[dj] + 1 ;
		}
		
		for (i=0; i<9; i++)
			C[i] = C[i] + C[i−1];
		
		for (i=/*length(A)*///; i>1; i--)
/*		{
			dj = digito(A[j],d) ;
			B[C[dj]]=A[j];
			C[dj]= C[dj]− 1;
		}
		// Copia array auxiliar B de volta em A
		array = B; 
	}
// retorno??
}

*/

/****************************************************************/
int main()
{
	// Definições de todas as variaveis locais (do main) 
	int num = 0;	// total de teste
	int loc = 0;	// vertices - quantidade de localidades 
	int ruas = 0;	// arestas -- quantidade de ruas
  
	// Representação da rua: x <---(d)----> y
	// Uma rua = x,y,d.  onde
  	int x = 0;    // um dos extremos da rua
  	int y = 0;    // outro extremo da rua
  	int d = 0;    // valor/peso da aresta
  
  	// Informações da Bomba
  	int bomb = 0;	// A localidade da bomba é um valor entre 0 a loc
  	int raio = 0;	// Raio de destruição

	// Variaveis Auxiliares
  	int i = 0;
	int cidade[100][100];
  	int k = 0;

  	// Quantidade de Testes
	//printf("qtd testes:"); // deve ser excluido antes da entrega
	scanf("%d",&num);

	do{
		k++;
		// Leitura do Mapa
		//printf("qtd de localidade e ruas: "); // deve ser excluido antes da entrega
		scanf("%d%d",&loc, &ruas);
		  
		for (i; i < ruas; ++i)
		{
		    //printf("rua %d :",i+1); // deve ser excluido antes da entrega
			scanf("%d%d%d",&x, &y, &d);

			// Duplo salvamento de distancias para garantir a pesquisa depois 
		    cidade[x][y] = d;
		    cidade[y][x] = d;
		}

		  // ONDE ESTA A BOMBA
		//printf("onde esta a bomba e seu raio: "); // deve ser excluido antes da entrega
		scanf("%d%d",&bomb, &raio);
		cidade[bomb][bomb] = -1;

		printf("Caso %d: ",k); 
		areasRiscos(cidade,loc,bomb,raio,k);


	} while (k>num);

	return 0;	  
}