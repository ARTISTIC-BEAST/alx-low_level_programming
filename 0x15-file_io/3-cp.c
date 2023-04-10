#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFSIZE 1024

/**
 * main - copy the content of a file to another file
 *
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success, or the corresponding error code
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, rcount, wcount;
	char buf[BUFSIZE];

	/* check argument count */
	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	/* open source file for reading */
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	/* open destination file for writing, truncate if it exists */
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);

	/* copy file content */
	do {
		rcount = read(fd_from, buf, BUFSIZE);
		if (rcount == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
		wcount = write(fd_to, buf, rcount);
		if (wcount == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	} while (rcount == BUFSIZE);

	/* close files */
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}

