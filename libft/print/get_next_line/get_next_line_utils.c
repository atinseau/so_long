/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:54:42 by atinseau          #+#    #+#             */
/*   Updated: 2021/06/24 14:17:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	int		e;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_gnl_strlen(s1)
				+ ft_gnl_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	e = 0;
	i = 0;
	while (s1 && s1[i] != '\0')
		new[e++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new[e++] = s2[i++];
	new[e] = '\0';
	free(s1);
	return (new);
}

int	ft_gnl_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
