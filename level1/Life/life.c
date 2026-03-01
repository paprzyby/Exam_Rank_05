# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_life
{
    int width;
    int height;
    int iterations;
}   t_life;

int main(int ac, char **av)
{
    if (ac == 4)
    {
        t_life    life;

        life.width = atoi(av[1]);
        life.height = atoi(av[2]);
        life.iterations = atoi(av[3]);

        char    board[life.height][life.width];
        char    new_board[life.height][life.width];

        if (life.width <= 0 || life.height <= 0 || life.iterations < 0)
        {
            return (1);
        }

        int i = 0;
        while (i < life.height)
        {
            int j = 0;
            while (j < life.width)
            {
                board[i][j] = 0;
                j++;
            }
            i++;
        }

        char    instruction;
        int pen = 1, x = 0, y = 0;
        while (read(STDIN_FILENO, &instruction, 1))
        {
            if (instruction == 'w' && y > 0)
                y--;
            else if (instruction == 's' && y < life.height - 1)
                y++;
            else if (instruction == 'a' && x > 0)
                x--;
            else if (instruction == 'd' && x < life.width - 1)
                x++;
            else if (instruction == 'x')
                pen = pen * -1;
            if (pen == -1)
                board[y][x] = 1;
        }

        i = 0;
        while (i < life.iterations)
        {
            y = 0;
            while (y < life.height)
            {
                x = 0;
                while (x < life.width)
                {
                    int density = 0;
                    int yy = -1;
                    while (yy <= 1)
                    {
                        int xx = -1;
                        while (xx <= 1)
                        {
                            if ((xx || yy) && x + xx >= 0 && x + xx < life.width && y + yy >= 0 && y + yy < life.height)
                                density = density + board[y + yy][x + xx];
                            xx++;
                        }
                        yy++;
                    }
                    if (board[y][x] && (density == 2 || density == 3))
                        new_board[y][x] = 1;
                    else if (!board[y][x] && density == 3)
                        new_board[y][x] = 1;
                    else
                        new_board[y][x] = 0;

                    x++;
                }
                y++;
            }

            int rows = 0;
            while (rows < life.height)
            {
                int cols = 0;
                while (cols < life.width)
                {
                    board[rows][cols] = new_board[rows][cols];
                    cols++;
                }
                rows++;
            }
            i++;
        }

        i = 0;
        while (i < life.height)
        {
            int j = 0;
            while (j < life.width)
            {
                if (board[i][j])
                    putchar('0');
                else
                    putchar(' ');
                j++;
            }
            putchar('\n');
            i++;
        }
        return (0);
    }
    else
    {
        return (1);
    }
}
