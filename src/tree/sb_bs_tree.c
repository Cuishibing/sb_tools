#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sb_tree.h"


void back_traversal(sb_tree_node *node,arraylist *list);

int sb_init_bs_tree(sb_bs_tree *bst){
  if(bst==NULL)
    return 0;
  //初始情况下让根节点指向自己,根据这个条件来判断根节点还未初始化
  bst->node1 = bst;
  bst->node2 = bst;
  return 1;
}

int sb_insert_bs_tree(sb_bs_tree *bst,sb_tree_node node_){
  assert(bst!=NULL);
  //此处必须要进行初始化
  node_.node1 = NULL;
  node_.node2 = NULL;
  //  node_.parent = NULL;
  if(bst->node1 == bst&&bst->node2==bst){
    //    printf("root node is null\n");
    *bst = node_;
    bst->parent = NULL;//根节点的parent为NULL
    return 1;
  }
  /*
    插入节点都是对要插入节点的复制,所以在删除某一个节点时必须
    释放这个节点的内存
  */
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
int sb_get_bs_tree(sb_bs_tree *bst,int key,sb_tree_node **node_){
  assert(bst!=NULL);
  assert(node_!=NULL);
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

int sb_traversal_bs_tree(sb_bs_tree *bst,arraylist *list,sb_traversal_type bt){
  assert(bst!=NULL);
  assert(list!=NULL);
  sb_stack s;
  sb_element e;
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
      sb_insert_arraylist(list,current_node->e,list->length);//遍历根结点
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
      sb_insert_arraylist(list,current_node->e,list->length);
      current_node = current_node->node2;
    }
  }break;
  case BACK:{
    //后序遍历,目前用递归的方法
    back_traversal(bst, list);
  }break;
  }
  sb_clear_stack(&s);
  return 1;
}

void back_traversal(sb_tree_node *node,arraylist *list){
  if(node==NULL)
    return;
  back_traversal(node->node1, list);
  back_traversal(node->node2, list);
  sb_insert_arraylist(list,node->e,list->length);
}

int sb_remove_bs_tree(sb_bs_tree *bst,int key,sb_tree_node *d_node){
  assert(bst!=NULL);
  sb_tree_node *del_node;
  if(sb_get_bs_tree(bst,key,&del_node)){
    if(d_node!=NULL)
      *d_node = *del_node;//返回了删除的节点
    if(del_node->node1==NULL&&del_node->node2==NULL){//没有儿子节点,直接删除该节点
      if(del_node->parent!=NULL){//有父亲节点时,让父亲节点指向该节点的指针为空
	if(del_node->parent->node1==del_node){
	  del_node->parent->node1 = NULL;
	}else del_node->parent->node2 = NULL;
	free(del_node);
      }else{//没有父亲节点,说明这是一个根节点,根节点不能free掉
	del_node->node1 = del_node;
	del_node->node2 = del_node;
      }
    }else if(del_node->node1!=NULL&&del_node->node2!=NULL){//有两个儿子节点的情况
      /*
	两个儿子节点时,用待删除节点右子树的最小值来替代该节点的值
       */
      sb_tree_node *min_node;
      if(sb_find_min_bs_tree(del_node->node2,&min_node)){
	del_node->e = min_node->e;//替换节点的值
	sb_remove_bs_tree(min_node,min_node->e.key,NULL);//递归删除那个最小值节点
      }
    }else{//有一个儿子的情况
      sb_tree_node *parent = del_node->parent;
      sb_tree_node *temp;
      temp = del_node->node1!=NULL ? del_node->node1 : del_node->node2;
      *del_node = *temp;
      free(temp);
      del_node->parent = parent;
      //修改子节点的parent值
      if(del_node->node1!=NULL)
	del_node->node1->parent = del_node;
      if(del_node->node2!=NULL)
	del_node->node2->parent = del_node;
    }
  }else return 0;
  return 1;
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
