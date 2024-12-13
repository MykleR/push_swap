/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:00:54 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 19:19:16 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ss(t_stack *a, t_stack *b, bool quiet)
{
	sx(a, 1);
	sx(b, 1);
	if (!quiet)
		ft_printf(1, "ss\n");
}

void	rr(t_stack *a, t_stack *b, bool quiet)
{
	rx(a, 1);
	rx(b, 1);
	if (!quiet)
		ft_printf(1, "rr\n");
}

void	rrr(t_stack *a, t_stack *b, bool quiet)
{
	rrx(a, 1);
	rrx(b, 1);
	if (!quiet)
		ft_printf(1, "rrr\n");
}
