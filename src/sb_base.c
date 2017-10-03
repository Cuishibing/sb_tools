#include "sb_base.h"

void sb_swap(sb_element* elements,int first,int second){
	sb_element temp = elements[first];
    elements[first] = elements[second];
    elements[second] = temp;
}

int sb_compare(sb_element first, sb_element second){
    return first.key - second.key;
}

int sb_equals(sb_element first, sb_element second){
    if(first.key==second.key&&first.value==second.value)
      return 1;
    return 0;
}
