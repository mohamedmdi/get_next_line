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

char *checker(char *remainder, char **line)
{
    char *ptr;
    ptr = NULL;
    size_t l;

    if (remainder)
        if ((ptr = ft_strchr(remainder, '\n')))        
        {
            *ptr = '\0';
            *line = ft_strdup(remainder);
            ptr++;
            l = strlen(ptr);
            ft_strlcpy(remainder, ptr, l + 1);
        }
        else
        {
            *line = ft_strdup(remainder);
            free(remainder);
            remainder = NULL;
        }
    else
        *line = ft_strdup("");
    return (ptr);
}

int get_next_line(int fd, char **line)
{
    static char *rem;
    char        *buff;
    int         bwr;
    char        *ptr;
    
 

    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    ptr = checker(rem, line);
    while (!ptr && (bwr = read(fd, buff, BUFFER_SIZE)))
    {
        buff[bwr] = '\0';
        if ((ptr = ft_strchr(buff, '\n')))  
        {
            *ptr = '\0';
            rem = ft_strdup(ptr + 1);
        }
        *line = ft_strjoin(*line ,buff);
    }
        free(buff);
        buff = NULL;
        if (bwr || ft_strlen(rem))
            return(1);
        else
            return(0);
        //return(bwr || ft_strlen(rem)) ? 1 : 0;
}

int main()
{
    char *line; 
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    int ret = 0;
        while (get_next_line(fd, &line))
            printf("%s\n", line);
            ret++;
}