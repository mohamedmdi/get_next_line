/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchergui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:08:37 by mchergui          #+#    #+#             */
/*   Updated: 2019/10/28 21:08:55 by mchergui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char buff[BUFFER_SIZE + 1];
    int bwr;
    char *ptr;
    int bol;
    static char *rem;
 
    
    bol = 1;
    *line = ft_strdup("");
    if(rem)
        *line = ft_strjoin(*line, rem);
    while (bol && (bwr = read(fd, buff, BUFFER_SIZE)))
    {
        buff[bwr] = '\0';
        if ((ptr = ft_strchr(buff, '\n')))
        {
            rem = ft_strdup(ptr + 1);
            *ptr = '\0'; 
            bol = 0;
        }
        *line = ft_strjoin(*line ,buff);
    }
        return(0);
}

int main()
{
    char *line; 
    int fd;
    int bytes;
    
    bytes = 0;
    fd = open("text.txt", O_RDONLY);
    int ret = 1;
        //while (ret != 0)
        //{
            /*ret =*/ get_next_line(fd, &line);
            printf("%s\n", line);  
        //}
        get_next_line(fd, &line);
        printf("%s", line);
}