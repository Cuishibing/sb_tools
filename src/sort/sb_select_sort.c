#include <stdio.h>
#include <stdlib.h>
#include "sb_base.h"
#include "sb_sort.h"

/*
  调整堆
*/
void select_sort_adjust_heap(sb_element *array,int need_adjust,int end);

/*
  顺序查找极值
*/
int select_sort_find_extremum_linear(sb_element *array,int start,int end);

/*
  构建一个堆
*/
void select_sort_build_heap(sb_element *array,int index);

void sb_select_sort(sb_element *array,int length,TYPE type){
    switch(type){
        case LINEAR:{
            int min_index;
            for(int i=0;i<length;i++){
                min_index = select_sort_find_extremum_linear(array, i, length-1);
                sb_swap(array,i,min_index);
            }
        }break;
        case HEAP:{
            for(int i=1;i<length;i++){
                select_sort_build_heap(array, i);
            }
            for(int i=length-1;i>0;i--){
                sb_swap(array,0,i);
                select_sort_adjust_heap(array, 0, i-1);
            }
        }break;
    }
}

void select_sort_build_heap(sb_element *array,int index){
    if(index<=0)
        return;
    int parent = (index-1) / 2;
    if(sb_compare(array[parent],array[index])>=0){//parent>=index
        if(index%2==0){//是偶数,说明是右儿子
            int brother = index - 1;
            if(sb_compare(array[brother],array[index])<0){//brother<index
                sb_swap(array,brother,parent);
            }else{
                sb_swap(array,index,parent);
                select_sort_build_heap(array, parent);
            }
        }else {//是奇数,说明是左儿子
            sb_swap(array,index,parent);
            select_sort_build_heap(array, parent);
        }
    }

}

void select_sort_adjust_heap(sb_element *array,int start,int end){
    int left_child = start *2 + 1;
    int right_child = left_child + 1;
    if(right_child<=end){//既有左儿子又有右儿子
        if(sb_compare(array[start],array[left_child])>0||
           sb_compare(array[start],array[right_child])>0){//start>left_child||start>right_child
            if(sb_compare(array[left_child],array[right_child])<0){//left_child<right_child
                sb_swap(array,left_child,start);
                select_sort_adjust_heap(array, left_child, end);
            }else{
                sb_swap(array,right_child,start);
                select_sort_adjust_heap(array, right_child, end);
            }
        }
    }else if(left_child<=end){//只有左儿子
        if(sb_compare(array[start],array[left_child])>0){//start>left_child
            sb_swap(array,start,left_child);
        }
    }
}

/*
  default find extremum function.
*/
int select_sort_find_extremum_linear(sb_element *array,int start,int end){
    sb_element min = array[start];
    int min_index = start;
    for(int i=start+1;i<=end;i++){
        if(sb_compare(array[i],min)<0){
            min = array[i];
            min_index = i;
        }
    }
    return min_index;
}
