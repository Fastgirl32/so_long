/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:18:12 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:13:29 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static char	**s;
	static char	**temp;
	int			j;
	int			i;

	i = 0;
	j = 0;
	if (argv[1] == NULL)
		argv[1] = "map1.ber";
	s = make_map(s, argv[1]);
	temp = make_map(temp, argv[1]);
	j = map_test(temp);
	while (temp[i])
		free(temp[i++]);
	free(temp);
	i = 0;
	if (j == 0 && argc)
	{
		while (s[i])
			free(s[i++]);
		free(s);
		return (0);
	}
	create_map(s);
}
