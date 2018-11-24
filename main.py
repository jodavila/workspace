#!/usr/bin/python
#coding: utf-8

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
# Realiza a leitura da quantidade de dispositivos dos campos e suas distancias
# Com base Monta a matriz com isso
#
def leitura_campus(campus_x):
#    print "Quantas dispositivos:"
    nDisp = int(raw_input()) 
    n = 0
    matriz=[]
    while n < nDisp:
 #       print "Lendo Dispositivo ",str(n+1)
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
  #  print "Quantos limitados"
    quantidade = int(raw_input()) 
    
#    print "Lista limitados"
    linha = raw_input() 
    
    linha = map(int, linha.split())
        
 #   if len(linha) == quantidade:
 #       print "ok"

    limitados_dict[str(campus_x)]=linha
    return None

def cria_Dict():
    for i in range(int(nCampus)):
        matrizes_dict[str(i+1)]=[]
        limitados_dict[str(i+1)]=[]
    return(matrizes_dict,limitados_dict)

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

#devolve a fila com os dispositivos ordenados
#de forma crescente conforme a sua chave na árvore
def reorganizaFila(Q, arvore):
    novoQ = []
    while Q:
        for i in Q:
            if all(arvore[j][1] >= arvore[i][1] for j in Q):
                novoQ.append(i)
                Q.remove(i)
    return novoQ

#retorna uma tabela representando a arvore geradora minima do grafo
#onde cada linha é m dispositivo, a primeira coluna é seu predecessor
#e a segunda a sua chave
def prim_AGM(matriz, lLimitados, arvore):
    Q = []

    #armazena em Q os indices dos dispositivos não limitados
    for v in range(len(matriz[0])):
        if (v+1) not in lLimitados:
            Q.append(v)

    r = Q[0];  # raiz é o primeiro dispositivo na fila
    arvore[r][1] = 0

    while Q:
        # retira da fila o dispositivo com menor chave
        # na árvore (sempre o primeiro)
        u = Q.pop(0)
        for v in range(len(matriz[u])):
            #para cada dispositivo, se custo(u,v) > chave(v)...
            if v in Q and matriz[v][u] < arvore[v][1]:
                #pred de v é u
                arvore[v][0] = u
                #chave de v é custo(u,v)
                arvore[v][1] = matriz[u][v]

                #reorganiza Q de forma crescente quanto à chave
                Q = reorganizaFila(Q, arvore)
    return arvore


# Soma o segundo valor do array
def peso(array):
    total = 0
    for i in range(len(array)):
        total = total + array[i][1]
    return total


## main

#print "Quantos campus:"
nCampus = raw_input()
cria_Dict()

for campus in range(int(nCampus)):
 #   print "Leitura campus",campus+1
    leitura_campus(campus+1)
  #  print "Limitados do campus",campus+1
    leitura_limitados(campus+1)

arvores_dict={}
for campus in range(int(nCampus)):
    arvores_dict[str(campus+1)] = prim_AGM(matrizes_dict[str(campus+1)], limitados_dict[str(campus+1)], prim_inicializacao(matrizes_dict[str(campus+1)],limitados_dict[str(campus+1)]))
    print "Campus " + str(campus+1) + ":" + " " + str(peso(arvores_dict[str(campus+1)]))
#    print arvores_dict[str(campus+1)]