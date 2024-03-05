#include <stdio.h>

int occurances(char **argv, int sep)
{
    int i;
    int j;
    int ocs;

    i = 1;
    ocs = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])    
        {
            if (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
                ocs++;
            while (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
                j++;
            if (argv[i][j] == sep && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
                j++;
            j++;
        }
        i++;
    }
    return (ocs);
}

int main(int argc, char **argv)
{
    printf("%d\n", occurances(argv, ' '));
}