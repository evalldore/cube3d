/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:45:32 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/18 18:50:45 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(uint64_t num, bool isUpper, int fd)
{
	char			ch;
	int				i;

	i = 1;
	ch = (num & 0x0F) + '0';
	if (ch > '9')
	{
		if (isUpper)
			ch += 7;
		else
			ch += 39;
	}
	if (num > 15)
		i += ft_puthex_fd((num >> 4), isUpper, fd);
	write(fd, &ch, 1);
	return (i);
}
