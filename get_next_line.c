/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:56 by hmeys             #+#    #+#             */
/*   Updated: 2018/11/14 13:53:28 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"


// La fonction recherche dans le string un \n et revoi sa position dans la string.
int ft_strchr_idx(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

int get_next_line(const int fd, char **line)
{
    int rd; //Code renvoyer par la fonction read
    char *buf; //Variable ou se trouve la string lue par read ou ce que contenais temp.
    static char *temp; //variable qui stoque la partie apres le \n d'une sting lue par read.
    char *back; //Ligne a renvoyer.
    int idx; //Index du \n dans le string.
    
    rd = 1;
    idx = 0;
    if (!(back = ft_strnew(0)) || !(buf = ft_strnew(BUFF_SIZE + 1)) || !(*line = ft_strnew(0)))
        return(-1);
    while (rd > 0 || temp)
    {
        if (temp)
        {
            buf = ft_strdup(temp);
            ft_strdel(&temp);
        }
        else
        {
            rd = read(fd, buf, BUFF_SIZE);
            buf[rd] = '\0';
        }
        if ((idx = ft_strchr_idx(buf)) == -1)
            back = ft_strjoin(back, buf);
        else
        {
            back = ft_strjoin(back, ft_strsub(buf, 0, idx));
            temp = ft_strsub(buf, idx + 1, (ft_strlen(buf) - ft_strlen(ft_strsub(buf, 0, idx))));
            *line = ft_strdup(back);
            ft_strdel(&back);
            return (1);
        }
    }
    return (0);
}


int    main(int ac, char **av)
{
    int            fd;
    char        *line;
    int            ret;
    
    line = NULL;
    if (ac < 2)
    {
        ft_putendl("no entry");
        return (0);
    }

    fd = open(av[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        printf("LINE = %s\n", line);
        ft_strdel(&line);
    }
    close(fd);
    printf("%d", ret);
    return(0);
}
