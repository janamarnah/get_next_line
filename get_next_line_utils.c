/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamarn <jalamarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:14:09 by jalamarn          #+#    #+#             */
/*   Updated: 2025/09/20 15:12:19 by jalamarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			x;
	unsigned char	*ptr;

	x = size * nmemb;
	if (nmemb == 0 || size == 0)
	{
		ptr = (unsigned char *)malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (x / size != nmemb || x / nmemb != size)
		return (NULL);
	ptr = (unsigned char *)malloc(x);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, x);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*string;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	string = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[a++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		string[a++] = s2[i++];
	}
	string[a] = '\0';
	return (string);
}
