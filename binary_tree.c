/* ------------------------------------------------------------------------------------------------ */
/* File Name : binary_tree.h                                                                        */
/* ------------------------------------------------------------------------------------------------ */
/* Function  : Define some operations on binary tree for using in other files                       */
/* ------------------------------------------------------------------------------------------------ */
/* Time      : 2017.02.28                                                                           */
/* ------------------------------------------------------------------------------------------------ */
/* Author    : Gavin.Bai   gavin_8724@163.com                                                       */
/* ------------------------------------------------------------------------------------------------ */
/* License   : GPL                                                                                  */
/* ------------------------------------------------------------------------------------------------ */
/* Modify    :                                                                                      */
/* ------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "binary_tree.h"

#define    MAKE_LEFT_NULL(p)         \
    do {                             \
        (p)->left_child = NULL;      \
    } while (0)                      \
        
#define    MAKE_RIGHT_NULL(p)        \
    do {                             \
        (p)->right_child = NULL;     \
    } while (0)                      \

#define    MAKE_DATA_NULL(p)         \
    do {                             \
        (p)->data = 0x0;             \
    } while (0)                      \

#define    GET_LEFT(p)          ((p)->left_child)
#define    GET_RIGHT(p)         ((p)->right_child)
#define    GET_DATA(p)          ((p)->data)

/* Name     : __free_node                                                                           */
/* Function : Free node of the free                                                                 */
/* Input    : p_node --> node of leaf                                                               */
/* Output   : NONE                                                                                  */
static void __free_node(pbitree_t p_node)
{
    if ( p_node) {
        free(p_node);
        p_node = NULL;
    }
}

/* Name     : init_bitree                                                                           */
/* Function : Initialize root of the tree, make root of tree to be NULL  */
/* Input    : p_node --> root of tree                                                         */
/* Output   : TRUE will be returned, or else FALSE                                 */
BOOL init_bitree(pbitree_t *pp_root)
{
    *pp_root = NULL;

    return (TRUE);
}

/* Name     : destroy_bitree                                                                        */
/* Function : Destroy the binary tree                                                               */
/* Input    : p_node --> root of tree                                                               */
/* Output   : NONE                                                                                  */
void destroy_bitree(pbitree_t *pp_root)
{
    clear_bitree(pp_root);
}

/* Name     : create_bitree                                                                         */
/* Function : Create root of the binary tree                                                        */
/* Input    : element -- Element to be insert the leaf of tree                                      */
/* Output   : Node of tree to be created                                                            */
pbitree_t create_node_bitree(ElementType element)
{
    pbitree_t p_tree_node = NULL;

    p_tree_node = (pbitree_t)malloc(sizeof(bitree_t));
    if ( !p_tree_node) {
#ifdef __DEBUG_PRINTF        
        fprintf(stderr, "[X] malloc space for new node of bitree error. In %s at line %d for %s \n",
                GET_FILE,
                GET_LINE,
                GET_FUNC);
#endif /* __DEBUG_PRINTF */        
        
        return (NULL);
    }

    MAKE_LEFT_NULL(p_tree_node);
    MAKE_RIGHT_NULL(p_tree_node);
    /* memcpy(&(p_tree_node->data), &element, sizeof(ElementType)); */
    p_tree_node->data = element;

    return (p_tree_node);
}

/* Name     : clear_bitree                                                                          */
/* Function : Clear all leaives of tree                                                             */
/* Input    : p_root -- Tree to be cleared                                                          */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL clear_bitree(pbitree_t *pp_root)
{
    pbitree_t p_left  = NULL;
    pbitree_t p_right = NULL;

#ifdef __DEBUG_OTHER    
    if ( !(*pp_root)) {
        return (TRUE);
    }
    
    p_left  = GET_LEFT(*pp_root);
    p_right = GET_RIGHT(*pp_root);

    /* Destroy left child tree and right child tree separately */
    clear_bitree(pp_left);
    clear_bitree(pp_right);
#endif /* __DEBUG_OTHER */    
    
    if ( (*pp_root)->left_child) {
        clear_bitree(&((*pp_root)->left_child));
    }

    if ( (*pp_root)->right_child) {
        clear_bitree(&((*pp_root)->right_child));
    }
    
    /* Destroy root node from free first */
    GET_LEFT(*pp_root)  = NULL;
    GET_RIGHT(*pp_root) = NULL;
    free(*pp_root);
    *pp_root            = NULL;
    
    return (TRUE);
}

