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
    }
}

/* Name     : init_bitree                                                                           */
/* Function : Initialize root of the tree                                                           */
/* Input    : p_node --> root of tree                                                               */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL init_bitree(pbitree_t p_root)
{
    p_root = (pbitree_t)malloc(sizeof(bitree_t));
    if ( !p_root) {
#ifdef __DEBUG_PRINTF        
        fprintf(stderr, "[X] malloc space for bitree error. In %s at line %d for %s \n",
                GET_FILE,
                GET_LINE,
                GET_FUNC);
#endif /* __DEBUG_PRINTF */
        
        return (FALSE);
    }

    MAKE_LEFT_NULL(p_root);
    MAKE_RIGHT_NULL(p_root);
    MAKE_DATA_NULL(p_root);

    return (TRUE);
}

/* Name     : destroy_bitree                                                                        */
/* Function : Destroy the binary tree                                                               */
/* Input    : p_node --> root of tree                                                               */
/* Output   : NONE                                                                                  */
void destroy_bitree(pbitree_t p_root)
{
    clear_bitree(p_root);
}

/* Name     : create_bitree                                                                         */
/* Function : Create root of the binary tree                                                        */
/* Input    : element -- Element to be insert the leaf of tree                                      */
/* Output   : Node of tree to be created                                                            */
pbitree_t create_bitree(ElementType element)
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
    memcpy(&(p_tree_node->data), &element, sizeof(ElementType));

    return (p_tree_node);
}

/* Name     : clear_bitree                                                                          */
/* Function : Clear all leaives of tree                                                             */
/* Input    : p_root -- Tree to be cleared                                                          */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL clear_bitree(pbitree_t p_root)
{
    pbitree_t p_temp = p_root;

    if ( p_root->left_child) {
        clear_bitree(p_root->left_child);
    }

    if ( p_root->right_child) {
        clear_bitree(p_root->right_child);
    }

    __free_node(p_temp);
    return (TRUE);
}

/* Name     : is_empty_bitree                                                                       */
/* Function : Check whether the tree is empty                                                       */
/* Input    : p_root -- Tree to be checked                                                          */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL is_empty_bitree(const pbitree_t p_tree)
{
    if ( !p_tree) {
        return (FALSE);
    }

    if ( GET_LEFT(p_tree) || GET_RIGHT(p_tree)) {
        return (FALSE);
    } else {
        return (TRUE);
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
    
    if ( !p_tree) {
        return (0);
    }

    depth_left  = depth_bitree(GET_LEFT(p_tree));
    depth_right = depth_bitree(GET_RIGHT(p_tree));
    depth_root  = (depth_left > depth_right) ? depth_left : depth_right;

    return (depth_root + 1);
}

/* Name     : root_bitree                                                                           */
/* Function : Get root leaf of the tree                                                             */
/* Input    : p_root -- Tree to be checked                                                          */
/* Output   : Pointer points to root node of tree                                                   */
pbitree_t root_bitree(const pbitree_t p_tree)
{
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

/* Name     : insert_child_bitree                                                                   */
/* Function : Insert new child leaf to the tree                                                     */
/* Input    : p_tree   -- Tree to be checked
              child    -- left child or right child
              p_node   -- specific node of the tree                                                 */
/* Output   : TRUE will be returned, or else FALSE                                                  */
BOOL insert_child_bitree(pbitree_t p_tree, child_e child, pbitree_t p_node)
{
    if ( !p_tree || !p_node) {
        return (FALSE);
    }

    switch ( child) {

    case LEFT_CHILD:
        {
            pbitree_t p_temp = NULL;

            p_temp = GET_LEFT(p_tree);
            GET_LEFT(p_node) = p_temp;
            GET_LEFT(p_tree) = p_node;
        }
        break;

    case RIGHT_CHILD:
        {
            pbitree_t p_temp  = NULL;

            p_temp = GET_LEFT(p_tree);
            GET_LEFT(p_node) = p_temp;
            GET_LEFT(p_tree) = p_node;
        }
        break;

    default:
        fprintf(stderr, "[X] invalid child \n");

        return (FALSE);
    }

    return (TRUE);
}
