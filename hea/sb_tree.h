#ifndef SB_TREE_H_
#define SB_TREE_H_

#include <stddef.h>
#include "sb_base.h"
#include "sb_collection.h"
typedef struct tree_node_{
    sb_element e;
    struct tree_node_ *node1;
    struct tree_node_ *node2;
    int height;
}sb_tree_node;

/*
  二叉查找树的通用操作
*/
typedef sb_tree_node sb_bs_tree;
/**
 * 查找最小元素
 * @param tree 目标树
 * @param tn 存放查询结果的指针
 * @return 0:失败,0以外成功
 * */
int sb_find_min_bs_tree(sb_tree_node *tree,sb_tree_node **tn);
int sb_find_max_bs_tree(sb_tree_node *tree,sb_tree_node **tn);
int sb_get_bs_tree(sb_bs_tree *tree,int key,sb_tree_node **node_);
//遍例
typedef enum traversal_type{
    PRE,
    MIDDLE,
    BACK
}sb_traversal_type;
int sb_traversal_bs_tree(sb_bs_tree *bst,sb_arraylist *list,sb_traversal_type bt);

/*
  AVL树
*/
typedef sb_tree_node sb_avl_tree;
int sb_insert_avl_tree(sb_avl_tree **tree,sb_tree_node node_);
int sb_find_min_avl_tree(sb_avl_tree *tree,sb_tree_node **tn);
int sb_find_max_avl_tree(sb_avl_tree *tree,sb_tree_node **tn);
int sb_get_avl_tree(sb_avl_tree *tree,int key,sb_tree_node **node_);
int sb_traversal_avl_tree(sb_avl_tree *tree,sb_arraylist *list,sb_traversal_type bt);
int sb_remove_avl_tree(sb_avl_tree **tree,sb_tree_node *need_remove_node);
int sb_clear_avl_tree(sb_avl_tree *tree,void(*release_value)(void*));
int sb_free_avl_tree(sb_avl_tree **tree,void(*release_value)(void*));

typedef struct sb_map{
    sb_avl_tree *tree;
    unsigned int length;
}sb_map;
int sb_init_map(sb_map *map);
int sb_insert_map(sb_map *map,void *key,size_t key_size,sb_element e);
int sb_get_map(sb_map *map,void *key,size_t key_size,sb_element *result);
int sb_remove_map(sb_map *map,void *key,size_t key_size,sb_element *deleted_elements);
int sb_clear_map(sb_map *map,void(*release_value)(void*));
int sb_free_map(sb_map *map,void(*release_value)(void*));

#endif
