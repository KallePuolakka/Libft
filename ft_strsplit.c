/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuolakk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:13:31 by kpuolakk          #+#    #+#             */
/*   Updated: 2022/02/23 18:20:03 by kpuolakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_wordsize(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_free(char **mem, int i)
{
	if (!mem[i])
	{
		while (i > -1)
		{
			free(mem[i]);
			i--;
		}
		free(mem);
	}
}

static char	**ft_split(char const *s, char c, int i, int j)
{
	char	**mem;
	int		k;

	mem = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!mem)
		return (NULL);
	if (s[0] == '\0')
	{
		mem[0] = 0;
		return (mem);
	}
	while (ft_wordcount(s, c) > ++i)
	{
		k = 0;
		mem[i] = (char *)malloc(sizeof(char) * (ft_wordsize(&s[j], c) + 1));
		ft_free(mem, i);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			mem[i][k++] = s[j++];
		mem[i][k] = '\0';
	}
	mem[i] = 0;
	return (mem);
}

char	**ft_strsplit(char const *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	return (ft_split(s, c, i, j));
}
