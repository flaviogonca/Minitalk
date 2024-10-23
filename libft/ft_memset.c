/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:29:52 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/14 15:04:59 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = (char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[] = "Flavio Escobar";
	ft_memset(str, 42, 3);
	printf("%s",str);

	return (0);
}*/
