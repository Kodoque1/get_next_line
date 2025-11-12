#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include "get_next_line.h"

/*TODO
- DONE Regler le cas de la derniere ligne 
- DONE Eliminer les sorties superflues sur STDIN
- LOCK Expliquer pourquoi l'enchainement de la lecture de fichier et du stdin fail
- Formaliser le raisonnement
- DONE Factoriser le code 
- DONE Gestion des erreurs
- DONE Check Valgrind
- Handle test multiple BUFFER SIZE
*/

int acquire_data(char* buffer, stack s, int *red, int fd, char** res)
{
    
    if(!(*red = read(fd, buffer, BUFFER_SIZE)))
    {
        if (s.size)
        {
            *res = (char *) malloc (sizeof(char) * (s.size + 1));
            if(*res == NULL)
                return (-1);
            ft_memcpy(*res, s.data, s.size);
            (*res)[s.size] = '\0';
        }
    } 
    return (0);
}

int extract_new_line(int *i, stack *s, char *buffer, int red, char** res)
{
    while(*i < red && !(*res))
    {
        append(s, buffer[*i]);
        if (buffer[*i] == '\n')
        {
            *res = (char *) malloc (sizeof(char) * (s->size + 1));
            if (*res == NULL)
                return (-1);
            ft_memcpy(*res, s->data, s->size);
            (*res)[s->size] = '\0';
        }
        (*i)++;
    }
    return (0);
}

char *get_next_line(int fd)
{
    char *res;
    static int i = 1;
    static int red = 0;
    static char buffer[BUFFER_SIZE];
    stack s;

    s.capacity = 1;
    s.size = 0;
    s.data = (char *) malloc(sizeof(char));
    res = NULL;
    while(1)
    {
        if(i >= red)
        {
            i = 0;
            if((acquire_data(buffer, s, &red, fd, &res) == -1) || res || !red)
                break;
        }    
        if((extract_new_line(&i, &s, buffer, red, &res) == -1) || res)
            break;
    }
    free(s.data);
    return (res);
}