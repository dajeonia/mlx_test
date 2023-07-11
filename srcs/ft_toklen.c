/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toklen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:21:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 11:23:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_toklen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set) == 0)
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

int	ft_duplen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set))
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

int	ft_nextlen(const char *s, const char *set)
{
	int	len;

	len = ft_duplen(s, set);
	len += ft_toklen(s + len, set);
	return (len);
}

int	ft_nextptr(const char *s, const char *set)
{
	int	len;

	len = ft_toklen(s, set);
	len += ft_duplen(s + len, set);
	return (len);
}
