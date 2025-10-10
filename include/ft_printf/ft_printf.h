/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:11:44 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/29 12:28:45 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_putnbr(int i);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putundec(unsigned int number);
int	ft_puthex(unsigned int hexa, int uppercase);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif
