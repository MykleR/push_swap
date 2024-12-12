/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 20:54:37 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**parse_args(int ac, char **av)
{
	if (__builtin_expect(!ac || !av, 0))
		return (NULL);
	ac--;
	while (ac--)
		av[ac][ft_strlen(av[ac])] = ' ';
	return (ft_split(av[0], ' '));
}

static void	clean(t_stack *a, t_stack *b, char **args)
{
	ft_split_free(args);
	stack_destroy(a);
	stack_destroy(b);
}

int	main(int ac, char **av)
{
	static t_stack	a = {0};
	static t_stack	b = {0};
	char			**split_args;

	split_args = parse_args(ac - 1, av + 1);
	if (split_args
		&& stack_parse_fill(&a, split_args)
		&& stack_create(&b, a.cap, 'b')
		&& stack_parse_check(&a, __check_doubles))
		stack_sort(&a, &b);
	else
		ft_printf(2, "Error\n");
	clean(&a, &b, split_args);
	return (0);
}
