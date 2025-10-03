#include <list.h>
#include <errno.h>

list_t *list_create() {
    list_t *list = malloc(sizeof(list_t));
    if (!list) {
        printf("list create failed, with memory allocation: %s\n", strerror(errno));
        return NULL;
    }

    list->head = NULL;
    
    return list;
}



void list_destroy(list_t *list) {
    //make destroying to all nodes
    //not all
    free(list);
}

