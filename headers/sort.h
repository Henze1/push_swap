/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:36:16 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:39:25 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
#include "stack_utils.h"

void    sort_two_numbers(t_stack **stack);
void    sort_three_numbers(t_stack **stack);
void    sort_four_numbers(t_stack **stack_a, t_stack **stack_b);
void    sort_five_numbers(t_stack **stack_a, t_stack **stack_b);
void    radix_sort(t_stack **stack_a, t_stack **stack_b);
void    merge_sort(int *arr, int left, int right);
void    merge_halves(int *arr, int left, int middle, int right);
void    execute_merge(int *arr, int *l_tmp, int *r_tmp, int *vars);
void    copy_data_to_temp(int *dest, int *src, int start_idx, int size);
int is_sorted(t_stack **stack_a);
t_stack *find_max(t_stack **stack);
t_stack *find_min(t_stack **stack);

#endif
