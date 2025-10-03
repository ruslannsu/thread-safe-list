#include <stdlib.h>

typedef struct _Node {
    int val;
    node_t *next;
}node_t; 


typedef struct _List {
    node_t *head
}list_t;


list_t *list_create();

void list_add(list_t *list, int val);

void list_del_last(list_t *list);

void list_destroy(list_t *list);








