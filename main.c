#include <stdio.h>
#include <sb_sort.h>

int main() {
    int array_data[10] = {4,2,4,4,8,-1,34,99,-10,-2};
    sb_element array[10];
    for(int i=0;i<10;i++){
        array[i].key = array_data[i];
    }
    sb_select_sort(array,10,HEAP);
    for(int i=0;i<10;i++){
        printf("%d ",array[i].key);
    }
    return 0;
}

