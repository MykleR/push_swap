/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:54:25 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 20:02:54 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	simplify_moves(t_moves *moves)
{
	while(moves->rb && moves->ra)
	{
		moves->rb--;
		moves->ra--;
		moves->rr++;
	}
	while(moves->rra && moves->rrb)
	{
		moves->rrb--;
		moves->rra--;
		moves->rrr++;
	}
}

void	exec_moves(t_stack *a, t_stack *b, t_moves moves)
{
	while (moves.rrr--)
		rrr(a, b, 0);
	while (moves.rr--)
		rr(a, b, 0);
	while (moves.ra--)
		rx(a, 0);
	while (moves.rb--)
		rx(b, 0);
	while (moves.rra--)
		rrx(a, 0);
	while (moves.rrb--)
		rrx(b, 0);
}

void	find_best_pb(t_stack *a, t_stack *b, t_moves *out)
{
	t_moves		moves;
	uint32_t	rrcost;
	uint32_t	rcost;
	uint32_t	i;

	i = a->len;
	ft_memset(out, UINT32_MAX / 6, sizeof(t_moves));
	while (i--)
	{
		ft_memset(&moves, 0, sizeof(t_moves));
		rcost = rotate_top_cost(a, i);
		rrcost = rrotate_top_cost(a, i);
		moves.ra = rcost * (rcost <= rrcost);
		moves.rra = rrcost * (rrcost < rcost);
		rcost = rotate_top_cost(b, a->targets[i]);
		rrcost = rrotate_top_cost(b, a->targets[i]);
		moves.rb = rcost * (rcost <= rrcost);
		moves.rrb = rrcost * (rrcost < rcost);
		simplify_moves(&moves);
		if (moves.ra + moves.rb + moves.rra + moves.rrb + moves.rr + moves.rrr
			< out->ra + out->rb + out->rra + out->rrb + out->rr + out->rrr)
			*out = moves;
	}
}

void	find_best_pa(t_stack *a, t_stack *b, t_moves *out)
{
	t_moves		moves;
	uint32_t	rrcost;
	uint32_t	rcost;
	uint32_t	i;

	i = b->len;
	ft_memset(out, UINT32_MAX / 6, sizeof(t_moves));
	while (i--)
	{
		ft_memset(&moves, 0, sizeof(t_moves));
		rcost = rotate_top_cost(b, i);
		rrcost = rrotate_top_cost(b, i);
		moves.rb = rcost * (rcost <= rrcost);
		moves.rrb = rrcost * (rrcost < rcost);
		rcost = rotate_top_cost(a, b->targets[i]);
		rrcost = rrotate_top_cost(a, b->targets[i]);
		moves.ra = rcost * (rcost <= rrcost);
		moves.rra = rrcost * (rrcost < rcost);
		simplify_moves(&moves);
		if (moves.ra + moves.rb + moves.rra + moves.rrb + moves.rr + moves.rrr
			< out->ra + out->rb + out->rra + out->rrb + out->rr + out->rrr)
			*out = moves;
	}
}