/* Name     : is_empty_bitree                                                                                    */
/* Function : Check whether the tree is empty                                                        */
/* Input    : p_root -- Tree to be checked                                                                  */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL is_empty_bitree(const pbitree_t p_tree)
{
    if ( !(p_tree)) {
        return (FALSE);
    }

    if ( GET_LEFT(p_tree) || GET_RIGHT(p_tree)) {
        return (FALSE);
    } else {
        return (TRUE);
    }
}

/* Name     : search_bitree                                                                         */
/* Function : Search specific node in the tree with equal value                                     */
/* Input    : p_root -- Tree to be checked
 *                 item    -- to be found                                                           */
/* Output   : Pointer to the node has been found, or else NULL                                      */
pbitree_t search_bitree(pbitree_t p_root, ElementType item)
{
    pbitree_t p_temp = NULL;

    if ( !(p_root)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] tree root is null. In %s at line %d for %s. \n",
                GET_FILE,
                GET_LINE,
                GET_FUNC);
#endif /* __DEBUG_PRINTF */

        return (NULL);
    }

    if ( GET_DATA(p_root) == item) {
        return (p_root);
    } else if ( GET_DATA(p_root) > item) {
        return (search_bitree(GET_LEFT(p_root), item));
    } else {
        return (search_bitree(GET_RIGHT(p_root), item));
    }
}

/* Name     : depth_bitree                                                                          */
/* Function : Get depth of the tree                                                                 */
/* Input    : p_root -- Tree to be checked                                                          */
/* Output   : Most depth for left and right child                                                   */
UINT32 depth_bitree(const pbitree_t p_tree)
{
    UINT32 depth_root  = 0;
    UINT32 depth_left  = 0;
    UINT32 depth_right = 0;
    
    if ( !(p_tree)) {
        return (0);
    }

    depth_left   = depth_bitree(GET_LEFT(p_tree));
    depth_right = depth_bitree(GET_RIGHT(p_tree));
    depth_root  = (depth_left > depth_right) ? (depth_left + 1) : (depth_right + 1);

    return (depth_root);
}

/* Name     : root_bitree                                                                           */
/* Function : Get root leaf of the tree                                                             */
/* Input    : p_root -- Tree to be checked                                                          */
/* Output   : Pointer points to root node of tree                                                   */
pbitree_t root_bitree(const pbitree_t p_tree)
{
    assert(p_tree != NULL);
    return (p_tree);
}

/* Name     : get_value_bitree                                                                      */
/* Function : Get value of specific data field of the tree                                          */
/* Input    : p_root -- Tree to be checked
              node   -- Value of specific node                                                      */
/* Output   : Value of the specific node                                                            */
ElementType get_value_bitree(const pbitree_t p_tree, bitree_t node)
{
    return (node.data);
}

/* Name     : set_bitree                                                                            */
/* Function : Set value of specific data field of the tree                                          */
/* Input    : p_root   -- Tree to be checked
              p_leaf   -- specific node
              element  -- value of node                                                             */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL set_bitree(pbitree_t p_tree, pbitree_t p_leaf, ElementType element)
{
    if ( !p_leaf) {
        return (FALSE);
    }

    memcpy(&(p_leaf->data), &element, sizeof(ElementType));
    return (TRUE);
}

/* Name     : left_child_bitree                                                                     */
/* Function : Get left child of specific node                                                       */
/* Input    : p_root   -- Tree to be checked
              p_node   -- specific node of the tree                                                 */
