#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "common_types.h"
#include "binary_tree.h"
#include "binary_tree_test.h"

int main(int argc, char *argv[])
{
    T_init_bitree();

    T_is_pbinary_tree_null();
    
    T_is_empty_bitree();
    
    T_create_binary_tree();
    
    T_is_empty_bitree();

    T_is_pbinary_tree_null();

    T_depth_bitree();
    
#if 1
    fprintf(stdout, "pre order traverse binary tree \n");
    T_pre_order_traverse_bitree();
#endif

#if 1    
    fprintf(stdout, "in order traverse binary tree \n");    
    T_in_order_traverse_bitree();
#endif

#if 1    
    fprintf(stdout, "post order traverse binary tree \n");    
    T_post_order_traverse_bitree();
#endif

    T_insert_new_child_bitree();

#if 0    
    fprintf(stdout, "destroy binary tree \n");
    T_destroy_bitree();
#endif
    
    return (0);
}
