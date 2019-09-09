#ifndef DSTACK_H
#define DSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STDABSDATA_H
#include "stdabsdata.h"
#endif

    typedef struct DSNODE* DSPTR;

    typedef struct DSNODE {
        ITEM dsitem;
        DSPTR dsnext;
    } DSNODE;

    typedef struct {
        DSPTR dstop;
        int dssize;
    } DSTACK;

    void dsinit(DSTACK *p) {
        p->dssize = 0;
        p->dstop = NULL;
    }

    bool dsempty(DSTACK *p) {
        return (p->dssize == 0);
    }

    int dssize(DSTACK *p) {
        return p->dssize;
    }

    bool dspush(DSTACK *p, ITEM obj) {
        DSPTR aux = NULL;
        aux = (DSPTR) malloc(sizeof (DSNODE));
        aux->dsitem = obj;
        aux->dsnext = p->dstop;
        p->dstop = aux;
        p->dssize++;
        if (aux == NULL)
            return false;
        return true;
    }

    void dspop(DSTACK *p, ITEM *obj) {
        if (!dsempty(p)) {
            *obj = p->dstop->dsitem;
            p->dstop = p->dstop->dsnext;
            p->dssize--;
        } else
            printf("Empty Stack!\n");
    }

    void dsprinttop(DSTACK *p) {
        if (dsempty(p))
            printf("Empty Stack!\n");
        else {
            printf("Top -> [%i]\n", p->dstop->dsitem.key);
        }
    }

    void dsprintall(DSTACK *p) {
        if (p->dstop == NULL) {
            printf("===\nStackEnd\n");
            return;
        } else {
            DSTACK q;
            ITEM imaginary;
            q = *p;
            printf("===\n");
            printf("|%i|\n", q.dstop->dsitem.key);
            dspop(&q, &imaginary);
            dsprintall(&q);
        }
    }

    void dsdestroy(DSTACK *p) {
        if (p != NULL)
            return;
        else {
            DSPTR aux;
            p->dstop = p->dstop->dsnext;
            free(aux);
            dsdestroy(p);
        }
    }


#ifdef __cplusplus
}
#endif

#endif /* DSTACK_H */

