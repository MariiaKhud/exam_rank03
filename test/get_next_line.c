// Assignment name   : broken_GNL
// Expected files    : get_next_line.c get_next_line.h
// Allowed functions : read, free, malloc
// --------------------------------------------------------------------------------

// Repair the function 'get_next_line' in the file get_next_line.c, whose prototype should be:
// char    *get_next_line(int fd);

// You may need to repair other functions as well.



// Description of the 'get_next_line' function:

// Your function must return a line that has been read from the file descriptor
// passed as a parameter.

// A 'line that has been read' is defined as a succession of 0 to n characters
// ending with '\n' (ASCII code 0x0a) or with End Of File (EOF).

// The line should be returned including the '\n' if there is one at the end
// of the line that has been read.

// When you reach the EOF, you must store the current buffer in a char * and
// return it. If the buffer is empty, you must return NULL.

// In case of an error, return NULL.

// If not returning NULL, the pointer should be freeable.

// Your program will be compiled with the flag -D BUFFER_SIZE=xx, which must be
// used as the buffer size for the read calls in your functions.

// Your function must be free of memory leaks.

// When you reach the EOF, your function should not keep any memory allocated with
// malloc except for the line that has been returned.

// Calling your function get_next_line in a loop will allow you to read
// the text available on a file descriptor one line at a time until the end of the
// text, regardless of the size of the text or any of its lines.

// Ensure that your function behaves correctly when reading from a file, from the
// standard output, from a redirection etc.

// No call to another function will be done on the file descriptor between two calls
// of get_next_line.

// Finally, we consider that get_next_line has undefined behavior when reading
// from a binary file.

// --------------------------------------------------------------------------------

// #include "get_next_line.h"

// char *ft_strchr(char *s, int c)
// {
//     int i = 0;
// 	while (s[i] != c)
// 		i++;
// 	if (s[i] == c)
// 		return s + i;
// 	else
// 		return NULL;
// }

// void *ft_memcpy(void *dest, const void *src, size_t n)
// {
//     while (--n > 0)
//         ((char*)dest)[n - 1] = ((char*)src)[n - 1];
//     return dest;
// }

// size_t  ft_strlen(char *s)
// {
//     size_t ret = 0;
// 	while (*s)
// 	{
// 		s++;
// 		ret++;
// 	}
//     return (ret);
// }

// int str_append_mem(char **s1, char *s2, size_t size2)
// {
//     size_t size1 = ft_strlen(*s1);
//     char *tmp = malloc(size2 + size1 + 1);
//     if (!tmp)
//         return 0;
//     ft_memcpy(tmp, *s1, size1);
//     ft_memcpy(tmp + size1, s2, size2);
//     tmp [size1 + size2] = 0;
//     free(*s1);
//     *s1 = tmp;
//     return 1;
// }

// int str_append_str(char **s1, char *s2)
// {
//     return str_append_mem(s1, s2, ft_strlen(s2));
// }

// void *ft_memmove(void *dest, const void *src, size_t n)
// {
//     if (dest > src)
//         return ft_memcpy(dest, src, n);
//     else if (dest == src)
//         return dest;
// 	size_t i = ft_strlen((char *)src) - 1;
//     while (i >= 0)
// 	{
// 		((char *)dest)[i] = ((char *)src)[i];
// 		i--;
// 	}
//     return dest;
// }

// char    *get_next_line(int fd)
// {
//     static char b[BUFFER_SIZE + 1] = "";
//     char *ret = NULL;

//     char *tmp = ft_strchr(b, '\n');
//     while (!tmp) {
//         if (!str_append_str(&ret, b))
//             return NULL;
//         int read_ret = read(fd, b, BUFFER_SIZE);
//         if (read_ret == -1)
//             return NULL;
//         b[read_ret] = 0;
//     }
//     if (!str_append_mem(&ret, b, tmp - b + 1))
//     {
//         free(ret);
//         return NULL;
//     }
//     return ret;
// }


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>

char *ft_strchr(char *s, int c)
{
	int i = 0;
	if (s == 0)
		return (0);
    while (s[i] && s[i] != c)
        i++;
    if (s[i] == c)
    {
		return &s[i];
	}
	return NULL;
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
	if (dest == 0 && src == 0)
		return (0);
    while (i < n)
    {
        ((unsigned char*)dest)[i] = ((const unsigned char*)src)[i];
		i++;
    }
    return (dest);
}

int str_apped_mem(char **s1, char *s2, size_t size2)
{
    size_t size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return (0);
    ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = '\0';
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
	if (dest == src)
        return (dest);
    if (dest < src)
        return (ft_memcpy(dest, src, n));
    i = n;
    while (i-- > 0)
    {
        ((char*)dest)[i] = ((char*)src)[i];
    }
    return (dest);
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret;
    char *tmp;
	int read_ret;

	ret = malloc(1);
	if (ret == 0)
		return (0);
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
			return (ret);
		}
        b[read_ret] = '\0';
		tmp = ft_strchr(b, '\n');
    }
    if (!str_apped_mem(&ret, b, tmp - b + 1))
    {
        free(ret);
        return NULL;
    }
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return (ret);
}

int main()
{
	int fd;
	char *line;

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
