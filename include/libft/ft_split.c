/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:55:33 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:41 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	under_25_lines_is_the_worst(char ***res, t_split_data *d,
										const char *s, char c)
{
	d->i = 0;
	d->j = 0;
	d->start_word = -1;
	if (!s)
		return (0);
	d->len = ft_strlen(s);
	*res = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!*res)
		return (0);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char			**res;
	t_split_data	d;

	if (!under_25_lines_is_the_worst(&res, &d, s, c))
		return (NULL);
	while (d.i <= d.len)
	{
		if (s[d.i] != c && d.start_word < 0)
			d.start_word = d.i;
		else if ((s[d.i] == c || d.i == d.len) && d.start_word >= 0)
		{
			res[d.j] = fill_word(s, d.start_word, d.i);
			if (!res[d.j])
				return (ft_free(res, d.j));
			d.start_word = -1;
			d.j++;
		}
		d.i++;
	}
	return (res);
}

/*#include <stdio.h>

int main(void)
{
    char **result;
    const char *str = "  this  is   a test ";
    char delimiter = ' ';

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; result[i]; i++)
    {
        printf("Word %d: '%s'\n", i, result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}*/
