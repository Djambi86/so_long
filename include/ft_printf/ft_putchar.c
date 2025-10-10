/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:23:25 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/29 12:20:45 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/*#include <stdio.h>

int main(void)
{
	char c = '%';
	
	printf("%c", c);
	printf("\n");
	ft_putchar('%');
}*/
