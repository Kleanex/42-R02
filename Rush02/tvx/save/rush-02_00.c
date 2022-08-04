/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosteine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:27:59 by dosteine          #+#    #+#             */
/*   Updated: 2022/07/30 20:33:03 by dosteine         ###   ########.fr       */
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

int	ft_atoi(char *str)
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
#include <stdio.h>

int main (int argc, char **argv)
{
	char *str;

	str="Error\n";
	if (argc == 2)
		if (ft_atoi(argv[1]) == 0)
			ft_putstr(str);
		else 
			printf("%d", ft_atoi(argv[1]));
	else if (argc == 3)	
		printf("%d", ft_atoi(argv[2]));
	else if (argc > 3)
		ft_putstr(str);
}
