#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int doublestrlen(char **s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_size(char **s)
{
	int i = -1;
	int len = 0;

	while (s[++i])
	{
		if (!len)
		{
			len = strlen(s[i]);
			continue ;
		}
		if (!strchr(s[i], '\n'))
		{
			if (len != strlen(s[i]) + 1)
				return (printf("the size is not the same (without /\n) :o\n"), 0);
			return (1);
		}
		else if (len != strlen(s[i]))
			return (printf("the size is not the same :o\n"), 0);
	}
	printf("check size function is work :)\n");
	return (1);
}

int	check_wall(char **content)
{

	int	x = 0;
	int y = 0;
	int	xlen = strlen(content[y]) - 1;
	int	ylen = doublestrlen(content);

	//check horizontal line
	while (x < xlen)
	{
		if (!strchr(content[ylen - 1], '\n') && !x)
			xlen -= 1;
		if (content[0][x] != '1')
			return (printf("top horizontal test is faild :(\n"), 0);
		if (content[ylen - 1][x] != '1')
			return (printf("bottom horizontal test is faild :(\n"), 0);
		x++;
	}
	y = 0;
	//check vertical line
	while (y < ylen)
	{
		if (content[y++][0] != '1')
			return (printf("left vertical test is faild :(\n"), 0);
		if (content[y][xlen - 1] != '1')
			return (printf("right vertical test is faild :(\n"), 0);
		y++;
	}
	printf("check wall function is work :)\n");
	return (1);
}

int	check_players(char **s)
{
	int i = -1;
	int	j;
	int	p = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == 'P' || s[i][j] == 'p')
				p++;
	}
	if (p == 1)
		return (printf("check players function is work :)\n"), 1);
	return (printf("there is no (or multi) players in the map :(\n"), 0);
}


int	check_coins(char **s)
{
	int i = -1;
	int	j;
	int	p = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == 'C')
				p++;
	}
	if (p == 0)
		return (printf("there is no coins in the map :(\n"), 0);
	return (printf("check coins function is work :)\n"), 1);
}

int	check_door(char **s)
{
	int i = -1;
	int	j;
	int	p = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == 'E' || s[i][j] == 'e')
				p++;
	}
	if (p == 1)
		return (printf("check door function is work :)\n"), 1);
	return (printf("there is no (or multi) door in the map :(\n"), 0);
}

int	check_invalid_char(char **s)
{
	int i = -1;
	int	j;
	int	p = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] != 'P' && s[i][j] != 'E' && s[i][j] != '1' && s[i][j] != '0' && s[i][j] != 'C' && s[i][j] != '\n')
				return (printf("there is invalid characters in the map :( in %d -- %d ==> %c\n", i+1, j+1, s[i][j]), 0);
	}
	return (printf("check players function is work :)\n"), 1);
}

int	check_condition(char	**s)
{
	if (!check_wall(s))
		return (0);
	int	i = -1;
	int	j;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 'C' || s[i][j] == 'P' || s[i][j] == 'E')
				if (s[i - 1][j] == '1' &&  s[i + 1][j] == '1' && s[i][j - 1] == '1' && s[i][j + 1] == '1')
					return (printf("the condition is inside wall :(\n"), 0);
		}
	}
	return (printf("check condition function is work :)\n"), 1);
}

char	**getfullcontent(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
			return (0);
	char	**text = malloc(256 * sizeof(char *));
	int		i = -1;
	while (1)
	{
		text[++i] = get_next_line(fd);
		if (!text[i])
			break ;
	}
	close(fd);
	return (text);
}

//int main(int argc, char const *argv[])
//{
//	char	**content = getfullcontent("maps");
//	if (!content)
//		return (0);
//	if (!check_size(content) || !check_wall(content) || !check_players(content) || !check_invalid_char(content)
//			|| !check_door(content) || !check_coins(content) || !check_condition(content))
//		printf("test faild :(\n");
//	else
//		printf("test is passed :)\n");
//	free(content);
//	return 0;
//}
