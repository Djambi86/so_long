/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:30:45 by dabdulka          #+#    #+#             */
/*   Updated: 2025/06/06 16:02:54 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/*#include <stdio.h>

int main()
{
	char *s = NULL;
	
	int x = printf("%s", s);
	int y = ft_putstr(s);
	printf("r: %d", x-y);
}*/
