#ifndef SB_SORT_H_
#define SB_SORT_H_

#include "sb_base.h"

/**
 * 常用的排序算法
 * */

/**
 * 插入排序
 * */
void sb_insert_sort(sb_element *array,int length);

/**
 * 归并排序
 * */
void sb_merge_sort(sb_element *array,int length);

/**
 * 快速排序
 * */
void sb_quick_sort(sb_element *array,int length);

/**
 * 选择排序的两种选择极值的方法
 * */
typedef enum {
  LINEAR,//使用线性查找查找极值
  HEAP//使用堆结构查找极值
}TYPE;

/**
 * 选择排序
 * */
void sb_select_sort(sb_element *array,int length,TYPE type);

/**
 * shell排序
 * */
void sb_shell_sort(sb_element *array,int length,int *increments,int increment_length);

#endif
