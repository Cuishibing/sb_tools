#include <stdio.h>
#include "sb_base.h"

int get_key(sb_element *array, int start, int end);

void quick_sort_real(sb_element *array, int start, int end);

int get_key(sb_element *array, int start, int end) {
    return (end + start) / 2;;//暂时返回数据的中间元素作为枢杻元
}

int quick_sort_partition(sb_element *array,int start,int end){
    int key = get_key(array,start,end);
    sb_element temp_ele = array[key];
    while(start<end){
        while(sb_compare(array[end],temp_ele)>=0&&end>start){
            end--;
        }
        array[start] = array[end];
        while(sb_compare(array[start],temp_ele)<=0&&end>start){
            start++;
        }
        array[end] = array[start];
    }
    array[end] = temp_ele;
    return key;
}

void quick_sort_real_1(sb_element *array,int start,int end){
    if(start >= end){
        return;
    }
    int key = quick_sort_partition(array,start,end);
    quick_sort_real_1(array,start,key-1);
    quick_sort_real_1(array,key+1,end);
}

void quick_sort_real(sb_element *array, int start, int end) {
    if (start > end) {
        return;
    }
    int left_index = start;
    int right_index = end - 1;
    int key = get_key(array, start, end);
    sb_swap(array, key, end);//先把枢纽元和最后一个元素交换
    while (1) {
        while (left_index < end && sb_compare(array[left_index], array[end]) <= 0) {
            left_index++;
        }
        while (right_index > start && sb_compare(array[right_index], array[end]) >= 0) {
            right_index--;
        }
        if (left_index < right_index) {
            sb_swap(array, left_index, right_index);
        } else {
            sb_swap(array, left_index, end);
            quick_sort_real(array, start, left_index - 1);
            quick_sort_real(array, left_index + 1, end);
            break;
        }
    }
}

void sb_quick_sort(sb_element *array, int length) {
    quick_sort_real(array, 0, length - 1);
}
