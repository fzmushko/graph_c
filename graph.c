#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

const int vertex_without_value = -1;

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
    if (err != NULL)
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
    if (err != NULL)
        *err = ESUCCESS;
    return;
}

int edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err, _Bool true_if_add, _Bool true_if_replace_or_remove) {
    if (gr == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (from < 0 || from >= gr->number_of_vertices) {
        fprintf (stderr, "Invalid argument: vertex 'from'\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (to < 0 || to >= gr->number_of_vertices) {
        fprintf (stderr, "Invalid argument: vertex 'to'\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (from == to) {
        fprintf (stderr, "Invalid argument: loops are not allowed\n");
        if (err != NULL)
            *err = EINVARG;
        return -1;
    }
    if (cost < 1) {
        fprintf (stderr, "Invalid argument: cost of edge should be more than 0\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (true_if_add) {
        if (true_if_replace_or_remove) {
            gr->key[from].adjacent_vertices[to] = cost;
            if (err != NULL)
                *err = ESUCCESS;
        }
        else {
            if (gr->key[from].adjacent_vertices[to] == 0) {
                if (err != NULL)
                    *err = ESUCCESS;
                gr->key[from].adjacent_vertices[to] = cost;
            }
            else {
                fprintf (stdout, "The edge already exists\n");
                if (err != NULL)
                    *err = EEXIST;
                return -1;
            } 
        }
        return 0;
    }
    else {
        if (true_if_replace_or_remove) {
            gr->key[from].adjacent_vertices[to] = 0;
            if (err != NULL)
                *err = ESUCCESS;
            return 0;
        }
        else {
            if (gr->key[from].adjacent_vertices[to] == 0) {
                fprintf (stdout, "The edge doesn't exists\n");
                if (err != NULL)
                    *err = ENEXIST;
                return 0;
            }
            else {
                if (err != NULL)
                    *err = ESUCCESS;
                return gr->key[from].adjacent_vertices[to];
            }
        }
    }
    return 0;
}

void add_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err) {
    int x = edge (gr, from, to, cost, err, 1, 0);
    return;
}

void add_or_replace_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err) {
    int x = edge (gr, from, to, cost, err, 1, 1);
    return;
}

void remove_edge (graph *gr, int from, int to, GRAPH_ERR *err) {
    int x = edge (gr, from, to, 1, err, 0, 1);
    return;
}

int edge_cost (graph *gr, int from, int to, GRAPH_ERR *err) {
    return edge (gr, from, to, 1, err, 0, 0);
}

int value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err, _Bool true_if_add, _Bool true_if_replace_or_remove) {
    if (gr == NULL) {
        fprintf (stderr, "Invalid argument: graph\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (vertex_key < 0 || vertex_key >= gr->number_of_vertices) {
        fprintf (stderr, "Invalid argument: vertex key\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (recieved_value < 0) {
        fprintf (stderr, "Invalid argument: value should be 0 or more\n");
        if (err != NULL) 
            *err = EINVARG;
        return -1;
    }
    if (true_if_add) {
        if (!true_if_replace_or_remove && gr->key[vertex_key].value != -1) {
            fprintf (stdout, "The value already exists\n");
            if (err != NULL)
                *err = EEXIST;
            return -1;
        }
        else {
            gr->key[vertex_key].value = recieved_value;
            if (err != NULL)
                *err = ESUCCESS;
            return 0;
        }
    }


    return 0;
}

void add_value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err) {
    int x = value (gr, vertex_key, recieved_value, err, 1, 0);
    return;
}

void add_or_replace_value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err) {
    int x = value (gr, vertex_key, recieved_value, err, 1, 1);
    return;
}