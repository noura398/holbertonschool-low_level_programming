#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	rcount = read(fd, buffer, letters);
	if (rcount == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	wcount = write(STDOUT_FILENO, buffer, rcount);
	free(buffer);
	close(fd);

	if (wcount == -1 || wcount != rcount)
		return (0);

	return (wcount);
}

