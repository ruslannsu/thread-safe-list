#include <list.h>
#include <errno.h>

list_t *list_create() {
    list_t *list = malloc(sizeof(list_t));
    if (!list) {
        errno = ENOMEM;
        return NULL;
    }

    list->head = NULL;
    
    return list;
}


int list_add_back(list_t *list, int val) {
    if (!list) {
        errno  = EINVAL;
        return -1;
    }

    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        errno = ENOMEM;
        return -1;
    }

    node->val = val;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
        return 0;
    }

    node_t *tmp = list->head;
    while (!tmp->next) {
        tmp = tmp->next;
    } 
    
    tmp->next = node;
    return 0;
}



void list_destroy(list_t *list) {
    if (!list->head) {
        free(list);
        return;
    }

    node_t *tmp = list->head;
    while (!tmp) {
        node_t *destroyed_node = tmp;
        tmp = tmp->next;
        free(destroyed_node); 
    }
    
    free(list);
}

