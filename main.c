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
    fprintf(stdout, "initialize binary tree \n");
    T_init_bitree();

    fprintf(stdout, "is empty binary tree \n");
    T_is_empty_bitree();

    fprintf(stdout, "create node for binary tree \n");
    T_create_node_bitree();

    fprintf(stdout, "pre order traverse binary tree \n");
    T_pre_order_traverse_bitree();

    fprintf(stdout, "in order traverse binary tree \n");    
    T_in_order_traverse_bitree();

    fprintf(stdout, "post order traverse binary tree \n");    
    T_post_order_traverse_bitree();

    fprintf(stdout, "destroy binary tree \n");
    T_destroy_bitree();
    
    return ;
}
