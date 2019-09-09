#ifndef DQUEUE_H
#define DQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STDABSDATA_H
#include "stdabsdata.h"
#endif

    typedef struct DQNODE *DQPTR;

    typedef struct DQNODE {
        ITEM dqitem;
        DQPTR dqnext;
    } DQNODE;

    typedef struct {
        DQPTR dqbegin;
        DQPTR dqend;
        int dqsize;
    } DQUEUE;

    void dqinit(DQUEUE *p) {
        p->dqsize = 0;
        p->dqend = NULL;
        p->dqbegin = NULL;
    }

    bool dqempty(DQUEUE *p) {
        return (p->dqsize == 0);
    }

    int dqsize(DQUEUE *p) {
        return (p->dqsize);
    }

    bool dqpush(DQUEUE *p, ITEM obj) {
        DQPTR aux = (DQPTR) malloc(sizeof (DQNODE));
        aux->dqitem = obj;
        aux->dqnext = NULL;

        if (p->dqbegin == NULL)
            p->dqbegin = aux;
        else
            p->dqend->dqnext = aux;
        p->dqend = aux;
        p->dqsize++;
        return true;
    }

    bool dqpop(DQUEUE *p, ITEM *obj) {
        if (dqempty(p)) {
            printf("Empty Queue!");
            return false;
        }
        *obj = p->dqbegin->dqitem;
        DQPTR aux = p->dqbegin;
        p->dqbegin = p->dqbegin->dqnext;
        //free(aux);
        if (p->dqbegin == NULL)
            p->dqend = NULL;
        p->dqsize--;
        return true;
    }

    void dqprintall(DQUEUE *p) {
        if (dqempty(p)) {
            printf("||\n");
            return;
        } else {
            DQUEUE q = *p;
            ITEM imaginary;
            dqpop(&q, &imaginary);
            printf("|| %i  ", imaginary.key);
            dqprintall(&q);
        }
    }

    void dqprintend(DQUEUE *p) {
        if (p->dqsize == 0)
            printf("Empty Queue\n");
        else {
            printf("END -> | %i |\n", p->dqend->dqitem.key);
        }
    }

    void dqprintbegin(DQUEUE *p) {
        if (p->dqsize == 0)
            printf("Empty Queue\n");
        else {
            printf("BEGIN -> | %i |\n", p->dqbegin->dqitem.key);
        }
    }

    ITEM inicioFila(DQUEUE *fila);
    ITEM fimFila(DQUEUE *fila);

#ifdef __cplusplus
}
#endif

#endif /* DQUEUE_H */

