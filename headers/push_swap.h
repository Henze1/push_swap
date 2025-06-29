/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:39:21 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack_utils.h"
# include "../libft/libft.h"

int		push_swap(char *str[], const int size);
int		*separate_numbers(char *str[], const int size);
char	*ft_strjoin_two(char *s1, char const *s2);
char	**shuffle_split(char *str[], const int size);
int		count_numbers(char **num_arr);
void	init_stack(t_stack **stack, int *numbers, const int size);
void	sort(t_stack **stack_a, t_stack **stack_b, const int size);
void	normalize_stack(t_stack **stack);
void	free_stack(t_stack **stack);

#endif