/* Output   : Left child of the specific node                                                       */
pbitree_t left_child_bitree(pbitree_t p_tree, pbitree_t p_node)
{
    if ( !p_node) {
        return (NULL);
    }

    return (GET_LEFT(p_node));
}

/* Name     : right_child_bitree                                                                    */
/* Function : Get right child of specific node                                                      */
/* Input    : p_root   -- Tree to be checked
              p_node   -- specific node of the tree                                                 */
/* Output   : Right child of the specific node                                                      */
pbitree_t right_child_bitree(pbitree_t p_tree, pbitree_t p_node)
{
    if ( !p_node) {
        return (NULL);
    }

    return (GET_RIGHT(p_node));
}

pbitree_t set_left_child_bitree(pbitree_t ptree, pbitree_t l_child)
{
    assert(ptree != NULL);

    ptree->left_child = l_child;

    return (l_child);
}

pbitree_t set_right_child_bitree(pbitree_t ptree, pbitree_t r_child)
{
    assert(ptree != NULL);

    ptree->right_child = r_child;

    return (r_child);
}

/* Name     : insert_child_bitree                                                                   */
/* Function : Insert new child leaf to the tree                                                     */
/* Input    : p_tree   -- Tree to be checked
              child    -- left child or right child
              p_node   -- specific node of the tree                                                 */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL insert_child_bitree(pbitree_t p_tree, pbitree_t p_node)
{
    if ( !p_node) {
        fprintf(stdout, "Node to be inserted is NULL.\n");

        return (FALSE);
    }
    
    if ( TRUE == is_empty_bitree(p_tree)) {
        p_tree = p_node;

        return (TRUE);
    }

    if ( GET_DATA(p_node) < GET_DATA(p_tree)) {
        return (insert_child_bitree(GET_LEFT(p_tree), p_node));
    } else {
        return (insert_child_bitree(GET_RIGHT(p_tree), p_node));
    }

    return (TRUE);
}

/* Name     : del_child_bitree                                                                      */
/* Function : Delete left child or right child from the tree                                        */
/* Input    : p_tree       -- Tree to be deleted
              child        -- left child or right child
              p_new_tree   -- specific sub-tree                                                     */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL del_child_bitree(pbitree_t p_tree, child_e child, pbitree_t p_new_tree)
{
    if ( !(p_tree)) {
        return (FALSE);
    }

    switch (child) {

    case LEFT_CHILD:
        clear_bitree(&(GET_LEFT(p_tree)));
        break;

    case RIGHT_CHILD:
        clear_bitree(&(GET_RIGHT(p_tree)));
        break;

    default:
        fprintf(stdout, "[X] invalid child parameter. \n");
        return (FALSE);
    }

    return (TRUE);
}

BOOL pre_order_traverse_bitree(const pbitree_t p_tree, void (*visit)(ElementType element))
{
    if ( p_tree) {
        visit(GET_DATA(p_tree));
        pre_order_traverse_bitree(GET_LEFT(p_tree), visit);
        pre_order_traverse_bitree(GET_RIGHT(p_tree), visit);

        return (TRUE);
    }

    return (FALSE);
}

BOOL in_order_traverse_bitree(const pbitree_t p_tree, void (*visit)(ElementType element))
{
    if ( p_tree) {
        pre_order_traverse_bitree(GET_LEFT(p_tree), visit);
        visit(GET_DATA(p_tree));
        pre_order_traverse_bitree(GET_RIGHT(p_tree), visit);

        return (TRUE);
    }

    return (FALSE);
}

BOOL post_order_traverse_bitree(const pbitree_t p_tree, void (*visit)(ElementType element))
{
    if ( p_tree) {
        pre_order_traverse_bitree(GET_LEFT(p_tree), visit);
        pre_order_traverse_bitree(GET_RIGHT(p_tree), visit);
        visit(GET_DATA(p_tree));

        return (TRUE);
    }

    return (FALSE);
}
