/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:05 by schoe             #+#    #+#             */
/*   Updated: 2022/04/15 21:52:16 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_type(va_list *ap, char type)
{
	if (type == 'c')
		return (ft_c(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_s(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_p(va_arg(*ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_di(va_arg(*ap, int)));
	else if (type == 'x' || type == 'X' || type == 'u')
		return (ft_xu(va_arg(*ap, int), type));
	else if (type == '%')
	{
		ft_putchar_fd(type, 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, arg);
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
		{
			i++;
			count += ft_type(&ap, arg[i]);
		}
		else
		{
			ft_putchar_fd(arg[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
