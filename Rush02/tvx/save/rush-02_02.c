/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosteine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:27:59 by dosteine          #+#    #+#             */
/*   Updated: 2022/07/31 11:52:10 by dosteine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str [++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "Error\n", 6);
		return ;
	}
/*	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}*/
	if (nb >= 0 && nb < 10)
		ft_putchar ('0' + nb);
	else
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
}
int	ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
//	while ((*str >= 33 && *str <= 47) || (*str >= 58 && *str <= 64)
//			|| (*str >= 91 && *str <= 96) || (*str >= 123 && *str <= 126))
//		return ('E');
			
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
		if (ft_atoi(argv[1]) == 0)
			ft_putstr(str);
		else 
			ft_putnbr(ft_atoi(argv[1]));
	else if (argc == 3)	
		ft_putnbr(ft_atoi(argv[2]));	
	else if (argc > 3)
		ft_putstr(str);
}
