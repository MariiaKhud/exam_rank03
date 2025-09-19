// Assignment name: rip
// Expected files: *.c *.h
// Allowed functions: puts, write
// --------------------------------------------------------------------------------
// Write a program that will take as argument a string containing only parenthesis.
// If parenthesis are unbalanced (for example "())") your program shall remove the
// minimum number of parenthesis for the expression to be balanced.
// By removing we mean replacing by spaces.
// You will print all the solutions (can be more than one).
// The order of the solutions is not important.
// For example this should work:
// (For readability reasons the '_' means space and the spaces are for readability only.)
// $> ./rip '( ( )' | cat -e
// _ ( ) $
// ( _ ) $
// $> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
// ( ( ( ) ( ) ( ) ) ( ) ) $
// $> ./rip '( ) ( ) ) ( )' | cat -e
// ( ) ( ) _ ( ) $
// ( ) ( _ ) ( ) $
// ( _ ( ) ) ( ) $
// $> ./rip '( ( ) ( ( ) (' | cat -e
// ( ( ) _ _ ) _ $
// ( _ ) ( _ ) _ $
// ( _ ) _ ( ) _ $
// _ ( ) ( _ ) _ $
// _ ( ) _ ( ) _ $

// #include <unistd.h>
// #include <stdio.h>

// int min_remove(char *s)
// {
// 	int i = 0;
// 	int open = 0, close = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '(')
// 			open++;
// 		else if (s[i] == ')')
// 		{
// 			if (open > 0)
// 				open--;
// 			else
// 				close++;
// 		}
// 		i++;
// 	}
// 	return open + close;
// }

// int is_valid(char *s)
// {
// 	int i = 0;
// 	int balance = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '(')
// 			balance++;
// 		else if (s[i] == ')')
// 		{
// 			if (balance == 0)
// 				return 0;
// 			balance--;
// 		}
// 		i++;
// 	}
// 	return balance == 0;
// }

// void solve(char *s, int i, int removed, int to_remove)
// {
// 	if (!s[i])
// 	{
// 		if (removed == to_remove && is_valid(s))
// 			puts(s);
// 		return;
// 	}
// 	if (s[i] == '(' || s[i] == ')')
// 	{
// 		char saved = s[i];
// 		s[i] = ' ';
// 		solve(s, i + 1, removed + 1, to_remove);
// 		s[i] = saved;
// 	}
// 	solve(s, i + 1, removed, to_remove);
// }

// int main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int to_remove = min_remove(av[1]);
// 	if (!to_remove && is_valid(av[1]))
// 		puts(av[1]);
// 	else
// 		solve(av[1], 0, 0, to_remove);
// }



#include <unistd.h>
#include <stdio.h>

int check_parentheses(char *s, int action)
{
    int i = 0;
    int open = 0;
    int close = 0;

    while (s[i])
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
        i++;
    }
    if (action == 0)
        return open + close;
    else
        return (open + close == 0);
}

void solve(char *s, int i, int removed, int to_remove)
{
    if (!s[i])
    {
        if (removed == to_remove && check_parentheses(s, 1))
            puts(s);
        return ;
    }
    if (s[i] == '(' || s[i] == ')')
    {
        char temp = s[i];
        s[i] = ' ';
        solve(s, i + 1, removed + 1, to_remove);
        s[i] = temp;
    }
    solve(s, i + 1, removed, to_remove);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    int to_remove = check_parentheses(argv[1], 0);
    if (to_remove == 0 && check_parentheses(argv[1], 1))
        puts(argv[1]);
    else
        solve(argv[1], 0, 0, to_remove);
    return (0);
}
