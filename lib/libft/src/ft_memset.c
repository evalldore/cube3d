/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:36:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/08/25 23:16:42 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	uint8_t			*mem;

	if (!b)
		return (NULL);
	i = 0;
	mem = b;
	while (i < len)
		mem[i++] = (unsigned char)c;
	return (b);
}
