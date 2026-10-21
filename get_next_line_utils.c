/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazzal <mnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:30:03 by mnazzal           #+#    #+#             */
/*   Updated: 2026/10/14 14:07:05 by mnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (!(s[i] == '\0'))
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*newstring;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	while (*s1)
		newstring[i++] = *s1++;
	while (*s2)
		newstring[i++] = *s2++;
	newstring[i] = '\0';
	return (newstring);
}

int	append_buffer(char **saved, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*saved, buffer);
	if (!temp)
	{
		free(*saved);
		*saved = NULL;
		return (0);
	}
	free(*saved);
	*saved = temp;
	return (1);
}
