/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:54:28 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/07 12:41:34 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int		ft_abs(int a);
void				print_rev(char *arr, int size);
int					check_neg(int n);

void	ft_putnbr(int nb)
{
	int					i;
	unsigned int		nb_c;
	char				orig_arr_rev[11];

	nb_c = ft_abs(nb);
	i = 1;
	orig_arr_rev[0] = '\0';
	while (nb_c)
	{
		orig_arr_rev[i] = nb_c % 10 + '0';
		nb_c = nb_c / 10;
		i++;
	}
	i--;
	if (check_neg(nb))
		write(1, "-", 1);
	print_rev(orig_arr_rev, i);
	if (nb == 0)
		write(1, "0", 1);
	return ;
}

int	check_neg(int n)
{
	return (n < 0);
}

void	print_rev(char *arr, int size)
{
	int	i;

	i = size;
	while (arr[i] != '\0')
	{
		write(1, &arr[i], 1);
		i--;
	}
}

unsigned int	ft_abs(int a)
{
	return (a * ((a > 0) - (a < 0)));
}
