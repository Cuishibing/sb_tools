#ifndef SB_CELLECTION_H_
#define SB_CELLECTION_H_

#include "sb_base.h"

/**
 * 线性表结构体
 * */
typedef struct array_list{
  int length;//当前元素的个数
  int size;//表的大小
  sb_element *elements;//存放元素的数组
}sb_arraylist;

/**
 * 初始化arraylist
 * @param list 要初始化的线性表
 * @param size 初始线性表的大小
 * @return 0:初始化失败
 *         1:初始化成功
 * */
int sb_init_arraylist(sb_arraylist *list,int size);

/**
 * 往arraylist里插入一个元素
 * @param list 要插入的线性表
 * @param position 要插入的位置
 * @param e 要插入的元素
 * @return 0:失败
 *         1:成功
 * */
int sb_insert_arraylist(sb_arraylist *list,sb_element e,int position);

/**
 * 获取指定位置的元素
 * @param list 获取元素的线性表
 * @param position 位置
 * @param e 存放获取到的元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_get_arraylist(sb_arraylist *list,int position,sb_element *e);

/**
 * 替换指定位置的元素
 * @param list 被替换元素的线性表
 * @param position 要替换元素的位置
 * @param new_e 新的元素
 * @param pre_e 存放先前的元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_set_arraylist(sb_arraylist *list,int position,sb_element new_e,sb_element *pre_e);

/**
 * 移除指定位置的元素
 * @param list 操作的线性表
 * @param position 要移除元素的位置
 * @param e 存放移除的元素
 * @return 0:失败
 *         1:成功
 * */
int sb_remove_position_arraylist(sb_arraylist *list,int position,sb_element *e);

/**
 * 清除线性表中的全部元素,回复到初始状态
 * @param list 要清除的线性表
 * @param release_value 释放线性表中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_clear_arraylist(sb_arraylist *list,void(*release_value)(void*));

/**
 * 释放一个线性表所占的内存,要求该线性表必须是存放在堆上的
 * @param list 要释放的线性表
 * @param release_value 释放线性表中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_free_arraylist(sb_arraylist **list,void(*release_value)(void*));

/**
 * 链表节点结构体,双向
 * */
typedef struct linked_list_node_{
  sb_element e;
  struct linked_list_node_ *next;
  struct linked_list_node_ *pre;
}sb_linkedlist_node;

/**
 * 双向链表结构体
 * */
typedef struct linked_list_{
  int length;//链表中元素的个数
  sb_linkedlist_node *head;
  sb_linkedlist_node *rear;
}sb_linkedlist;

/**
 * 初始化linkedlist
 * @param list 要初始化的链表
 * @return 0:初始化失败
 *         1:初始化成功
 * */
int sb_init_linkedlist(sb_linkedlist *list);

/**
 * 向链表中的指定位置插入一个元素
 * @param list 要插入的链表
 * @param e 要插入的元素
 * @param position 位置
 * @return 0:初始化失败
 *         1:初始化成功
 * */
int sb_insert_linkedlist(sb_linkedlist *list,sb_element e,int position);

/**
 * 在链表的头部插入一个元素
 * @param list 要插入的链表
 * @param e 要插入的元素
 * @return 0:初始化失败
 *         1:初始化成功
 * */
int sb_insert_linkdelist_head(sb_linkedlist *list,sb_element e);

/**
 * 获取指定位置的元素
 * @param list 操作的链表
 * @param position 位置
 * @param e 存放获取到的元素的指针
 * @return 0:初始化失败
 *         1:初始化成功
 * */
int sb_get_linkedlist(sb_linkedlist *list,int position,sb_element *e);

/**
 * 替换指定位置的元素
 * @param list 操作的链表
 * @param position 要替换元素的位置
 * @param new_e 新的元素
 * @param pre_e 存放先前的元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_set_linkedlist(sb_linkedlist *list,int position,sb_element e,sb_element *pre_e);

/**
 * 移除指定位置的元素
 * @param list 操作的链表
 * @param position 要移除元素的位置
 * @param e 存放移除的元素
 * @return 0:失败
 *         1:成功
 * */
int sb_remove_position_linkedlist(sb_linkedlist *list,int position,sb_element *e);

/**
 * 清除链表中的全部元素,回复到初始状态
 * @param list 要清除的链表
 * @param release_value 释放链表中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_clear_linkedlist(sb_linkedlist *list,void(*release_value)(void*));

/**
 * 释放一个链表所占的内存,要求该链表必须是存放在堆上的
 * @param list 要释放的链表
 * @param release_value 释放链表中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_free_linkedlist(sb_linkedlist **list_ptr,void(*release_value)(void*));

/**
 * 队列的结构体,队列采用链表来实现
 * */
typedef sb_linkedlist sb_queue;

/**
 * 初始化队列
 * @param q 要初始化的队列
 * @return 0:失败
 *         1:成功
 * */
int sb_init_queue(sb_queue *q);

/**
 * 将一个元素入队
 * @param q 要操作的队列
 * @param e 要入队的元素
 * @return 0:失败
 *         1:成功
 * */
int sb_enqueue(sb_queue *q,sb_element e);

/**
 * 将一个元素出队
 * @param q 要操作的元素
 * @param e 存放出队元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_dequeue(sb_queue *q,sb_element *e);

/**
 * 清除队列中所有的元素
 * @param q 要清除的队列
 * @param release_value 释放队列中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_clear_queue(sb_queue *q,void(*release_value)(void*));

/**
 * 释放一个队列所占的内存,要求队列是存放在堆上的
 * @param queue 要释放队列的地址的指针
 * @param release_value 释放队列中元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_free_queue(sb_queue **queue,void(*release_value)(void*));

/**
 * 栈的结构体,使用线性表实现
 * */
typedef sb_arraylist sb_stack;

/**
 * 初始化一个栈
 * @param s 要初始化的栈
 * @param size 初始化的大小
 * @return 0:失败
 *         1:成功
 * */
int sb_init_stack(sb_stack *s,int size);

/**
 * 将一个元素入栈
 * @param s 要操作的栈
 * @param e 要入栈的元素
 * @return 0:失败
 *         1:成功
 * */
int sb_push_stack(sb_stack *s,sb_element e);

/**
 * 获取栈顶元素
 * @param s 要操作的栈
 * @param e 存放栈顶元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_top_stack(sb_stack *s,sb_element *e);

/**
 * 将一个元素出栈
 * @param s 要操作的栈
 * @param e 存放出栈元素的指针
 * @return 0:失败
 *         1:成功
 * */
int sb_pop_stack(sb_stack*s,sb_element *e);

/**
 * 清除栈内所有的元素
 * @param s 要清除的栈
 * @param release_value 释放栈内元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_clear_stack(sb_stack *s,void(*release_value)(void*));

/**
 * 释放一个栈所占用的内存,要求栈必须是存放在堆上的
 * @param stack 要释放栈的地址的指针
 * @param release_value 释放栈内元素的方法
 * @return 0:失败
 *         1:成功
 * */
int sb_free_stack(sb_stack **stack,void(*release_value)(void*));
#endif