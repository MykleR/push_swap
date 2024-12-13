/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 21:57:09 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	is_empty_string(const char *str)
{
	while (str && *str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	return (!str || !(*str));
}

static char	**parse_args(int ac, char **av)
{
	if (__builtin_expect(is_empty_string(av[--ac]), 0))
		return (NULL);
	while (ac--)
	{
		if (is_empty_string(av[ac]))
			return (NULL);
		av[ac][ft_strlen(av[ac])] = ' ';
	}
	return (ft_split(av[0], ' '));
}

int	main(int ac, char **av)
{
	static t_stack	a = {0};
	static t_stack	b = {0};
	char			**split_args;

	if (__builtin_expect(ac <= 1, 0))
		return (0);
	split_args = parse_args(ac - 1, av + 1);
	if (split_args
		&& stack_parse_fill(&a, split_args)
		&& stack_create(&b, a.cap, 'b')
		&& stack_parse_check(&a, __check_doubles))
		stack_sort(&a, &b);
	else
		ft_printf(2, "Error\n");
	ft_split_free(split_args);
	stack_destroy(&a);
	stack_destroy(&b);
	return (0);
}
