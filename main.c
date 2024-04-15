/*
 TITLE: PROGRAMMING II LABS                     SUBTITLE: P2
 AUTHOR 1: IVÁN AFONSO CERDEIRA                 LOGIN 1:IVAN.AFONSO
 AUTHOR 2: PABLO PÉREZ NOCEDA                   LOGIN 2:PABLO.PEREZ5
 GROUP: 1.4                                     DATE: 28/04/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255

void Create(char *juryName, char *totalVoters, tListJ* L);
/*
Objetivo: se añade el jurado a la lista con el número de votantes
igualado al parámetro indicado.
Entradas: Al igual que en todas las funciones, lo primero que nos pasan es la letra del comando de la función a la que se quiere
acceder, el nombre del jurado el cual siempre se constituye de "Jury" seguido de un número y por último su número de miembros
Salidas:
Precondición: No existe otro jurado con el mismo nombre ya en la lista(o que sea el propio jurado el que está ya en la lista).
*/

void New(tListJ *L, char *param1, char *param2, char *param3);

/*
Objetivo: Añadir un participante al jurado indicado.
Entrada: La letra del comando como siempre, el jurado al que queremos añadir el
participante, el participante y la condición de eu(europeo) o non-eu(no europeo).
Salida: Se añade al participante y se imprime un mensaje por pantalla que sigue el siguiente modelo: *⎵New:⎵jury⎵XX⎵participant⎵YY⎵location⎵ZZ
Precondición: El participante no puede existir previamente a la inserción.
*/

void Vote(tJuryName juryName, tParticipantName participantName, tListJ* L);
/*
Objetivo: Aumentar el número de votos del participante en el jurado, es decir, emitir un voto para un participante en un jurado.
Entradas: Además de la letra de comando, el nombre del participante y el del jurado.
Salidas: La adicción de un voto para un participante.
Precondiciones: El jurado tiene que existir y el participante tiene que existir para el jurado indicado, en caso de que la primera
condición no se cumpla el voto no se podrá efectuar, pero si la que falla es la segunda, el voto se podrá emitir, pero se
contabilizará como voto nulo.
*/

void Disqualify(tParticipantName participantName, tListJ* L);
/*
Objetivo: Se buscará al participante en todas las listas locales, se
borrará de las listas, pasando sus votos a considerarse como nulos.
Entradas: El nombre del participante a descalificar de la lista.
Salidas: En caso de éxito, la eliminación del participante.
Precondiciones: La lista de jurados no puede estar vacía y el participante tiene que existir.
*/

void Remove(tListJ* J);
/*
Objetivo: Se eliminarán todos los jurados con 0 votos válidos.
Entradas: La lista de jurados en la que se buscarán los jurados a eliminar.
Salidas: Si nada lo evita, la eliminación de los jurados que cumplan la condición.
Precondiciones: Tiene que haber algún jurado en la lista y/o alguno que eliminar
aunque el programa contempla la posibilidad de que ambas o alguna de ellas no se cumpla.
*/

void Stats(tListJ *L) ;
/* Objetivo: Se mostrarán las estadísticas de voto.
Entradas: La letra de comando, la lista ya la tiene incluida la propia función,
ya que es la única de la que deseamos conocer las estadísticas.
Salida: Los distintos jurados con los participantes dentro y sus estadísticas: nombre,
localización, número de votos válidos y nulos, sus porcentajes y los datos de participación para el número de votantes.
Precondición: La lista de jurados no puede estar totalmente vacía.
*/

void Winners(tListJ* J);
/*
Objetivo: se mostrarán los ganadores de cada jurado en función de si pertenecen o no a la Unión Europea.
Entrada: La letra de comando la cual, al igual que en la función stats, nos mostrará unos datos de la lista que viene incluida en la función, en este caso los ganadores.
Salida: Muestra por pantalla para cada jurado el ganador de los europeos y, por otra parte, la de los no europeos.
Precondición: La lista de jurados no puede estar totalmente vacía.
*/

void Create(char *juryName, char *totalVoters, tListJ* L){
    tItemJ d;
    tPosJ p;

    p = findItemJ(juryName, *L); //busco el item (jurado) con el que quiero trabajar, por su nombre en la lista
    d.nullVotes=0; d.validVotes=0; //inicializo estas dos variables
    createEmptyListP(&d.participantList); //creo una lista (de participante)
    strcpy(d.juryName, juryName); //copio el nombre del jurado del item en el de mi jurado por asi decirlo
    d.totalVoters=atoi(totalVoters); //el numero de votos se me pasa en forma de char por lo que la pasamos a entero mediante la función atoi

    if(p==NULLJ){ //si la posicion está vacía...
        if(insertItemJ(d, L)) //si puede insertar el item
            printf("* Create: jury %s totalvoters %d\n", juryName, d.totalVoters); //inserta el item y me pasa mi frase de control
        else{ //si no lo pudo insertar
            printf("+ Error: Create not possible\n"); //no lo crea y asi me lo indica
        }
    }else{ //si no está vacía
        printf("+ Error: Create not possible\n"); //no puede insertarlo y así me lo indica
    }
}

