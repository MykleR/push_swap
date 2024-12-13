/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:51:54 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/13 14:46:04 by mrouves          ###   ########.fr       */
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

static bool	exec_move(t_stack *a, t_stack *b, const char *name)
{
	if (!ft_strncmp(name, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(name, "pb\n", 3))
		pb(a, b, 1);
	else if (!ft_strncmp(name, "sa\n", 3))
		sx(a, 1);
	else if (!ft_strncmp(name, "sb\n", 3))
		sx(b, 1);
	else if (!ft_strncmp(name, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(name, "ra\n", 3))
		rx(a, 1);
	else if (!ft_strncmp(name, "rb\n", 3))
		rx(b, 1);
	else if (!ft_strncmp(name, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(name, "rra\n", 4))
		rrx(a, 1);
	else if (!ft_strncmp(name, "rrb\n", 4))
		rrx(b, 1);
	else if (!ft_strncmp(name, "rrr\n", 4))
		rrr(a, b, 1);
	else
		return (false);
	return (true);
}

static bool	parse_moves(t_stack *a, t_stack *b)
{
	char	*line;
	bool	valid;

	valid = true;
	line = get_next_line(0);
	while (line)
	{
		valid = valid && exec_move(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	return (valid);
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
		&& stack_parse_check(&a, __check_doubles)
		&& parse_moves(&a, &b))
	{
		if (!b.len && stack_parse_check(&a, __check_sorted))
			ft_printf(1, "OK\n");
		else
			ft_printf(1, "KO\n");
	}
	else
		ft_printf(2, "Error\n");
	ft_split_free(split_args);
	stack_destroy(&a);
	stack_destroy(&b);
	return (0);
}
