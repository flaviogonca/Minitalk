/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:39:15 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/17 19:32:26 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*restr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = (size_t)ft_strlen(s1);
	j = (size_t)ft_strlen(s2);
	restr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!restr)
		return (NULL);
	i = -1;
	while (s1[++i])
		restr[i] = s1[i];
	j = 0;
	while (s2[j])
		restr[i++] = s2[j++];
	restr[i] = '\0';
	return (restr);
}
/*
int	main()
{
	char s1[]="first mom";
	char s2[]="";
	char *r;

	r = ft_strjoin(s1,s2);
	printf("=%s",r);
	return (0);
}*/
