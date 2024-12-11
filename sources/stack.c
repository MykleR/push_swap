/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:36 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 18:13:51 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


bool	stack_create(t_stack *stack, uint32_t cap)
{
	if (__builtin_expect(!stack, 0))
		return (false);
	stack->cap = cap;
	stack->len = 0;
	stack->min = INT32_MAX;
	stack->max = INT32_MIN;
	stack->array = malloc(sizeof(int32_t) * cap);
	return (stack->array != NULL);
}

void	stack_destroy(t_stack *stack)
{
	if (__builtin_expect(!stack, 0))
		return ;
	free(stack->array);
	stack->cap = 0;
	stack->len = 0;
	stack->array = 0;
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
