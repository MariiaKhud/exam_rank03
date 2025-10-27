
// Assignment name : infin_add
// Expected files : *.c *.h
// Allowed functions : write, malloc, free.
// ---------------------------------------------------------------

// Write a program that take as a parameter two strings that represent
// two numbers that are potentially infinit, and displays on stdout the result of
// the addition of those two numbers, followed by a \n.

// A negative number will always be prefixed by one and only one -. The only characters
// thtat can be part of the strings are digits and sign '-'.

// Both parameters will always be well formatted and you will always have exactly
// two parameters, no tricks.

// Examples:
// $> ./infin_add "879879087" "67548976597" | cat -e
// 68428855684$

// $> ./infin_add "-876435" "987143265" | cat -e
// 986266830$

// $> ./infin_add "-807965" "-34532" | cat -e
// -842497$



#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	rev_str(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

static int	compare_abs(char *a, char *b)
{
	int	la;
	int	lb;
	int	i;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la != lb)
		return (la - lb);
	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

static char	*add_positive(char *a, char *b)
{
	int		la;
	int		lb;
	int		max_len;
	int		carry;
	int		i;
	char	*res;

	la = ft_strlen(a) - 1;
	lb = ft_strlen(b) - 1;
	max_len = la;
	if (lb > la)
		max_len = lb;
	carry = 0;
	i = 0;
	res = malloc(max_len + 3);
	if (!res)
		return (NULL);
	while (la >= 0 || lb >= 0 || carry)
	{
		int da;
		int db;
		int sum;

		da = 0;
		db = 0;
		if (la >= 0)
			da = a[la] - '0';
		if (lb >= 0)
			db = b[lb] - '0';
		sum = da + db + carry;
		res[i] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
		la--;
		lb--;
	}
	res[i] = '\0';
	rev_str(res);
	return (res);
}

static char	*sub_positive(char *a, char *b) // assumes |a| >= |b|
{
	int		la;
	int		lb;
	int		borrow;
	int		i;
	char	*res;

	la = ft_strlen(a) - 1;
	lb = ft_strlen(b) - 1;
	borrow = 0;
	i = 0;
	res = malloc(la + 2);
	if (!res)
		return (NULL);
	while (la >= 0)
	{
		int da;
		int db;

		da = a[la] - '0' - borrow;
		db = 0;
		if (lb >= 0)
			db = b[lb] - '0';
		if (da < db)
		{
			da += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		res[i] = (da - db) + '0';
		i++;
		la--;
		lb--;
	}
	while (i > 1 && res[i - 1] == '0')
		i--;
	res[i] = '\0';
	rev_str(res);
	return (res);
}

static char	*prepend_minus(char *s)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(s);
	res = malloc(len + 2);
	if (!res)
		return (NULL);
	res[0] = '-';
	i = 0;
	while (s[i])
	{
		res[i + 1] = s[i];
		i++;
	}
	res[i + 1] = '\0';
	free(s);
	return (res);
}

char	*infin_add(char *a, char *b)
{
	int		neg_a;
	int		neg_b;
	int		cmp;
	char	*res;

	neg_a = 0;
	neg_b = 0;
	if (a[0] == '-')
		neg_a = 1;
	if (b[0] == '-')
		neg_b = 1;
	if (neg_a)
		a++;
	if (neg_b)
		b++;
	if (!neg_a && !neg_b)
		res = add_positive(a, b);
	else if (neg_a && neg_b)
		res = prepend_minus(add_positive(a, b));
	else
	{
		cmp = compare_abs(a, b);
		if (cmp == 0)
			return ("0");
		if (cmp > 0)
			res = sub_positive(a, b);
		else
			res = sub_positive(b, a);
		if ((neg_a && cmp > 0) || (neg_b && cmp < 0))
			res = prepend_minus(res);
	}
	return (res);
}

int	main(int ac, char **av)
{
	char	*res;
	int		len;

	if (ac == 3)
	{
		res = infin_add(av[1], av[2]);
		len = ft_strlen(res);
		write(1, res, len);
		write(1, "\n", 1);
		if (res[0] != '-' && res[0] != '0')
			free(res);
	}
	return (0);
}
