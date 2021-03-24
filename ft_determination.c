/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:02:26 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/31 17:34:29 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_etoile(char *str, t_list *data)
{
	char c;

	c = data->cvrs;
	data->cvrs = *str;
	ft_check(data);
	data->cvrs = c;
	if ((data->signe == -1 && data->i < 0) || (data->signe == 1 && data->i < 0))
		return (data->i);
	else
		return (data->signe * data->i);
}

int	ft_exp_precision(char *str, t_list *data)
{
	char	*copy;
	int		i;

	data->signe = 1;
	i = 0;
	copy = str;
	copy++;
	if (!(ft_strchr(".*-0123456789", *copy)))
		return (0);
	while (!(ft_strchr(".*0123456789", copy[i])))
		i++;
	if (copy[i] == '*')
		return (ft_etoile(copy, data));
	return (ft_atoi(copy));
}

int	ft_exp_width(char *str, t_list *data)
{
	int i;
	int j;

	i = 0;
	data->signe = 1;
	while (((str[i] == '0' && (str[i + 1] == '0' || str[i + 1] == '-')) ||
	(str[i] == '-' && (str[i + 1] == '0' || str[i + 1] == '-'))) && str[i])
	{
		if (str[i] == '-')
			data->signe = -1;
		i++;
	}
	j = i;
	while (!(ft_strchr(".*123456789", str[j])) && str[j])
	{
		if (str[j] == '-')
			data->signe = -1;
		j++;
	}
	if (str[j] == '*')
		return (ft_etoile(&str[j], data));
	else if (str[i] == '0' && data->signe == -1)
		return (data->signe * ft_atoi(&str[i]));
	else
		return (ft_atoi(&str[i]));
}

int	ft_deter_prc(int index, char *str, t_list *data)
{
	data->w = ft_exp_width(&str[data->j], data);
	data->p = ft_exp_precision(&str[index], data);
	if (data->p < 0 && str[++index] == '*')
		return (1);
	return (2);
}

int	ft_determination(char *str, t_list *data)
{
	int i;
	int k;

	i = data->j;
	k = data->j;
	while (ft_strchr(".*-0123456789", str[k]) && str[k])
	{
		if (str[k] == '.')
			return (ft_deter_prc(k, str, data));
		k++;
	}
	while (ft_strchr(".*-0123456789", str[i]) && str[i])
	{
		if (str[i] == '-' || ft_isdigit(str[i]) || str[i] == '*')
		{
			data->w = ft_exp_width(&str[i], data);
			return (1);
		}
		i++;
	}
	return (0);
}
