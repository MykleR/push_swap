/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:36 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 20:55:46 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	stack_create(t_stack *stack, uint32_t cap, char name)
{
	if (__builtin_expect(!stack, 0))
		return (false);
	stack->cap = cap;
	stack->len = 0;
	stack->index_min = 0;
	stack->index_max = 0;
	stack->name = name;
	stack->array = malloc(sizeof(int32_t) * cap);
	stack->targets = malloc(sizeof(uint32_t) * cap);
	return (stack->array != NULL);
}

void	stack_destroy(t_stack *stack)
{
	if (__builtin_expect(!stack, 0))
		return ;
	free(stack->array);
	free(stack->targets);
	stack->cap = 0;
	stack->len = 0;
	stack->array = NULL;
	stack->targets = NULL;
}

void	stack_push(t_stack *stack, int32_t x)
{
	if (__builtin_expect(!stack || stack->len >= stack->cap, 0))
		return ;
	stack->array[stack->len++] = x;
}

int32_t	stack_pop(t_stack *stack)
{
	if (__builtin_expect(!stack || !stack->len, 0))
		return (0);
	return (stack->array[--stack->len]);
}

void	stack_minmax(t_stack *stack)
{
	uint32_t	i;

	stack->index_min = 0;
	stack->index_max = 0;
	if (__builtin_expect(!stack->len, 0))
		return ;
	i = stack->len;
	while (--i)
	{
		if (stack->array[i] > stack->array[stack->index_max])
			stack->index_max = i;
		if (stack->array[i] < stack->array[stack->index_min])
			stack->index_min = i;
	}
}
