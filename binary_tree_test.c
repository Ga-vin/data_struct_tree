#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "binary_tree.h"
#include "binary_tree_test.h"

bitree_t _G_binary_tree;

static void __print(ElementType element)
{
    fprintf(stdout, "%-3d \n");
}

void T_init_bitree(void)
{
    if ( FALSE == init_bitree(&_G_binary_tree)) {
        fprintf(stderr, "[X] initialize binary tree error. \n");
    } else {
        fprintf(stdout, "[*] initialize binary tree [OK] \n");
    }
}

void T_destroy_bitree(void)
{
    destroy_bitree(&_G_binary_tree);
}

void T_create_node_bitree(void)
{
    pbitree_t p_temp = NULL;

    p_temp = create_node_bitree(9);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] insert left child [OK] \n");
    }
    T_depth_bitree();

    p_temp = create_node_bitree(4);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }    
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] insert left child [OK] \n");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(15);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }        
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] insert right child [OK] \n");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(2);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }            
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] insert left child [OK] \n");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(6);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }                
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] insert right child [OK] \n");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(12);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }                    
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] insert left child [OK] \n");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(17);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] create node of binary tree [OK] \n");
    }                        
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] insert right child [OK] \n");
    }
    T_depth_bitree();    
}

void T_is_empty_bitree(void)
{
    if ( TRUE == is_empty_bitree(&_G_binary_tree)) {
        fprintf(stdout, "binary tree is empty \n");
    } else {
        fprintf(stdout, "binary tree is not empty \n");
    }
}

void T_pre_order_traverse_bitree(void)
{
    pre_order_traverse_bitree(&_G_binary_tree, __print);
}

void T_in_order_traverse_bitree(void)
{
    in_order_traverse_bitree(&_G_binary_tree, __print);
}

void T_post_order_traverse_bitree(void)
{
    post_order_traverse_bitree(&_G_binary_tree, __print);
}

void T_depth_bitree(void)
{
    fprintf(stdout, "depth of binary tree is %d \n", depth_bitree(&_G_binary_tree));
}
