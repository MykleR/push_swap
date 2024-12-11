/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 19:21:31 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	print_stack(t_stack *stack)
{
	for(int i = stack->len - 1; i >= 0; i--)
		ft_printf(1, "%d,", stack->array[i]);
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
	static t_stack	a = {0};
	static t_stack	b = {0};
	char			**split_args;

	split_args = parse_args(ac - 1, av + 1);
	if (split_args && stack_parse_fill(&a, split_args)
		&& stack_create(&b, a.cap, 'b')
		&& stack_parse_check(&a, __check_doubles))
	{
		stack_sort(&a, &b);
		print_stack(&a);
		print_stack(&b);
	}
	else
		ft_printf(2, "Error\n");
	ft_split_free(split_args);
	stack_destroy(&a);
	stack_destroy(&b);
	return (0);
}
