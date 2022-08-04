/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosteine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:27:59 by dosteine          #+#    #+#             */
/*   Updated: 2022/07/31 14:55:50 by dosteine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str [i] != '\0')
		i++;
	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	if (j == i)
		return (1);
	else
		return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str [++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(unsigned int nb)
{
	if (nb > 4294967294)
	{
		write (1, "Error\n", 6);
		return ;
	}
	
	if (nb == 0  || (nb > 0 && nb < 10))
		ft_putchar ('0' + nb);
	else
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
}
int	ft_atoi (char *str)
{
	unsigned int	res;
	unsigned int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
			while (*str >= '0' && *str <= '9')
			{
				res = res * 10 + *str - '0';
				str++;
			}
				return (res * sign);
		}

		int main (int argc, char **argv)
		{
			char *str;

			str="Error\n";
			if (argc == 2)
				if (ft_atoi(argv[1]) >= 0 && ft_str_is_numeric(argv[1]))
					ft_putnbr(ft_atoi(argv[1]));
										
				else if (ft_str_is_numeric(argv[1]))
					ft_putnbr(ft_atoi(argv[2]));	
				else
					ft_putstr(str);
		
			else if (argc == 3)	
				if (ft_str_is_numeric(argv[2]))
					ft_putnbr(ft_atoi(argv[2]));	
				else
					ft_putstr(str);
		
				else if (argc > 3)
					ft_putstr(str);
}
