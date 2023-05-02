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
