/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:05 by schoe             #+#    #+#             */
/*   Updated: 2022/04/14 19:14:28 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * 20);
	i = 0;
	va_start(ap, arg);
	while (arg[i])
	{
		if (arg[i] == '%')
		{
			i++;
			if (arg[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (arg[i] == 's')
				ft_putstr_fd(va_arg(ap, char*), 1);
			else if (arg[i] == 'p')
			{
				str = ft_itoa16(va_arg(ap, void *));
				ft_putstr_fd(str,1);
			}
			else if (arg[i] == 'd')
			{
				str = ft_itoa(va_arg(ap, int));
				ft_putstr_fd(str, 1);
			}
		//	else if (type == 'i')
		//	else if (type == 'u')
			else if (arg[i] == 'x')
			{
				str = ft_convert_base(ft_itoa(va_arg(ap, int)), "0123456789", "0123456789abcdef");
				ft_putstr_fd(str,1);
			}
			else if (arg[i] == 'X')
			{
				str = ft_convert_base(ft_itoa(va_arg(ap, int)), "0123456789", "0123456789ABCDEF");
				ft_putstr_fd(str,1);
			}
			else if (arg[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
		ft_putchar_fd(arg[i], 1);
		i++;
	}
	va_end(ap);
	return (0);//출력한 글자 수 
}

int	main(void)
{
	int a = 100;

	ft_printf("aaaa%c\n%s\n%x\n%%\n%X\n%p", 'b', "111111", 1000000,a,&a);
	printf("\naaaa%c\n%s\n%x\n%%\n%X\n%p", 'b', "111111", 1000000,a,&a );
	return (0);
}
