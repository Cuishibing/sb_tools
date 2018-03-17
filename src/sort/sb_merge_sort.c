#include <stdlib.h>
#include <stdio.h>
#include "sb_base.h"


void merge_sort_real(sb_element *array,sb_element *result_store,int start,int end);

void sb_merge_sort(sb_element *array,int length){
  sb_element *result_store = (sb_element*)malloc(sizeof(sb_element)*length);
  merge_sort_real(array,result_store,0,length-1);
  free(result_store);
}

void merge_sort_real(sb_element *array,sb_element *result_store,int start,int end){
  //  printf("start:%d end:%d\n",start,end);
  if(start==end)
    return;
  if((start+1)==end){//已经只有两个元素了
    if(sb_compare(array[start],array[end])>=0)//start>=end
      sb_swap(array,start,end);
    return;
  }
  int middle = (start + end) / 2;
  merge_sort_real(array, result_store, start, middle);
  merge_sort_real(array, result_store, middle+1, end);

  //合并
  int left_index = start,left_end = middle;
  int right_index = middle+1,right_end = end;
  int result_index = 0;
  while(1){
    if(left_index>left_end){//左边数据已经取完了
      for(;right_index<=right_end;right_index++){//把右边的数据合并
	result_store[result_index++] = array[right_index];
      }
      break;
    }
    if(right_index>right_end){//右边数据已经取完了
      for(;left_index<=left_end;left_index++){
	result_store[result_index++] = array[left_index];
      }
      break;
    }
    if(sb_compare(array[left_index],array[right_index])<0)//left_index<right_index
      result_store[result_index++] = array[left_index++];
    else result_store[result_index++] = array[right_index++];
  }
  //把临时数据拷贝回源数据源中
  for(int i=0,j=start;i<result_index;i++,j++){
    array[j] = result_store[i];
  }
}
