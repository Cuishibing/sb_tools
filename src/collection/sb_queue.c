#include <assert.h>
#include <stddef.h>
#include "sb_collection.h"

int sb_init_queue(sb_queue *q){
  sb_linkedlist *list = (sb_linkedlist*)q;
  return sb_init_linkedlist(list);
}
int sb_enqueue(sb_queue *q,sb_element e){
  sb_linkedlist *list = (sb_linkedlist*)q;
  return sb_insert_linkedlist(list,e,0);
}
int sb_dequeue(sb_queue *q,sb_element *e){
  sb_linkedlist *list = (sb_linkedlist*)q;
  return sb_remove_position_linkedlist(list,list->length-1,e);
}
int sb_clear_queue(sb_queue *q,void(*release_value)(void*)){
  sb_linkedlist *list = (sb_linkedlist*)q;
  return sb_clear_linkedlist(list,release_value);
}

int sb_free_queue(sb_queue **queue,void(*release_value)(void*)){
    return sb_free_linkedlist(queue,release_value);
}
