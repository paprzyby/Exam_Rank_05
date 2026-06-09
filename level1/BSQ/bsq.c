#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int is_printable(char c)
{
    if (c == '\n' || c < 32 || c == 127)
        return (0);
    else
        return (1);
}

void    free_map(char **map, int line_count)
{
    int i = 0;
    while (i < line_count)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int min3(int a, int b, int c)
{
    if (a > b)
        a = b;
    if (a > c)
        a = c;
    return (a);
}

void    bsq(FILE *file)
{
    int line_count = 0;
    char    empty, obstacle, full;

    if (fscanf(file, "%d%c%c%c\n", &line_count, &empty, &obstacle, &full) != 4
        || line_count <= 0
        || !is_printable(empty) || !is_printable(obstacle) || !is_printable(full)
        || empty == obstacle || empty == full || obstacle == full)
    {
        fprintf(stdout, "map error\n");
        return ;
    }

    char    **map = calloc(line_count, sizeof(char *));
    if (!map)
    {
        fprintf(stdout, "map error\n");
        return ;
    }

    size_t  capacity = 0;
    ssize_t len = 0;
    char    *line = NULL;
    int     rows = 0;
    int     cols = 0;
    int     width = -1;
    while (rows < line_count)
    {
        line = NULL;
        capacity = 0;
        len = getline(&line, &capacity, file);
        if (len == -1 || line[len - 1] != '\n')
        {
            free(line);
            free_map(map, rows);
            fprintf(stdout, "map error\n");
            return ;
        }
        line[--len] = '\0';
        if (width == -1)
            width = (int)len;
        else if (width != len || width == 0)
        {
            free(line);
            free_map(map, rows);
            fprintf(stdout, "map error\n");
            return ;
        }
        cols = 0;
        while (cols < width)
        {
            if (line[cols] != empty && line[cols] != obstacle)
            {
                free(line);
                free_map(map, rows);
                fprintf(stdout, "map error\n");
                return ;
            }
            cols++;
        }
        map[rows] = line;
        rows++;
    }

    int *dp = calloc(line_count * width, sizeof(int));
    if (!dp)
    {
        free_map(map, line_count);
        fprintf(stdout, "map error\n");
        return ; 
    }

    int best_size = 0, best_row = 0, best_col = 0;
    rows = 0;
    while (rows < line_count)
    {
        cols = 0;
        while (cols < width)
        {
            int top = 0, left = 0, diagonal = 0, value = 0;
            if (map[rows][cols] == obstacle)
                value = 0;
            else if (rows == 0 || cols == 0)
                value = 1;
            else
            {
                top = dp[(rows - 1) * width + cols];
                left = dp[rows * width + (cols - 1)];
                diagonal = dp[(rows - 1) * width + (cols - 1)];
                value = 1 + min3(top, left, diagonal);
            }
            dp[rows * width + cols] = value;
            if (value > best_size)
            {
                best_size = value;
                best_row = rows;
                best_col = cols;
            }
            cols++;
        }
        rows++;
    }

    rows = best_row - best_size + 1;
    while (rows <= best_row)
    {
        cols = best_col - best_size + 1;
        while (cols <= best_col)
        {
            map[rows][cols] = full;
            cols++;
        }
        rows++;
    }

    rows = 0;
    while (rows < line_count)
    {
        fprintf(stdout, "%s", map[rows]);
        fprintf(stdout, "\n");
        rows++;
    }

    free_map(map, line_count);
    free(dp);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        bsq(stdin);
        return (0);
    }
    else if (ac == 2)
    {
        FILE *file = fopen(av[1], "r");
        if (!file)
        {
            fprintf(stdout, "map error\n");
            return (1);
        }
        bsq(file);
        fclose(file);
        return (0);
    }
    else
    {
        fprintf(stdout, "map error\n");
        return (1);
    }
}
