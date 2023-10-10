# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>

void    *roll_dice()
{
    int value;
    int *res;

    value = (rand() % 6) + 1;
    res = malloc(sizeof(int));
    *res = value;
    return (void *) res;
}

int main()
{
    pthread_t   pth;
    int *res;
    srand(time(NULL));

    if (pthread_create(&pth, NULL, &roll_dice, NULL))
        return (printf("ERROR CREATE PTHREAD"));
    if (pthread_join(pth, (void **) &res))
        return (1);
    printf("Result: %d\n", *res);
    free(res);
    return (0);
}