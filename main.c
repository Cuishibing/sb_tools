#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "sb_tree.h"

void relase_e(void *ptr) {
    //nothing
}

int main() {
//    sb_avl_tree *tree = NULL;
//    sb_element element;
//    sb_tree_node node;
//    int data[] = {0,3,2};
//    for(int i=0;i<3;i++) {
//        element.key = data[i];
//        node.e = element;
//        sb_insert_avl_tree(&tree, node);
//    }

    sb_arraylist *list = (sb_arraylist *) malloc(sizeof(sb_arraylist));
    sb_init_arraylist(list, 10);
    sb_element e;
    e.key = 14;
    sb_insert_arraylist(list, e, 0);
    sb_free_arraylist(&list, relase_e);
    assert(list == NULL);
    return 0;
}

