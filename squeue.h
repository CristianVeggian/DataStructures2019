#ifndef SQUEUE_H
#define SQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef N
#define N 10
#endif

    typedef struct {
        int sqbegin;
        int sqend;
        int sqtam;
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
        p->sqtam = 0;
    }

    int sqsize(SQUEUE *p) {
        return p->sqtam;
    }

    bool sqempty(SQUEUE *p) {
        return (p->sqtam == 0);
    }

    bool sqfull(SQUEUE *p) {
        return (p->sqtam == N - 1);
    }

    bool sqpush(SQUEUE *p, ITEM obj) {
        if (!sqfull(p)) {
            p->sqend = sqplus(p->sqend);
            p->sqarray[p->sqend] = obj;
            p->sqtam++;
            return true;
        }
        printf("Full Queue!\n");
        return false;
    }
    
    bool sqpop(SQUEUE *p, ITEM *obj){
        if(!sqempty(p)){
            *obj = p->sqarray[p->sqbegin];
            p->sqbegin = sqplus(p->sqbegin);
            p->sqtam--;
            return true;
        }
        printf("Empty Queue");
        return false;
    }

#ifdef __cplusplus
}
#endif

#endif /* SQUEUE_H */

