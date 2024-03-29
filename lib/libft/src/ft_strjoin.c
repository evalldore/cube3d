/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:10:15 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/15 13:24:19 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	buffl;

	if (!s1 || !s2)
		return (NULL);
	buffl = ft_strlen(s1) + ft_strlen(s2) + 1;
	buff = malloc(buffl);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, buffl);
	ft_strlcat(buff, s2, buffl);
	return (buff);
}
