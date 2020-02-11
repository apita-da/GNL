/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:24:13 by apita-da          #+#    #+#             */
/*   Updated: 2020/02/11 17:45:11 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	cont;

	cont = 0;
	while (str[cont] != c)
	{
		if (str[cont] == '\0')
			return (NULL);
		cont++;
	}
	return ((char *)&str[cont]);
}

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		cont;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *))))
		return (NULL);
	cont = 0;
	while (*s1)
	{
		s3[cont] = *s1;
		s1++;
		cont++;
	}
	while (*s2)
	{
		s3[cont] = *s2;
		s2++;
		cont++;
	}
	s3[cont] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		cont;
	int		len;

	len = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * len + 1)))
		return (NULL);
	cont = 0;
	while (s1[cont] != '\0')
	{
		s2[cont] = s1[cont];
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
