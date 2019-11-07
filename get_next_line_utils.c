/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchergui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:09:18 by mchergui          #+#    #+#             */
/*   Updated: 2019/10/31 19:09:20 by mchergui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;

	i = 0;
	ls = ft_strlen((char*)src);
	if (size == 0)
		return (ls);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ls);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*stri;

	stri = (char*)malloc(sizeof(*stri) * (ft_strlen(src) + 1));
	if (!stri)
		return (0);
	ft_strlcpy(stri, src, ft_strlen(src) + 1);
	return (stri);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*txt;
	char	*temp;

	if (!s1 || !s2 ||
	!(txt = (char *)malloc(sizeof(*txt) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	temp = txt;
	while (*s1)
		*txt++ = *s1++;
	while (*s2)
		*txt++ = *s2++;
	*txt = '\0';
	return (temp);
}

char	*ft_strchr(const char *str, int ch)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(str) + 1;
	while (j--)
	{
		if (str[i] == (unsigned char)ch)
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
