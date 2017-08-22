#include "sb_collection.h"

int sb_init_stack(sb_stack *s, int size){
  arraylist *list = (arraylist*)s;
  return sb_init_arraylist(list,size);
}
int sb_push_stack(sb_stack *s,sb_element e){
  arraylist *list = (arraylist*)s;
  return sb_insert_arraylist(list,e,list->length);
}
int sb_top_stack(sb_stack *s,sb_element *e){
  arraylist *list = (arraylist*)s;
  return sb_get_arraylist(list,list->length-1,e);
}
int sb_pop_stack(sb_stack*s,sb_element *e){
  arraylist *list = (arraylist*)s;
  return sb_remove_position_arraylist(list,list->length-1,e);
}
int sb_clear_stack(sb_stack *s){
  arraylist *list = (arraylist*)s;
  return sb_clear_arraylist(list);
}
