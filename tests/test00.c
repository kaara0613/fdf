#include "../fdf.h"
#include <stdio.h>
int main()
{
    int a[5] = {4, 123, 23, 3, 6};
    char *str;

    str = int_array_to_string(a);
    printf("int_array_to_string \"%s\"\n", str);
    return (0);
}