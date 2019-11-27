/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:28:23 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/27 18:09:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	
	if (s1 == 0)
		return (s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	if (!(str = (char*)malloc(len_s1 + len_s2 + 1)))
		return (0);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + ft_strlen(s1), s2, len_s2 + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(src) == size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = '\0';
	}
	if (ft_strlen(src) < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	if (ft_strlen(src) > size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(str, 0, len + 1);
	if (start > ft_strlen(s))
		return (str);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
