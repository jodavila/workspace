#!/usr/bin/python
#coding: utf-8

__author__ = "43133"  
__status__ = "Development" 
__date__   = "06/11/2018 21:37:03"

## funções
#def inicializacao():
nLimitados = 0
lLimitados = []
nCampus = 0
nDisp = 0
linha = 0
matriz = []

#
# Realiza a leitura da qtd de dispositivos dos campos e suas distancias
# Monta a matriz com isso
#
def leitura_campus():
    print "quantas linhas"
    nDisp = int(raw_input()) 
    n = 0
    while n < nDisp:
        print "lendo linha ",str(n)
        #leitura de uma string com os numeros
        linha = raw_input() 
        
        #transforma a string em uma lista de numeros
        linha = map(int, linha.split())
        
        #para cada linha lida, adiciona ela na matriz
        matriz.append(linha)
        
        n = n + 1

    return matriz


def leitura_limitados():
    print "quantos limitados"
    quantidade = int(raw_input()) 
    
    print "lista limitados"
    linha = raw_input() 
    
    linha = map(int, linha.split())
        
    if len(linha) == quantidade:
        print "ok"
    
    return linha

#
# if NaLista(matriz,linha,valor) == True:
#     resultado se true
# else:
#     resultado se falso
# 

def NaLista(lista,vertice, valor):
    if valor in lista[vertice] :
       return True
    else:
       return False

#inicializa matriz nDisp x 2 onde cada linha é um dispositivo
#a primeira coluna é o indice do pred do dispositivo na matriz
#e a segunda a sua chave
def prim_inicializacao(matriz, lLimitados):
    arvore = []
    n = 0
    #percorre todos os n dispositivos
    while n < len(matriz[0]):
        #se n for limitado precisa setar o pred mais barato
        if((n + 1) in lLimitados):
            lChave = float("inf")
            # percorre toda a linha do dispositivo n procurando a
            # conexão mais barata com um não-limitado
            for i in range(len(matriz[n])):
                if matriz[n][i] <= lChave and (i + 1) not in lLimitados:
                    lPred = i
                    lChave = matriz[n][i]
            arvore.append([lPred, lChave])
        #se não faz inicialização normal
        else:
            arvore.append([float("NaN") , float("inf")])
        n += 1
    return arvore
## main
#inicializacao()


print "qtd campus"
nCampus = raw_input()

print "leitura campus"
matriz = leitura_campus()

print "limitados"
lLimitados = leitura_limitados()

arvore = prim_inicializacao(matriz, lLimitados)
print "inicialização:" , arvore