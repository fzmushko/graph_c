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
    gr->key = (vertex *)malloc(n*sizeof(vertex));
    if (gr->key == NULL) {
        fprintf (stderr, "Not enough memory\n");
        if (err != NULL)
            *err = EMALLOC;
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        gr->key[i].adjacent_vertices = (int *)calloc(n, sizeof(int));
        if (gr->key[i].adjacent_vertices == NULL) {
            fprintf (stderr, "Not enough memory\n");
            if (err != NULL)
                *err = EMALLOC;
            return NULL;
        }
        gr->key[i].value = vertex_without_value;
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
        if ((*gr)->key[i].adjacent_vertices)
            free ((*gr)->key[i].adjacent_vertices);
    }
    free ((*gr)->key);
    free (*gr);
    *gr = NULL;
    *err = ESUCCESS;
    return;
}

void print_graph (graph *gr, GRAPH_ERR *err) {
    if (gr == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    fprintf (stdout, " \t");
    for (int i = 0; i < gr->number_of_vertices; i++)
        fprintf (stdout, "%d\t", i);
    fprintf (stdout, "\n");
    for (int i = 0; i < gr->number_of_vertices; i++) {
        fprintf (stdout, "%d\t", i);
        for (int j = 0; j < gr->number_of_vertices; j++)
            fprintf (stdout, "%d\t", gr->key[i].adjacent_vertices[j]);
        fprintf (stdout, "\n");
    }
    for (int i = 0; i < gr->number_of_vertices; i++)
        fprintf (stdout, "%d\t%d\n", i, gr->key[i].value);
    *err = ESUCCESS;
    return;
}

void add_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err) {
    if (gr == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    if (from < 0 || from >= gr->number_of_vertices) {
        fprintf (stderr, "Invalid argument: vertex 'from'\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    if (to < 0 || to >= gr->number_of_vertices) {
        fprintf (stderr, "Invalid argument: vertex 'to'\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    if (from == to) {
        fprintf (stderr, "Invalid argument: loops are not allowed\n");
        if (err != NULL)
            *err = EINVARG;
        return;
    }
    if (gr->key[from].adjacent_vertices[to] != 0) {
        fprintf (stderr, "The edge already exists\n");
        if (err != NULL) 
            *err = EEXIST;
        return;
    }
    if (cost < 1) {
        fprintf (stderr, "Invalid argument: cost of edge should be more than 0\n");
        if (err != NULL) 
            *err = EINVARG;
        return;
    }
    gr->key[from].adjacent_vertices[to] = cost;
    *err = ESUCCESS;
    return;
}

