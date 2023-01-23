/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/01/22 12:59:58 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	simplify(t_stack *stack)
{
	int	i;
	int	*distances;

	i = 0;
	distances = malloc(stack->len_a * sizeof(int));
	if (distances == NULL)
		error_exit(stack);
	while (i < stack->len_a)
		distances[i++] = -1;
	i = 0;
	while (i < stack->len_a)
	{
		distances[i] = find_smallest_mod(stack->a, distances, stack->len_a);
		i++;
	}
	i = 0;
	while (i < stack->len_a)
	{
		stack->a[distances[i]] = i;
		i++;
	}
	free (distances);
	return (EXIT_SUCCESS);
}

void	radix_sort(t_stack *stack)
{
	int	max_n;
	int	n_bits;
	int	i;
	int	nbr;

	max_n = stack->len_a - 1;
	n_bits = 0;
	while ((max_n >> n_bits) != 0)
		n_bits++;
	i = 0;
	while (i < n_bits)
	{
		nbr = stack->len_a;
		while (nbr)
		{
			if (((stack->a[0] >> i) & 1) == 1)
				rotate_a(stack);
			else
				push_b(stack);
			nbr--;
		}
		while (stack->len_b)
			push_a(stack);
		i++;
	}
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

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		error_exit(stack);
	get_stack(argc, argv, stack);
	if (!is_sorted(stack))
	{
		if (stack->len_a <= 5)
			small_sort(stack);
		else
		{
			simplify(stack);
			radix_sort(stack);
		}
	}
	memfree(stack);
	return (EXIT_SUCCESS);
}
