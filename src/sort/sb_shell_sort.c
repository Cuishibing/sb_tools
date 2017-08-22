#include <stdio.h>
#include "sb_base.h"


void sb_shell_sort(sb_element *array,int length,int *increments,int increment_length){

  for(int i=0;i<increment_length;i++){
    int increment = increments[i];
    int k;
    for(int j=increment;j<length;j++){
      sb_element temp = array[j];
      for(k=j;k>=increment;k=k-increment){//这里是一个简单的插入排序
	if(sb_compare(temp,array[k-increment])<0){//temp<array[k-increment]
	  array[k] = array[k-increment];
	}else break;
      }
      array[k] = temp;
    }
  }
}
