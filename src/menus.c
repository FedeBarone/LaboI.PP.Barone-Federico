/*
 * menus.c
 *
 *  Created on: 10 oct. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"
#include "menus.h"
#include "informes.h"
#define VACIO 1
#define OCUPADO 0

int mostrarMenuPrincipal()
{
	int opcion;

		printf("***** MENU PRINCIPAL *****\n\n");
		printf("1- [ALTA TRANSPORTE]\n");
		printf("2- [MODIFICAR TRANSPORTE]\n");
		printf("3- [BAJA TRANSPORTE]\n");
		printf("4- [LISTAR TRANSPORTE]\n");
		printf("5- [LISTAR TIPOS]\n");
		printf("6- [ALTA HOJA DE RUTA]\n");
		printf("7- [LISTAR HOJA DE RUTA]\n");
		printf("8- [INFORMES]\n");
		printf("9- [SALIR]\n");

	utn_getEntero(&opcion, 5," \nIngrese una opcion ","Error, Esa opcion no existe", 1, 9);

	return opcion;
}


int ejecutarMenuAltaTransporte()
{
	int opcion;

	utn_getEntero(&opcion, 5," ALTA TRANSPORTE\n\n1-[TRANSPORTE]\n2-[SALIR]\n", "ERROR...\n", 1, 2);

	return opcion;
}

int ejecutarMenuAltaHojaRuta()
{
	int opcion;

	utn_getEntero(&opcion, 5," ALTA HOJA DE RUTA\n\n1-[HOJA DE RUTA]\n2-[SALIR]\n", "ERROR...\n", 1, 2);

	return opcion;
}




void darDeAltaTransporte(int* flagT,eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{
	char continuar = 's';
	char confimar;




			if(flagT != NULL && listaT != NULL && tamT >0 && listaTipo != NULL && tamTipo> 0)
			{
				do
				{
					switch(ejecutarMenuAltaTransporte())
					{

							case 1:

									if(altaTransporte( listaT, tamT, listaTipo,tamTipo) == 1)
									{
										*flagT = 1;

									}

								break;

							case 2:
										printf("---EXIT---");
										printf("Esta seguro que desea salir? [s/n]");
										fflush(stdin);
										scanf("%c", &confimar);

										if(confimar == 's')
										{
											continuar = 'n';
										}

								break;

							default :

									printf("Error...elija una opcion valida\n");

								break;

					}

				}while(continuar == 's');
			}

}



void darDeAltaHojaRuta(int* flagH, eHojaRuta* listaH, int tamH, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{

	char continuar = 's';
	char confimar;

			if(flagH!= NULL  && listaH != NULL && tamH >0 && listaT != NULL && tamT >0 && listaTipo != NULL && tamTipo> 0)
			{
				do
				{
					switch(ejecutarMenuAltaHojaRuta())
					{
							case 1:

									if(altaHojaRuta(listaH, tamH, listaT, tamT, listaTipo, tamTipo) == 1)
								    {

											*flagH = 1;

									}

								break;

							case 2:

									printf("---EXIT---");
									printf("Esta seguro que desea salir? [s/n]");
									fflush(stdin);
									scanf("%c", &confimar);

									if(confimar == 's')
									{
										continuar = 'n';
									}

								break;

							default :

									printf("Error...elija una opcion valida\n");

								break;
					}

				}while(continuar == 's');
			}

}




void darBajaTransporte(int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{

	int idTransporte ;

		if(listaT != NULL && tamT > 0 && listaTipo != NULL && tamTipo > 0)
		{
			if(flagT == 1)
			{
				mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
				utn_getEntero(&idTransporte, 4, "Ingrese el ID del transporte a eliminar ", "ERROR, ese ID no existe\n", 0, 20);

				if(bajaTransporte(idTransporte, flagT,listaT, tamT, listaTipo,tamTipo) == 1)
				{
					printf("***BAJA EXITOSA***\n");
				}

			}
			else
			{
				printf("No hay transporte para eliminar\n");
			}

		}
}



int ejecutarMenuListarTransporte()
{
	int opcion;

	utn_getEntero(&opcion, 4," ***Listar Transporte***\n\n1-[transporte]\n2-[SALIR]", "ERROR...\n", 1, 2);


	return opcion;
}



void listarTransporte(int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{


	char continuar = 's';
	char confirmar;

			do
			{
				switch(ejecutarMenuListarTransporte())
				{

				  case 1:

					  	 	 if(flagT == 1)
					  	 	 {
					  	 		 ordenarTransportes(listaT, tamT);
					  	 		 mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
					  	 	 }
					  	 	 else
					  	 	 {
					  	 		 printf("No hay transportes cargados");
					  	 	 }

					  break;

				  case 2:
								printf("\n---EXIT---\n\n ");
								printf("Confirma salida? s/n: ");
								fflush(stdin);
								scanf("%c", &confirmar);
								if(confirmar == 's')
								{
									continuar = 'n';
								}

					  break;

				  default :
					  printf("Se equivoco");
					  break;

				}

			}while(continuar == 's');

}



int ejecutarMenuListarTipos()
{
	int opcion;

	utn_getEntero(&opcion, 4," ***Listar Tipos***\n\n1-[TIPOS]\n2-[SALIR]", "ERROR...\n", 1, 2);


	return opcion;
}



void listarTipos( eTipo* listaTipo, int tamTipo)
{
	char continuar = 's';
	char confirmar;

			do
			{
				switch(ejecutarMenuListarTipos())
				{

				  case 1:
					  	 mostrarTipos(listaTipo, tamTipo);

					  break;

				  case 2:
								printf("\n---EXIT---\n\n ");
								printf("Confirma salida? s/n: ");
								fflush(stdin);
								scanf("%c", &confirmar);
								if(confirmar == 's')
								{
									continuar = 'n';
								}

					  break;

				  default :
					  printf("Se equivoco");
					  break;

				}

			}while(continuar == 's');

}



int ejecutarMenuListarHojaRuta()
{
	int opcion;

	utn_getEntero(&opcion, 4," ***Listar Hoja De Ruta***\n\n1-[transporte]\n2-[SALIR]", "ERROR...\n", 1, 2);


	return opcion;
}



void listarHojaRuta(int flagH,eHojaRuta* listaH, int tamH, eTransporte* listaT, int sizeT)
{
	char continuar = 's';
	char confirmar;

			do
			{
				switch(ejecutarMenuListarHojaRuta())
				{
				  case 1:
					  	  	  if(flagH == 1)
					  	  	  {
					  	  		mostrarHojasRuta(listaH, tamH, listaT, sizeT);

					  	  	  }
					  	  	  else
					  	  	  {
					  	  		  printf("No hay hojas de ruta cargadas");
					  	  	  }

					  break;
				  case 2:
								printf("\n---EXIT---\n\n ");
								printf("Confirma salida? s/n: ");
								fflush(stdin);
								scanf("%c", &confirmar);
								if(confirmar == 's')
								{
									continuar = 'n';
								}

					  break;

				  default :
					  printf("Se equivoco");
					  break;

				}

			}while(continuar == 's');

}




int mostrarMenuInformes()
{
	int opcion;

		printf("***** INFORMES *****\n\n");
		printf("1- [Mostrar transportes de un tipo seleccionado]\n");
		printf("2- [Mostrar todas las hojas de ruta efectuadas en una fecha seleccionada]\n");
		printf("3- [Informar importe total de las hojas de ruta realizadas en un transporte seleccionado]\n");
		printf("4- [Informar importe total de todas las hojas de ruta de un tipo en una fecha seleccionada]\n");
		printf("5- [SALIR]\n");

		utn_getEntero(&opcion, 5," \nIngrese una opcion ","Error, Esa opcion no existe", 1, 5);

	return opcion;
}



void ejecutarInformes(eTransporte* listaTransporte,int sizeT, eTipo* listaTipo, int sizeTipo, eHojaRuta* listaH, int sizeH)
{
	char seguir = 's';
	char confirmar;

	do{
		switch(mostrarMenuInformes())
		{
			case 1:
				mostrarTransportesTipoSeleccionado(listaTransporte,sizeT, listaTipo, sizeTipo);
				break;
			case 2:
				mostrarHojasRutaFechaSeleccionada(listaH, sizeH, listaTransporte,sizeT);
				break;
			case 3:
				informarImporteTotalTransporteSeleccionado(listaH, sizeH, listaTransporte, sizeT, listaTipo,  sizeTipo);
				break;
			case 4:
				informarImporteTotalTipoFechaSeleccionada(listaH, sizeH, listaTransporte, sizeT, listaTipo, sizeTipo);
				break;
			case 5:
				printf("Confirma salida? s/n: ");
				fflush(stdin);
				scanf("%c", &confirmar);
				if(confirmar == 's')
				{
					seguir = 'n';
				}
				break;
			default:
				printf("Ingrese una opcion disponible\n\n");
		}

	}while(seguir == 's');

}














































































































