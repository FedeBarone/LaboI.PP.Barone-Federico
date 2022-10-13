/*
 * transporte.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"
#define VACIO 1
#define OCUPADO 0

//INICIALIZAR
int inicializarTransporte(eTransporte* listaT, int size)
{
	int retorno = -1;

			if(listaT != NULL && size > 0)
			{
				for(int i = 0; i < size; i++)
				{
					(*(listaT+i)).isEmpty = VACIO;
				}

				retorno = 0;
			}


	return retorno;
}



int buscarIndiceLibreT(eTransporte* listaT, int size)
{
	//-1 no consiguio lugar
	int indice = -1;


			if(listaT != NULL && size > 0)
			{
				for(int i = 0; i < size; i++)
				{
					if((*(listaT+i)).isEmpty == VACIO)
					{
						indice = i;//devuelvo el valor que tiene el indice
						break;
					}
				}

			}

	return indice;

}



int buscarTransportePorId(eTransporte* listaT, int size, int idT)
{
	int indice = -1;

			if(listaT != NULL && size > 0)
			{
				for(int i = 0; i < size; i++)
				{
					if((*(listaT+i)).idTransporte == idT && (*(listaT+i)).isEmpty == OCUPADO)
					{
						indice = i;
						break;
					}
				}
			}

	return indice;
}

//MOSTRAR

void mostrarTransporte(eTransporte transporte, eTipo* listaTipo, int sizeTipo)
{
	char descripcionTipo[30];

	cargarDescripcionTipo(descripcionTipo, transporte.tipoId, listaTipo, sizeTipo);

	printf("%-5d    %5s        %6d       %13.2f         %11s\n\n", transporte.idTransporte,descripcionTipo, transporte.cantidadBultos, transporte.pesoCarga, transporte.descripcion);

}



void mostrarTransportes(eTransporte* listaT, int tamT, eTipo* listaTipo, int sizeTipo)
{

	printf("\n IDT          Tipo               Cantidad         Carga           Descripcion\n\n");


		if(listaT != NULL && tamT > 0 && listaTipo != NULL && sizeTipo > 0)
		{
			for(int i = 0; i < tamT; i++)
			{
					if((*(listaT+i)).isEmpty == 0)
					{
						mostrarTransporte((*(listaT+i)), listaTipo, tamT);
					}
			}

		}

}


int ordenarTransportes(eTransporte* listaT, int tamT)
{


	eTransporte transporteAuxiliar;
	int perfecto = -1;


	if(listaT != NULL && tamT > 0)
			{
				for(int i = 0; i < tamT-1; i++)
				{
					if((*(listaT+i)).isEmpty == 0)
						{
							//if(ordenamiento == 1)
							//{
								for(int j = i+1; j < tamT; j++)
								{

									if((*(listaT+i)).tipoId > (*(listaT+j)).tipoId)
									{
										transporteAuxiliar = (*(listaT+i));
											(*(listaT+i)) = (*(listaT+j));
											(*(listaT+j)) =  transporteAuxiliar;
								    }
									else
									{
										if(((*(listaT+i)).tipoId == (*(listaT+j)).tipoId) || (strcmp((*(listaT+i)).descripcion, (*(listaT+j)).descripcion)>0) )
										{

											transporteAuxiliar = (*(listaT+i));
												(*(listaT+i)) = (*(listaT+j));
												(*(listaT+j)) =  transporteAuxiliar;
										}

									}

								}
						}
					}

				perfecto = 0;
			}

	return perfecto;

}



















































































