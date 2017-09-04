#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sb_tree.h"
#include "sb_collection.h"

/*
 * 返回parent_node节点是否平衡
 * big_node为高度更高的节点
 * */
int is_balance(sb_tree_node *parent_node,sb_tree_node **big_node);

/**
 * 以parent_node节点进行左旋转
 * @param parent_node 新插入节点的祖父节点
 * */
void left_left_rotate(sb_tree_node *parent_node);

void right_right_rotate(sb_tree_node *parent_node);

int sb_init_avl_tree(sb_avl_tree *bst){
    if(bst==NULL)
        return 0;
    //初始情况下让根节点的儿子指向自己,根据这个条件来判断根节点还未初始化
    bst->node1 = bst;
    bst->node2 = bst;
    bst->parent = NULL;
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
        bst->height = 0;
        return 1;
    }
    sb_tree_node *node = (sb_tree_node*)malloc(sizeof(sb_tree_node));
    if(node==NULL)
        return 0;
    *node = node_;

    sb_stack node_stack;
    sb_element e;
    if(!sb_init_stack(&node_stack,12))
        return 0;
    e.value = bst;
    sb_push_stack(&node_stack,e);
    sb_tree_node *iteator = bst;
    while(1){
        if(sb_compare(node->e, iteator->e)<0){//小于根结点
            if(iteator->node1!=NULL){//有左子树
                iteator = iteator->node1;
                e.value = iteator;
                sb_push_stack(&node_stack,e);
                continue;
            }else{
                iteator->node1 = node;
                iteator->node1->parent = iteator;

                while (node_stack.length>0){
                    sb_pop_stack(&node_stack,&e);
                    sb_tree_node *tmp_node = NULL;
                    if(!is_balance((sb_tree_node*)e.value,&tmp_node)){//不平衡了,且不平衡的节点是:tmp_node
                        if(tmp_node->parent->node1==tmp_node){//L,tmm_node是个左节点
                            if(tmp_node->node1==NULL){//LR
                                right_right_rotate(tmp_node->node2);
                                left_left_rotate(tmp_node);
                            }else if(tmp_node->node2==NULL){//LL
                                left_left_rotate(tmp_node);
                            }else{
                                if(tmp_node->node1->height > tmp_node->node2->height){//LL
                                    left_left_rotate(tmp_node);
                                } else{//LR
                                    right_right_rotate(tmp_node->node2);
                                    left_left_rotate(tmp_node);
                                }
                            }
                        } else{//R
                            if(tmp_node->node1==NULL){//RR
                                right_right_rotate(tmp_node);
                            }else if(tmp_node->node2==NULL){//RL
                                left_left_rotate(tmp_node->node1);
                                right_right_rotate(tmp_node);
                            }else {
                                if(tmp_node->node1->height > tmp_node->node2->height){//RL
                                    left_left_rotate(tmp_node->node1);
                                    right_right_rotate(tmp_node);
                                } else{//RR
                                    right_right_rotate(tmp_node);
                                }
                            }
                        }
                    }
                }
                break;
            }
        }else{//大于根结点
            if(iteator->node2!=NULL){//有右子树
                iteator = iteator->node2;
                e.value = iteator;
                sb_push_stack(&node_stack,e);
                continue;
            }else{
                iteator->node2 = node;
                iteator->node2->parent = iteator;
                while (node_stack.length>0){
                    sb_pop_stack(&node_stack,&e);
                    sb_tree_node *tmp_node = NULL;
                    if(!is_balance((sb_tree_node*)e.value,&tmp_node)){//不平衡了
                        if(tmp_node->parent->node1==tmp_node){//L
                            if(tmp_node->node1==NULL){//LR
                                right_right_rotate(tmp_node->node2);
                                left_left_rotate(tmp_node);
                            }else if(tmp_node->node2==NULL){//LL
                                left_left_rotate(tmp_node);
                            }else{
                                if(tmp_node->node1->height > tmp_node->node2->height){//LL
                                    left_left_rotate(tmp_node);
                                } else{//LR
                                    right_right_rotate(tmp_node->node2);
                                    left_left_rotate(tmp_node);
                                }
                            }
                        } else{//R
                            if(tmp_node->node1==NULL){//RR
                                right_right_rotate(tmp_node);
                            }else if(tmp_node->node2==NULL){//RL
                                left_left_rotate(tmp_node->node1);
                                right_right_rotate(tmp_node);
                            }else {
                                if(tmp_node->node1->height > tmp_node->node2->height){//RL
                                    left_left_rotate(tmp_node->node1);
                                    right_right_rotate(tmp_node);
                                } else{//RR
                                    right_right_rotate(tmp_node);
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    sb_clear_stack(&node_stack);
    return 1;
}
int sb_find_min_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_find_max_avl_tree(sb_tree_node *tr,sb_tree_node **tn);
int sb_get_avl_tree(sb_avl_tree *bst,int key,sb_tree_node **node_);
int sb_traversal_avl_tree(sb_avl_tree *bst,arraylist *list,sb_traversal_type bt);
int sb_remove_avl_tree(sb_avl_tree *bst,int key,sb_tree_node *node);

int calculate_tree_height(sb_tree_node *node){
    if (node==NULL){
        return -1;
    }
    int node1_height = calculate_tree_height(node->node1);
    int node2_height = calculate_tree_height(node->node2);
    return (node->height = 1 + (node1_height > node2_height ? node1_height : node2_height));
}

int is_balance(sb_tree_node *parent_node,sb_tree_node **big_node){
    assert(parent_node!=NULL&&big_node!=NULL);
    int node1_height =
            calculate_tree_height(parent_node->node1);
    int node2_height =
            calculate_tree_height(parent_node->node2);
    if(abs(node1_height-node2_height)>1){//不平衡了
        node1_height>node2_height?((*big_node)=parent_node->node1):((*big_node)=parent_node->node2);
        return 0;
    }
    return 1;
}

void left_left_rotate(sb_tree_node *parent_node){
    sb_tree_node *pre_root_node = (sb_tree_node*)malloc(sizeof(sb_tree_node));
    sb_tree_node *tem_node = NULL;
    *pre_root_node = *(parent_node->parent);

    *(parent_node->parent) = *(parent_node);
    tem_node = parent_node->parent;
    free(parent_node);
    parent_node = tem_node;
    parent_node->parent = pre_root_node->parent; //parent
    if(parent_node->node1!=NULL)
        parent_node->node1->parent = parent_node;//要重新设置父亲节点,因为父节点的位置已经改变

    pre_root_node->node1 = parent_node->node2;
    if(pre_root_node->node1!=NULL)
        pre_root_node->node1->parent = pre_root_node;

    parent_node->node2 = pre_root_node;
    if(parent_node->node2!=NULL)
        parent_node->node2->parent = parent_node;
}

void right_right_rotate(sb_tree_node *parent_node){
    sb_tree_node *tem_node = NULL;
    sb_tree_node *pre_root_node = (sb_tree_node*)malloc(sizeof(sb_tree_node));
    *pre_root_node = *(parent_node->parent);

    *(parent_node->parent) = *(parent_node);
    tem_node = parent_node->parent;
    free(parent_node);
    parent_node = tem_node;
    parent_node->parent = pre_root_node->parent;
    if(parent_node->node2!=NULL)
        parent_node->node2->parent = parent_node;//要重新设置父亲节点,因为父节点的位置已经改变

    pre_root_node->node2 = parent_node->node1;
    if(pre_root_node->node2!=NULL)
        pre_root_node->node2->parent = pre_root_node;

    parent_node->node1 = pre_root_node;
    if(parent_node->node1!=NULL)
        parent_node->node1->parent = parent_node;
}