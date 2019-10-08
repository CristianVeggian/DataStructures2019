#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

    typedef struct {
        int key;
    } ITEM;

    typedef struct NOLISTA* PTRNOLISTA;

    typedef struct NOLISTA {
        ITEM obj;
        PTRNOLISTA foward;
        PTRNOLISTA back;
    } NOLISTA;

    typedef struct {
        PTRNOLISTA start;
        PTRNOLISTA end;
        int size;
    } DLISTA;

    void dlistinit(DLISTA *p) {
        p->start = NULL;
        p->end = NULL;
        p->size = 0;
    }

    bool dlistempty(DLISTA *p) {
        return (p->start == NULL);
    }

    bool dlsearch(DLISTA *p, ITEM obj) {
        if (dlistempty(p) || (obj.key < p->start->obj.key))
            return false;
        PTRNOLISTA aux = p->start;
        do {
            if (aux->obj.key == obj.key)
                return true;
            aux = aux->foward;
        } while (aux != NULL);
        return false;
    }

    bool dlistinsert(DLISTA *p, ITEM obj) {
        if (dlsearch(p, obj))
            return false;
        PTRNOLISTA novo = (PTRNOLISTA) malloc(sizeof (NOLISTA));
        novo->obj.key = obj.key;
        if (dlistempty(p)) {
            novo->foward = NULL;
            novo->back = NULL;
            p->start = novo;
            p->end = novo;

        } else if (novo->obj.key < p->start->obj.key) {
            p->start->back = novo;
            novo->foward = p->start;
            novo->back = NULL;
            p->start = novo;
        } else if (novo->obj.key > p->end->obj.key) {
            p->end->foward = novo;
            novo->back = p->end;
            novo->foward = NULL;
            p->end = novo;
        } else {
            PTRNOLISTA aux = p->start;
            while ((aux->foward != NULL) && (novo->obj.key > aux->obj.key))
                aux = aux->foward;
            novo->foward = aux;
            novo->back = aux->back;
            aux->back->foward = novo;
            aux->back = novo;
        }
        p->size++;
        return true;
    }

    void dlPrintUp(DLISTA *p) {
        PTRNOLISTA aux = p->start;
        while (aux != NULL) {
            printf("| %i |", aux->obj.key);
            aux = aux->foward;
        }
        printf("\n");
    }

    void dlPrintFileUp(FILE *arq, DLISTA *p) {
        PTRNOLISTA aux = p->start;
        fprintf(arq, "Tamanho = %i\n", p->size);
        fprintf(arq, "Lista = {");
        while (aux != NULL) {
            if (aux->foward != NULL)
                fprintf(arq, "%i,", aux->obj.key);
            else
                fprintf(arq, "%i}", aux->obj.key);
            aux = aux->foward;
        }
        fprintf(arq, "\n");
    }

    void dlPrintDown(DLISTA *p) {
        PTRNOLISTA aux = p->end;
        while (aux != NULL) {
            printf("| %i |", aux->obj.key);
            aux = aux->back;
        }
        printf("\n");
    }

    void dlPrintFileDown(FILE *arq, DLISTA *p) {
        PTRNOLISTA aux = p->end;
        fprintf(arq, "Tamanho = %i\n", p->size);
        fprintf(arq, "Lista = {");
        while (aux != NULL) {
             if (aux->back != NULL)
                fprintf(arq, "%i,", aux->obj.key);
            else
                fprintf(arq, "%i}", aux->obj.key);
            aux = aux->back;
        }
        fprintf(arq, "\n");
    }

    bool dlremove(DLISTA *p, ITEM *x, int key) {
        if (dlistempty(p))
            return false;
        if (key < p->start->obj.key)
            return false;
        if (key > p->end->obj.key)
            return false;
        PTRNOLISTA aux = p->start;
        if (key == p->start->obj.key) {
            *x = p->start->obj;
            p->start = p->start->foward;
            p->start->back = NULL;
            free(aux);
        } else if (key == p->end->obj.key) {
            aux = p->end;
            *x = p->end->obj;
            p->end = p->end->back;
            p->end->foward = NULL;
            free(aux);
        } else {

            while ((aux->foward != NULL) && (aux->foward->obj.key < key))
                aux = aux->foward;
            if ((aux->foward != NULL) && (aux->foward->obj.key == key)) {
                PTRNOLISTA removedor = aux->foward;
                aux->foward = aux->foward->foward;
                aux->foward->back = aux;
                *x = removedor->obj;
                free(removedor);
            }
        }
        p->size--;
        return true;
    }

    void dldestroy(DLISTA *p) {
        do {
            PTRNOLISTA killer = (PTRNOLISTA) malloc(sizeof (NOLISTA));
            killer = p->start;
            p->start = p->start->foward;
            p->size--;
            free(killer);
        } while (!dlistempty(p));
    }

#ifdef __cplusplus
}
#endif

#endif /* LISTADUPLA_H */

