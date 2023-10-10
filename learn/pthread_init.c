# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

int x = 0;
pthread_mutex_t mutex;

// void*   routine()
// {
//     int i;

//     i = 0;
//     while (i < 1000000)
//     {
//         pthread_mutex_lock(&mutex);
//         x++;
//         i++;
//         pthread_mutex_unlock(&mutex);
//     }
// }

// This function create a thread in a loop

// int main()
// {
//     pthread_t   t[4];
//     int i = 0;
//     pthread_mutex_init(&mutex, NULL);

//     while (i < 4)
//     {
//         if (pthread_create(&t[i], NULL, &routine, NULL))
//             return (printf("ERROR CREATE PTHREAD"));
//         printf("Pthread %d init\n", i);
//         i++;
//     }
//     i = 0;
//     while (i < 4)
//     {
//         if (pthread_join(t[i], NULL))
//             return (1);
//         printf("Pthread %d close\n", i);
//         i++;
//     }
//     pthread_mutex_destroy(&mutex);
//     printf("Number of x: %d\n", x);
//     return (0);
// }

// This function create a differente trades

// int main(int argc, char **argv)
// {
//     pthread_t   t1;
//     pthread_t   t2;
//     pthread_t   t3;
//     pthread_t   t4;
//     pthread_mutex_init(&mutex, NULL);

//     argc = 0;
//     argv = NULL;
//     pthread_create(&t1, NULL, &routine, NULL);
//     pthread_create(&t2, NULL, &routine, NULL);
//     pthread_create(&t3, NULL, &routine, NULL);
//     pthread_create(&t4, NULL, &routine, NULL);
//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     pthread_join(t3, NULL);
//     pthread_join(t4, NULL);
//     pthread_mutex_destroy(&mutex);
//     printf("Number of x: %d\n", x);
//     return (0);
// }