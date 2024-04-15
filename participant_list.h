/*
 TITLE: PROGRAMMING II LABS                     SUBTITLE: P2
 AUTHOR 1: IVÁN AFONSO CERDEIRA                 LOGIN 1:IVAN.AFONSO
 AUTHOR 2: PABLO PÉREZ NOCEDA                   LOGIN 2:PABLO.PEREZ5
 GROUP: 1.4                                     DATE: 28/04/2023
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"
#define NAME_LENGTH_LIMIT 25
#define MAX 25
#include <string.h>
#include <stdlib.h>
#define NULLP NULL

typedef struct tItemP{
    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;
}tItemP;

typedef struct tNode* tPosP;
struct tNode{
    tItemP data;
    tPosP next;
};

typedef tPosP tListP;



void createEmptyListP(tListP* L);
/*
Objetivo: Crea una lista vacía y la inicializa.
Salida: Una lista vacía.
Postcondición: La lista sin datos.
*/

bool insertItemP(tItemP d, tListP* L);
/*
Inserta un elemento de forma ordenada en función del campo participantName.
Devuelve un valor true si el elemento fue insertado; false en caso contrario.
PostCD: Las posiciones de los elementos de la lista posteriores a la del
elemento insertado pueden haber variado.
*/

bool isEmptyListP(tListP L);
/*
Objetivo: Determina si la lista está vacía.
Entrada:
List: Lista a comprobar.
Salida:
Verdadero si la lista está vacía, falso en caso contrario.
*/

tPosP firstP(tListP L);
/*
Objetivo: Devuelve la posición del primer elemento de la lista.
Entrada:
List: Lista a manipular.
Salida:
Position: Posición del primer elemento.
Precondición: La lista no está vacía.
*/

tPosP lastP(tListP L);
/*
Objetivo: Devuelve la posición del último elemento de la lista.
Entrada:
List: Lista a manipular.
Salida:
Position: Posición del último elemento.
Precondición: La lista no está vacía.
*/

tPosP nextP(tPosP p, tListP L);
/*
Objetivo: Devuelve la posición del elemento siguiente al actual.
Entrada:
Position: Posición del elemento actual.
List: Lista a manipular.
Salida:
Position: Posición del elemento siguiente o nulo si es el último.
Precondición: Position es una posición válida de la lista.
*/

tPosP previousP(tPosP p, tListP L);
/*
Objetivo: Devuelve la posición del elemento anterior al actual.
Entrada:
Position: Posición del elemento actual.
List: Lista a manipular.
Salida:
Posición del elemento anterior o nulo si es el primero.
Precondición: Position es una posición válida de la lista.
*/

void deleteAtPositionP(tPosP p, tListP* L);
/*
Objetivo: Elimina de la lista un elemento con cierta posición.
Entrada:
Position: Posición del elemento a eliminar.
List: Lista a modificar.
Salida:
List: Lista sin el elemento correspondiente a Position.
Precondición:
Position es una posición válida de la lista.
Postcondición:
Las posiciones de los elementos de la lista posteriores a la de la
posición eliminada pueden haber variado.
*/

tItemP getItemP(tPosP p, tListP L);
/*
Objetivo: Recupera el contenido de un elemento de la lista.
Entrada:
Position: Posición del elemento buscado.
List: Lista donde realizar la búsqueda.
Salida:
Item: Contenido del elemento que está en Position.
Precondición:
Position es una posición válida en la lista.
*/

void updateItemP(tItemP d, tPosP p, tListP* L);
/*
Objetivo: Modifica el contenido de un elemento de la lista.
Entrada:
Item: Nuevo contenido a asignar al elemento en Position.
Position: Posición del elemento que queremos modificar.
List: Lista a modificar.
Salida:
List: Lista con el contenido del elemento modificado.
Precondición:
Position es una posición válida de la lista.
*/

tPosP findItemP(tParticipantName d, tListP L);
/*
Objetivo: Busca el primer elemento con cierto contenido en la lista.
Entrada:
Item: Contenido del elemento buscado.
List: Lista donde realizar la búsqueda.
Salida:
Position: Posición del elemento encontrado o nulo si no se encuentra.
*/

#endif