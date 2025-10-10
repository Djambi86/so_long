/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:06:57 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/07 18:56:13 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
#include <ctype.h>

void to_uppercase_with_index(unsigned int i, char *c)
{
    printf("Character %u before: %c\n", i, *c);
    *c = toupper(*c);
    printf("Character %u after: %c\n", i, *c);
}

int main()
{
    char str[] = "hello42";
    ft_striteri(str, to_uppercase_with_index);
    printf("Result: %s\n", str);
    return 0;
}

void to_upper_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;  // convert to uppercase
}

int main(void)
{
	char str[] = "libft functions are giving me nightmares, please help!";
	ft_striteri(str, to_upper_even_index);
	printf("Modified: %s\n", str);
	return 0;
}*/
