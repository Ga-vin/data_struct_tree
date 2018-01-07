#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

#include "binary_tree.h"
#include "binary_tree_test.h"

bitree_t _G_binary_tree;
pbitree_t _G_pbinary_tree;

static void __print(ElementType element)
{
    fprintf(stdout, "%-3d \n", element);
}

void T_init_bitree(void)
{
    init_bitree(&_G_pbinary_tree);
    fprintf(stdout, "[*] %40s[OK] \n", "initialize binary tree");
}

void T_destroy_bitree(void)
{
    destroy_bitree(&_G_pbinary_tree);
}

void T_create_binary_tree(void)
{
    pbitree_t pnode1 = create_node_bitree(10);
    pbitree_t pnode2 = create_node_bitree(20);
    pbitree_t pnode3 = create_node_bitree(30);
    set_left_child_bitree(pnode3, pnode1);
    set_right_child_bitree(pnode3, pnode2);

    pbitree_t pnode4 = create_node_bitree(40);
    pbitree_t pnode5 = create_node_bitree(50);
    pbitree_t pnode6 = create_node_bitree(60);
    set_left_child_bitree(pnode6, pnode4);
    set_right_child_bitree(pnode6, pnode5);

    _G_pbinary_tree = create_node_bitree(70);
    set_left_child_bitree(_G_pbinary_tree, pnode3);
    set_right_child_bitree(_G_pbinary_tree, pnode6);
}

void T_insert_new_child_bitree(void)
{
    pbitree_t new_node = create_node_bitree(35);
    assert(new_node != NULL);

    insert_child_bitree(_G_pbinary_tree, new_node);

    T_pre_order_traverse_bitree();
    T_depth_bitree();
}

void T_create_node_bitree(void)
{
    pbitree_t p_temp = NULL;

    p_temp = create_node_bitree(9);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert left child");
    }
    T_depth_bitree();

    p_temp = create_node_bitree(4);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }    
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert left child");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(15);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }        
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert right child");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(2);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }            
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert left child");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(6);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }                
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert right child");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(12);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }                    
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert left child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert left child");
    }
    T_depth_bitree();    

    p_temp = create_node_bitree(17);
    if ( !p_temp) {
        fprintf(stderr, "[X] create node of binary tree error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "create node of binary tree");
    }                        
    if ( FALSE == insert_child_bitree(&_G_binary_tree, p_temp)) {
        fprintf(stderr, "[X] insert right child error. \n");
    } else {
        fprintf(stdout, "[*] %40s[OK]\n", "insert right child");
    }
    T_depth_bitree();    
}

void T_is_empty_bitree(void)
{
    if ( TRUE == is_empty_bitree(_G_pbinary_tree)) {
        fprintf(stdout, "[*] %40s\n", "binary tree is empty");
    } else {
        fprintf(stdout, "[*] %40s\n", "binary tree is not empty");
    }
}

void T_pre_order_traverse_bitree(void)
{
    pre_order_traverse_bitree(_G_pbinary_tree, __print);
}

void T_in_order_traverse_bitree(void)
{
    in_order_traverse_bitree(_G_pbinary_tree, __print);
}

void T_post_order_traverse_bitree(void)
{
    post_order_traverse_bitree(_G_pbinary_tree, __print);
}

void T_depth_bitree(void)
{
    fprintf(stdout, "depth of binary tree is %d \n", depth_bitree(_G_pbinary_tree));
}

void T_is_pbinary_tree_null(void)
{
    if ( !_G_pbinary_tree) {
        fprintf(stdout, "[x] pbinary tree is NULL.\n");
    } else  {
        fprintf(stdout, "[*] pbinary tree is not NULL\n");
    }
}
