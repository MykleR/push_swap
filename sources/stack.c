/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:36 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 14:32:54 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int32_t	stack_get(t_stack *stack, uint32_t index)
{
	void	*ptr;

	if (__builtin_expect(!stack || !stack->data || !stack->len, 0))
		return (0);
	ptr = array_list_get(stack, index);
	if (__builtin_expect(!ptr, 0))
		return (0);
	return (*(int32_t *)ptr);
}

int32_t	stack_pop(t_stack *stack)
{
	int32_t	val;
	
	val = stack_get(stack, stack->len - 1);
	stack->len--;
	return (val);
}

bool	stack_push(t_stack *stack, int32_t x)
{
	if (__builtin_expect(!stack || !stack->data, 0))
		return (false);
	array_list_insert(stack, &x);
	return (true);
}

bool	stack_parse_fill(t_stack *stack, char **args)
{
	uint32_t	i;
	int32_t		convert;

	i = 0;
	while (args[i])
		i++;
	while (i--)
	{
		if (!ft_safe_atoi(args[i], &convert))
			return (false);
		array_list_insert(stack, &convert);
	}
	return (true);
}

bool	stack_parse_duplicates(t_stack *stack)
{
	uint32_t	i;
	uint32_t	j;

	if (__builtin_expect(!stack || !stack->data || !stack->len, 0))
		return (false);
	i = -1;
	while (++i < stack->len)
	{
		j = i;
		while (++j < stack->len)
			if (*(int32_t *)array_list_get(stack, i)
				== *(int32_t *)array_list_get(stack, j))
				return (false);
	}
	return (true);
}
