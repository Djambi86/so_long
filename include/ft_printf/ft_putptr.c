/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:56:39 by dabdulka          #+#    #+#             */
/*   Updated: 2025/06/19 16:34:06 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putptr_rec(uintptr_t ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
		count += ft_putptr_rec(ptr / 16);
	count += write(1, &base[ptr % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_putptr_rec((uintptr_t)ptr);
	return (count);
}

/*int	main(void)
{
	int a = 42;
	char c = 'A';

	ft_putptr(&a);    // Should print the address of variable 'a'
	write(1, "\n", 1);

	ft_putptr(&c);    // Should print the address of variable 'c'
	write(1, "\n", 1);

	ft_putptr(NULL);  // Should print "0x0"
	write(1, "\n", 1);

	return (0);
}*/
