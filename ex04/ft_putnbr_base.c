/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:24:35 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/07 16:10:14 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			dec_to_bin(int num);
void			print_rev(int *res, int len, char *example);
int				convert_any(int *res, unsigned int num, int base);
int				ft_strlen(char *str);
unsigned int	ft_abs(int a);

void	ft_putnbr_base(int nbr, char *base)
{
	int				res[45];
	int				len;
	unsigned int	int_base;
	unsigned int	nbr_pos;

	int_base = ft_strlen(base);
	if (int_base < 2)
		return ;
	nbr_pos = ft_abs(nbr);
	len = convert_any(res, nbr_pos, int_base);
	if (nbr < 0)
		write(1, "-", 1);
	print_rev(res, len, base);
	if (nbr == 0)
		write(1, &base[0], 1);
	return ;
}

unsigned int	ft_abs(int a)
{
	return (a * ((a > 0) - (a < 0)));
}

int	ft_strlen(char *str)
{
	int		size1;
	char	c;
	int		j;

	j = 0;
	size1 = 0;
	c = str[0];
	while (c != '\0')
	{
		if (c == 43 || c == 45)
			return (0);
		j = size1 + 1;
		while (str[j])
		{
			if (str[j++] == c)
				return (0);
		}
		size1++;
		c = str[size1];
	}
	return (size1);
}

int	convert_any(int *res, unsigned int num, int base)
{
	int	rem;
	int	i;

	i = 0;
	rem = 0;
	while (num)
	{
		rem = num % base;
		num = num / base;
		res[i++] = rem;
	}
	return (i);
}

void	print_rev(int *res, int len, char *example)
{
	int	i;

	i = len - 1;
	while (i != -1)
	{
		write (1, &example[res[i]], 1);
		i--;
	}
	return ;
}
