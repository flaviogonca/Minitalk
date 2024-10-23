/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:22:09 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/16 17:05:54 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src && !n)
		return (0);
	if (find[0] == '\0' || find == src)
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == find[j] && (i + j) < n)
		{
			if (src[i + j] == '\0' && find[j] == '\0')
				return ((char *)&src[i]);
			j++;
		}
		if (find[j] == '\0')
			return ((char *)(src + i));
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	b[]="this is the big string";
	char	l[]=" is";
	char *p;

	p = ft_strnstr(b, l, 10);
	printf("%s",p);
	return (0);
}*/
