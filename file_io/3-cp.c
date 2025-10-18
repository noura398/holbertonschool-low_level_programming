#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/**
 * print_usage_exit - print usage and exit with code 97
 */
static void print_usage_exit(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * read_error_exit - print read error for a file and exit with code 98
 * @file: file name that couldn't be read
 */
static void read_error_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * write_error_exit - print write error for a file and exit with code 99
 * @file: file name that couldn't be written
 */
static void write_error_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * close_error_exit - print close error for an fd and exit with code 100
 * @fd: file descriptor value that couldn't be closed
 */
static void close_error_exit(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - copy the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with specific codes on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, c1, c2;
	ssize_t rcount, wcount;
	char buffer[BUFSIZE];
	mode_t mode = 0664;

	if (ac != 3)
		print_usage_exit();

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		read_error_exit(av[1]);

	/* O_TRUNC required; permissions only applied if file is created */
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		c1 = close(fd_from);
		if (c1 == -1)
			close_error_exit(fd_from);
		write_error_exit(av[2]);
	}

	while ((rcount = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		ssize_t written = 0;

		while (written < rcount)
		{
			wcount = write(fd_to, buffer + written, rcount - written);
			if (wcount == -1)
			{
				c1 = close(fd_from);
				c2 = close(fd_to);
				if (c1 == -1)
					close_error_exit(fd_from);
				if (c2 == -1)
					close_error_exit(fd_to);
				write_error_exit(av[2]);
			}
			written += wcount;
		}
	}

	if (rcount == -1)
	{
		c1 = close(fd_from);
		c2 = close(fd_to);
		if (c1 == -1)
			close_error_exit(fd_from);
		if (c2 == -1)
			close_error_exit(fd_to);
		read_error_exit(av[1]);
	}

	c1 = close(fd_from);
	if (c1 == -1)
		close_error_exit(fd_from);

	c2 = close(fd_to);
	if (c2 == -1)
		close_error_exit(fd_to);

	return (0);
}

