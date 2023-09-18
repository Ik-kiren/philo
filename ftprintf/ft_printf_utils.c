/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:10:19 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/15 11:33:25 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_printptr(unsigned long long d)
{
	if (d >= 16)
	{
		ft_printptr(d / 16);
		ft_printptr(d % 16);
	}
	else
	{
		if (d >= 10 && d <= 15)
			ft_putchar(d + 87);
		else
			ft_putchar(d + 48);
	}
}

int	ft_putptr(unsigned long long d)
{
	unsigned long long	nb;
	int					i;

	i = 2;
	nb = d;
	if (d == 0)
	{
		write(1, "0x0", 3);
		i = 3;
	}
	else
	{
		write(1, "0x", 2);
		while (nb != 0)
		{
			nb = nb / 16;
			i++;
		}
		ft_printptr(d);
	}
	return (i);
}
