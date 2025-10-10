/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:06:36 by dabdulka          #+#    #+#             */
/*   Updated: 2025/06/19 15:52:28 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int hexa, int uppercase)
{
	char	*base;
	int		count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hexa >= 16)
		count += ft_puthex(hexa / 16, uppercase);
	count += ft_putchar(base[hexa % 16]);
	return (count);
}

/*int main(void)
{
	ft_puthex(255, 1);
}*/
