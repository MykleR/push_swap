/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 14:36:00 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	print_stack(t_array_list *stack)
{
	uint32_t	i;

	i = -1;
	while (++i < stack->len)
		ft_printf(1, "%d, ", *(int32_t *)array_list_get(stack, i));
	ft_printf(1, "\n");
}

static char	**parse_args(int ac, char **av)
{
	if (__builtin_expect(!ac || !av, 0))
		return (NULL);
	ac--;
	while (ac--)
		av[ac][ft_strlen(av[ac])] = ' ';
	return (ft_split(av[0], ' '));
}

int	main(int ac, char **av)
{
	static t_stack	astack = {0};
	static t_stack	bstack = {0};
	char	**split_args;

	split_args = parse_args(ac - 1, av + 1);
	if (split_args && array_list_create(&astack, sizeof(int32_t))
		&& array_list_create(&bstack, sizeof(int32_t))
		&& stack_parse_fill(&astack, split_args)
		&& stack_parse_duplicates(&astack))
	{
		print_stack(&astack);
		sort_three(&astack);
		print_stack(&astack);
		print_stack(&bstack);
	}
	else
		ft_printf(2, "Error\n");
	ft_split_free(split_args);
	array_list_destroy(&astack);
	array_list_destroy(&bstack);
	return (0);
}
