//
// Created by Thalles Batista on 11/09/16.
//

typedef int TipoL;
typedef struct ListaNo {
    TipoL info;
    struct ListaNo *prox;
} * Node;

Node inicNode();

void anxLista(Node lst, TipoL elem);

void printList(Node root);
