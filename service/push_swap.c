/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/17 15:20:16 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"
#include "../headers/sort.h"

int push_swap(char *str[], const int size) {
    int *numbers;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    numbers = separate_numbers(str, size);
    if (!numbers)
        return (1);
    init_stack(&stack_a, numbers, size);
    free(numbers);
    normalize_stack(&stack_a);
    sort(&stack_a, &stack_b, size);
    // t_stack *tmp = stack_a;//TODO: Debug. To delete
    // ft_putendl_fd("stack a: ", 1);//TODO: Debug. To delete
    // while (tmp)//TODO: Debug. To delete
    // {
    //     ft_putnbr_fd(tmp->index, 1);
    //     ft_putstr_fd(" : ", 1);
    //     ft_putnbr_fd(tmp->number, 1);
    //     ft_putchar_fd('\n', 1);
    //     tmp = tmp->next;
    // }//TODO: Debug. To delete
    free_stack(&stack_a);
    return (0);
}

char    **shuffle_split(char *str[], const int size)
{
    int	i;
    char	*str_array;
    char	**num_array;

    str_array = ft_strdup("");
    if (!str_array)
        return (NULL);
    i = 0;
    while (i < size)
    {
        str_array = ft_strjoin_two(str_array, str[i++]);
        str_array = ft_strjoin_two(str_array, " ");
    }
    num_array = ft_split(str_array, ' ');
    free(str_array);
    if (!num_array)
        return (NULL);
    return (num_array);
}

void    init_stack(t_stack **stack, int *numbers, const int size)
{
    int i;

    i = 0;
    *(stack) = create_stack(numbers[i++]);
    while (i < size)
        push(stack, create_stack(numbers[i++]));
}

void    sort(t_stack **stack_a, t_stack **stack_b, const int size)
{
    if (!stack_a || !stack_b || is_sorted(stack_a) || size == 1)
        return ;
    if (size == 2)
        sort_two_numbers(stack_a);
    else if (size == 3)
        sort_three_numbers(stack_a);
    else if (size == 4)
        sort_four_numbers(stack_a, stack_b);
    else if (size == 5)
        sort_five_numbers(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

void    free_stack(t_stack **stack)
{
    t_stack *temp;

    temp = NULL;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}