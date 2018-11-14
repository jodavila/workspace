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
        

## main
#inicializacao()


print "qtd campus"
nCampus = raw_input()

print "leitura campus"
leitura_campus()

print "limitados"
leitura_limitados()

