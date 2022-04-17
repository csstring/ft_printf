/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:49:54 by schoe             #+#    #+#             */
/*   Updated: 2022/04/15 21:52:27 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *arg, ...);
int		ft_type(va_list *ap, char type);
int		ft_c(char c);
int		ft_s(char *str);
int		ft_p(void *p);
int		ft_xu(unsigned int ud, char type);
int		ft_di(int i);

char	*ft_uitoa(size_t n);
char	*ft_u_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