void New(tListJ *L, char *param1, char *param2, char *param3){
    tItemJ d;
    tPosJ p;
    tItemP h;
//inicializo las cosas que necesito en el programa para trabajar

    if(isEmptyListJ(*L)==true){ //compruebo si la lista está vacía
        printf("+ Error: New not possible\n"); //no puede hacer nada
    }else{ //(no está vacía)
        p= findItemJ(param1, *L);//mi posición es la que "contiene" el nombre del param1 que me pasan, en la listaL
        if(p==NULLJ){ //no hay posición, no encontró lo que buscaba
            printf("+ Error: New not possible\n"); //y así me lo indica
        }
        else{ //la lista no está vacía y encontró la posición
            d=getItemJ(p, *L); //cojo el item de la posición con la función getItem y le doy nombre a ese item

            if(findItemP(param2, d.participantList)==NULLP){ //si la posicion del item que estoy buscando es nula
                h.numVotes=0; //inicializo sus votos a 0
                strcpy(h.participantName, param2); //copio el nombre de mi participante al item

                if(strcmp(param3, "eu")==0){ //compruebo si el tercer parámetro el cual me pasa en forma de char es eu(participante europeo) o non-eu(participante no europeo)
                    h.EUParticipant=true; //europeo
                }else
                    h.EUParticipant=false; //no europeo

                if(insertItemP(h, &d.participantList)){ //si pudo insertar el item
                    updateItemJ(d, p, L); //lo recargo
                    printf("* New: jury %s participant %s location %s\n", d.juryName, h.participantName, param3); //mi sentencia de control me confirma que lo pude insertar
                }
                else {
                    printf("+ Error: New not possible\n"); //no lo pudo insertar y asi me lo indica
                }
            }
            else
                printf("+ Error: New not possible\n"); //no se pudo efectuar el new y asi me lo indica
        }
    }
}

void Vote(tJuryName juryName, tParticipantName participantName, tListJ* L){
    tItemJ d;
    tItemP h;
    tPosP posP;
    tPosJ posJ;
    posJ= findItemJ(juryName, *L);

    if(posJ==NULLJ || isEmptyListJ(*L)){
        printf("+ Error: Vote not possible");
    }else{
        d = getItemJ(posJ, *L);
        posP = findItemP(participantName, d.participantList);
        if(posP!=NULLP){
            h = getItemP(posP, d.participantList);
            h.numVotes++;
            d.validVotes++;
            updateItemP(h, posP, &d.participantList);
            updateItemJ(d, posJ, L);

            if(h.EUParticipant==true){
                printf(" * Vote: jury %s participant %s location eu numvotes %d\n", d.juryName, participantName, h.numVotes);
            }else{
                printf(" * Vote: jury %s participant %s location non-eu numvotes %d\n", d.juryName, participantName, h.numVotes);

            }
        }else{
            printf("+ Error: Vote not possible. Participant %s not found in jury %s.  NULLVOTE\n", participantName, d.juryName);
            d.nullVotes++;
            updateItemJ(d, posJ, L);
        }
    }
}

void Disqualify(tParticipantName participantName, tListJ* L){
    tPosJ posJ;
    tPosP posP;
    tItemJ j;
    tItemP p;

    if(isEmptyListJ(*L)==true){
        printf("+ Error: Disqualify not possible\n");
    }else{
        for(posJ = firstJ(*L); posJ != NULLJ; posJ = nextJ(posJ, *L)){
            j = getItemJ(posJ, *L);
            posP = findItemP(participantName, j.participantList);
            printf("Jury %s\n", j.juryName);
            if (posP != NULLP){
                p = getItemP(posP, j.participantList);
                j.validVotes = j.validVotes-p.numVotes;
                j.nullVotes=j.nullVotes+p.numVotes;
                deleteAtPositionP(posP, &(j.participantList));
                updateItemJ(j, posJ, L);
                printf("Participant %s disqualified\n\n", participantName);

            }else{
                printf("No participant %s\n\n", p.participantName);
            }
        }
    }

}

void Remove(tListJ* J){
    tPosJ posJ;
    tItemJ jurado;
    int borrados=0;

    if(isEmptyListJ(*J)==true){
        printf("+ Error: Remove not possible\n");
    }else{
        for(posJ = firstJ(*J); posJ != NULLJ; posJ = nextJ(posJ, *J)){
            jurado= getItemJ(posJ, *J);
            if(jurado.validVotes==0){
                deleteAtPositionJ(posJ, J);
                posJ=posJ-1;
                printf("* Remove: jury %s\n", jurado.juryName);
                borrados++;
            }
        }
        if(borrados==0){
            printf("+ Error: Remove not possible\n");
        }
    }
}

