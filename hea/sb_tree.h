#ifndef SB_TREE_H_
#define SB_TREE_H_
#include "sb_base.h"
#include "sb_collection.h"
typedef struct tree_node_{
  sb_element e;
  struct tree_node_ *node1;
  struct tree_node_ *node2;
  struct tree_node_ *parent;
  int height;
}sb_tree_node;

/*
  二叉查找树
*/
typedef sb_tree_node sb_bs_tree;
int sb_init_bs_tree(sb_bs_tree *bst);
int sb_insert_bs_tree(sb_bs_tree *bst,sb_tree_node node_);
int sb_find_min_bs_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_find_max_bs_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_get_bs_tree(sb_bs_tree *bst,int key,sb_tree_node **node_);
//遍例
typedef enum traversal_type{
  PRE,
  MIDDLE,
  BACK
}sb_traversal_type;
int sb_traversal_bs_tree(sb_bs_tree *bst,arraylist *list,sb_traversal_type bt);
int sb_remove_bs_tree(sb_bs_tree *bst,int key,sb_tree_node *node);

/*
  AVL树
*/
typedef sb_tree_node sb_avl_tree;
int sb_init_avl_tree(sb_avl_tree *bst);
int sb_insert_avl_tree(sb_avl_tree *bst,sb_tree_node node_);
int sb_find_min_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_find_max_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_get_avl_tree(sb_avl_tree *bst,int key,sb_tree_node **node_);
int sb_traversal_avl_tree(sb_avl_tree *bst,arraylist *list,sb_traversal_type bt);
int sb_remove_avl_tree(sb_avl_tree *bst,int key,sb_tree_node *node);

#endif
