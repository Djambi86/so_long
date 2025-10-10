/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:16:47 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (size != 0 && num > SIZE_MAX / size)
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}

/*#include <stdio.h>

int main()
{
	size_t count;
	size_t size;
	int *arr;

	count = 5;
	size = sizeof(int);
	arr = (int *)ft_calloc(count, size);
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Memory allocation returned; ");
	for (size_t i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}*/
