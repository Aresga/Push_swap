/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:44:06 by agaga             #+#    #+#             */
/*   Updated: 2025/01/09 16:06:18 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*joined;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	joined = (char *)malloc(len1 + len2 + 1);
// 	if (!joined)
// 		return (NULL);
// 	i = 0;
// 	while (i < len1)
// 	{
// 		joined[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (j < len2)
// 		joined[i++] = s2[j++];
// 	joined[i] = '\0';
// 	return (joined);
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (!s || start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	sub = (char *)malloc(len + 1);
// 	if (!sub)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && s[start + i])
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }
