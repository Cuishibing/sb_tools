#include <stdio.h>
#include "sb_base.h"

int get_key(sb_element *array,int start,int end);

void quick_sort_real(sb_element *array,int start,int end);

int get_key(sb_element *array,int start,int end){
  int middle = (end + start) / 2;
  return middle;//暂时返回数据的中间元素作为枢杻元
}

void quick_sort_real(sb_element *array,int start,int end){
  if(!(start<end&&start>-1)){
    return;
  }
  int left_index = start;
  int right_index = end - 1;
  int key = get_key(array,start,end);
  sb_swap(array,key,end);//先把枢纽元和最后一个元素交换
  while(1){
    while(sb_compare(array[left_index],array[end])<0){//left_index<end
      left_index++;
    }
    while(sb_compare(array[right_index],array[end])>0||
	  sb_compare(array[right_index],array[end])==0){//right_index>=end
      right_index--;
    }
    if(left_index<right_index){
      sb_swap(array,left_index,right_index);
    }else{
      sb_swap(array,left_index,end);
      break;
    }
  }
  quick_sort_real(array,start,left_index-1);
  quick_sort_real(array,left_index+1,end);
}

void sb_quick_sort(sb_element *array,int length){
  quick_sort_real(array,0,length-1);
}
