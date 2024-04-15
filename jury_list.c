/*
 TITLE: PROGRAMMING II LABS                     SUBTITLE: P2
 AUTHOR 1: IVÁN AFONSO CERDEIRA                 LOGIN 1:IVAN.AFONSO
 AUTHOR 2: PABLO PÉREZ NOCEDA                   LOGIN 2:PABLO.PEREZ5
 GROUP: 1.4                                     DATE: 28/04/2023
 */

#include "jury_list.h"
#include "participant_list.h"

void createEmptyListJ(tListJ* L){
    L-> lastPos = NULLJ;  //crea una lista vacia
}

bool isEmptyListJ(tListJ L){
    return L.lastPos == NULLJ; // devuelve true si la última posición es nula
}

bool insertItemJ(tItemJ d,tListJ *L){
    tPosJ p;
    if(L->lastPos==(MAX-1))
        return false;
    else{
        if(isEmptyListJ(*L) || (strcmp(d.juryName,L->data[L->lastPos].juryName)>0)){ //si la lista está vacía o la comparación da mayor que cero
            L->lastPos++;                                                               //la ultima posición aumentará en uno
            L->data[L->lastPos]=d;                                                      //y se insertara el elemento deseado en la ultima posición
        }
        else{
            L->lastPos++;                                                               //si no, la última posición aumentará en uno
            for(p=L->lastPos;(p>0) && (strcmp(d.juryName,L->data[p-1].juryName)<0);p--) //mientras que la posición sea mayor que cero, y la comparación sea menor que cero, la posición irá disminuyendo
                L->data[p]=L->data[p-1];                                                //los datos de la posición p, seran iguales a los datos de la posicion anterior a p
            L->data[p]=d;                                                               //y se insertará el elemento deseado en p
        }
        return true;
    }

}

tPosJ firstJ(tListJ L){ //primera posición de la lista
    return 0;
}

tPosJ lastJ(tListJ L){ //última posición de la lista
    return L.lastPos;
}

tPosJ nextJ(tPosJ p, tListJ L){
    if(p == L.lastPos) //si la posición es la última, devuelve nulo
        return NULLJ;
    else
        return ++p; //si no, se pasa a la siguiente posición
}

tPosJ previousJ(tPosJ p, tListJ L){
    if(p == 0) //si la posición es la primera, devuelve nulo
        return NULLJ;
    else
        return --p;//si no, se vuelve a la posición anterior
}

void deleteAtPositionJ(tPosJ p, tListJ* L){
    tPosJ q;
    for(q = p; q < L->lastPos; q++){ //para la posición q, y mientras que la posición sea anterior a la última, la posicion aumentará
        L->data[q] = L->data[q+1]; //los datos de la posición q, serán iguales a los datos de la posición siguiente a la q
    }
    L->lastPos --; //la última posición en la lista, disminuye en uno
}

tItemJ getItemJ(tPosJ p, tListJ L){
    return L.data[p]; //devuelve los datos en la posicion p
}

void updateItemJ(tItemJ d, tPosJ p, tListJ* L){
    L->data[p] = d; //introduce los datos del nuevo item en la posicion p
}

tPosJ findItemJ(tJuryName d, tListJ L){
    tPosJ inicio = 0; // se le llama a la primera posición, inicio
    tPosJ fin = L.lastPos; //se le llama a la ultima posición, fin
    tPosJ p;

    while (inicio <= fin){
        p = (inicio + fin) / 2;
        if (strcmp(L.data[p].juryName, d) == 0){ //si al comparar ambos strings, el resultado da cero
            while (p > 0 && strcmp(L.data[p-1].juryName, d) == 0){ // y mientras que la posición sea mayor que cero, y la comparacion de igual a cero
                p--;  // se disminuye una posición
            }
            return p;
        } else if(strcmp(L.data[p].juryName, d) < 0){// si la comparación da menor que cero
            inicio = p + 1; //el inicio es en una posicion mayor
        } else{
            fin = p - 1; //si no, la posición final disminuye en uno
        }
    }
    return NULLJ;
}