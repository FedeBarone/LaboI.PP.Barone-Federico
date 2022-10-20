/*
 * informes.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Federico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"
#include "informes.h"
#define VACIO 1
#define OCUPADO 0



//INFORMES
//1- Mostrar transportes de un tipo seleccionado(listooo)
//2- Mostrar todas las hojas de ruta efectuadas en una fecha seleccionada(listooo)
//3- Informar importe total de las hojas de ruta realizadas en un transporte seleccionado(listooo)
//4- Informar importe total de todas las hojas de ruta de un tipo en una fecha seleccionada(listoo)


//1- Mostrar transportes de un tipo seleccionado(listooo)
void mostrarTransportesTipoSeleccionado(eTransporte* listaTransporte, int sizeT, eTipo* listaTipo, int sizeTipo)
{
	int tipo;
	int flag = 0;
	int anchoColumnaIDT = -20;
	int anchoColumnaTipo = -25;
	int anchoColumnaCantidad = -25;
	int anchoColumnaCarga = -25;
	int anchoColumnaDesc = -18;

	printf("*** Mostrar Transportes Tipo Seleccionado ***\n\n");

	mostrarTipos(listaTipo, sizeTipo);
	utn_getEntero(&tipo, 3,"Ingrese el id del tipo : ", "Id tipo invalido.\n", 1000, 1003);

	 printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");
	 printf("|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaIDT, " IDT", anchoColumnaTipo,
			      " Tipo", anchoColumnaCantidad, "Peso", anchoColumnaCarga, "Cantidad", anchoColumnaDesc, "Descripcion");
	 printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");

	if(listaTransporte != NULL && sizeT > 0 && listaTipo != NULL && sizeTipo > 0)
	{
		for(int i = 0; i < sizeT ; i++)
		{
			if((*(listaTransporte+i)).isEmpty == 0 && (*(listaTransporte+i)).tipoId == tipo)
			{
				mostrarTransporte((*(listaTransporte+i)), listaTipo, sizeTipo);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("No hay transportes de este tipo seleccionado.\n\n");
		}
	}
}


//2- Mostrar todas las hojas de ruta efectuadas en una fecha seleccionada(listooo)
void mostrarHojasRutaFechaSeleccionada(eHojaRuta* listaHojaRuta, int sizeH,eTransporte* listaT, int sizeT)
{
	int anio;
	int mes;
	int dia;
	int i;
	int flag = 0;
	int anchoColumnaIDT = -20;
	int anchoColumnaTipo = -25;
	int anchoColumnaCantidad = -25;
	int anchoColumnaCarga = -25;
	int anchoColumnaDesc = -18;

	printf("*** Hoja ruta efectuada en fecha seleccionada ***\n\n");
    utn_getEntero(&dia, 4, "Ingrese dia: [1-31] " , "error...", 1, 31);
    utn_getEntero(&mes, 4, "Ingrese mes: [1-12] " , "error...", 1, 12);
    utn_getEntero(&anio, 4, "Ingrese anio: [2022-3022] " , "error...", 2022, 3022);

    printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");
   	printf("|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaIDT, " IDH", anchoColumnaTipo,
   		       " Transporte", anchoColumnaCantidad, "Precio Viaje", anchoColumnaCarga, "Kms Totales", anchoColumnaDesc, "dia/mes/anio");
   	printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");

   	if(listaHojaRuta != NULL && sizeH > 0 && listaT != NULL && sizeT > 0)
   	{
		for(i = 0; i < sizeH ; i++)
		{
			if((*(listaHojaRuta+i)).isEmpty == 0 && (*(listaHojaRuta+i)).fecha.dia == dia && (*(listaHojaRuta+i)).fecha.mes == mes && (*(listaHojaRuta+i)).fecha.anio == anio)
			{
				mostrarHojaRuta((*(listaHojaRuta+i)), listaT, sizeT);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("Esa fecha no existe .\n\n");
		}

   	}
}


//3- Informar importe total de las hojas de ruta realizadas en un transporte seleccionado(listooo)
void informarImporteTotalTransporteSeleccionado(eHojaRuta* listaH, int sizeH, eTransporte* listaT, int sizeT, eTipo* listaTipo, int sizeTipo)
{
    int flag = 0;
    int idTransporte;
    float acumPrecioViaje = 0;

    if( listaH != NULL && sizeH > 0 && listaT != NULL && sizeT > 0 && listaTipo != NULL && sizeTipo > 0)
    {
        printf("   *** importe total hoja ruta transporte ***\n");

        mostrarTransportes(listaT, sizeT, listaTipo, sizeTipo);
        utn_getEntero(&idTransporte, 3,"Ingrese el id de transporte : ", "Id invalido.\n", 0, 13);

        for(int i=0; i < sizeH; i++)
        {
            if((*(listaH+i)).isEmpty == OCUPADO && (*(listaH+i)).transporteId == idTransporte)
            {
                acumPrecioViaje += (*(listaH+i)).precioViaje;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay transportes seleccionados.\n\n");
        }
        else
        {
            printf("El importe total es $ %.2f\n",acumPrecioViaje);
        }

    }

}


//4- Informar importe total de todas las hojas de ruta de un tipo en una fecha seleccionada(listoo)
void informarImporteTotalTipoFechaSeleccionada(eHojaRuta* listaH, int sizeH, eTransporte* listaT, int sizeT, eTipo* listaTipo, int sizeTipo)
{
  	int anio;
  	int mes;
  	int dia;
    int flag = 0;
    int idTipo;
    float acumPrecioViaje = 0;

    if( listaH != NULL && sizeH > 0 && listaT != NULL && sizeT > 0 && listaTipo != NULL && sizeTipo > 0)
    {
        printf("   *** importe total hoja ruta fecha tipo ***\n");

        utn_getEntero(&dia, 4, "Ingrese dia: [1-31] " , "error...", 1, 31);
        utn_getEntero(&mes, 4, "Ingrese mes: [1-12] " , "error...", 1, 12);
        utn_getEntero(&anio, 4, "Ingrese anio: [2022-3022] " , "error...", 2022, 3022);

        mostrarTipos(listaTipo, sizeTipo);
        utn_getEntero(&idTipo, 3,"Ingrese el id del tipo : ", "Id tipo invalido.\n", 1000, 1003);

        for(int i=0; i < sizeH; i++)
        {
            if((*(listaH+i)).isEmpty == OCUPADO && (*(listaT+i)).tipoId == idTipo && (*(listaH+i)).fecha.dia == dia && (*(listaH+i)).fecha.mes == mes && (*(listaH+i)).fecha.anio == anio )
            {
                acumPrecioViaje += (*(listaH+i)).precioViaje;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay tipo seleccionado.\n\n");
        }
        else
        {
            printf("El importe total es $ %.2f\n",acumPrecioViaje);
        }

    }

}



