#ifndef SB_BASE_H_
#define SB_BASE_H_

typedef struct element_{
  int key;
  void* value;
}sb_element;
int sb_compare(sb_element first,sb_element sedond);

int sb_equals(sb_element first,sb_element second);

void sb_swap(sb_element* elements,int first,int second);
#endif
