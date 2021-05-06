#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

const int vertex_without_value = 1000000007;

graph *create_graph (int n, GRAPH_ERR *err) {
    if (n < 1) {
        fprintf (stderr, "Invalid argument: number of vertices\n");
        if (err != NULL) 
            *err = EINVARG;
        return NULL;
    }
    graph *gr = (graph *)malloc(sizeof(graph));
    if (gr == NULL) {
        fprintf (stderr, "Not enough memory\n");
        if (err != NULL)
            *err = EMALLOC;
        return NULL;
    }
    gr->number_of_vertices = n;
    gr->vertices = (vertex *)malloc(n*sizeof(vertex));
    if (gr->vertices == NULL) {
        fprintf (stderr, "Not enough memory\n");
        if (err != NULL)
            *err = EMALLOC;
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        gr->vertices[i].arr = (int *)calloc(n, sizeof(int));
        if (gr->vertices[i].arr == NULL) {
            fprintf (stderr, "Not enough memory\n");
            if (err != NULL)
                *err = EMALLOC;
            return NULL;
        }
        gr->vertices[i].value = vertex_without_value;
    }
    if (err != NULL)
        *err = ESUCCESS;
    return gr;
}

void remove_graph (graph **gr, GRAPH_ERR *err) {
    if (gr == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    if ((*gr) == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    for (int i = 0; i < (*gr)->number_of_vertices; i++) {
        if ((*gr)->vertices[i].arr)
            free ((*gr)->vertices[i].arr);
    }
    free ((*gr)->vertices);
    free (*gr);
    *gr = NULL;
    *err = ESUCCESS;
    return;
}