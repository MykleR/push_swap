/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:33 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 18:22:29 by mrouves          ###   ########.fr       */
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
	uint32_t	cap;
	uint32_t	len;
	int32_t		max;
	int32_t		min;
}	t_stack;


bool	stack_parse_fill(t_stack *stack, char **split);
bool	stack_parse_check(t_stack *stack, bool (*check)(int32_t, int32_t));
bool	__check_sorted(int32_t x, int32_t y);
bool	__check_doubles(int32_t x, int32_t y);

bool	stack_create(t_stack *stack, uint32_t cap);
void	stack_destroy(t_stack *stack);
void	stack_push(t_stack *stack, int32_t x);
int32_t	stack_pop(t_stack *stack);

void	stack_sx(t_stack *stack, char name);
void	stack_rx(t_stack *stack, char name);
void	stack_rrx(t_stack *stack, char name);

void	stack_ss(t_stack *a, t_stack *b, bool log);
void	stack_pa(t_stack *a, t_stack *b, bool log);
void	stack_pb(t_stack *a, t_stack *b, bool log);
void	stack_rr(t_stack *a, t_stack *b, bool log);
void	stack_rrr(t_stack *a, t_stack *b, bool log);

void	stack_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *stack);

#endif
