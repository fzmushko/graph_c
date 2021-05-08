#include "graph.h"
#include <stdio.h>

int main() {
    int n = 10;
    GRAPH_ERR err;
    graph *gr = NULL;
    gr = create_graph (0, &err);
    if (err != EINVARG) 
        fprintf (stdout, "Test_1_invalid_number_of_vertices\tfailed\n");
    else 
        fprintf (stdout, "Test_1_invalid_number_of_vertices\tpassed\n");
    gr = create_graph (n, &err);
    if (gr == NULL)
        fprintf (stdout, "Test_2_create_graph\t failed\n");
    else 
        fprintf (stdout, "Test_2_create_graph\t passed\n");
    remove_graph (NULL, &err);
    if (err != EINVARG)
        printf ("Test_3_remove_graph_NULL\t failed\n");
    else 
        printf ("Test_3_remove_graph_NULL\t passed\n");
    remove_graph (&gr, &err);
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4_remove_graph\t failed\n");
    else 
        fprintf (stdout, "Test_4_remove_graph\t passed\n");
    gr = NULL;
    remove_graph (&gr, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_5_remove_removed_graph\t failed\n");
    else 
        fprintf (stdout, "Test_5_remove_removed_graph\t passed\n");
    gr = create_graph (n, &err);
    if (gr == NULL)
        fprintf (stdout, "Test_2_create_graph\t failed\n");
    else 
        fprintf (stdout, "Test_2_create_graph\t passed\n");
    print_graph (gr, &err);
    




    remove_graph (&gr, &err);
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4_remove_graph\t failed\n");
    else 
        fprintf (stdout, "Test_4_remove_graph\t passed\n");
    return 0;
}