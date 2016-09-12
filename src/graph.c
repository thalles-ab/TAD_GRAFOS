//
// Created by Thalles Batista on 11/09/16.
//

#include <stdlib.h>
#include <stdio.h>
#include "headers/graph.h"

void checkGrapValid(Grafo grafo) {
    if (grafo == NULL) {
        printf("\n**** ERROR ****");
        printf("\n**** VOCÊ ESTÁ TENTANDO MANIPULAR UM GRAFO INVÁLIDO(NULO) ****");
        exit(0);
    }
}

void checkPosValidVertices(Grafo g, int x1, int x2) {
    if (x1 >= MAX || x2 >= MAX) {
        printf("\n**** ERROR ****");
        printf("\nVocê tentou acessar uma aresta inexistente!!!");
        printf("\nO NÚMERO LIMITE DE ARESTAS É %i", MAX);
        exit(0);
    }
    if (x1 > g->numElem || x2 > g->numElem) {
        printf("\n**** ATENÇÃO ****");
        printf("\nVocê está manipulando arestas cujo os vertices ainda não existem");
    }
}

Grafo inicGrafo() {
    Grafo graph = (Grafo) malloc(sizeof(TGrafo));
    graph->vertices = (Vertice *) calloc(MAX, (sizeof(Vertice)));
    graph->arcos = (int **) calloc(MAX, sizeof(int *));
    graph->numElem = 0;

    int i, j;
    for (i = 0; i < MAX; i++) {
        graph->arcos[i] = (int *) calloc(MAX, sizeof(int *));
        for (j = 0; j < MAX; j++) {
            graph->arcos[i][j] = -1;
        }
    }

    return graph;
}

void insGrafo(Grafo g, TipoG elem) {
    checkGrapValid(g);
    if (g->numElem == MAX) {
        printf("\n\n\tTODAS AS %i POSIÇÕES JÁ FORAM PREENCHIDAS **** \n\tNão é possível adicionar novos vertices",
               MAX);
        return;
    }

    g->vertices[g->numElem++] = (Vertice) {.info = elem, .marca = 0};
}

void insArco(Grafo g, int x1, int x2, int c) {
    checkGrapValid(g);
    checkPosValidVertices(g, x1, x2);

    g->arcos[x1][x2] = c;
}

void elimArco(Grafo g, int x1, int x2) {
    checkGrapValid(g);
    checkPosValidVertices(g, x1, x2);

    g->arcos[x1][x2] = -1;
}

int custoArco(Grafo g, int x1, int x2) {
    checkPosValidVertices(g, x1, x2);
    return g->arcos[x1][x2];
}

Node sucessores(Grafo g, int v) {
    Node root = inicNode();

    for (int i = 0; i < MAX; i++) {
        int valArc = g->arcos[v][i];
        if (valArc != -1) {
            anxLista(root, i);
        }
    }

    if (root->info == -1) {
        return NULL;
    }

    return root;
}


TipoG infoVertice(Grafo g, int v) {
    checkGrapValid(g);
    if (v >= g->numElem) {
        printf("\n**** ATENÇÃO **** ");
        printf("\nVOCÊ ESTÁ BUSCANDO POR UMA INFORMAÇÃO ASSOCIADA DE UM VERTICE QUE AINDA NÃO EXISTE POR ISSO SEU VALOR SERÁ NULO");
    }

//    if (DEBUG) {
//        printf("\n*** VERTICES EXISTENTES");
//        for (int i = 0; i < g->numElem; i++) {
//            printf("\n%s", g->vertices[i].info);
//        }
//        printf("\n\n");
//    }

    return g->vertices[v].info;
}

int ordemGrafo(Grafo g) {
    checkGrapValid(g);
    return g->numElem;
}

void destruirGrafo(Grafo g) {
    if (g == NULL) {
        return;
    }

    free(g);
}

void salvarGrafo(Grafo g, FILE *fp) {
    fprintf(fp, "%i\n", ordemGrafo(g));
    for (int i = 0; i < MAX; i++) {
        fprintf(fp, "%s\n", infoVertice(g, i));
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int custo = custoArco(g, i, j);
            if (custo != -1) {
                fprintf(fp, "%i\t%i\t%i\n", i, j, custo);
            }
        }
    }
    fprintf(fp, "-1\t-1\t-1");
    fclose(fp);
}

void marcarVertice(Grafo g, int v) {
    g->vertices[v].marca = 1;
}

void desmarcarVertice(Grafo g, int v) {
    g->vertices[v].marca = 0;
}

void desmarcarGrafo(Grafo g) {
    for (int i = 0; i < MAX; i++) {
        desmarcarVertice(g, i);
    }
}

int marcadoVertice(Grafo g, int v) {
    return g->vertices[v].marca == 1;
}

int existeCaminho(Grafo g, int x1, int x2) {
    if (g->arcos[x1][x2] != -1) {
        return 1;
    }

    marcarVertice(g, x1);
    Node root = sucessores(g, x1);
    while (root != NULL) {
        if (marcadoVertice(g, root->info) == 0 && existeCaminho(g, root->info, x2) == 1) {
            desmarcarGrafo(g);
            return 1;
        }
        root = root->prox;
    }
    desmarcarVertice(g, x1);
    return 0;
}