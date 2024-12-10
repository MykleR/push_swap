/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:36 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 18:39:45 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int32_t	stack_pop(t_stack *stack)
{
	void	*ptr;
	int32_t	val;

	if (__builtin_expect(!stack || !stack->data || !stack->len, 0))
		return (0);
	ptr = array_list_get(stack, stack->len - 1);
	stack->len--;
	if (__builtin_expect(!ptr, 0))
		return (0);
	val = *(int32_t *)ptr;
	return (val);
}

bool	stack_push(t_stack *stack, int32_t x)
{
	if (__builtin_expect(!stack || !stack->data, 0))
		return (false);
	array_list_insert(stack, &x);
	return (true);
}

bool	stack_parse_fill(t_stack *stack, uint32_t ac, char **av)
{
	int32_t	convert;

	while (ac--)
	{
		if (!ft_safe_atoi(av[ac], &convert))
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
