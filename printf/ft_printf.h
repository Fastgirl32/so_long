/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:50:33 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:02 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putstr3(char *s, int i);
int	ft_putchar3(char c, int i);
int	ft_hexa_low(unsigned int i, int k);
int	ft_hexa_up(unsigned int i, int k);
int	ft_putnbr(int n, int i);
int	ft_putnbr_long(unsigned int n, int i);
int	ft_pointer(void *s, int i);
#endif