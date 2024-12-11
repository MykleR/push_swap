/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:23 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 19:20:32 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three(t_stack *stack)
{
	if (stack->array[2] == stack->max)
		rx(stack, 0);
	else if (stack->array[1] == stack->max)
		rrx(stack, 0);
	if (stack->array[2] > stack->array[1])
		sx(stack, 0);
}

static void	sort_more(t_stack *a, t_stack *b)
{
	(void) a;
	(void) b;
}

void	stack_sort(t_stack *a, t_stack *b)
{
	if (stack_parse_check(a, __check_sorted))
		return ;
	if (a->len == 2)
		sx(a, 0);
	else if (a->len == 3)
		sort_three(a);
	else if (a->len > 3)
		sort_more(a, b);
}
