#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int     i;

    a = NULL;
    b = NULL;
    i = 1;
    if ((argc == 1) || (argc == 2 && !argv[1]))
        return 1;
    if (argc >= 2)
        argv = ft_split(argv, ' ');
    ini_stack(&a, argv);
    while (a)
    {
        printf("%d\n", a->value);
        a = a->next;
    }
}