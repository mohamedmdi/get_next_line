/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchergui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:08:37 by mchergui          #+#    #+#             */
/*   Updated: 2019/11/05 18:50:50 by mchergui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	ft_strdel(char **as)
{
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int		checker(char **remainder, char **line, char* buff)
{
	char		*ptr;
	char		*tmp;

	if (*remainder)
	{
		if ((ptr = ft_strchr(*remainder, '\n')))
		{
			*ptr = '\0';
			ptr++;
			tmp = *line;
			*line = ft_strdup(*remainder);
			//ft_strdel(&tmp);
			*remainder = ft_strdup(ptr);
			ft_strdel(&buff);
			return (1);
		}
		else
		{	
			tmp = *line;
			*line = ft_strdup(*remainder);
			//ft_strdel(&tmp);
			ft_strdel(remainder);
		}
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem;
	char		*buff;
	int			bwr;
	char		*ptr;
	char		*tmp;

	if (BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0 || !line 
	|| !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if(checker(&rem, line, buff))
		return (1);
	while ((bwr = read(fd, buff, BUFFER_SIZE)))
	{
		buff[bwr] = '\0';
		if ((ptr = ft_strchr(buff, '\n')) != NULL)
		{
			*ptr = '\0';
			rem = ft_strdup(ptr + 1);
			*line = ft_strjoin(*line, buff);
			ft_strdel(&buff);
			return(1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return(0);
}
int main()
{
    char *line; 
    int fd;
    
    fd = open("64bit_paragraph.txt", O_RDONLY);
	int g;
	g = 1;
	while (g)
    {
		g = get_next_line(fd, &line);
		printf("%s--%d\n", line, g);
		free(line);
	}
 }
