/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:36 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 17:28:56 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int32_t	stack_pop(t_stack *stack)
{
	void	*ptr;
	int32_t	val;

	if (__builtin_expect(!stack || !stack->data || !stack->len, 0))
		return (0);
	stack->len--;
	ptr = array_list_get(stack, stack->len);
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
	static bool	look_table[UINT32_MAX];
	uint32_t	index;
	uint32_t	i;

	if (__builtin_expect(!stack || !stack->data || !stack->len, 0))
		return (false);
	i = -1;
	while (++i < stack->len)
	{
		index = (*(int32_t *)array_list_get(stack, i)) + ((uint32_t)INT32_MAX + 1);
		if (look_table[index])
			return (false);
		look_table[index] = true;
	}
	return (true);

}
