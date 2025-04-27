#include "list.h"
#include <stdlib.h>

int main(void)
{
    t_list *list;

    list = NULL;
    list_int_push(&list, 10);
    list_int_push(&list, 100);
    list_int_push(&list, 1000);
    list_int_push(&list, 10000);
    list_int_print(list);
    list_void_clear(list);
    return (0);
}
