/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:06:35 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/17 12:53:05 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*element;

	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	element = malloc(nmemb * size);
	if (!element)
		return (NULL);
	ft_bzero(element, (nmemb * size));
	return (element);
}
