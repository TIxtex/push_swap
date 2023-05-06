/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:54 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:55 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	get_next_line(int fd, char **line)
{
	char	buffer[42 * _1K];
	int		lectura;
	int		i;

	i = ZERO;
	lectura = ZERO;
	if (read(fd, &buffer[ZERO], ZERO) < 0 || NULL == line)
		return (-1);
	while ((lectura = read(fd, &buffer[i], BYTE)) > ZERO && buffer[i] != '\n')
		++i;
	buffer[i] = '\0';
	if (lectura != -1 && (*line = malloc(i + BYTE)) && (i = -1))
	{
		while (buffer[++i])
			(*line)[i] = buffer[i];
		(*line)[i] = '\0';
	}
	return (lectura > 0 ? 1 : lectura);
	
}
