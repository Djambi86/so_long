/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:11:39 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:18:11 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_hate_under_25_lines(char const *s, unsigned int start,
									size_t *s_len, char **substr)
{
	if (!s)
		return (0);
	*s_len = ft_strlen(s);
	if (start >= *s_len)
	{
		*substr = (char *)malloc(1);
		if (!*substr)
			return (0);
		(*substr)[0] = '\0';
		return (0);
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!i_hate_under_25_lines(s, start, &s_len, &substr))
		return (substr);
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*#include <stdio.h>

int main()
{
	char *test = ft_substr("I hope this will work", 2, 4);
	printf("Result: %s\n", test);
}*/
