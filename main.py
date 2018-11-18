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
matrizes_dict={}
limitados_dict={}

#
# Realiza a leitura da qtd de dispositivos dos campos e suas distancias
# Monta a matriz com isso
#
def leitura_campus(campus_x):
    print "Quantas dispositivos:"
    nDisp = int(raw_input()) 
    n = 0
    matriz=[]
    while n < nDisp:
        print "Lendo Dispositivo ",str(n+1)
        #leitura de uma string com os numeros
        linha = raw_input() 
        
        #transforma a string em uma lista de numeros
        linha = map(int, linha.split())
        
        #para cada linha lida, adiciona ela na matriz
        matriz.append(linha)
        
        n = n + 1
    
    matrizes_dict[str(campus_x)]=matriz
    return (None)

######################################################################

def leitura_limitados(campus_x):
    print "Quantos limitados"
    quantidade = int(raw_input()) 
    
    print "Lista limitados"
    linha = raw_input() 
    
    linha = map(int, linha.split())
        
    if len(linha) == quantidade:
        print "ok"
        
    limitados_dict[str(campus_x)]=linha
    return None

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

def cria_Dict():
    for i in range(int(nCampus)):
        matrizes_dict[str(i+1)]=[]
        limitados_dict[str(i+1)]=[]
    return(matrizes_dict,limitados_dict)

## main
#inicializacao()

print "Quantos campus:"
nCampus = raw_input()
cria_Dict()

for campus in range(int(nCampus)):
    print "Leitura campus",campus+1
    leitura_campus(campus+1)
    print "Limitados do campus",campus+1
    leitura_limitados(campus+1)
