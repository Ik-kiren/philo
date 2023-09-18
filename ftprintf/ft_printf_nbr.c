/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:23:36 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/15 11:31:36 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int d)
{
	if (d == 0)
		ft_putchar('0');
	if (d == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (d < 0)
		{
			ft_putchar('-');
			d = -d;
		}
		if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 9)
		{
			ft_printnbr(d / 10);
			ft_putchar((d % 10) + '0');
		}
	}
}

int	ft_putnbr(int d)
{
	int	nb;
	int	i;

	i = 0;
	nb = d;
	if (d < 0)
		i++;
	if (d == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
		ft_printnbr(d);
	}
	return (i);
}

void	ft_printunsnbr(unsigned int d)
{
	if (d == 0)
		ft_putchar('0');
	if (d <= 9 && d > 0)
		ft_putchar(d + 48);
	else if (d >= 9)
	{
		ft_printunsnbr(d / 10);
		ft_putchar((d % 10) + '0');
	}
}

int	ft_putunsnbr(unsigned int d)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = d;
	if (d == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
		ft_printunsnbr(d);
	}
	return (i);
}
