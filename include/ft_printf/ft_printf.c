/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:20:41 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/10 15:53:57 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (c == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (c == 'p')
		return (ft_putptr((va_arg(args, void *))));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (c == 'u')
		return (ft_putundec((va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += dispatch_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

/*#include <stdio.h>

int main()
{
	int integer = 5;
	int hexa = 255;
	int decimal = 5;
	char character = 'F';
	char *string = "I HATE pointers, they show up in my dreams";
	char *null = NULL;
	int *ptr = NULL;
	int pointer = 255;
	int counter = ft_printf("It should count this %u\n", 123456);
	int counter2 = printf("It should count this %u\n", 123456);
	ft_printf("My Version: I have about --> %i <-- apples left // ", integer);
	ft_printf("Decimal should be decimal.. not whole --> %d // ", decimal);
	ft_printf("Hexa is math, I hate math --> %x and %X <-- // ", hexa, hexa);
	ft_printf("this %c <-- Percentage sign character is evil // ", character);
	ft_printf("Pointers, my biggest fear in life --> %p // ", &pointer);
	ft_printf("I love strings, strings aren't so bad --> %s //", string);
	ft_printf("should be (null) --> %s // ", null);
	ft_printf("This pointer also should be NULL --> %p // ", ptr);
	ft_printf("Now we test our counter --> %d", counter);
	ft_printf("\n");
	printf("Original: I have about --> %i <-- apples left // ", integer);
	printf("Decimal should be decimal.. not whole --> %d // ", decimal);
	printf("Hexa is math, I hate math --> %x and %X <-- // ", hexa, hexa);
	printf("this %c <-- Percentage sign character is atrocious // ", character);
	printf("Pointers, my biggest fear in life --> %p // ", &pointer);
	printf("I love strings, strings aren't so bad --> %s ", string);
	printf("should be (null) --> %s // ", null);
	printf("This pointer also should be NULL --> %p // ", ptr);
	printf("Now we test our counter --> %u", counter2);
	printf("\n");
}*/
