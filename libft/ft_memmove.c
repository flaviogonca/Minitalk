/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:09:56 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/15 12:03:07 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
/*
int	main(void)
{
	char	s[]="tahjljdlj";
	char	d[20]="tahjljdljfddl";

	ft_memmove(d,s,5);
	printf("**** %s ****\n",d);
	memmove(d,s,5);
	printf("**** %s ****",d);
	return (0);
}*/
