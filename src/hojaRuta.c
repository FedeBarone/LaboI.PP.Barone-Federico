/*
 * hojaRuta.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico Barone 1ero J
 */

#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "input.h"
#include "transporte.h"
#include "HojaRuta.h"
#define VACIO 1
#define OCUPADO 0



static int eHojaRuta_ObtenerID(void);
static int eHojaRuta_ObtenerID(void)
{
	static int idHojaAuto = 20000;
	return idHojaAuto++;
}



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



int altaHojaRuta(eHojaRuta* listaH, int tamH, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{

	int retorno = 0;
	int indice = buscarIndiceLibreHojaRuta(listaH, tamH);
	int idAuxTransporte;

		if(listaH != NULL && tamH > 0 && listaT != NULL && tamT > 0 && listaTipo != NULL && tamTipo > 0)
		{
				printf("---Alta Hoja Ruta---");

				if(indice < 0)
				{
					printf("completo \n");

				}
				else
				{
					if(utn_getEntero(&listaH[indice].fecha.dia, 4, "Ingrese dia: [1-31] " , "error...", 1, 31) == 0)
					{
						if(utn_getEntero(&listaH[indice].fecha.mes, 4, "Ingrese mes: [1-12] " , "error...", 1, 12)== 0)
						{
							utn_getEntero(&listaH[indice].fecha.anio, 4, "Ingrese anio: [2022-3022] " , "error...", 2022, 3022);
						}
					}

					utn_getFlotante(&listaH[indice].precioViaje, 4, "Ingrese el precio del viaje: [200-100000] ", "ERROR...\n", 200, 100000);
					utn_getFlotante(&listaH[indice].kmsTotales, 4, "Ingrese los kms totales: [80-8500] ", "ERROR...\n", 80, 8500);
					mostrarTransportes(listaT, tamT, listaTipo, tamTipo);

					if(utn_getEntero(&idAuxTransporte,4, "Ingrese ID de transporte", "Error",0,20) == 0)
						 mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
					{
						if(buscarTransportePorId(listaT, tamT, idAuxTransporte) > -1)
						{
							listaH[indice].transporteId = idAuxTransporte;
							listaH[indice].idHoja = eHojaRuta_ObtenerID();
							listaH[indice].isEmpty = 0; //lleno el lugar
							retorno = 1;
							 mostrarHojasRuta(listaH, tamH, listaT, tamT);
						}
						else
						{
							printf("No existe ese transporte");
						}
					}

				}

		}


	return retorno;
}



void mostrarHojaRuta(eHojaRuta hojaRuta, eTransporte* listaT, int sizeT)
{
	char descripcionTransporte[30];
	cargarDescripcionTransporte(descripcionTransporte, hojaRuta.transporteId, listaT, sizeT);
	printf("|%-20d|%-25s|%-25.2f|%-25.2f|%-3d/%-3d/%-10d|\n", hojaRuta.idHoja, descripcionTransporte, hojaRuta.precioViaje, hojaRuta.kmsTotales, hojaRuta.fecha.dia,hojaRuta.fecha.mes,hojaRuta.fecha.anio);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

}



void mostrarHojasRuta(eHojaRuta* listaH, int sizeH, eTransporte* listaT, int sizeT)
{
	int anchoColumnaIDH = -20;
	int anchoColumnaTransporte= -25;
	int anchoColumnaPrecioViaje = -25;
	int anchoColumnaKms = -25;
	int anchoColumnaFecha = -18;

		  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");
		  printf("|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaIDH, " IDH", anchoColumnaTransporte,
		         " Transporte", anchoColumnaPrecioViaje, "precioViaje", anchoColumnaKms, "kmsTotales", anchoColumnaFecha, "Dia/Mes/Anio");
		  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");

 	 	 if(listaH != NULL && sizeH > 0)
 	 	 {

 	 		for(int i = 0; i < sizeH; i++)
 	 		{
 	 			if((*(listaH+i)).isEmpty == OCUPADO)
 	 			{
 	 				mostrarHojaRuta((*(listaH+i)), listaT, sizeT);
 	 			}
 	 		}

 	 	 }

}








































































