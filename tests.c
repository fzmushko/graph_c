#include "graph.h"
#include <stdio.h>

int main() {
    int n = 5;
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
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6_print_graph\t failed\n");
    else
        fprintf (stdout, "Test_6_print_graph\t passed\n");
    



    add_edge (NULL, 0, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_7_add_edge_to_NULL_graph\t failed\n");
    else
        fprintf (stdout, "Test_7_add_edge_to_NULL_graph\t passed\n");
    err = ESUCCESS;
    add_edge (gr, -1, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_8_add_edge_from_<_0\t failed\n");
    else
        fprintf (stdout, "Test_8_add_edge_from_<_0\t passed\n");
    err = ESUCCESS;
    add_edge (gr, n, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_9_add_edge_from_>_n\t failed\n");
    else
        fprintf (stdout, "Test_9_add_edge_from_>_n\t passed\n");
    err = ESUCCESS;
    add_edge (gr, 0, -1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_10_add_edge_to_<_0\t failed\n");
    else
        fprintf (stdout, "Test_10_add_edge_to_<_0\t passed\n");
    err = ESUCCESS;
    add_edge (gr, 0, n, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_11_add_edge_to_>_n\t failed\n");
    else
        fprintf (stdout, "Test_11_add_edge_to_>_n\t passed\n");
    err = ESUCCESS;
    add_edge (gr, 0, 0, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_12_add_edge_loop\t failed\n");
    else
        fprintf (stdout, "Test_12_add_edge_loop\t passed\n");
    err = ESUCCESS;
    add_edge (gr, 0, 1, 0, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_13_add_edge_cost_<_1\t failed\n");
    else
        fprintf (stdout, "Test_13_add_edge_cost_<_1\t passed\n");
    add_edge  (gr, 0, 1, 2, &err);
    if (err != ESUCCESS)
        fprintf (stdout, "Test_14_add_edge\t failed\n");
    else
        fprintf (stdout, "Test_14_add_edge\t passed\n");
    add_edge (gr, 0, 1, 3, &err);
    if (err != EEXIST)
        fprintf (stdout, "Test_15_add_edge_already_exists\t failed\n");
    else
        fprintf (stdout, "Test_15_add_edge_already_exists\t passed\n");
    

    print_graph (gr, &err);
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6_print_graph\t failed\n");
    else
        fprintf (stdout, "Test_6_print_graph\t passed\n");
    



    add_or_replace_edge (NULL, 0, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_16_add_or_replace_edge_to_NULL_graph\t failed\n");
    else
        fprintf (stdout, "Test_16_add_or_replace_edge_to_NULL_graph\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, -1, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_17_add_or_replace_edge_from_<_0\t failed\n");
    else
        fprintf (stdout, "Test_17_add_or_replace_edge_from_<_0\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, n, 1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_18_add_or_replace_edge_from_>_n\t failed\n");
    else
        fprintf (stdout, "Test_18_add_or_replace_edge_from_>_n\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, -1, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_19_add_or_replace_edge_to_<_0\t failed\n");
    else
        fprintf (stdout, "Test_19_add_or_replace_edge_to_<_0\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, n, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_20_add_or_replace_edge_to_>_n\t failed\n");
    else
        fprintf (stdout, "Test_20_add_or_replace_edge_to_>_n\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, 0, 2, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_21_add_or_replace_edge_loop\t failed\n");
    else
        fprintf (stdout, "Test_21_add_or_replace_edge_loop\t passed\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, 1, 0, &err);
    if (err != EINVARG)
        fprintf (stdout, "Test_22_add_or_replace_edge_cost_<_1\t failed\n");
    else
        fprintf (stdout, "Test_22_add_or_replace_edge_cost_<_1\t passed\n");
    add_or_replace_edge  (gr, 0, 2, 2, &err);
    if (err != ESUCCESS)
        fprintf (stdout, "Test_23_add_or_replace_edge\t failed\n");
    else
        fprintf (stdout, "Test_23_add_or_replace_edge\t passed\n");
    add_or_replace_edge (gr, 0, 2, 3, &err);
    if (err != ESUCCESS)
        fprintf (stdout, "Test_24_add_edge_already_exists\t failed\n");
    else
        fprintf (stdout, "Test_24_add_edge_already_exists\t passed\n");


    print_graph (gr, &err);
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6_print_graph\t failed\n");
    else
        fprintf (stdout, "Test_6_print_graph\t passed\n");




    remove_graph (&gr, &err);
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4_remove_graph\t failed\n");
    else 
        fprintf (stdout, "Test_4_remove_graph\t passed\n");
    return 0;
}