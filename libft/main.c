#include "libft.h"

int main(int argc, char **argv)
{
    char **aaa = ft_split(argv, ' ');
    for (int i = 0; aaa[i]; i++)
        printf("%s\n", aaa[i]);
}