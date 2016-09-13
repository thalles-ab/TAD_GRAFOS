//
// Created by Thalles Batista on 11/09/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"

Node inicNode() {
    Node list = (Node) malloc(sizeof(Node));
    list->info = -1;
    list->prox = NULL;
    return list;
}

void anxLista(Node lst, TipoL elem) {
    if (lst == NULL) {
        return;
    }

    if (lst->info == -1) {
        lst->info = elem;
        return;
    }

    if (lst->prox == NULL) {
        lst->prox = inicNode();
        lst->prox->info = elem;
        return;
    }

    anxLista(lst->prox, elem);
}

void printList(Node root) {
    if (root == NULL) {
        printf("\n");
        return;
    }

    printf("\nindice %i", root->info);
    printList(root->prox);
}