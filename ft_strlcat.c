/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuolakk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:25:27 by kpuolakk          #+#    #+#             */
/*   Updated: 2022/02/23 18:14:36 by kpuolakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*temp;
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	result;

	temp = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(temp);
	result = 0;
	i = 0;
	if (size > dst_len)
		result = src_len + dst_len;
	else
		result = src_len + size;
	while (temp[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = temp[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (result);
}
