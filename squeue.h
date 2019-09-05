#ifndef SQUEUE_H
#define SQUEUE_H

#include "dstack.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef N
#define N 10
#endif

    typedef struct {
        int sqbegin;
        int sqend;
        int sqsize;
        ITEM sqarray[N];
    } SQUEUE;

    int sqplus(int X) {
        X++;
        if (X == N)
            X = 0;
        return X;
    }

    void sqinit(SQUEUE *p) {
        p->sqbegin = 0;
        p->sqend = -1;
        p->sqsize = 0;
    }

    int sqsize(SQUEUE *p) {
        return p->sqsize;
    }

    bool sqempty(SQUEUE *p) {
        return (p->sqsize == 0);
    }

    bool sqfull(SQUEUE *p) {
        return (p->sqsize == N);
    }

    bool sqpush(SQUEUE *p, ITEM obj) {
        if (!sqfull(p)) {
            p->sqend = sqplus(p->sqend);
            p->sqarray[p->sqend] = obj;
            (p->sqsize)++;
            return true;
        }
        printf("Full Queue!\n");
        return false;
    }

    bool sqpop(SQUEUE *p, ITEM *obj) {
        if (!sqempty(p)) {
            *obj = p->sqarray[p->sqbegin];
            p->sqbegin = sqplus(p->sqbegin);
            p->sqsize--;
            return true;
        }
        printf("Empty Queue\n");
        return false;
    }

    void sqprintall(SQUEUE *p) {
        if (p->sqsize == 0) {
            printf("|\n");
            return;
        }
        SQUEUE q = *p;
        ITEM imaginary;
        printf("| %i ", q.sqarray[q.sqbegin].key);
        sqpop(&q, &imaginary);
        sqprintall(&q);
    }

    void sqprintend(SQUEUE *p) {
        if (p->sqsize == 0)
            printf("Empty Queue\n");
        else {
            printf("END -> | %i |\n", p->sqarray[p->sqend].key);
        }
    }

    void sqprintbegin(SQUEUE *p) {
        if (p->sqsize == 0)
            printf("Empty Queue\n");
        else {
            printf("BEGIN -> | %i |\n", p->sqarray[p->sqbegin].key);
        }
    }

#ifdef __cplusplus
}
#endif

#endif /* SQUEUE_H */

