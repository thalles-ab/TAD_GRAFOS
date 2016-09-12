//
// Created by Thalles Batista on 11/09/16.
//
#define DEBUG 1
#define MAX 5

#include "list.h"

typedef char *TipoG;

typedef struct {
    TipoG info;
    int marca;
} Vertice;

typedef struct {
    int **arcos;
    Vertice *vertices;
    int numElem;
} TGrafo, *Grafo;

void checkGrapValid(Grafo grafo);

void checkPosValidVertices(Grafo g, int x1, int x2);

Grafo inicGrafo();

void insGrafo(Grafo g, TipoG elem);

void insArco(Grafo g, int x1, int x2, int c);

void elimArco(Grafo g, int x1, int x2);

int custoArco(Grafo g, int x1, int x2);

Node sucessores(Grafo g, int v);

TipoG infoVertice(Grafo g, int v);

int ordemGrafo(Grafo g);

void destruirGrafo(Grafo g);

Grafo carregarGrafo(FILE *fp);

void salvarGrafo(Grafo g, FILE *fp);

void marcarVertice(Grafo g, int v);

void desmarcarVertice(Grafo g, int v);

void desmarcarGrafo(Grafo g);

int marcadoVertice(Grafo g, int v);

int existeCaminho(Grafo g, int x1, int x2);