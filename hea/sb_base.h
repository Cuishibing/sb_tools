#ifndef SB_BASE_H_
#define SB_BASE_H_

/**
 * 基本元素的结构体
 * */
typedef struct element_ {
    int key;//存放数值型数据
    void *value;//存放指针型数据
} sb_element;

/**
 * 比较两个element的大小,实际上是比较key的值,如果元素内部的引用影响元素的大小请转化到key的大小上.
 * @param first 要比较的第一个元素
 * @param second 要比较的第二个元素
 * @return 比较的结果
 *         大于0:first > second;
 *         小于0:first < second;
 *         等于0:first = second;
 * */
int sb_compare(sb_element first, sb_element second);

/**
 * 比较两个元素是否相等,key和value都要相等
 * @param first 要比较的第一个元素
 * @param second 要比较的第二个元素
 * @return 比较的结果
 *         非0:first不等于second;
 *         等于0:first = second;
 * */
int sb_equals(sb_element first, sb_element second);

/**
 * 交换两个元素
 * @param first 要交换的第一个元素
 * @param second 要交换的第二个元素
 * @param elements 元素所在的数组
 * */
void sb_swap(sb_element *elements, int first, int second);

#endif
