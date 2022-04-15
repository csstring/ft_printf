/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:20:28 by schoe             #+#    #+#             */
/*   Updated: 2022/04/15 21:33:34 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check(char *base)
{
	int	k;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' \
				|| base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (-1);
		k = i + 1;
		while (base[k])
		{
			if (base[i] == base[k])
				return (-1);
			k++;
		}
		i++;
	}
	return (i);
}

static int	base_find(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	return (i);
}

static char	*new_base(int minus, int r, char *base_to)
{
	int		i;
	int		size;
	char	*str;

	i = r;
	size = 0;
	while (i > 0 || size == 0)
	{
		i /= check(base_to);
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (str == NULL)
		return (NULL);
	if (minus == -1 && r > 0)
		i = 1;
	str[0] = '-';
	str[size + i] = '\0';
	while (size > 0)
	{
		str[size + i - 1] = base_to[r % check(base_to)];
		r /= check(base_to);
		size--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	minus;
	int	i;
	int	r;

	minus = 1;
	r = 0;
	if (check(base_from) < 0 || check(base_to) < 0)
		return (NULL);
	i = ft_space(nbr);
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			minus *= -1;
		i++;
	}
	while (base_find(nbr[i], base_from) >= 0)
	{
		r = r * check(base_from) + base_find(nbr[i], base_from);
		i++;
	}
	return (new_base(minus, r, base_to));
}
