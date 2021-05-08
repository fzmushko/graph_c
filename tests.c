#include "graph.h"
#include <stdio.h>

int main() {
    int n = 5;
    GRAPH_ERR err;
    graph *gr = NULL;
    gr = create_graph (0, &err);
    fprintf (stdout, "Test_1_invalid_number_of_vertices:\n");
    if (err != EINVARG) 
        fprintf (stdout, "Test_1\tfailed\n\n");
    else 
        fprintf (stdout, "Test_1\tpassed\n\n");
    gr = create_graph (n, &err);
    fprintf (stdout, "Test_2_create_graph:\n");
    if (gr == NULL)
        fprintf (stdout, "Test_2\t failed\n\n");
    else 
        fprintf (stdout, "Test_2\t passed\n\n");
    
    
    
    
    remove_graph (NULL, &err);
    fprintf (stdout, "Test_3_remove_graph_NULL: \n");
    if (err != EINVARG)
        fprintf (stdout, "Test_3\t failed\n\n");
    else 
        fprintf (stdout, "Test_3\t passed\n\n");
    remove_graph (&gr, &err);
    fprintf (stdout, "Test_4_remove_graph:\n");
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4\t failed\n\n");
    else 
        fprintf (stdout, "Test_4\t passed\n\n");
    gr = NULL;
    remove_graph (&gr, &err);
    fprintf (stdout, "Test_5_remove_removed_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_5\t failed\n\n");
    else 
        fprintf (stdout, "Test_5\t passed\n\n");
    
    
    gr = create_graph (n, &err);
    fprintf (stdout, "Test_2_create_graph:\n");
    if (gr == NULL)
        fprintf (stdout, "Test_2\t failed\n\n");
    else 
        fprintf (stdout, "Test_2\t passed\n\n");
    



    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");
    



    add_edge (NULL, 0, 1, 2, &err);
    fprintf (stdout, "Test_7_add_edge_to_NULL_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_7\t failed\n\n");
    else
        fprintf (stdout, "Test_7\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, -1, 1, 2, &err);
    fprintf (stdout, "Test_8_add_edge_from_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_8\t failed\n\n");
    else
        fprintf (stdout, "Test_8\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, n, 1, 2, &err);
    fprintf (stdout, "Test_9_add_edge_from_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_9\t failed\n\n");
    else
        fprintf (stdout, "Test_9\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, 0, -1, 2, &err);
    fprintf (stdout, "Test_10_add_edge_to_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_10\t failed\n\n");
    else
        fprintf (stdout, "Test_10\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, 0, n, 2, &err);
    fprintf (stdout, "Test_11_add_edge_to_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_11\t failed\n\n");
    else
        fprintf (stdout, "Test_11\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, 0, 0, 2, &err);
    fprintf (stdout, "Test_12_add_edge_loop:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_12\t failed\n\n");
    else
        fprintf (stdout, "Test_12\t passed\n\n");
    err = ESUCCESS;
    add_edge (gr, 0, 1, 0, &err);
    fprintf (stdout, "Test_13_add_edge_cost_<_1:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_13\t failed\n\n");
    else
        fprintf (stdout, "Test_13\t passed\n\n");
    add_edge  (gr, 0, 1, 2, &err);
    fprintf (stdout, "Test_14_add_edge:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_14\t failed\n\n");
    else
        fprintf (stdout, "Test_14\t passed\n\n");
    add_edge (gr, 0, 1, 3, &err);
    fprintf (stdout, "Test_15_add_edge_already_exists:\n");
    if (err != EEXIST)
        fprintf (stdout, "Test_15\t failed\n\n");
    else
        fprintf (stdout, "Test_15\t passed\n\n");
    

    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");
    



    add_or_replace_edge (NULL, 0, 1, 2, &err);
    fprintf (stdout, "Test_16_add_or_replace_edge_to_NULL_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_16\t failed\n\n");
    else
        fprintf (stdout, "Test_16\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, -1, 1, 2, &err);
    fprintf (stdout, "Test_17_add_or_replace_edge_from_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_17\t failed\n\n");
    else
        fprintf (stdout, "Test_17\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, n, 1, 2, &err);
    fprintf (stdout, "Test_18_add_or_replace_edge_from_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_18\t failed\n\n");
    else
        fprintf (stdout, "Test_18\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, -1, 2, &err);
    fprintf (stdout, "Test_19_add_or_replace_edge_to_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_19\t failed\n\n");
    else
        fprintf (stdout, "Test_19\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, n, 2, &err);
    fprintf (stdout, "Test_20_add_or_replace_edge_to_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_20\t failed\n\n");
    else
        fprintf (stdout, "Test_20\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, 0, 2, &err);
    fprintf (stdout, "Test_21_add_or_replace_edge_loop:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_21\t failed\n\n");
    else
        fprintf (stdout, "Test_21\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_edge (gr, 0, 1, 0, &err);
    fprintf (stdout, "Test_22_add_or_replace_edge_cost_<_1:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_22\t failed\n\n");
    else
        fprintf (stdout, "Test_22\t passed\n\n");
    add_or_replace_edge  (gr, 0, 2, 2, &err);
    fprintf (stdout, "Test_23_add_or_replace_edge:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_23\t failed\n\n");
    else
        fprintf (stdout, "Test_23\t passed\n\n");
    add_or_replace_edge (gr, 0, 2, 3, &err);
    fprintf (stdout, "Test_24_add_or_replace_edge_already_exists:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_24\t failed\n\n");
    else
        fprintf (stdout, "Test_24\t passed\n\n");


    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");




    remove_edge (NULL, 0, 1, &err);
    fprintf (stdout, "Test_25_remove_edge_to_NULL_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_25\t failed\n\n");
    else
        fprintf (stdout, "Test_25\t passed\n\n");
    err = ESUCCESS;
    remove_edge (gr, -1, 1, &err);
    fprintf (stdout, "Test_26_remove_edge_from_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_26\t failed\n\n");
    else
        fprintf (stdout, "Test_26\t passed\n\n");
    err = ESUCCESS;
    remove_edge (gr, n, 1, &err);
    fprintf (stdout, "Test_27_remove_edge_from_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_27\t failed\n\n");
    else
        fprintf (stdout, "Test_27\t passed\n\n");
    err = ESUCCESS;
    remove_edge (gr, 0, -1, &err);
    fprintf (stdout, "Test_28_remove_edge_to_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_28\t failed\n\n");
    else
        fprintf (stdout, "Test_28\t passed\n\n");
    err = ESUCCESS;
    remove_edge (gr, 0, n, &err);
    fprintf (stdout, "Test_29_remove_edge_to_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_29\t failed\n\n");
    else
        fprintf (stdout, "Test_29\t passed\n\n");
    err = ESUCCESS;
    remove_edge (gr, 0, 0, &err);
    fprintf (stdout, "Test_30_remove_edge_loop:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_30\t failed\n\n");
    else
        fprintf (stdout, "Test_30\t passed\n\n");
    err = ESUCCESS;
    remove_edge  (gr, 0, 1, &err);
    fprintf (stdout, "Test_31_remove_edge:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_31\t failed\n\n");
    else
        fprintf (stdout, "Test_31\t passed\n\n");
    remove_edge (gr, 1, 0, &err);
    fprintf (stdout, "Test_32_remove_zero_edge:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_32\t failed\n\n");
    else
        fprintf (stdout, "Test_32\t passed\n\n");


    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");




    
    int x = 0;
    x = edge_cost (NULL, 0, 1, &err);
    fprintf (stdout, "Test_33_edge_cost_in_NULL_graph:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_33\t failed\n\n");
    else
        fprintf (stdout, "Test_33\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost (gr, -1, 1, &err);
    fprintf (stdout, "Test_34_edge_cost_from_<_0:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_34\t failed\n\n");
    else
        fprintf (stdout, "Test_34\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost (gr, n, 1, &err);
    fprintf (stdout, "Test_35_edge_cost_from_>_n:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_35\t failed\n\n");
    else
        fprintf (stdout, "Test_35\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost (gr, 0, -1, &err);
    fprintf (stdout, "Test_36_edge_cost_to_<_0:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_36\t failed\n\n");
    else
        fprintf (stdout, "Test_36\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost (gr, 0, n, &err);
    fprintf (stdout, "Test_37_edge_cost_to_>_n:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_37\t failed\n\n");
    else
        fprintf (stdout, "Test_37\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost (gr, 0, 0, &err);
    fprintf (stdout, "Test_38_edge_cost_loop:\n");
    if (err != EINVARG || x != -1)
        fprintf (stdout, "Test_38\t failed\n\n");
    else
        fprintf (stdout, "Test_38\t passed\n\n");
    err = ESUCCESS;
    x = edge_cost  (gr, 0, 2, &err);
    fprintf (stdout, "Test_39_edge_cost:\n");
    if (err != ESUCCESS || x != 3)
        fprintf (stdout, "Test_39\t failed\n\n");
    else
        fprintf (stdout, "Test_39\t passed\n\n");
    x = edge_cost (gr, 1, 0, &err);
    fprintf (stdout, "Test_40_edge_cost_zero:\n");
    if (err != ENEXIST || x != 0)
        fprintf (stdout, "Test_40\t failed\n\n");
    else
        fprintf (stdout, "Test_40\t passed\n\n");

    
    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");
    





    add_value (NULL, 0, 1, &err);
    fprintf (stdout, "Test_41_add_value_to_NULL_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_41\t failed\n\n");
    else
        fprintf (stdout, "Test_41\t passed\n\n");
    err = ESUCCESS;
    add_value (gr, -1, 1, &err);
    fprintf (stdout, "Test_42_add_value_to_vertex_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_42\t failed\n\n");
    else
        fprintf (stdout, "Test_42\t passed\n\n");
    err = ESUCCESS;
    add_value (gr, n, 1, &err);
    fprintf (stdout, "Test_43_add_value_to_vertex_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_43\t failed\n\n");
    else
        fprintf (stdout, "Test_43\t passed\n\n");
    err = ESUCCESS;
    add_value (gr, 0, -1, &err);
    fprintf (stdout, "Test_44_add_value_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_44\t failed\n\n");
    else
        fprintf (stdout, "Test_44\t passed\n\n");
    add_value  (gr, 0, 1, &err);
    fprintf (stdout, "Test_45_add_value:\n");
    if (err != ESUCCESS || gr->key[0].value != 1)
        fprintf (stdout, "Test_45\t failed\n\n");
    else
        fprintf (stdout, "Test_45\t passed\n\n");
    add_value (gr, 0, 2, &err);
    fprintf (stdout, "Test_46_add_value_already_exists:\n");
    if (err != EEXIST || gr->key[0].value != 1)
        fprintf (stdout, "Test_46\t failed\n\n");
    else
        fprintf (stdout, "Test_46\t passed\n\n");
    

    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");
    





    add_or_replace_value (NULL, 0, 1, &err);
    fprintf (stdout, "Test_47_add_or_replace_value_to_NULL_graph:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_47\t failed\n\n");
    else
        fprintf (stdout, "Test_47\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_value (gr, -1, 1, &err);
    fprintf (stdout, "Test_48_add_or_replace_value_to_vertex_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_48\t failed\n\n");
    else
        fprintf (stdout, "Test_48\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_value (gr, n, 1, &err);
    fprintf (stdout, "Test_49_add_or_replace_value_to_vertex_>_n:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_49\t failed\n\n");
    else
        fprintf (stdout, "Test_49\t passed\n\n");
    err = ESUCCESS;
    add_or_replace_value (gr, 0, -1, &err);
    fprintf (stdout, "Test_50_add_or_replace_value_<_0:\n");
    if (err != EINVARG)
        fprintf (stdout, "Test_50\t failed\n\n");
    else
        fprintf (stdout, "Test_50\t passed\n\n");
    add_or_replace_value  (gr, 1, 1, &err);
    fprintf (stdout, "Test_51_add_or_replace_value:\n");
    if (err != ESUCCESS || gr->key[1].value != 1)
        fprintf (stdout, "Test_51\t failed\n\n");
    else
        fprintf (stdout, "Test_51\t passed\n\n");
    add_or_replace_value (gr, 1, 2, &err);
    fprintf (stdout, "Test_46_add_or_replace_value_already_exists:\n");
    if (err != ESUCCESS || gr->key[1].value != 2)
        fprintf (stdout, "Test_52\t failed\n\n");
    else
        fprintf (stdout, "Test_52\t passed\n\n");
    

    print_graph (gr, &err);
    fprintf (stdout, "Test_6_print_graph:\n");
    if (err != ESUCCESS)
        fprintf (stdout, "Test_6\t failed\n\n");
    else
        fprintf (stdout, "Test_6\t passed\n\n");











    remove_graph (&gr, &err);
    fprintf (stdout, "Test_4_remove_graph:\n");
    if (err != ESUCCESS || gr != NULL)
        fprintf (stdout, "Test_4\t failed\n\n");
    else 
        fprintf (stdout, "Test_4\t passed\n\n");
    return 0;
}