/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:16:59 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/13 15:29:34 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ud;
	unsigned const char	*us;

	if (!dest)
		return (NULL);
	ud = (unsigned char *)dest;
	us = (unsigned const char *)src;
	while (n--)
		*ud++ = *us++;
	return (dest);
}
