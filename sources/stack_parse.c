/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:06:20 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 19:21:21 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	stack_parse_fill(t_stack *stack, char **args)
{
	uint32_t	i;
	int32_t		number;

	i = 0;
	while (args[i])
		i++;
	if (!stack_create(stack, i, 'a'))
		return (false);
	while (i--)
	{
		if (!ft_safe_atoi(args[i], &number))
			return (false);
		if (number > stack->max)
			stack->max = number;
		if (number < stack->min)
			stack->min = number;
		stack_push(stack, number);
	}
	return (true);
}

bool stack_parse_check(t_stack *stack, bool (*check)(int32_t, int32_t))
{
	uint32_t	i;
	uint32_t	j;

	i = stack->len;
	while (i--)
	{
		j = i;
		while (j--)
			if (!check(stack->array[i], stack->array[j]))
				return (false);
	}
	return (true);

}

bool	__check_doubles(int32_t x, int32_t y)
{
	return (x != y);
}

bool	__check_sorted(int32_t x, int32_t y)
{
	return (x <= y);
}
