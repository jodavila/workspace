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


int main()
{
  // Definições de todas as variaveis locais (do main)
  // total de teste
  int num = 0;  
  // vertices - quantidade de localidades 
  int loc = 0;  
  // arestas -- quantidade de ruas
  int ruas = 0;  
  
  // Representação da rua: x <---(d)----> y
  // Uma rua = x,y,d.  onde
  int x = 0;    // um dos extremos da rua
  int y = 0;    // outro extremo da rua
  int d = 0;    // valor/peso da aresta
  
  int bomb = 0;  // A localidade da bomba é um valor entre 0 a loc
  int raio = 0; // Raio de destruição

  // Quantidade de Testes
  printf("qtd testes: \n"); // deve ser excluido antes da entrega
  scanf("%d",&num);

  // A leitura do mapa ate onde esta a bomba deve ser lido num vezes 

  // Leitura do Mapa
  printf("qtd de localidade e ruas: \n"); // deve ser excluido antes da entrega
  scanf("%d%d",&loc, &ruas);
  
  for (int i = 0; i < ruas; ++i)
  {
    printf(" rua %d : \n",i+1); // deve ser excluido antes da entrega
    scanf("%d%d%d",&x, &y, &d);

    // salvar essa informação como ??
  }

  // ONDE ESTA A BOMBA
  printf("onde esta a bomba: \n"); // deve ser excluido antes da entrega
  scanf("%d%d",&bomb, &raio);

  //Salvando as pessoas
  
  /*
    Se distancia entre onde esta a bomba (bomb) e localidade (loc) 
    for menor ou igual ao raio então a localidade precisa ser evacuada

      -> percorrer o caminho de bomb a loc, se peso das arestas <= raio,
         loc entra para lugares a ser evacuados

  */

  return 0;
  
}