/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:02 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/15 16:46:23 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (i == -1)
			return (NULL);
		i--;
	}
	return (NULL);
}
/*
int     main()
{
        char str[]="";

        printf("#_%s_#\n",ft_strrchr(str, 'e'));
        printf("#_%s_#",str);
        return (0);
}
*/
