#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

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

int main(int argc, char const *argv[])
{
	char	**content = getfullcontent("maps");
	if (!content)
		return (0);
	printf("test is passed :)\n");
	free(content);
	return 0;
}
