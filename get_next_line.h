#include<stdlib.h>
#include<stdio.h>
#define BUFFER_SIZE 5

typedef struct stack
{
    char *data;
    int capacity;
    int size;
} stack;

char *get_next_line(int fd);
int append(stack *s, char c);
void *ft_memcpy(void *dest, const void *src, int n);