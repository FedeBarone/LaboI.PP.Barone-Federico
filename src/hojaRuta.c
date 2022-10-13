/*
 * hojaRuta.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico Barone 1ero J
 */

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "tipo.h"
#include "input.h"
#include "transporte.h"
#include "HojaRuta.h"
#define VACIO 1
#define OCUPADO 0



int inicializarHojaRuta(eHojaRuta* listaH, int sizeH)
{
	int retorno = -1;

		if(listaH != NULL && sizeH > 0)
		{
			for(int i = 0; i < sizeH; i++)
			{
				(*(listaH+i)).isEmpty = VACIO;

				retorno = 0;
			}
		}


	return retorno;
}




int buscarIndiceLibreHojaRuta(eHojaRuta* listaH, int sizeH)
{
	int indice = -1;

			//-1 no consiguio lugar
			if(listaH != NULL && sizeH > 0)
			{
				for(int i = 0; i < sizeH; i++)
				{
					if((*(listaH+i)).isEmpty == VACIO)
					{
						indice = i; //devuelvo el valor que tiene el indice
						break;
					}
				}
			}

	return indice;
}



int buscarHojaRutaPorId(eHojaRuta* listaH, int sizeH, int idH)
{
	int indice = -1;

				if(listaH != NULL && sizeH > 0)
				{
					for(int i = 0; i<sizeH; i++)
					{
						if((*(listaH+i)).idHoja == idH && (*(listaH+i)).isEmpty == OCUPADO)
						{
							indice = i;
							break;
						}
					}
				}

	return indice;
}



void mostrarHojaRuta(eHojaRuta hojaRuta)
{

	printf("%-5d    %5d     %10d   %15f    			/%d/%d/%d      \n\n", hojaRuta.idHoja, hojaRuta.transporteId,hojaRuta.precioViaje,hojaRuta.kmsTotales,hojaRuta.fecha.dia,hojaRuta.fecha.mes,hojaRuta.fecha.anio);

}



void mostrarHojasRuta(eHojaRuta* listaH, int sizeH)
{
 printf("IDH    ID Transporte         precioViaje         kmsTotales       dia/mes/anio\n\n");

 	 	 if(listaH != NULL && sizeH > 0)
 	 	 {

 	 		for(int i = 0; i < sizeH; i++)
 	 		{
 	 			if((*(listaH+i)).isEmpty == OCUPADO)
 	 			{
 	 				mostrarHojaRuta(*(listaH+i));
 	 			}
 	 		}

 	 	 }

}








































































