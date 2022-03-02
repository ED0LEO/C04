/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:21:26 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/07 14:35:34 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_char_is_numeric(char str);
unsigned int	return_mult(char *arr, int start);
int				does_follow_rule(char *arr, int *signs);

int	ft_atoi(char *str)
{
	int				i;
	unsigned int	j;
	unsigned int	arr;
	int				sign_counter;
	int				res;

	res = 0;
	sign_counter = 0;
	i = 0;
	j = 1;
	arr = 0;
	i = does_follow_rule(str, &sign_counter);
	if (i < 0)
		return (0);
	j = return_mult(str, i);
	while (ft_char_is_numeric(str[i]))
	{
		arr += (str[i] - 48) * j;
		j /= 10;
		i++;
	}
	res = arr;
	if (sign_counter % 2 != 0)
		res = arr * -1;
	return (res);
}

int	does_follow_rule(char *arr, int *signs)
{
	int	rule;
	int	i;

	i = 0;
	rule = 1;
	while ((arr[i] >= 9 && arr[i] <= 13)
		|| arr[i] == 32)
		i++;
	if (!ft_char_is_numeric(arr[i])
		&& !(arr[i] == 45 || arr[i] == 43))
		return (-1);
	while ((arr[i]) == 45 || arr[i] == 43)
	{
		if (arr[i] == 45)
			(*signs)++;
		i++;
	}
	if (!ft_char_is_numeric(arr[i]))
		return (-1);
	return (i);
}

unsigned int	return_mult(char *arr, int start)
{
	int				count;
	unsigned int	mult;

	mult = 1;
	count = 1;
	while (ft_char_is_numeric(arr[start + count]))
	{
		mult *= 10;
		count++;
	}
	return (mult);
}

int	ft_char_is_numeric(char str)
{
	if (str < 48 || str > 57)
	{
		return (0);
	}
	return (1);
}
