/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:10:02 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:11 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr3(char *s, int i)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (i + 6);
	}
	while (*s)
	{
		write(1, &*s, 1);
		s++;
		i++;
	}
	return (i);
}
