#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int	is_printable(char c)
{
	if (c == '\n' || c < 32 || c == 127)
        return (0);
    else
        return (1);
}

void	free_map(char **map, int line_count)
{
	int i = 0;

	if (!map)
		return ;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	min3(int a, int b, int c)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	return (a);
}

void	bsq(FILE *file, int sep)
{
	int	line_count = 0;
	char	empty, obstacle, full;
	char	**map = NULL;
	char	*line = NULL;
	size_t	capacity = 0;
	ssize_t	len = 0;
	int	width = 0;
	int	rows = 0;
	int	cols = 0;
	int	*dp = NULL;

	if (fscanf(file, "%d %c %c %c\n", &line_count, &empty, &obstacle, &full) != 4
		|| line_count <= 0
		|| !is_printable(empty) || !is_printable(obstacle) || !is_printable(full)
		|| empty == obstacle || empty == full || obstacle == full)
	{
		fprintf(stderr, "map error\n");
		if (sep)
			fprintf(stdout, "\n");
		return ;
	}

	map = calloc(line_count, sizeof(char *));
	if (!map)
	{
		fprintf(stderr, "map error\n");
		if (sep)
			fprintf(stdout, "\n");
		return ;
	}

	width = -1;
	while (rows < line_count)
	{
		line = NULL;
		capacity = 0;
		len = getline(&line, &capacity, file);
		if (len == -1 || line[len - 1] != '\n')
		{
			free(line);
			free_map(map, rows);
			fprintf(stderr, "map error\n");
			if (sep)
				fprintf(stdout, "\n");
			return ;
		}
		line[--len] = '\0';
		if (width == -1)
			width = (int)len;
		else if ((int)len != width || width == 0)
		{
			free(line);
			free_map(map, rows);
			fprintf(stderr, "map error\n");
			if (sep)
				fprintf(stdout, "\n");
			return ;
		}
		cols = 0;
		while (cols < width)
		{
			if (line[cols] != empty && line[cols] != obstacle)\
			{
				free(line);
				free_map(map, rows);
				fprintf(stderr, "map error\n");
				if (sep)
					fprintf(stdout, "\n");
				return ;
			}
			cols++;
		}
		map[rows] = line;
		rows++;
	}

	dp = calloc(line_count * width, sizeof(int));
	if (!dp)
	{
		free_map(map, rows);
		fprintf(stderr, "map error\n");
		if (sep)
			fprintf(stdout, "\n");
		return ;
	}

	int	best_size = 0, best_row = 0, best_col = 0;
	rows = 0;
	while (rows < line_count)
	{
		cols = 0;
		while (cols < width)
		{
			int value, top, left, diagonal;

			if (map[rows][cols] == obstacle)
				value = 0;
			else if (rows == 0 || cols == 0)
				value = 1;
			else
			{
				top = dp[(rows - 1) * width + cols];
				left = dp[(cols - 1) + width * rows];
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
	free(dp);

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
	if (sep)
		fprintf(stdout, "\n");
	
	free_map(map, line_count);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		bsq(stdin, 0);
		return (0);
	}

	FILE *file;
	int	i = 1;
	while (i < ac)
	{
		file = fopen(av[i], "r");
		if (!file)
		{
			fprintf(stderr, "map error\n");
			if (ac > 2)
				fprintf(stdout, "\n");
		}
		else
		{
			bsq(file, ac > 2);
			fclose(file);
		}
		i++;
	}
	return (0);
}

