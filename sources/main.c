/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 18:57:52 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_array_list *stack)
{
	uint32_t	i;

	i = -1;
	while (++i < stack->len)
		ft_printf(1, "%d, ", *(int32_t *)array_list_get(stack, i));
	ft_printf(1, "\n");
}

int	main(int ac, char **av)
{
	t_stack	astack;
	t_stack	bstack;
	
	if (ac < 2)
		return (0);
	if (array_list_create(&astack, sizeof(int32_t))
			&& array_list_create(&bstack, sizeof(int32_t))
			&& stack_parse_fill(&astack, ac - 1, av + 1)
			&& stack_parse_duplicates(&astack))
	{
		stack_rrx(&astack, 'a');
		// START SORTING
		print_stack(&astack);
		print_stack(&bstack);
	}
	else
		ft_printf(2, "Error\n");
	array_list_destroy(&astack);
	array_list_destroy(&bstack);
	return (0);
}
