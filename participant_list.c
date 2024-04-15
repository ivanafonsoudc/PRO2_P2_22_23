/*
 TITLE: PROGRAMMING II LABS                     SUBTITLE: P2
 AUTHOR 1: IVÁN AFONSO CERDEIRA                 LOGIN 1:IVAN.AFONSO
 AUTHOR 2: PABLO PÉREZ NOCEDA                   LOGIN 2:PABLO.PEREZ5
 GROUP: 1.4                                     DATE: 28/04/2023
 */

#include "participant_list.h"


void createEmptyListP(tListP* L){
    *L = NULLP;
}

bool createNode(tPosP* p){
    *p = malloc(sizeof(struct tNode));
    return *p != NULLP;
}

bool insertItemP(tItemP d, tListP* L){
    tPosP q, r, s;

    if (!createNode(&q))
        return false;
    else {
        q->data = d;
        q->next = NULLP;
        s= firstP(*L);
        if (*L == NULLP){
            *L = q;
        } else if (strcmp(d.participantName, (*L)->data.participantName)<0){
            q->next = (*L);
            *L = q;
        } else{
            while(s!=NULLP && (strcmp(s->data.participantName, d.participantName))<0){
                s=s->next;
            }
            if(s==NULLP){
                for (r = *L; r->next != NULLP; r = r->next);
                r->next = q;
            }else{
                q->data = s->data;
                s->data = d;
                q->next = s->next;
                s->next = q;
            }
        }
        return true;
    }
}

void updateItemP(tItemP d, tPosP p, tListP* L){
    p->data = d;
}

tPosP findItemP(tParticipantName d, tListP L){
    tPosP p;
    if(L==NULLP)
        return NULLP;
    else{
        for (p = L; (p != NULLP) && strcmp(p->data.participantName, d) != 0; p = p->next);
        return p;
    }
}
tPosP firstP(tListP L){
    return L;
}

tPosP lastP(tListP L){
    tPosP p;

    for(p = L; p->next != NULLP; p=p->next);
    return p;
}

tPosP previousP (tPosP p, tListP L){
    tPosP q;
    if (p == NULLP)
        return NULLP;
    for (q = L; q->next != p; q = q->next);

    return q;
}

tPosP nextP(tPosP p, tListP L){
    return p->next;
}


bool isEmptyListP(tListP L){
    return L == NULLP;

}

tItemP getItemP(tPosP p, tListP L){
    return p-> data;
}

void deleteAtPositionP(tPosP p, tListP* L){
    tPosP q;

    if(p == *L)
        *L = (*L)->next;
    else if(p->next == NULLP){
        for (q = *L; q->next != p; q = q->next);
        q->next = NULLP;
    }else{
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }
    free(p);
    p = NULLP;
}

