/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:22 by mpascual          #+#    #+#             */
/*   Updated: 2023/01/12 20:32:29 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

typedef struct t_stack {
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;

void	init_stacks(int len, t_stack *stack);
void	get_stack(int argc, char **argv, t_stack *stack);
int		find_duplicate(int *stack, int len);
int		is_sorted(t_stack *stack);
int		sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);
void	small_sort(t_stack *stack);
int		find_smallest(int *stack, int len);
int		find_smallest_mod(int *stack, int *distarr, int len);
int		simplify(t_stack *stack);
int		find_in(int *haystack, int needle, int len);
void	memfree(t_stack *stack);
void	error_exit(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack);
int		push_a(t_stack *stack);
int		push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_both(t_stack *stack);
/*
** DEBUG
*/
void	print_stack(t_stack *stack);
#endif
