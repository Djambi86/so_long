/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/06 18:22:53 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z')
		|| (a >= 'A' && a <= 'Z'))
		return (8);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>

int main(void)
{
    int b = ft_isalnum('+');
    int c = isalnum('+');
    printf("Result: %d\n", b);
    printf("Result original: %d\n", c);
} */
