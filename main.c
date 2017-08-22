#include <stdio.h>
#include "sb_collection.h"
int main() {
    arraylist arraylist1;
    sb_init_arraylist(&arraylist1,10);
    sb_element e;
    e.key = 14;
    sb_insert_arraylist(&arraylist1,e,0);
    printf("%d\n",arraylist1.length);
    sb_element result;
    sb_get_arraylist(&arraylist1,0,&result);
    printf("%d\n",result.key);
    return 0;
}