#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sb_collection.h"
#include "sb_tree.h"

void printf_tree(sb_bs_tree bs_tree){
    sb_element e;
    arraylist list;
    sb_init_arraylist(&list,10);
    sb_traversal_bs_tree(&bs_tree,&list,PRE);
    for (int j = 0; j < list.length; ++j) {
        sb_get_arraylist(&list,j,&e);
        sb_tree_node *node = (sb_tree_node*)e.value;
        printf("%d ",node->e.key);
    }
    printf("\n");
    printf("%d\n",list.length);
    sb_clear_arraylist(&list);
}

int get_array_length(){
    return 0;
}

int main() {
    sb_bs_tree bs_tree;
    sb_init_bs_tree(&bs_tree);
    sb_tree_node node;
    sb_element e;
    int length = 10;
    for (int i = 0; i <=length; ++i) {
        e.key = i;
        node.e = e;
        sb_insert_avl_tree(&bs_tree,node);
    }

    printf("%d\n",calculate_tree_height(&bs_tree));
    printf_tree(bs_tree);
    sb_tree_node *result = NULL;
    sb_get_bs_tree(&bs_tree,length,&result);
    printf("%d \n",result->e.key);
    return 0;
}

