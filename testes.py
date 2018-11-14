#!/usr/bin/python
#coding: utf-8

__author__ = "43133"  
__status__ = "Development" 
__date__   = "06/11/2018 21:37:03"

def NaLista(lista,vertice, valor):
    if valor in lista[vertice] :
       return True
    else:
       return False

# variaveis
nLimitados = 0
lLimitados = []
nCampus = 0
nDisp = 0
linha = 0
matriz = []

matriz.append([1,2,3,4])
matriz.append([5,6,7,8])
matriz.append([9,10,11,12])


"""
if NaLista(matriz,linha,valor) == True:
    #resultado se true
else:
    #resultado se falso
"""

