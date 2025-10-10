/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/06 18:23:35 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int b)
{
	if (b >= 0 && b <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>

int main(void)
{
    int b = ft_isascii(129);
    int c = isascii(129);
    printf("Result original: %d\n", c);
    printf("Result original: %d\n", b);
}*/
