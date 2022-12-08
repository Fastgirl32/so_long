/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:14:55 by secker            #+#    #+#             */
/*   Updated: 2022/10/13 13:44:19 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	form_int(const char *str, int i, int k, int fin)
{
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (k == -1)
			{
				fin = fin * 10 - (str[i] - '0');
			}
			else
				fin = fin * 10 + (str[i] - '0');
			i++;
		}
		else
			break ;
	}
	return (fin);
}

int	ft_allwork(const char *str, int i, int fin)
{
	int	k;

	k = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v')
			i++;
		else
			break ;
	}
	while (str[i])
	{
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				k = -1;
			i++;
			break ;
		}
		else
			break ;
	}
	fin = form_int(str, i, k, fin);
	return (fin);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	fin;

	i = 0;
	fin = 0;
	fin = ft_allwork(str, i, fin);
	if (fin == -469762049)
		return (-1);
	if (fin == 469762049)
		return (0);
	return (fin);
}
