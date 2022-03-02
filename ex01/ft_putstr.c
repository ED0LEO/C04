/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:03:41 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/06 12:53:23 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

void	ft_putstr(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	ft_strlen(char *str)
{
	int		size1;
	char	c;

	size1 = 0;
	c = str[0];
	while (c != '\0')
	{
		size1++;
		c = str[size1];
	}
	return (size1);
}
