/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:57:56 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 19:21:49 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_stack *a, t_stack *b, bool quiet)
{
	if (__builtin_expect(!a || !b || !b->len, 0))
		return ;
	stack_push(a, stack_pop(b));
	if (!quiet)
		ft_printf(1, "pa\n");
}

void	pb(t_stack *a, t_stack *b, bool quiet)
{
	if (__builtin_expect(!a || !b || !a->len, 0))
		return ;
	stack_push(b, stack_pop(a));
	if (!quiet)
		ft_printf(1, "pb\n");
}

void	sx(t_stack *a, bool quiet)
{
	int32_t	val1;
	int32_t	val2;

	if (__builtin_expect(!a || a->len < 2, 0))
		return ;
	val1 = stack_pop(a);
	val2 = stack_pop(a);
	stack_push(a, val1);
	stack_push(a, val2);
	if (!quiet)
		ft_printf(1, "s%c\n", a->name);
}

void	rx(t_stack *a, bool quiet)
{
	uint32_t		top;
	uint32_t		i;

	if (__builtin_expect(!a || a->len < 2, 0))
		return ;
	top = a->array[a->len - 1];
	i = a->len;
	while (i-- > 1)
		a->array[i] = a->array[i - 1];
	a->array[0] = top;
	if (!quiet)
		ft_printf(1, "r%c\n", a->name);
}

void	rrx(t_stack *a, bool quiet)
{
	uint32_t		bottom;
	uint32_t		i;

	if (__builtin_expect(a->len < 2, 0))
		return ;
	bottom = a->array[0];
	i = -1;
	while (++i < a->len - 1)
		a->array[i] = a->array[i + 1];
	a->array[a->len - 1] = bottom;
	if (!quiet)
		ft_printf(1, "rr%c\n", a->name);
}
