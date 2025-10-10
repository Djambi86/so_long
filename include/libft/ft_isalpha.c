/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/04/22 14:23:16 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1024);
	else
		return (0);
}

/* #include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = ft_isalpha('A');
	write(1, &c, 1);
}

int main(void)
{
	int b = ft_isalpha('A');
	printf("Result: %d\n", b);

} */
