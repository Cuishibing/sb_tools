#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sb_tree.h"


void back_traversal(sb_tree_node *node,sb_arraylist *list);

int sb_get_bs_tree(sb_bs_tree *bst,int key,sb_tree_node **node_){
//    assert(bst!=NULL);
//    assert(node_!=NULL);
    if(bst == NULL || node_ == NULL){
        return 0;
    }
    sb_tree_node *iteator = bst;
    while(1){
        if(iteator->e.key==key){
            *node_ = iteator;
            break;
        }
        if(key<iteator->e.key){//小于根结点
            if(iteator->node1==NULL){
                return 0;
            }else{
                iteator = iteator->node1;
                continue;
            }
        }else{
            if(iteator->node2==NULL){
                return 0;
            }else{
                iteator = iteator->node2;
                continue;
            }
        }
    }
    return 1;
}

void false_release_tree_node(void *ptr){
    //do nothing
}

int sb_traversal_bs_tree(sb_bs_tree *bst,sb_arraylist *list,sb_traversal_type bt){
    assert(bst!=NULL);
    assert(list!=NULL);
    sb_stack s;
    sb_element e,result_e;
    sb_tree_node *current_node = NULL;
    if(bst->node1==bst||bst->node2==bst)
        return 0;
    if(!sb_init_stack(&s,1))//初始化栈
        return 0;
    switch(bt){
        case PRE:{
            e.value = bst;
            sb_push_stack(&s,e);
            while(1){
                if(!sb_pop_stack(&s,&e))
                    break;
                current_node = (sb_tree_node*)e.value;
                result_e.value = current_node;
                sb_insert_arraylist(list,result_e,list->length);//遍历根结点
                if(current_node->node2!=NULL){
                    e.value = current_node->node2;
                    sb_push_stack(&s,e);
                }
                if(current_node->node1!=NULL){
                    e.value = current_node->node1;
                    sb_push_stack(&s,e);
                }
            }
        }break;
        case MIDDLE:{
            current_node = bst;
            while(s.length!=0||current_node!=NULL){
                while(current_node!=NULL){
                    e.value = current_node;
                    sb_push_stack(&s,e);
                    current_node = current_node->node1;
                }
                sb_pop_stack(&s,&e);
                current_node = (sb_tree_node*)e.value;
                result_e.value = current_node;
                sb_insert_arraylist(list,result_e,list->length);
                current_node = current_node->node2;
            }
        }break;
        case BACK:{
            //后序遍历,目前用递归的方法
            back_traversal(bst, list);
        }break;
    }
    sb_clear_stack(&s,false_release_tree_node);
    return 1;
}

void back_traversal(sb_tree_node *node,sb_arraylist *list){
    if(node==NULL)
        return;
    back_traversal(node->node1, list);
    back_traversal(node->node2, list);
    //here is a bad code
    sb_element result_e;
    result_e.value = node;
    sb_insert_arraylist(list,result_e,list->length);
}

int sb_find_min_bs_tree(sb_tree_node *tr,sb_tree_node **tn){
    if(tr==NULL)
        return 0;
    if(tr->node1==NULL){
        *tn = tr;
        return 1;
    }else
        sb_find_min_bs_tree(tr->node1,tn);
}

int sb_find_max_bs_tree(sb_tree_node *tr,sb_tree_node **tn){
    if(tr==NULL)
        return 0;
    if(tr->node2==NULL){
        *tn = tr;
        return 1;
    }else
        sb_find_max_bs_tree(tr->node2,tn);
}