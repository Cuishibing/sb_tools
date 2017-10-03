#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "sb_collection.h"

void back_move_arraylist(sb_arraylist *list, int position);

void pre_move_arraylist(sb_arraylist *list, int position);

int need_expand_arraylist(sb_arraylist *list);

int expand_arraylist(sb_arraylist *list);

int sb_init_arraylist(sb_arraylist *list, int size) {
    assert(list != NULL);
    assert(size > 0);
    list->length = 0;
    list->size = size;
    list->elements = (sb_element *) malloc(sizeof(sb_element) * list->size);
    if (list->elements == NULL) {
        perror("no heap space\n");
        return 0;
    }
    return 1;
}

int sb_insert_arraylist(sb_arraylist *list, sb_element e, int position) {
    assert(list != NULL);
    if (position < 0 || position > list->length)
        return 0;
    if (need_expand_arraylist(list))
        expand_arraylist(list);
    back_move_arraylist(list, position);
    list->elements[position] = e;
    list->length++;
    return 1;
}

int sb_get_arraylist(sb_arraylist *list, int position, sb_element *e) {
    assert(list != NULL);
    if (position < 0 || position >= list->length)
        return 0;
    if (e == NULL)
        return 0;
    *e = list->elements[position];
    return 1;
}

int sb_set_arraylist(sb_arraylist *list, int position, sb_element e, sb_element *pre_e) {
    assert(list != NULL);
    assert(pre_e != NULL);
    if (position < 0 || position >= list->length)
        return 0;
    *pre_e = list->elements[position];
    list->elements[position] = e;
    return 1;
}

int sb_remove_position_arraylist(sb_arraylist *list, int position, sb_element *e) {
    assert(list != NULL);
    if (position < 0 || position >= list->length)
        return 0;
    if (e != NULL)
        *e = list->elements[position];
    pre_move_arraylist(list, position);
    list->length--;
    return 1;
}

void back_move_arraylist(sb_arraylist *list, int position) {
    for (int i = list->length - 1; i >= position; i--) {
        list->elements[i + 1] = list->elements[i];
    }
}

void pre_move_arraylist(sb_arraylist *list, int position) {
    for (int i = position; i < list->length - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
}

int need_expand_arraylist(sb_arraylist *list) {
    if ((list->length + 1) > (list->size))
        return 1;
    return 0;
}

int expand_arraylist(sb_arraylist *list) {
    int temp = list->size;
    list->size = temp + list->size >> 1;//扩展为原来的1.5倍
    if (temp == list->size)//当初始大小为1的情况时
        list->size += 1;
    //  printf("list size:%d\n",list->size);
    list->elements = (sb_element *) realloc(list->elements, sizeof(sb_element) * list->size);
    return 1;
}

int sb_clear_arraylist(sb_arraylist *list, void(*release_value)(void *)) {
    assert(list != NULL);
    assert(release_value != NULL);
    sb_element temp_e;
    for (int i = list->length - 1; i >= 0; i--) {
        sb_remove_position_arraylist(list, i, &temp_e);
        release_value(temp_e.value);
    }
    list->length = 0;
    return 1;
}

int sb_free_arraylist(sb_arraylist **list, void(*release_value)(void *)) {
    assert(list != NULL);
    sb_arraylist *list_rea = *list;
    assert(list_rea != NULL);
    sb_clear_arraylist(list_rea, release_value);
    free(list_rea->elements);
    free(list_rea);
    *list = NULL;
    return 1;
}
