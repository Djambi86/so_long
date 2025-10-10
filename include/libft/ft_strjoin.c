/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:22 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/06 20:00:58 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*join;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *)malloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

/*int main()
{
	ft_strjoin("Why does my", "LIBFT.a not work");	
}*/
