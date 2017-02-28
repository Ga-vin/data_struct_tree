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
    } while (0);                     \
#define    MAKE_RIGHT_NULL(p)   ((p)->right_child)

#define    GET_LEFT(p)          ((p)->left_right)

BOOL init_bitree(pbitree_t p_root)
{
    p_root = (pbitree_t)malloc(sizeof(bitree_t));

    return (TRUE);
}

void destroy_bitree(pbitree_t p_root)
{
    
}

pbitree_t create_bitree(ElementType element)
{
    pbitree_t p_tree_node = NULL;

    p_tree_node = (pbitree_t)malloc(sizeof(bitree_t));
    if ( !p_tree_node) {
        fprintf(stderr, "[X] malloc space for new node of bitree error. In %s at line %d for %s \n",
                GET_FILE,
                GET_LINE,
                GET_FUNC);
        
        return (NULL);
    }

    p_tree_node->left_child = NULL;
}
