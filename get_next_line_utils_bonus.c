/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:57:40 by pllucian          #+#    #+#             */
/*   Updated: 2020/12/18 22:34:59 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(p = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(p, s, len + 1);
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(p = malloc(sizeof(char ) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcpy(p + s1_len, s2, s2_len + 1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dest;
	s = src;
	n = size;
	if (!s)
		return (0);
	if (n)
		while (--n && (*d++ = *s++))
			;
	if (!n && size)
		*d = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	return (*s == (char)c ? (char*)s : NULL);
}
