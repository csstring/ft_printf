/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:05 by schoe             #+#    #+#             */
/*   Updated: 2022/04/18 21:32:59 by schoe            ###   ########.fr       */
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
		return (-1);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		count;
	int		check;

	count = 0;
	va_start(ap, arg);
	while (*arg != '\0')
	{
		if (*arg == '%')
		{
			arg++;
			check = ft_type(&ap, *arg);
			if (check == -1)
				return (-1);
			count += check;
		}
		else
		{
			ft_putchar_fd(*arg, 1);
			count++;
		}
		arg++;
	}
	va_end(ap);
	return (count);
}
