/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:18:12 by secker            #+#    #+#             */
/*   Updated: 2023/01/12 17:03:22 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static char	**s;
	static char	**temp;
	int			j;
	int			i;

	i = 0;
	j = 0;
	s = make_map(s);
	temp = make_map(temp);
	j = map_test(temp);
	while (temp[i])
		free(temp[i++]);
	free(temp);
	i = 0;
	if (j == 0)
	{
		while (s[i])
			free(s[i++]);
		free(s);
		return (0);
	}
	create_map(s);
}
