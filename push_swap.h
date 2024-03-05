#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf.h"

typedef struct  s_stack
{
    int             value;
    int             pos;
    int             tar;
    int             cost;
    struct s_stack  *prev;
    struct s_stack  *next;
    struct s_stack  *target;
}               t_stack;

void    ini_stack(t_stack **a, char **argv);

#endif