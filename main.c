# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

void*   routine()
{
    printf("Hello from thread\n");
    sleep(3);
    printf("Bye from thread\n");
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t   t1;
    pthread_t   t2;

    argc = 0;
    argv = NULL;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}