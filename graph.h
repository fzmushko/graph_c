#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct vertex {
    int *adjacent_vertices;
    int value;
} vertex;

typedef struct graph {
    vertex *key;
    int number_of_vertices;
} graph;

typedef enum {
    ESUCCESS = 0,
    EINVARG,
    EEXIST,
    ENEXIST,
    EMALLOC
} GRAPH_ERR;

graph *create_graph (int n, GRAPH_ERR *err);

void remove_graph (graph **gr, GRAPH_ERR *err);

void print_graph (graph *gr, GRAPH_ERR *err);

void add_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err);

/*
void add_or_replace_edge (int u, int v, int cost, GRAPH_ERR *err);

void remove_edge (int u, int v, GRAPH_ERR *err);

int edge_cost (int u, int v, GRAPH_ERR *err);

void add_value (int u, int vl, GRAPH_ERR *err);

void add_or_replace_value (int u, int vl, GRAPH_ERR *err);

int vertex_value (int u, GRAPH_ERR *err);

void remove_value (int i, GRAPH_ERR *err);
*/

#endif