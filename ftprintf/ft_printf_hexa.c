/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:24:31 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/15 11:28:51 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned int d)
{
	if (d == 0)
		ft_putchar('0');
	else
	{
		if (d >= 10 && d <= 15)
		{
			ft_putchar(d + 87);
		}
		else if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 16)
		{
			ft_printhexa(d / 16);
			if (d % 16 >= 10 && d % 16 <= 15)
				ft_putchar((d % 16) + 87);
			else
				ft_putchar((d % 16) + '0');
		}
	}
}

int	ft_puthexa(unsigned int d)
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
			nb = nb / 16;
			i++;
		}
		ft_printhexa(d);
	}
	return (i);
}

void	ft_printhexa_m(unsigned int d)
{
	if (d == 0)
		ft_putchar('0');
	else
	{
		if (d >= 10 && d <= 15)
			ft_putchar(d + 55);
		else if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 16)
		{
			ft_printhexa_m(d / 16);
			if (d % 16 >= 10 && d % 16 <= 15)
				ft_putchar((d % 16) + 55);
			else
				ft_putchar((d % 16) + '0');
		}
	}
}

int	ft_puthexa_m(unsigned int d)
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
			nb = nb / 16;
			i++;
		}
		ft_printhexa_m(d);
	}
	return (i);
}
