Get_Next_Line:

On creer une boucle qui sort lorsque read renvoi EOF, ou que strchr trouve une occurence de \n.
Dans cette boucle, on test premierement si la variable statique contiens quelque chose, si oui on indique que la variable buf vaut cette variable, sinon on read le fichier pour remplir buf. 
Toujours dans le boucle, on passe un strchr_idx pour savoir si la chaine de caractere buf contien un \n et ou il se trouve. Si il n'en contient pas, il l'ajoute a la variable return avec la fonction strjoin. Si il en contiens un, il utilise ft_strsub pour recuperer le dubut de la chaine jusqu'au \n et l'ajoute avec strjoin a return. Ensuite il reutilise ft_strsub placer la partie apres le \n dans temp, quitte la boucle et retourne la chaine.


Variables: 
buf: contiens ce qu'a lu read ou temp si il existe.
temp: variable statique qui contiens la parie du buffer apres le \n.
index: l'emplacement du \n dans buf.


Fonctions:
strchr_idx: recherche et retourne la position du 1er \n dans une string.
