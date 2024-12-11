/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:23 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 14:25:22 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack *stack)
{
	uint32_t	i;
	int32_t		max;

	if (__builtin_expect(!stack || !stack->data || stack->len != 3, 0))
		return ;
	i = 0;
	max = stack_get(stack, 0);
	while (++i < stack->len)
		if (stack_get(stack, i) > max)
			max = stack_get(stack, i);
	if (stack_get(stack, 2) == max)
		stack_rx(stack, 'a');
	else if (stack_get(stack, 1) == max)
		stack_rrx(stack, 'a');
	if (stack_get(stack, 2) > stack_get(stack, 1))
		stack_sx(stack, 'a');
}
