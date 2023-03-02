/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:57 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:38:56 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_set	*set_new(void *data)
{
	t_set	*new;

	new = (t_set *) malloc(sizeof(t_set));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	set_add(t_set **set, void *data)
{
	t_set	*new;

	new = set_new(data);
	if (!new || set_contains(*set, data))
		return ;
	while (*set)
		set = &(*set)->next;
	*set = new;
}

void	set_remove(t_set **set, void *data)
{
	t_set	*aux;
	t_set	*prev;

	if (!set_contains(*set, data))
		return ;
	aux = *set;
	prev = NULL;
	while (aux)
	{
		if (aux->data == data)
		{
			if (prev)
				prev->next = aux->next;
			else
				*set = aux->next;
			free(aux);
			return ;
		}
		prev = aux;
		aux = aux->next;
	}
}
