#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void    push_swap(int *array);
void    rotate(int *array);
void    reverse_rotate(int  *array);
void    push(int *stackorig, int *stackdest);
void    swap(int *array);
int     get_median(int *array);
int     array_len(int *array);

#endif