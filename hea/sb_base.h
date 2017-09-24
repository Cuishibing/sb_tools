#ifndef SB_BASE_H_
#define SB_BASE_H_

typedef struct element_{
  int key;
  void* value;
}sb_element;

/*
 * 比较两个element的大小，在这个实现里只是比较key的值
 * first > second：大于0
 * first < second：小于0
 * first == second：0
 * */
int sb_compare(sb_element first,sb_element second);

/*
 * 比较两个元素是否相等
 * 相等：非0
 * 不相等：0
 * */
int sb_equals(sb_element first,sb_element second);

/*
 * 交换两个element元素
 * */
void sb_swap(sb_element* elements,int first,int second);
#endif
