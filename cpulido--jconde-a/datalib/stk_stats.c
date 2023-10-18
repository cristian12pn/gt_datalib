/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:18:15 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

int	stk_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	stk_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stk_top(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack);
}

void	*stk_peek(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack->data);
}
