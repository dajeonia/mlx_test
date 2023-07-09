/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:37:38 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 20:54:46 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	ft_make_number(long nbr, int new, int radix);
static int	ft_ctoi_base(int c, const char *base);
static int	ft_stridx(char const *s, char c);
static long	ft_strtol_base(const char *nptr, const char *base);

int	ft_atoi_base(const char *nptr, const char *base)
{
	return (ft_strtol_base(nptr, base));
}

static long	ft_strtol_base(const char *nptr, const char *base)
{
	int		sign;
	long	nbr;
	int		new;
	int		radix;

	radix = ft_strlen(base);
	if (radix < 2)
		return (-1);
	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nbr = 0;
	while (ft_isin(*nptr, base))
	{
		new = ft_ctoi_base(*nptr, base);
		nbr = ft_make_number(nbr, sign * new, radix);
		nptr++;
	}
	return (nbr);
}

static long	ft_make_number(long nbr, int new, int radix)
{
	long	temp;
	long	check_nbr;
	int		check_new;

	temp = nbr * radix + new;
	check_nbr = temp / radix;
	check_new = temp % radix;
	if (check_nbr == nbr && check_new == new)
		return (temp);
	else if (nbr > 0)
		return (-1);
	else
		return (0);
}

static int	ft_ctoi_base(int c, const char *base)
{
	return (ft_stridx(base, c));
}

static int	ft_stridx(char const *s, char c)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}