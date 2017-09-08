//
// Created by cui on 17-9-8.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sb_tree.h"
sb_tree_node* insert_avl_tree(sb_tree_node **root,sb_tree_node *data);

sb_tree_node* left_left_rotate(sb_tree_node *root);
sb_tree_node* right_right_rotate(sb_tree_node *root);

int height(sb_tree_node *node);

int sb_insert_avl_tree(sb_avl_tree **root,sb_tree_node node_){
    if(root==NULL)
        return 0;
    node_.node1 = node_.node2 = NULL;
    node_.height = 0;
    sb_tree_node *result = insert_avl_tree(root,&node_);
    return result==NULL?0:1;
}

sb_tree_node* insert_avl_tree(sb_tree_node **root,sb_tree_node *data){
    if (*root == NULL){
        *root = (sb_tree_node*)malloc(sizeof(sb_tree_node));
        if(*root == NULL)
            return NULL;
        **root = *data;
        return *root;
    }
    int compare_result = sb_compare(data->e,(*root)->e);
    if(compare_result<0){
        if(insert_avl_tree(&(*root)->node1,data)){
            if(height((*root)->node1)-height((*root)->node2)>1){
                compare_result = sb_compare(data->e,(*root)->node1->e);
                if(compare_result<0){//LL
                    *root = left_left_rotate(*root);

                }
                if(compare_result>0){//LR
                    (*root)->node2 = right_right_rotate((*root)->node2);
                    *root = left_left_rotate(*root);

                }
            }
        }else{
            return NULL;
        }
    }

    if (compare_result>0){
        if(insert_avl_tree(&(*root)->node2,data)){
            if(height((*root)->node2)-height((*root)->node1)>1){
                compare_result = sb_compare(data->e,(*root)->node2->e);
                if(compare_result>0){//RR
                    *root = right_right_rotate(*root);

                }
                if(compare_result<0){//RL
                    (*root)->node1 = left_left_rotate((*root)->node1);
                    *root = right_right_rotate(*root);

                }
            }
        }else{
            return NULL;
        }
    }

    if (compare_result==0){

    }
    height(*root);
    return *root;
}
int height(sb_tree_node *node){
    if(node==NULL){
        return -1;
    }
    int left_height = -1;
    int right_height = -1;
    if(node->node1!=NULL)
        left_height = node->node1->height;
    if(node->node2!=NULL)
        right_height = node->node2->height;
    return (node->height = (left_height > right_height ? left_height : right_height)+1);
}
sb_tree_node* left_left_rotate(sb_tree_node *old_root){
    sb_tree_node * new_root = old_root->node1;
    old_root->node1 = new_root->node2;
    new_root->node2 = old_root;
    return new_root;
}
sb_tree_node* right_right_rotate(sb_tree_node *old_root){
    sb_tree_node * new_root = old_root->node2;
    old_root->node2 = new_root->node1;
    new_root->node1 = old_root;
    return new_root;
}

int sb_find_min_avl_tree(sb_avl_tree *tree,sb_tree_node **tn){
    return sb_find_min_bs_tree(tree,tn);
}
int sb_find_max_avl_tree(sb_avl_tree *tree,sb_tree_node **tn){
    return sb_find_max_bs_tree(tree,tn);
}
int sb_get_avl_tree(sb_avl_tree *tree,int key,sb_tree_node **node_){
    return sb_get_bs_tree(tree,key,node_);
}
int sb_traversal_avl_tree(sb_avl_tree *tree,arraylist *list,sb_traversal_type bt){
    return sb_traversal_bs_tree(tree,list,bt);
}
int sb_remove_avl_tree(sb_avl_tree **tree,int key,sb_tree_node *node){
    return 1;
}
