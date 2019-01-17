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
                printf("%s\n", line);
            else
                printf("error code %d", ret);
        }
        close(fd);
        return (0);
    }
    return (-1);
}
