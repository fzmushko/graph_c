#include "graph.h"
#include <stdio.h>

int main() {
    int n = 10;
    GRAPH_ERR err;
    graph *gr = NULL;
    gr = create_graph (0, &err);
    if (err != EINVARG) 
        fprintf (stdout, "Test_1_invalid_number_of_vertices failed\n");
    else 
        fprintf (stdout, "Test_1_invalid_number_of_vertices passed\n");
    gr = create_graph (n, &err);
    if (gr == NULL)
        fprintf (stdout, "Test_2_create_graph failed\n");
    else 
        fprintf (stdout, "Test_2_create_graph passed\n");
    remove_graph (NULL, &err);
    if (err != EINVARG)
        printf ("Test_3_remove_graph_NULL failed\n");
    else 
        printf ("Test_3_remove_graph_NULL passed\n");
    remove_graph (&gr, &err);
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4_remove_graph failed\n");
    else 
        fprintf (stdout, "Test_4_remove_graph passed\n");
    gr = NULL;
    remove_graph (&gr, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_5_remove_removed_graph failed\n");
    else 
        fprintf (stdout, "Test_5_remove_removed_graph passed\n");
    return 0;
}