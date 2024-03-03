#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

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

char    **ft_split(char *s, char sep);



#endif