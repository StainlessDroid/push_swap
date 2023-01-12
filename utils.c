/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:14:13 by mpascual          #+#    #+#             */
/*   Updated: 2023/01/12 20:38:40 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	memfree(t_stack *stack)
{
	free(stack->b);
	free(stack->a);
	free(stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	find_in(int *haystack, int needle, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (haystack[i] == needle)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	find_biggest(int *stack, int len)
{
	int	i;
	int	max;
	int	distance;

	i = 0;
	distance = 0;
	max = stack[i];
	while (i < len)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			distance = i;
		}
		i++;
	}
	return (distance);
}

int	find_smallest_mod(int *stack, int *distarr, int len)
{
	int	i;
	int	min;
	int	distance;

	i = 0;
	distance = 0;
	min = stack[find_biggest(stack, len)];
	while (i < len)
	{
		if (stack[i] <= min && find_in(distarr, i, len))
		{
			min = stack[i];
			distance = i;
		}
		i++;
	}
	return (distance);
}

void	error_exit(t_stack *stack)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	memfree(stack);
	exit(EXIT_FAILURE);
}
