#include "list.h"
#include "ft_printf.h"
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
    ft_printf("%d\n", list_int_pop(&list));
    ft_printf("%d\n", list_int_pop(&list));
    list_int_print(list);
    list_void_clear(list);
    return (0);
}