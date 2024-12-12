/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:23 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 21:00:27 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three(t_stack *stack)
{
	if (stack->array[2] == stack->array[stack->index_max])
		rx(stack, 0);
	else if (stack->array[1] == stack->array[stack->index_max])
		rrx(stack, 0);
	if (stack->array[2] > stack->array[1])
		sx(stack, 0);
}

static void	find_targets(t_stack *a, t_stack *b)
{
	uint32_t	i;

	i = a->len;
	while (i--)
		a->targets[i] = closest_smaller(b, a->array[i]);
	i = b->len;
	while (i--)
		b->targets[i] = closest_bigger(a, b->array[i]);
}

static void	finish_sort(t_stack *a)
{
	bool	direction;

	direction = a->index_min > a->len / 2;
	while (a->index_min != a->len - 1)
	{
		if (direction)
			rx(a, 0);
		else
			rrx(a, 0);
	}
}

static void	sort_more(t_stack *a, t_stack *b)
{
	t_moves	best_moves;

	if (a->len > 4)
		pb(a, b, 0);
	pb(a, b, 0);
	while (a->len > 3)
	{
		find_targets(a, b);
		find_best_pb(a, b, &best_moves);
		exec_moves(a, b, best_moves);
		pb(a, b, 0);
	}
	sort_three(a);
	while (b->len)
	{
		find_targets(a, b);
		find_best_pa(a, b, &best_moves);
		exec_moves(a, b, best_moves);
		pa(a, b, 0);
	}
	finish_sort(a);
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
