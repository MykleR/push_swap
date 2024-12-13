/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:41:55 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 19:06:01 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

uint32_t	rotate_top_cost(t_stack *stack, uint32_t index)
{
	return (stack->len - index - 1);
}

uint32_t	rrotate_top_cost(t_stack *stack, uint32_t index)
{
	(void) stack;
	return (index + 1);
}

uint32_t	closest_smaller(t_stack *stack, int32_t val)
{
	uint32_t	i;
	uint32_t	closest;

	if (val < stack->array[stack->index_min])
		return (stack->index_max);
	i = stack->len;
	closest = stack->index_min;
	while (i--)
	{
		if (stack->array[i] < val && stack->array[i] > stack->array[closest])
			closest = i;
	}
	return (closest);
}

uint32_t	closest_bigger(t_stack *stack, int32_t val)
{
	uint32_t	i;
	uint32_t	closest;

	if (val > stack->array[stack->index_max])
		return (stack->index_min);
	i = stack->len;
	closest = stack->index_max;
	while (i--)
	{
		if (stack->array[i] > val && stack->array[i] < stack->array[closest])
			closest = i;
	}
	return (closest);
}
