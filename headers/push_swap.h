/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:33 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/10 19:03:48 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>
# include <libft.h>

typedef t_array_list	t_stack;

int32_t	stack_pop(t_stack *stack);
bool	stack_push(t_stack *stack, int32_t x);
bool	stack_parse_fill(t_stack *stack, uint32_t ac, char **av);
bool	stack_parse_duplicates(t_stack *stack);

void	stack_sx(t_stack *stack, char name);// OK
void	stack_rx(t_stack *stack, char name);// OK
void	stack_rrx(t_stack *stack, char name); // OK
void	stack_ss(t_stack *a, t_stack *b, bool log);
void	stack_pa(t_stack *a, t_stack *b, bool log);// OK
void	stack_pb(t_stack *a, t_stack *b, bool log);// OK
void	stack_rr(t_stack *a, t_stack *b, bool log);
void	stack_rrr(t_stack *a, t_stack *b, bool log);

#endif
