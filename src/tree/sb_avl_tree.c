#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sb_tree.h"

int sb_init_avl_tree(sb_avl_tree *bst){
  if(bst==NULL)
    return 0;
  //初始情况下让根节点的儿子指向自己,根据这个条件来判断根节点还未初始化
  bst->node1 = bst;
  bst->node2 = bst;
  bst->height = -1;
  return 1;
}
int sb_insert_avl_tree(sb_avl_tree *bst,sb_tree_node node_){
  assert(bst!=NULL);
  node_.node1 = NULL;
  node_.node2 = NULL;
  if(bst->node1==bst&&bst->node2==bst){
    *bst = node_;
    bst->parent = NULL;
    return 1;
    //是根节点,不需要调整
  }
  sb_tree_node *node = (sb_tree_node*)malloc(sizeof(sb_tree_node));
  if(node==NULL)
    return 0;
  *node = node_;
  sb_tree_node *iteator = bst;
  while(1){
    if(sb_compare(node->e, iteator->e)<0){//小于根结点
      if(iteator->node1!=NULL){//有左子树
	iteator = iteator->node1;
	continue;
      }else{
	iteator->node1 = node;
	iteator->node1->parent = iteator;
	iteator->node1->height = iteator->height + 1;
	/*
	  增加了一个节点的左子树的高度,先比较以该节点为根节点的树和对应兄弟节点为根节点的树的高度,如果高度相差大于1则需要调整.
	 */
	break;
      }
    }else{//大于根结点
      if(iteator->node2!=NULL){//有右子树
	iteator = iteator->node2;
	continue;
      }else{
	iteator->node2 = node;
	iteator->node2->parent = iteator;
	break;
      }
    }
  }
  return 1;  
}
int sb_find_min_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_find_max_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_get_avl_tree(sb_avl_tree *bst,int key,sb_tree_node **node_);
int sb_traversal_avl_tree(sb_avl_tree *bst,arraylist *list,sb_traversal_type bt);
int sb_remove_avl_tree(sb_avl_tree *bst,int key,sb_tree_node *node);
