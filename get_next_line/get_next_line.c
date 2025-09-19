#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	int i = 0;

	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

size_t ft_strlen(char *s)
{
    size_t ret = 0;
    while (*s)
    {
        s++;
        ret++;
    }
    return (ret);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int str_apped_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int str_apped_str(char **s1, char *s2)
{
	return str_apped_mem(s1, s2, ft_strlen(s2));
}
void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i-- > 0)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

char *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char *ret;
	char *tmp;
	int read_ret;

	ret = malloc(1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_apped_str(&ret, b))
			return free(ret), NULL;
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			if (*ret == '\0')
				return free(ret), NULL;
			return ret;
		}
		b[read_ret] = '\0';
		tmp = ft_strchr(b, '\n');
	}
	if (!str_apped_mem(&ret, b, tmp - b + 1))
		return free(ret), NULL;
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return ret;
}



int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}