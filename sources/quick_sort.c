/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:41:58 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 18:46:44 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(int32_t *x, int32_t *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static int	partition(int32_t *tab, uint32_t start, uint32_t end)
{
	int32_t		pivot;
	uint32_t	start_tab;

	start_tab = start;
	pivot = tab[start];
	start++;
	while (start <= end)
	{
		while (start <= end && tab[start] < pivot)
			start++;
		while (start <= end && tab[end] > pivot)
			end--;
		if (start < end)
			swap(tab + start, tab + end);
	}
	swap(tab + start_tab, tab + end);
	return (end);
}

void	quick_sort(int32_t *tab, uint32_t start, uint32_t end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(tab, start, end);
		quick_sort(tab, start, pivot_index - 1);
		quick_sort(tab, pivot_index + 1, end);
	}
}
