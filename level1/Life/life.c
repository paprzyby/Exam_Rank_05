#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    
    int height = atoi(av[2]), width = atoi(av[1]), iter = atoi(av[3]);
    if (height <= 0 || width <= 0 || iter < 0)
        return (1);

    char    board[height][width];
    char    new_board[height][width];
    int i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
    }

    char    c;
    int pen = -1, x = 0, y = 0;
    while (read(STDIN_FILENO, &c, 1))
    {
        if (c == 'w' && y > 0)
            y--;
        else if (c == 's' && y < height - 1)
            y++;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 'd' && x < width - 1)
            x++;
        else if (c == 'x')
            pen = pen * -1;
        if (pen == 1)
            board[y][x] = 1;
    }

    i = 0;
    while (i < iter)
    {
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                int den = 0;
                int yy = -1;
                while (yy <= 1)
                {
                    int xx = -1;
                    while (xx <= 1)
                    {
                        if ((xx || yy) && x + xx >= 0 && x + xx < width && y + yy >= 0 && y + yy < height)
                            den = den + board[y + yy][x + xx];
                        xx++;
                    }
                    yy++;
                }
                if (board[y][x] && (den == 2 || den == 3))
                    new_board[y][x] = 1;
                else if (!board[y][x] && den == 3)
                    new_board[y][x] = 1;
                else
                    new_board[y][x] = 0;
                x++;
            }
            y++;
        }
        int rows = 0;
        while (rows < height)
        {
            int cols = 0;
            while (cols < width)
            {
                board[rows][cols] = new_board[rows][cols];
                cols++;
            }
            rows++;
        }
        i++;
    }

    i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            if (board[i][j])
                putchar('O');
            else
                putchar(' ');
            j++;
        }
        putchar('\n');
        i++;
    }
    return (0);
}
