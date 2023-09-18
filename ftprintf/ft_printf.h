/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:16:38 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/15 11:29:11 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int d);
int	ft_putunsnbr(unsigned int d);
int	ft_puthexa(unsigned int d);
int	ft_puthexa_m(unsigned int d);
int	ft_putptr(unsigned long long d);
int	ft_printf(const char *str, ...);

#endif