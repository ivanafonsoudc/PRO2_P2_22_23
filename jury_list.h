/*
 TITLE: PROGRAMMING II LABS                     SUBTITLE: P2
 AUTHOR 1: IVÁN AFONSO CERDEIRA                 LOGIN 1:IVAN.AFONSO
 AUTHOR 2: PABLO PÉREZ NOCEDA                   LOGIN 2:PABLO.PEREZ5
 GROUP: 1.4                                     DATE: 28/04/2023
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H
#define MAX 10
#define NULLJ (-1)

#include "types.h"
#include "participant_list.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef int tPosJ;

typedef struct tItemJ {
    tJuryName juryName;
    tNumVotes totalVoters;
    tNumVotes validVotes;
    tNumVotes nullVotes;
    tListP participantList;
} tItemJ;

typedef struct{
    tItemJ data[MAX];
    tPosJ lastPos;
}tListJ;

void createEmptyListJ(tListJ* L);
/*
Objetivo: Crea una lista vacía y la inicializa.
Salida: Una lista vacía.
Postcondición: La lista sin datos.
*/

bool insertItemJ(tItemJ d,tListJ *L);
/*
Inserta un elemento de forma ordenada en función del campo juryName. Devuelve
un valor true si el elemento fue insertado; false en caso contrario.
PostCD: Las posiciones de los elementos de la lista posteriores al insertado
pueden cambiar de valor.
*/
bool isEmptyListJ(tListJ L);
/*
Objetivo: Determina si la lista está vacía.
Entrada:
List: Lista a comprobar.
Salida:
Verdadero si la lista está vacía, falso en caso contrario.
*/

tPosJ firstJ(tListJ L);
/*
Objetivo: Devuelve la posición del primer elemento de la lista.
Entrada:
List: Lista a manipular.
Salida:
Position: Posición del primer elemento.
Precondición: La lista no está vacía.
*/

tPosJ lastJ(tListJ L);
/*
Objetivo: Devuelve la posición del último elemento de la lista.
Entrada:
List: Lista a manipular.
Salida:
Position: Posición del último elemento.
Precondición: La lista no está vacía.
*/

tPosJ nextJ(tPosJ p, tListJ L);
/*
Objetivo: Devuelve la posición del elemento siguiente al actual.
Entrada:
Position: Posición del elemento actual.
List: Lista a manipular.
Salida:
Position: Posición del elemento siguiente o nulo si es el último.
Precondición: Position es una posición válida de la lista.
*/

tPosJ previousJ(tPosJ p, tListJ L);
/*
Objetivo: Devuelve la posición del elemento anterior al actual.
Entrada:
Position: Posición del elemento actual.
List: Lista a manipular.
Salida:
Posición del elemento anterior o nulo si es el primero.
Precondición: Position es una posición válida de la lista.
*/

void deleteAtPositionJ(tPosJ p, tListJ* L);
/*
Elimina de la lista el elemento que ocupa la posición indicada.
PreCD: La posición indicada es una posición válida en la lista y el jurado en dicha
posición tiene una lista de participantes vacía.
PostCD: Las posiciones de los elementos de la lista posteriores a la de la
posición eliminada pueden haber variado.
*/

tItemJ getItemJ(tPosJ p, tListJ L);
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

void updateItemJ(tItemJ d, tPosJ p, tListJ* L);
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

tPosJ findItemJ(tJuryName d, tListJ L);
/*
Objetivo: Busca el primer elemento con cierto contenido en la lista.
Entrada:
Item: Contenido del elemento buscado.
List: Lista donde realizar la búsqueda.
Salida:
Position: Posición del elemento encontrado o nulo si no se encuentra.
*/

#endif