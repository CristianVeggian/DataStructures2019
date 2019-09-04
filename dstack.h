#ifndef DSTACK_H
#define DSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

    typedef struct {
        int key;
    } ITEM;

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
        }
    }



#ifdef __cplusplus
}
#endif

#endif /* DSTACK_H */

