/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:20:50 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/12 12:10:43 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	int		i;
	int		j;
	char	*str;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1 && s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	if (flag == 1)
	{
		free(s1);
		s1 = 0;
	}
	return (str);
}
