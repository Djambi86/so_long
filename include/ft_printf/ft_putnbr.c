/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:37:39 by dabdulka          #+#    #+#             */
/*   Updated: 2025/06/19 15:48:51 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int i)
{
	char	c;
	int		count;

	count = 0;
	if (i == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (i < 0)
	{
		count += write(1, "-", 1);
		i = -i;
	}
	if (i > 9)
		count += ft_putnbr(i / 10);
	c = (i % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

/*#include <stdio.h>

int main()
{
	int i = -2147483648;

	printf("%i", i);
	printf("\n");
	ft_putnbr(-2147483648);
}*/
