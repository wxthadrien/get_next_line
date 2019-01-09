/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:56 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 11:51:58 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    *line = ft_strdup(back);
    ft_strdel(&back);
    return (0);
}

int     main(int argc, char **argv)
{
    int fd;
    char *line;
    int ret;

    if (argc < 2)
        printf("Erreur d'entrée");
    else
    {
        if ((fd = open(argv[1], O_RDONLY)) < 1)
            return(printf("Open Error"));
        while((ret = get_next_line(fd, &line)) != 0)
        {
            if (ret > 0)
                printf("=--  %s  --=     returned value: %d\n", line, ret);
            else
                printf("error code %d", ret);
        }
        //printf("exit return value: %d\n", ret);
        printf("=--  %s  --=     returned value: %d\n", line, ret);
        close(fd);
        return (0);
    }
    return (-1);
}
