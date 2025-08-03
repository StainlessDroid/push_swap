/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:36:43 by mpascual          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:56 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate_a(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->len_a - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->len_b - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	ft_putstr_fd("rrb\n", 1);
}
