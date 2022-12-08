/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:18:12 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:44:28 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**s;
	char 	**temp;
	int		j;
	int 	i;
    
	s = NULL;
	temp = NULL;
	i = 0;
	s = make_map(s);
	temp = make_map(temp);
	j = map_test(temp);
	while(temp[i])
		free(temp[i++]);
	free(temp);
	if (j == 0)
	{
		return (0);
	}
	create_map(s);
}
