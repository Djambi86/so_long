/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putundec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:46:22 by dabdulka          #+#    #+#             */
/*   Updated: 2025/06/19 15:50:01 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putundec(unsigned int number)
{
	char	c;
	int		count;

	count = 0;
	if (number > 9)
		count += ft_putundec(number / 10);
	c = number % 10 + '0';
	count += ft_putchar(c);
	return (count);
}

/*#include <stdio.h>

int main(void)
{
	ft_putundec(123456);
	int a = ft_putundec(123456);
	printf("%u", a);
}*/
