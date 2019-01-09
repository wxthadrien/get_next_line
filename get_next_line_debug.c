/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:56 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 16:00:08 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// La fonction recherche dans le string un \n et revoi sa position dans la string.
int ft_strchr_idx(char *str)
{
    printf("on entre dans le srtchr_idx.....");
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            printf("ok (%d)\n", i);
            return (i);
        }
        i++;
    }
    printf("ok (-1)\n");
    return (-1);
}

/*
fonction endl qui serais appeller quand read revois - que la taille du BUFF_SIZE et qu'il n'y a pas de /n
et qui revairai donc la derniere ligne dans le pointeur de line puis renvoy 1. (if.. return(endl(back, buf, line)); )

int endl(**line, **back)
{
  *line = ft_strdup(*back);
  ft_strdel(back);
  return(0);
}
*/

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
            printf("temp existe, on le copie dans bub et on le free.....");
            buf = ft_strdup(temp);
            ft_strdel(&temp);
            printf("ok\n");
        }
        else
        {
            printf("temp n'existe pas, on lis depuis le fichier.....");
            rd = read(fd, buf, BUFF_SIZE);
            /*
            if (rd = 0)
            {
              endl(line, &back);
              return 1
            }
            */
            buf[rd] = '\0';
            printf("OK (rd = %d)\n", rd);
        }
        if ((idx = ft_strchr_idx(buf)) == -1)
        {
            write(1, "il n'y a pas de /n, on ajoute buf a back.....\n", 45);
            //printf("---back: %s  ---buf: %s\n", back, buf);
            //printf("il n'y a pas de /n, on ajoute buf a back.....");
            back = ft_strjoin(back, ft_strsub(buf, 0, (ft_strlen(buf) - 1)));
            write(1, "OK\n", 3);
            //printf("OK\n");
        }
        else
        {
            printf("Il y a une /n, on copie la partie avant dans back......");
            back = ft_strjoin(back, ft_strsub(buf, 0, idx));
            printf("OK\nEt la partie d'apres dans temp.....");
            temp = ft_strsub(buf, idx + 1, (ft_strlen(buf) - ft_strlen(ft_strsub(buf, 0, idx))));
            printf("OK\n");
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
                printf("=--  %s  --=     returned value: %d\n\n\n", line, ret);
            else
                printf("error code %d", ret);
        }
        //printf("exit return value: %d\n", ret);
        printf("=--  %s  --=     returned value: %d\n\n\n", line, ret);
        close(fd);
        return (0);
    }
    return (-1);
}
