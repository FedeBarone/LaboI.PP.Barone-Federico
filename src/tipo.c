/*
 * tipo.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"



int cargarDescripcionTipo(char* descripcion, int idTipoAux, eTipo* tipos, int tamT)
{
	int retorno = 0;

	if(descripcion != NULL && tipos!=NULL && tamT > 0)
	{

		for(int i = 0; i < tamT; i++)
		{
			if((*(tipos+i)).idTipo == idTipoAux)
			{
				strcpy(descripcion, (*(tipos+i)).descripcion);
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}



int mostrarTipos(eTipo* tipos, int tamT)
{
	int retorno = 0;
	if(tipos != NULL)
	{
		retorno = 1;
		printf("*** Tipos ***\n");
		printf("  ID      Descripcion\n\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("%d   %10s \n", (*(tipos+i)).idTipo, (*(tipos+i)).descripcion);
		}
	}
	return retorno;
}






































































