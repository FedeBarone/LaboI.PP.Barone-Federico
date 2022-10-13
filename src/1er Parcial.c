/*
	Federico Barone 1ero J

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"
#include "menus.h"
#define TAM_transporte 250
#define TAMH 30
#define TAMTIPO 4

int main(void) {
	setbuf(stdout,NULL);

	char continuar = 's';
	char confirmar;
	int flag = 0;
	int flagT = 0;
	int flagH = 0;

	eTransporte transporteAux[TAM_transporte];
	eHojaRuta hojaRutaAux[TAMH];

		eTipo tiposDeCamiones[4]={
						{1000,"Camion Recto"},
						{1001,"Camion Remolque"},
						{1002,"Camion Semirremolque"},
						{1003,"Camion Elevador"},
				};


		inicializarTransporte(transporteAux, TAM_transporte);
		inicializarHojaRuta(hojaRutaAux, TAMH);

		do
		{

			switch(mostrarMenuPrincipal())
			{

			case 1:
						flag= 1;
						darDeAltaTransporte(&flagT, transporteAux, TAM_transporte, tiposDeCamiones, TAMTIPO);

				break;

			case 2:
						if(flag == 1)
						{
							modificarTransporte(flagT, transporteAux, TAM_transporte, tiposDeCamiones, TAMTIPO);
						}
						else
						{
							printf("\nPARA PODER MODIFICAR PRIMERO DEEBE DAR EL ALTA DE TRANSPORTE\n");
						}

				break;
			case 3:
						if(flag == 1)
						{
							darBajaTransporte(flagT, transporteAux, TAM_transporte,tiposDeCamiones, TAMTIPO);
						}
						else
						{
							printf("\nPARA PODER DAR DE BAJA PRIMERO DEEBE DAR EL ALTA DE TRANSPORTE\n");
						}

				break;
			case 4:		if(flag == 1)
						{
							listarTransporte(flagT,transporteAux, TAM_transporte, tiposDeCamiones, TAMTIPO);
						}
						else
						{
							printf("\nPARA PODER LISTAR  PRIMERO DEEBE DAR EL ALTA DE TRANSPORTE\n");
						}

				break;
			case 5:
						if(flag == 1)
						{
							listarTipos(tiposDeCamiones, TAMTIPO);
						}
						else
						{
							printf("\nPARA PODER LISTAR PRIMERO DEEBE DAR EL ALTA DE TRANSPORTE\n");
						}

				break;
			case 6:
						if(flag == 1)
						{
							darDeAltaHojaRuta(&flagH, hojaRutaAux, TAMH, transporteAux, TAM_transporte, tiposDeCamiones, TAMTIPO);
						}
						else
						{
							printf("\nPARA PODER DAR DE ALTA LA HOJA DE RUTA PRIMERO DEEBE DAR EL ALTA DE TRANSPORTE\n");
						}


				break;
			case 7:
						if(flag == 1)
						{
							listarHojaRuta(flagH,hojaRutaAux, TAMH);
						}
						else
						{
							printf("\nDEEBE DAR EL ALTA DE TRANSPORTE\n");
						}

				break;
			case 8:
						printf("Informes");

				break;
			case 9:
					printf("\n\n\n---EXIT--- \n\n\n ");
					printf("Esta seguro que desea salir? [s/n]: ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
					 continuar = 'n';
					}

				break;

			default :
				printf("ERROR...Vuelva a elegir una opcion\n");

			}


		}while(continuar == 's');

	return 0;
}
