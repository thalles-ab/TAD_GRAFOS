//
// Created by Thalles Batista on 04/09/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "src/headers/graph.h"

int main(int argc, char **argv) {

    Grafo grafo = NULL;
    FILE *fp = NULL;

    grafo = carregarGrafo(fp);
//
//    grafo = inicGrafo();
//    for (int i = 0; i < MAX; i++) {
//        char *c = NULL;
//        c = (char *) calloc(5, sizeof(char));
//        sprintf(c, "A-%i", i);
//        insGrafo(grafo, c);
//    }
//
//    insArco(grafo, 0, 1, 2);
//    insArco(grafo, 0, 4, 4);
//    insArco(grafo, 1, 2, 3);
//    insArco(grafo, 1, 5, 3);
//    insArco(grafo, 5, 4, 3);
//    insArco(grafo, 2, 3, 3);
//    insArco(grafo, 2, 4, 3);
//    //insArco(grafo, 3, 4, 3);
//    //insArco(grafo, 4, 0, 3);
//    //insArco(grafo, 2, 1, 3);
//
    if (DEBUG) {
        int i, j;
        for (i = 0; i < MAX; i++) {
            printf("\n");
            for (j = 0; j < MAX; j++) {
                printf("%i\t", grafo->arcos[i][j]);
            }
        }
        printf("\n");
    }
//
//
//    //printList(sucessores(grafo, 0));
//
//
//    printf("\n%i", existeCaminho(grafo, 0, 0));
//    printf("\n%i", existeCaminho(grafo, 0, 4));
//
//
//    printf("\n\n***** CAMINHOS DE 0 A 4\n");
    exibeCaminhos(grafo, 0, 4);
//
//    // SALVA O ARQUIVO
//    char *nameFile = "data/output_graph.txt";
//    if (remove(nameFile) != 0 && DEBUG) {
//        printf("\n\nERRO AO APAGAR ARQUIVO %s\n", nameFile);
//    }
//    fp = fopen(nameFile, "wb+");
//    salvarGrafo(grafo, fp);

    return 0;
}
