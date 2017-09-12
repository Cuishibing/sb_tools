#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sb_tree.h"




int main() {
    char *my_name = (char*)malloc(sizeof(char)*11);
    strcpy(my_name,"cuishibing");
    sb_element e;
    e.value = my_name;
    sb_map map;
    sb_init_map(&map);
    sb_insert_map(&map,"cui",4,e);
    sb_element delete;
    if(sb_remove_map(&map,"cui",4,&delete))
        //printf("%s\n",delete.value);
    free(delete.value);
    printf("%s\n",my_name);
    return 0;
}

