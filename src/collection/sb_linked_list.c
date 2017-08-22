#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "sb_collection.h"


int sb_init_linkedlist(sb_linkedlist *list){
  assert(list!=NULL);
  list->length = 0;
  list->head = (sb_linkedlist_node*)malloc(sizeof(sb_linkedlist_node));
  list->rear = (sb_linkedlist_node*)malloc(sizeof(sb_linkedlist_node));
  list->head->next = list->rear;
  list->rear->pre = list->head;
  return 1;
}
int sb_insert_linkedlist(sb_linkedlist *list,sb_element e,int position){
  if(list==NULL)
    return 0;
  if(position<0||position>list->length)
    return 0;
  sb_linkedlist_node *iteator = NULL;
  if(position<=(list->length/2)){
    iteator = list->head;
    for(int i=0;i<position;i++)
      iteator = iteator->next;
    sb_linkedlist_node *new_node = (sb_linkedlist_node*)malloc(sizeof(sb_linkedlist_node));
    new_node->next = iteator->next;
    iteator->next->pre = new_node;
    new_node->e = e;
    iteator->next = new_node;
    new_node->pre = iteator;
  }else{
    position=list->length - position - 1;
    iteator = list->rear;
    for(int i=0;i<position;i++)
      iteator = iteator->pre;
    sb_linkedlist_node *new_node = (sb_linkedlist_node*)malloc(sizeof(sb_linkedlist_node));
    new_node->pre = iteator->pre;
    iteator->pre->next = new_node;
    new_node->e = e;
    iteator->pre = new_node;
    new_node->next = iteator;
  }
  list->length++;
  return 1;
}
int sb_insert_linkdelist_head(sb_linkedlist *list,sb_element e){
  return sb_insert_linkedlist(list,e,0);
}
int sb_get_linkedlist(sb_linkedlist *list,int position,sb_element *e){
  assert(list!=NULL);
  if(position<0||position>=list->length)
    return 0;
  sb_linkedlist_node *iteator = NULL;
  if(position<=list->length/2){
    iteator = list->head;
    for(int i=0;i<position;i++){
      iteator = iteator->next;
    }
    *e = iteator->next->e;
  }else{
    iteator = list->rear;
    position = list->length - position - 1;
    for(int i=0;i<position;i++){
      iteator = iteator->pre;
    }
    *e = iteator->pre->e;
  }
  return 1;
}
int sb_set_linkedlist(sb_linkedlist *list,int position,sb_element e,sb_element *pre_e){
  assert(list!=NULL);
  if(position<0||position>=list->length)
    return 0;
  sb_linkedlist_node *iteator = NULL;
  if(position<=list->length/2){
    iteator = list->head;
    for(int i=0;i<position;i++){
      iteator = iteator->next;
    }
    *pre_e = iteator->next->e;
    iteator->next->e = e;
  }else{
    iteator = list->rear;
    position = list->length - position - 1;
    for(int i=0;i<position;i++){
      iteator = iteator->pre;
    }
    *pre_e = iteator->pre->e;
    iteator->pre->e = e;
  }
  return 1;
}

int sb_remove_position_linkedlist(sb_linkedlist *list,int position,sb_element *e){
  assert(list!=NULL);
  if(position<0||position>=list->length)
    return 0;
  sb_linkedlist_node *iteator = NULL;
  if(position<=list->length/2){
    iteator = list->head;
    for(int i=0;i<position;i++){
      iteator = iteator->next;
    }
    if(e!=NULL)
      *e = iteator->next->e;
    sb_linkedlist_node *temp = iteator->next->next;
    free(iteator->next);
    iteator->next= temp;
    temp->pre = iteator;
  }else{
    iteator = list->rear;
    position = list->length - position -1;
    for(int i=0;i<position;i++){
      iteator = iteator->pre;
    }
    *e = iteator->pre->e;
    sb_linkedlist_node *temp = iteator->pre->pre;
    free(iteator->pre);
    iteator->pre= temp;
    temp->next = iteator;
  }
  list->length--;
  return 1;
}
int sb_clear_linkedlist(sb_linkedlist *list){
  assert(list!=NULL);
  for(int i=0;i<list->length;i++){
    sb_remove_position_linkedlist(list,0,NULL);
  }
  /*  list->head->next = list->rear;
  list->rear->pre = list->head;
  list->length = 0;*/
  return 1;
}
