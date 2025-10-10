/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:05:17 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:30 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main(void)
{
	ft_putchar_fd('M', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('E', 2);
	ft_putchar_fd('\n', 2);
}*/
