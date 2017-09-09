#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sb_collection.h"
#include "sb_tree.h"

void printf_tree(sb_bs_tree bs_tree){
    sb_element e;
    arraylist list;
    sb_init_arraylist(&list,10);
    sb_traversal_avl_tree(&bs_tree,&list,PRE);
    for (int j = 0; j < list.length; ++j) {
        sb_get_arraylist(&list,j,&e);
        sb_tree_node *node = (sb_tree_node*)e.value;
        printf("%d ",node->e.key);
    }
    printf("\n");
    sb_clear_arraylist(&list);
}



int main() {
    sb_tree_node *avl_tree = NULL;
    sb_tree_node node;
    sb_element element;

    for(int i=0;i<=10;i++) {
        element.key = i;
        node.e = element;
        sb_insert_avl_tree(&avl_tree, node);
    }

    printf_tree(*avl_tree);
    sb_tree_node *result_store = NULL;

    sb_get_avl_tree(avl_tree,3,&result_store);
    sb_remove_avl_tree(&avl_tree,result_store);

    sb_get_avl_tree(avl_tree,4,&result_store);
    sb_remove_avl_tree(&avl_tree,result_store);

    sb_get_avl_tree(avl_tree,6,&result_store);
    sb_remove_avl_tree(&avl_tree,result_store);

    printf_tree(*avl_tree);
    return 0;
}

