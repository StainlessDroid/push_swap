/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:13:08 by mpascual          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:43 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr("sa\n");
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_putstr("sb\n");
}

int	push_a(t_stack *stack)
{
	int	i;

	if (stack->len_b == 0)
		return (0);
	i = stack->len_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = stack->b[i];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->len_b--;
	stack->len_a++;
	ft_putstr("pa\n");
	return (1);
}

int	push_b(t_stack *stack)
{
	int	i;

	if (stack->len_a == 0)
		return (0);
	i = stack->len_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = stack->a[i];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->len_a--;
	stack->len_b++;
	ft_putstr("pb\n");
	return (1);
}
