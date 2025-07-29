#include "get_next_line.h"

void	read_from_file(int fd, char **buffer)
{
	char	*temp_buffer;
	int		chars_read;

	chars_read = 1;
	while (!ft_strchr(*buffer, '\n'))
	{
		temp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp_buffer)
			return ;
		chars_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(temp_buffer);
			return ;
		}
		temp_buffer[chars_read] = '\0';
		*buffer = ft_mstrjoin(*buffer, temp_buffer);
		free(temp_buffer);
		if (!*buffer)
			return ;
	}
}

size_t	modified_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = modified_strlen(buffer);
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void	clean_buffer(char **buffer)
{
	size_t	new_size;
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = modified_strlen(*buffer);
	if ((*buffer)[i] == '\n')
		i++;
	new_size = ft_strlen(*buffer + i);
	new_buffer = (char *)malloc(sizeof(char) * (new_size + 1));
	if (!new_buffer)
		return ;
	j = 0;
	while ((*buffer)[i])
		new_buffer[j++] = (*buffer)[i++];
	new_buffer[j] = '\0';
	free(*buffer);
	*buffer = new_buffer;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	read_from_file(fd, &buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	clean_buffer(&buffer);
	return (line);
}
