/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:46:15 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:11 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sort.h"
#include "../../headers/operations.h"

void	sort_two_numbers(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

void	sort_three_numbers(t_stack **stack)
{
	if ((*stack)->number < (*stack)->next->number
		&& (*stack)->next->number > (*stack)->next->next->number
		&& (*stack)->number < (*stack)->next->next->number)
	{
		rra(stack);
		sa(stack);
	}
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->next->number < (*stack)->next->next->number
		&& (*stack)->number < (*stack)->next->next->number)
		sa(stack);
	else if ((*stack)->number < (*stack)->next->number
		&& (*stack)->next->number > (*stack)->next->next->number
		&& (*stack)->number > (*stack)->next->next->number)
		rra(stack);
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->next->number < (*stack)->next->next->number
		&& (*stack)->number > (*stack)->next->next->number)
		ra(stack);
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->next->number > (*stack)->next->next->number)
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_four_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(stack_a);
	if (min == (*stack_a)->next->next->next)
		rra(stack_a);
	else if (min == (*stack_a)->next->next)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else
		while (min != *stack_a)
			ra(stack_a);
	pb(stack_a, stack_b);
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(stack_a);
	if (min == (*stack_a)->next->next->next->next)
		rra(stack_a);
	else if (min == (*stack_a)->next->next->next)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (min == (*stack_a)->next->next)
	{
		rra(stack_a);
		rra(stack_a);
		rra(stack_a);
	}
	else
		while (min != *stack_a)
			ra(stack_a);
	pb(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return (0);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
