#include "bsq.h"

t_bsc   *init_bsq(void)
{
    t_bsq *bsq;

    bsq = malloc(sizeof(t_bsq));
    if (!bsq)
        return (NULL);
    return (bsq);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {

    }
}
