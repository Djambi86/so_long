/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:45:15 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:12:56 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int i)
{
	int	len;

	len = (i <= 0);
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	len = ft_num_len(n);
	str = malloc(len + 1);
	num = n;
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
	int nums[] = {0, -42, 12345, -2147483648, 2147483647};
	for (int i = 0; i < 5; i++)
	{
		char *str = ft_itoa(nums[i]);
		if (str)
		{
			printf("ft_itoa(%d) = %s\n", nums[i], str);
			free(str);
		}
		else
		{
			printf("Memory allocation failed.\n");
		}
	}
}*/

/*int main(void)
{
    int test_values[] = {0, 1, -1, 123, -456, 2147483647, -2147483648};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *result = ft_itoa(test_values[i]);
        if (result)
        {
            printf("ft_itoa(%d) = \"%s\"\n", test_values[i], result);
            free(result);  // Don't forget to free the allocated string
        }
        else
        {
            printf("ft_itoa(%d) = NULL (allocation failed)\n", test_values[i]);
        }
    }

    return 0;
}*/
