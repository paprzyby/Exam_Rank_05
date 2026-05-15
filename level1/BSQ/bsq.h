#pragma once

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bsq
{
    int  lines_len;
    char empty_char;
    char obst_char;
    char full_char;
    char **map;
} t_bsq;
