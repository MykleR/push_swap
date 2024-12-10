/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:00:54 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 19:03:32 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stack_ss(t_stack *a, t_stack *b, bool log)
{
	stack_sx(a, 0);
	stack_sx(b, 0);
	if (log)
		ft_printf(1, "ss\n");
}

void	stack_rr(t_stack *a, t_stack *b, bool log)
{
	stack_rx(a, 0);
	stack_rx(b, 0);
	if (log)
		ft_printf(1, "rr\n");
}

void	stack_rrr(t_stack *a, t_stack *b, bool log)
{
	stack_rrx(a, 0);
	stack_rrx(b, 0);
	if (log)
		ft_printf(1, "rrr\n");
}
