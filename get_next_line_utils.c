/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:28:23 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/30 13:13:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s != 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
		return (i);
	return (-1);

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
	
	len_s1 = s1 != 0 ? ft_strlen(s1) : 0;
	len_s2 = s2 != 0 ? ft_strlen(s2) : 0;
	if (!(str = (char*)malloc(len_s1 + len_s2 + 1)))
		return (0);
	if (s1 != 0)
		ft_memcpy(str, s1, len_s1 + 1);
	if (s2 != 0)
		ft_memcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
		return (str);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
