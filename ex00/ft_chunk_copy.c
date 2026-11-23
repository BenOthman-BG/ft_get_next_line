#include "header.h"

int	error()
{
		write(2, "Error\n", 6);
		return (-1);
}

int main (int ac, char **av)
{
	int	fd1;
	int	fd2;
	char buffer[BUFFER_SIZE];
	int	n;

	if (ac != 3 || BUFFER_SIZE <= 0)
		return (error());
	fd1 = open(av[1], O_RDONLY);
	if (fd2 == -1)
		return (error());
	fd2 = open(av[2], O_WRONLY | O_CREAT | O_TRUNC | 0774);
	if (fd2 == -1)
		return (error());
	while (n = read(fd1, buffer, BUFFER_SIZE))
	{
		if (n == -1)
			return (error());
		if (write(fd2, buffer, n) == -1)
			return (error());
		if (write(1, buffer, n) == -1)
			return (error());
	}
	close(fd1);
	close(fd2);
	return (0);
}
