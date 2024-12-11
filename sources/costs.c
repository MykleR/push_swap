/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:41:55 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 17:42:16 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

uint32_t	move_top_cost(t_stack *stack, uint32_t index)
{
	if (index == stack->array.len - 1)
		return (0);
	if (index >= stack->array.len / 2)
		return (index);
	return (stack->array.len - index);
}

void get_lowest_cost(t_stack *a, t_stack *b);
