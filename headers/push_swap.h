/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:33 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 20:01:00 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>
# include <libft.h>

typedef struct s_stack
{
	int32_t		*array;
	uint32_t	*targets;
	uint32_t	cap;
	uint32_t	len;
	uint32_t	index_max;
	uint32_t	index_min;
	char		name;
}	t_stack;

typedef struct s_moves
{
	uint32_t	ra;
	uint32_t	rb;
	uint32_t	rra;
	uint32_t	rrb;
	uint32_t	rr;
	uint32_t	rrr;
}	t_moves;

// =========================== PARSING ===========================
bool		stack_parse_fill(t_stack *stack, char **split);
bool		stack_parse_check(t_stack *stack, bool (*check)(int32_t, int32_t));
bool		__check_sorted(int32_t x, int32_t y);
bool		__check_doubles(int32_t x, int32_t y);

// ============================ STACK ============================
bool		stack_create(t_stack *stack, uint32_t cap, char c);
void		stack_destroy(t_stack *stack);
void		stack_push(t_stack *stack, int32_t x);
int32_t		stack_pop(t_stack *stack);
void		stack_minmax(t_stack *stack);
void		stack_print(t_stack *stack);

// ======================== INSTRUCTIONS =========================
void		sx(t_stack *a, bool quiet);
void		rx(t_stack *a, bool quiet);
void		rrx(t_stack *a, bool quiet);
void		pa(t_stack *a, t_stack *b, bool quiet);
void		pb(t_stack *a, t_stack *b, bool quiet);
void		ss(t_stack *a, t_stack *b, bool quiet);
void		rr(t_stack *a, t_stack *b, bool quiet);
void		rrr(t_stack *a, t_stack *b, bool quiet);

// =========================== SORTING ===========================
void		stack_sort(t_stack *a, t_stack *b);
void		exec_moves(t_stack *a, t_stack *b, t_moves moves);
void		find_best_pa(t_stack *a, t_stack *b, t_moves *out);
void		find_best_pb(t_stack *a, t_stack *b, t_moves *out);
uint32_t	rotate_top_cost(t_stack *stack, uint32_t index);
uint32_t	rrotate_top_cost(t_stack *stack, uint32_t index);
uint32_t	closest_smaller(t_stack *stack, int32_t val);
uint32_t	closest_bigger(t_stack *stack, int32_t val);

void		quick_sort(int32_t *tab, uint32_t start, uint32_t end);

#endif
