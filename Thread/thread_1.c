#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

// pthread_t ntid;

// void
// printids(const char *s)
// {
//     pid_t
//     pid;
//     pthread_t tid;
//     pid = getpid();
//     tid = pthread_self();
//     printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
//     (unsigned int)tid, (unsigned int)tid);
// }
// void *
// thr_fn(void *arg)
// {
//     printids("new thread: ");
//     return((void *)0);
// }


// void
// printids(const char *s)
// {
//     pid_t
//     pid;
//     pthread_t tid;
//     pid = getpid();
//     tid = pthread_self();
//     printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
//     (unsigned int)tid, (unsigned int)tid);
// }

void *
    thr_fn1(void *arg)
    {
    printf("thread 1 returning\n");
    return((void *)1);
}

void *
    thr_fn2(void *arg)
    {
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
}
int
main(void)
{
    pthread_t ntid;
    pthread_t tid1, tid2;
    pid_t pid;

    int err;
    void *tret;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf(("can't create thread 1: %s\n", strerror(err)));
        exit(0);
    }
    if (err != 0) {
        printf(("can't create thread 2: %s\n", strerror(err)));
        exit(1);
    }
    err = pthread_join(tid1, &tret);
    if (err != 0) {
        printf(("can't join with thread 1: %s\n", strerror(err)));
        exit(1);
    }
    printf("thread 1 exit code 0x%lx\n", (unsigned long)tret);
    err = pthread_join(tid2, &tret);
    if (err != 0) {
        printf(("can't join with thread 2: %s\n", strerror(err)));
        exit(1);
    }
    printf("thread 2 exit code 0x%lx\n", (unsigned long)tret);
    exit(0);
}
