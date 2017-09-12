#include "sb_base.h"
/*
  二分查找
*/
int insert_sort_binary_search(sb_element *array,int start,int end,sb_element target);

void sb_insert_sort(sb_element *array,int length){
  sb_element temp;
  for(int i=1;i<length;i++){
    temp = array[i];
    int position = insert_sort_binary_search(array,0,i,temp);
    for(int j=i;j>=position;j--){
      array[j] = array[j-1];
    }
    array[position] = temp;
  }
}

int insert_sort_binary_search(sb_element *array,int start,int end,sb_element target){
  if(start==end||(end-start)==1){
    if(sb_compare(target,array[start])<0)
      return start;
    else return start+1;
  }
  int middle = (start + end) / 2;
  if(sb_compare(target,array[middle])>0)
    insert_sort_binary_search(array, middle, end, target);
  else if(sb_compare(target,array[middle])<0)
    insert_sort_binary_search(array, start, middle, target);
  else return middle;
}