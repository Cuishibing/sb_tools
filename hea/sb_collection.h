#ifndef SB_CELLECTION_H_
#define SB_CELLECTION_H_

#include "sb_base.h"

typedef struct array_list{
  int length;
  int size;
  sb_element *elements;
}sb_arraylist;
int sb_init_arraylist(sb_arraylist *list,int size);
int sb_insert_arraylist(sb_arraylist *list,sb_element e,int position);
int sb_get_arraylist(sb_arraylist *list,int position,sb_element *e);
int sb_set_arraylist(sb_arraylist *list,int position,sb_element e,sb_element *pre_e);
int sb_remove_position_arraylist(sb_arraylist *list,int position,sb_element *e);
int sb_clear_arraylist(sb_arraylist *list);

typedef struct linked_list_node_{
  sb_element e;
  struct linked_list_node_ *next;
  struct linked_list_node_ *pre;
}sb_linkedlist_node;

typedef struct linked_list_{
  int length;
  sb_linkedlist_node *head;
  sb_linkedlist_node *rear;
}sb_linkedlist;
int sb_init_linkedlist(sb_linkedlist *list);
int sb_insert_linkedlist(sb_linkedlist *list,sb_element e,int position);
int sb_insert_linkdelist_head(sb_linkedlist *list,sb_element e);
int sb_get_linkedlist(sb_linkedlist *list,int position,sb_element *e);
int sb_set_linkedlist(sb_linkedlist *list,int position,sb_element e,sb_element *pre_e);
int sb_remove_position_linkedlist(sb_linkedlist *list,int position,sb_element *e);
int sb_clear_linkedlist(sb_linkedlist *list);

typedef sb_linkedlist sb_queue;
int sb_init_queue(sb_queue *q);
int sb_enqueue(sb_queue *q,sb_element e);
int sb_dequeue(sb_queue *q,sb_element *e);
int sb_clear_queue(sb_queue *q);

typedef sb_arraylist sb_stack;
int sb_init_stack(sb_stack *s,int size);
int sb_push_stack(sb_stack *s,sb_element e);
int sb_top_stack(sb_stack *s,sb_element *e);
int sb_pop_stack(sb_stack*s,sb_element *e);
int sb_clear_stack(sb_stack *s);
#endif
