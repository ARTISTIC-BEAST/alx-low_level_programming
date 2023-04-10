#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to end of file
 * @filename: name of the file
 * @text_content: text to append to the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)

	{
		while (text_content[len] != '\0')
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)

	{
		if (write(fd, text_content, len) == -1)
	{
		close(fd);
		return (-1);
	}

	}

	close(fd);
	return (1);
}

