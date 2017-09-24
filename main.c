#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sb_tree.h"




int main() {
    sb_avl_tree *tree = NULL;
    sb_element element;
    sb_tree_node node;
    int data[] = {0,3,2};
    for(int i=0;i<3;i++){
        element.key = data[i];
        node.e = element;
        sb_insert_avl_tree(&tree,node);
    }
    return 0;
}