void Stats(tListJ *L){
    tPosJ p;
    tPosP h;
    tItemP d;
    tItemJ j;
    float porcentaje, porcenpart;

    if (!isEmptyListJ(*L)) {
        for (p = firstJ(*L); p != NULLJ; p = nextJ(p, *L)) {
            j = getItemJ(p, *L);
            printf("Jury %s\n",j.juryName);
            if(isEmptyListP(j.participantList)){
                printf("No participants\n");
            }else{
                for(h=firstP(j.participantList);h!=NULLP;h=nextP(h,j.participantList)){
                    d= getItemP(h,j.participantList);
                    if(d.numVotes==0){
                        if (d.EUParticipant == true)
                            printf("Participant %s location eu numvotes %d (%.2f%%)\n", d.participantName, d.numVotes, 0.00);
                        else
                            printf("Participant %s location non-eu numvotes %d (%.2f%%)\n", d.participantName, d.numVotes, 0.00);
                    }
                    else{
                        porcentaje=(((float)(d.numVotes))/((float)(j.validVotes+j.nullVotes)))*100;
                        if (d.EUParticipant == true)
                            printf("Participant %s location eu numvotes %d (%.2f%%)\n", d.participantName, d.numVotes,porcentaje);
                        else
                            printf("Participant %s location non-eu numvotes %d (%.2f%%)\n", d.participantName, d.numVotes,porcentaje);
                    }
                }
            }
            printf("Nullvotes %d\n", j.nullVotes);
            porcenpart=(((float)((j.validVotes+j.nullVotes))/((float)(j.totalVoters)))*100);
            printf("Participation: %d votes from %d voters (%.2f%%)\n\n",(j.validVotes+j.nullVotes), j.totalVoters,porcenpart);

        }
    }
    else{
        printf("+ Error: Stats not possible");
    }
}

void Winners(tListJ* J){
    tPosJ posJ;
    tPosP posP;
    tItemJ jurado;
    tItemP participante;
    tItemP ganadorEU;       ganadorEU.numVotes=0;
    tItemP ganadornonEU;    ganadornonEU.numVotes=0;
    bool coincidenEU, coincidennonEU;


    if(isEmptyListJ(*J)==true){
        printf("+ Error: Winners not possible");
    }else{
        for(posJ = firstJ(*J) ; posJ != NULLJ ; posJ = nextJ(posJ, *J)){
            jurado=getItemJ(posJ, *J);
            printf("Jury %s\n", jurado.juryName);
            if(isEmptyListP(jurado.participantList)==true){
                printf("Location eu: No winner\n"
                       "Location non-eu: No winner\n");
            }else{
                for(posP = firstP(jurado.participantList) ; posP != NULLP ; posP= nextP(posP, jurado.participantList)){
                    participante=getItemP(posP, jurado.participantList);
                    if(participante.EUParticipant==true){
                        if(participante.numVotes>ganadorEU.numVotes){
                            coincidenEU=false;
                            ganadorEU=participante;
                        }else{
                            if(participante.numVotes==ganadorEU.numVotes){
                                coincidenEU=true;
                            }
                        }
                    }else{
                        if(participante.numVotes>ganadornonEU.numVotes){
                            coincidennonEU=false;
                            ganadornonEU=participante;
                        }else{
                            if(participante.numVotes==ganadornonEU.numVotes){
                                coincidennonEU=true;
                            }
                        }
                    }
                }
                if(coincidenEU==true){
                    printf("Location eu: No winner\n");
                }else{
                    printf("Location eu: Participant %s numvotes %d\n", ganadorEU.participantName, ganadorEU.numVotes);
                }

                if(coincidennonEU==true){
                    printf("Location non-eu: No winner\n");
                }else{
                    printf("Location non-eu: Participant %s numvotes %d\n", ganadornonEU.participantName, ganadornonEU.numVotes);
                }
            }
            printf("\n");
        }
    }
}

void asteriscos(){
    printf("********************\n");
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *L) {
    switch (command) {
        case 'C':
            asteriscos();
            printf("%s %c: jury %s totalvoters %s\n", commandNumber, command, param1, param2);
            Create(param1, param2, L);
            break;
        case 'N':
            asteriscos();
            printf("%s %c: jury %s participant %s location %s\n", commandNumber, command, param1, param2, param3);
            New(L, param1, param2, param3);
            break;
        case 'V':
            asteriscos();
            printf("%s %c: jury %s participant %s\n", commandNumber, command, param1, param2);
            Vote(param1, param2, L);
            break;
        case 'D':
            asteriscos();
            printf("%s %c: participant %s\n", commandNumber, command, param1);
            Disqualify(param1, L);
            break;
        case 'S':
            asteriscos();
            printf("%s %c:\n", commandNumber, command);
            Stats(L);
            break;
        case 'R':
            asteriscos();
            printf("%s %c:\n", commandNumber, command);
            Remove(L);

            break;
        case 'W':
            asteriscos();
            printf("%s %c:\n", commandNumber, command);
            Winners(L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, tListJ *L) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tListJ L;
    createEmptyListJ(&L);

    char *file_name = "create.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &L);

    return 0;
}

