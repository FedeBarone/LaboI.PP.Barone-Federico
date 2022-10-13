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
#include "fecha.h"
#include "tipo.h"
#include "transporte.h"
#include "hojaRuta.h"
#include "input.h"
#include "menus.h"
#define VACIO 1
#define OCUPADO 0
#define BAJA -1

static int eTransporte_ObtenerID(void);
static int eTransporte_ObtenerID(void)
{
	static int idTransporteAuto = 0;
	return idTransporteAuto++;
}



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
										//idTransporte++;
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

	int idHojaRuta = 20000;

			if(flagH!= NULL  && listaH != NULL && tamH >0 && listaT != NULL && tamT >0 && listaTipo != NULL && tamTipo> 0)
			{
				do
				{
					switch(ejecutarMenuAltaHojaRuta())
					{
							case 1:

									if(altaHojaRuta(idHojaRuta,listaH, tamH, listaT, tamT, listaTipo, tamTipo) == 1)
								    {
											idHojaRuta++;

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







int modificarTransporte(int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{
	int retorno = -1;
	int idTransporteAux;
	int indice;
	int opcion;
	char continuar;
	char confirmar;
	float pesoCargaModificado;
	int cantidadBultosModificado;

	printf("---MODIFICAR---\n");

	if(flagT == 1 && listaT != NULL && tamT > 0 && listaTipo != NULL && tamTipo > 0)
	{
		mostrarTransportes(listaT, tamT, listaTipo, tamTipo);

		if(listaT != NULL && tamT > 0 && utn_getEntero(&idTransporteAux, 4, "\nIngrese el ID del transporte que va a modificar", "ERROR...Ese ID no existe\n", 0, 20)==0)
		{
			indice = buscarTransportePorId(listaT, tamT, idTransporteAux);

			if(indice == -1)
			{
				printf("ERROR...Ese ID no existe\n");
			}
			else
			{
				printf("El ID %d pertenece al siguiente transporte:\n", idTransporteAux);
				printf("ID     Tipo        Cantidad      Precio\n\n");
				mostrarTransporte(listaT[indice], listaTipo, tamTipo);
				printf("Desea modificar? [s/n] ");
				fflush(stdin);
				scanf("%c", &confirmar);

				if(confirmar == 's')
				{
					do
					{

						printf("1-[Modificar pesoCarga\n");
						printf("2-[Modificar cantidadBultos\n");


						if(utn_getEntero(&opcion, 4, "Eliga la opcion que quiere modificar ", "ERROR...", 1, 2) == 0)
						{
							switch(opcion)
							{
								case 1:

									if(utn_getFlotante(&pesoCargaModificado, 3, "Eliga el nuevo peso [250-2500] ", "ERROR...No eligio una opcion valida", 250, 2500) == 0)
									{
										listaT[indice].pesoCarga = pesoCargaModificado;
										retorno = 0;
									}

									break;
								case 2:

									if(utn_getEntero(&cantidadBultosModificado, 3, "Eliga el nuevo peso [250-2500] ", "ERROR...No eligio una opcion valida", 250, 2500) == 0)
									{
										listaT[indice].cantidadBultos = cantidadBultosModificado;
										retorno = 0;
									}

									break;

								default :
									printf("No es una opcion valida.\n\n");
									break;

							}

							if(retorno == 0)
							{
								printf("se han modificado los datos correctamente\n");
								printf("ID        Tipo        cantidad      Precio\n\n");
								mostrarTransporte(listaT[indice], listaTipo, tamTipo);
							}
							printf("Desea seguir modificando? s/n: ");
							fflush(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuar = 'n';
							}
						}

					}while(continuar == 's');
				}
				else
				{
					if(confirmar == 'n')
					{
						printf("No se han registrado modificaciones.\n");
					}
				}

			}
		}
	}
	else
	{
		printf("No hay que modificar.\n");
	}

 return retorno;

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
					  	 		 //Ascendente o descendente
					  	 		 //utn_getEntero(&ordenamiento,3, "Ascendente 1, Descendente 0 ", "Error, ese criterio no existe\n", 0, 1);
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



void listarHojaRuta(int flagH,eHojaRuta* listaH, int tamH)
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
					  	  		 mostrarHojasRuta(listaH, tamH);



					  	  	  }
					  	  	  else
					  	  	  {
					  	  		  printf("No hay hojas de ruta cargadas");
					  	  	  }


					  break;
				  case 2:
								//salir
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



int altaTransporte( eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{
	int retorno = 0;//no pudo dar de alta
	int indice = buscarIndiceLibreT(listaT, tamT);


					if(listaT != NULL && tamT > 0 && listaTipo != NULL && tamTipo > 0)
					{
							printf("---ALTA TRANSPORTE---\n");
							if( indice < 0)
							{
								printf("Completo\n");
							}
							else

							{
								utn_getEntero(&listaT[indice].cantidadBultos, 3, "\nIngrese cantidad bultos:  [100-50000] ", "Error...\n", 100, 50000);
								utn_getFlotante(&listaT[indice].pesoCarga, 5, "\nIngrese el peso de la carga: [7000Kg-25000Kg] ", "ERROR\n", 7000, 25000);


									printf("\nIngrese descripcion: ");
									fflush(stdin);
									gets(listaT[indice].descripcion);

									mostrarTipos(listaTipo, tamTipo);

									if(utn_getEntero(&listaT[indice].tipoId, 3, "Ingrese id tipo: ", "El id ingresado no es valido.\n", 1000, 1003) == 0)
									{
										//listaT[indice].idTransporte = idAux;
										listaT[indice].idTransporte = eTransporte_ObtenerID();
										listaT[indice].isEmpty = 0; //lleno el lugar
										 mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
										retorno = 1;
									}


							}


					}


	return retorno;
}





int altaHojaRuta(int idAux, eHojaRuta* listaH, int tamH, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
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
					//printf("Ingrese dia ");
					//fflush(stdin);
					if(utn_getEntero(&listaH[indice].fecha.dia, 4, "Ingrese dia" , "error...", 1, 31) == 0)
					{
						if(utn_getEntero(&listaH[indice].fecha.mes, 4, "Ingrese mes" , "error...", 1, 12)== 0)
						{
							utn_getEntero(&listaH[indice].fecha.anio, 4, "Ingrese anio" , "error...", 2022, 3022);
						}
					}

					utn_getEntero(&listaH[indice].precioViaje, 4, "Ingrese el precio del viaje: ", "ERROR...\n", 200, 100000);
					utn_getFlotante(&listaH[indice].kmsTotales, 4, "Ingrese los kms totales: ", "ERROR...\n", 80, 8500);
					mostrarTransportes(listaT, tamT, listaTipo, tamTipo);

					if(utn_getEntero(&idAuxTransporte,4, "Ingrese ID de transporte", "Error",0,20) == 0)
						 mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
					{
						if(buscarTransportePorId(listaT, tamT, idAuxTransporte) > -1)
						{
							listaH[indice].transporteId = idAuxTransporte;
							listaH[indice].idHoja = idAux;
							listaH[indice].isEmpty = 0; //lleno el lugar
							retorno = 1;
							 mostrarHojasRuta(listaH, tamH);
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


int bajaTransporte(int idTransporteAux, int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo)
{
	int retorno = 0;
	int indice;
	char eliminarTransporte;


				if(flagT == 1)
				{
					indice = buscarTransportePorId(listaT, tamT, idTransporteAux);

					if(indice > -1)
					{
						mostrarTransporte(listaT[indice], listaTipo, tamTipo);
						printf("Eliminar? s/n: ");
						scanf("%c", &eliminarTransporte);
						if(eliminarTransporte == 's')
						{
								listaT[indice].isEmpty = BAJA;
								retorno = 1;
						}
						else
						{
								printf("No se han realizado cambios.\n");
						}
					}
					else
					{
						printf("No existe un transporte con ese id.\n");
					}
				}
				else
				{
					printf("No hay transportes cargados\n");
				}

	return retorno;

}
















































































































