//
// Created by cui on 17-9-12.
//

#include <sb_tree.h>
#include <wchar.h>
#include <assert.h>
#include <stdlib.h>

int get_key_map(void *key,size_t key_size);
        int sb_init_map(sb_map *map){
    if (map==NULL){
        return 0;
    }
    map->length = 0;
    map->tree = NULL;
    return 1;
}

int sb_insert_map(sb_map *map,void *key,size_t key_size,sb_element e){
    if(map==NULL||key==NULL)
        return 0;
    int key_int = get_key_map(key,key_size);
    e.key = key_int;
    sb_tree_node node;
    node.e = e;
    if(sb_insert_avl_tree(&map->tree,node)){
        map->length++;
        return 1;
    }
    return 0;
}

int sb_get_map(sb_map *map,void *key,size_t key_size,sb_element *result){
    if(map==NULL||key==NULL)
        return 0;
    int key_int = get_key_map(key,key_size);
    sb_tree_node *result_node = NULL;
    if (sb_get_avl_tree(map->tree,key_int,&result_node)){
        if(result_node!=NULL){
            if(result!=NULL){
                *result = result_node->e;
            }
        }
        return 1;
    } else
        return 0;
}

int sb_remove_map(sb_map *map,void *key,size_t key_size,sb_element *deleted_elements){
    if(map==NULL||key==NULL)
        return 0;
    int key_int = get_key_map(key,key_size);
    sb_tree_node *need_remove_node = NULL;
    if (sb_get_avl_tree(map->tree,key_int,&need_remove_node)){
        if(need_remove_node!=NULL){
            if(deleted_elements!=NULL){
                *deleted_elements = need_remove_node->e;
            }
            if(sb_remove_avl_tree(&map->tree,need_remove_node)){
                map->length--;
                return 1;
            } else return 0;
        }
        return 1;
    }else {
        return 0;
    }
}

int sb_clear_map(sb_map *map,void(*release_value)(void*)){
    assert(map != NULL);
    sb_clear_avl_tree(map->tree,release_value);
    map->length = 0;
    return 1;
}

int sb_free_map(sb_map *map,void(*release_value)(void*)){
    assert(map != NULL);
    sb_clear_map(map,release_value);
    sb_free_avl_tree(map->tree,release_value);
    free(map);
    return 1;
}

int get_key_map(void *key,size_t key_size) {
    int key_int = 0,i;
    char *key_8_bit = (char*)key;
    for(i=0;i<key_size;i++){
        key_int = (*key_8_bit++) + (key_int<< 6) + (key_int << 16) - key_int;
    }
    return (key_int & 0x7FFFFFFF);
}