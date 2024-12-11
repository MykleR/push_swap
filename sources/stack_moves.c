/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:57:56 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 16:56:25 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stack_pa(t_stack *a, t_stack *b, bool log)
{
	if (__builtin_expect(!a || !b || !b->array.len, 0))
		return ;
	stack_push(a, stack_pop(b));
	if (log)
		ft_printf(1, "pa\n");
}

void	stack_pb(t_stack *a, t_stack *b, bool log)
{
	if (__builtin_expect(!a || !b || !a->array.len, 0))
		return ;
	stack_push(b, stack_pop(a));
	if (log)
		ft_printf(1, "pb\n");
}

void	stack_sx(t_stack *stack, char name)
{
	int32_t	val1;
	int32_t	val2;

	if (__builtin_expect(!stack || stack->array.len < 2, 0))
		return ;
	val1 = stack_pop(stack);
	val2 = stack_pop(stack);
	stack_push(stack, val1);
	stack_push(stack, val2);
	if (name)
		ft_printf(1, "s%c\n", name);
}

void	stack_rx(t_stack *stack, char name)
{
	t_array_list	*array;
	uint32_t		top;
	uint32_t		i;

	if (__builtin_expect(!stack || !stack->array.data
			|| stack->array.len < 2, 0))
		return ;
	array = &stack->array;
	top = *(int32_t *)array_list_get(array, array->len - 1);
	i = array->len;
	while (i-- > 1)
		ft_memcpy(array->data + array->mem * i,
			array->data + array->mem * (i - 1), array->mem);
	ft_memcpy(array->data, &top, array->mem);
	if (name)
		ft_printf(1, "r%c\n", name);
}

void	stack_rrx(t_stack *stack, char name)
{
	t_array_list	*array;
	uint32_t		bottom;
	uint32_t		i;

	if (__builtin_expect(!stack || !stack->array.data
			|| stack->array.len < 2, 0))
		return ;
	array = &stack->array;
	bottom = *(int32_t *)array_list_get(array, 0);
	i = -1;
	while (++i < array->len - 1)
		ft_memcpy(array->data + array->mem * i,
			array->data + array->mem * (i + 1), array->mem);
	ft_memcpy(array->data + (array->len - 1) * array->mem, &bottom, array->mem);
	if (name)
		ft_printf(1, "rr%c\n", name);
}
