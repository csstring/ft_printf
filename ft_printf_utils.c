/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:37:21 by schoe             #+#    #+#             */
/*   Updated: 2022/04/15 21:51:54 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"

int	ft_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_p(void *p)
{
	char	*str;
	int		i;
	size_t	addr;

	addr = (size_t)p;
	str = ft_u_convert_base(ft_uitoa(addr), "0123456789", "0123456789abcdef");
	ft_putchar_fd('0', 1);
	ft_putchar_fd('X', 1);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str) + 2;
	free(str);
	return (i);
}

int	ft_di(int d)
{
	char	*str;
	int		i;

	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_xu(unsigned int ud, char type)
{
	char	*str;
	int		i;

	if (type == 'x')
		str = ft_u_convert_base(ft_uitoa(ud), "0123456789", "0123456789abcdef");
	else if (type == 'X')
		str = ft_u_convert_base(ft_uitoa(ud), "0123456789", "0123456789abcdef");
	else
		str = ft_uitoa(ud);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}