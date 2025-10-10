/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/12 16:21:15 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (16384);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>


int main(void)
{
    int b = ft_isprint('a');
    int c = isprint('a');
    printf("Result: %d TEsting\n", b);
    printf("Result original: %d\n", c);

}*/
