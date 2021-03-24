/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 23:10:51 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/29 21:30:31 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_int(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		count_unsigned(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		ft_count_hexa(unsigned int nbr)
{
	int i;

	i = 0;
	while ((nbr / 16) > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	if ((nbr / 16) == 0)
		i++;
	return (i);
}

int		ft_count_add(unsigned long long nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (2);
	while ((nbr / 16) > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	if ((nbr / 16) == 0)
		i++;
	return (i + 2);
}
