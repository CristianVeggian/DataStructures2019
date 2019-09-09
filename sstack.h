#ifndef SSTACK_H
#define SSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STDABSDATA_H
#include "stdabsdata.h"
#endif



    typedef struct {
        ITEM ssarray[N];
        int sstop;
    } SSTACK;

    void ssinit(SSTACK *p) {
        p->sstop = 0;
    }

    bool ssempty(SSTACK *p) {
        return (p->sstop == 0);
    }

    bool ssfull(SSTACK *p) {
        return (p->sstop == N - 1);
    }

    int sstsize(SSTACK *p) {
        return p->sstop;
    }

    bool sspush(SSTACK *p, ITEM obj) {
        if (!ssfull(p)) {
            p->ssarray[p->sstop] = obj;
            p->sstop++;
            return true;
        }
        return false;
    }

    bool sspop(SSTACK *p, ITEM *obj) {
        if (!ssempty(p)) {
            *obj = p->ssarray[p->sstop];
            p->sstop--;
            return true;
        }
        return false;
    }

    void ssprinttop(SSTACK *p) {
        printf("TOP -> [%i]\n", p->ssarray[p->sstop - 1].key);
    }

    void ssprintall(SSTACK *p) {
        printf("/\\\n");
        for (int i = (p->sstop - 1); i >= 0; i--)
            printf("%i\n", p->ssarray[i].key);
        printf("\\/\n");
    }

#ifdef __cplusplus
}
#endif

#endif /* SSTACK_H */

