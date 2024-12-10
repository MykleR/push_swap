/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 16:37:45 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	//t_array_list	astack;
	//t_array_list	bstack;
	if (ac < 2)
		return (0);

	int32_t	x;
	ft_printf(1,"%d\n%d\n", ft_safe_atoi(av[1], &x), x);
	(void) av;
	return (0);
}
