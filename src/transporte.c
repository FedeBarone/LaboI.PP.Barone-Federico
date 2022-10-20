/*
 * transporte.c
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
#define VACIO 1
#define OCUPADO 0
#define BAJA -1



static int eTransporte_ObtenerID(void);
static int eTransporte_ObtenerID(void)
{
	static int idTransporteAuto = 0;
	return idTransporteAuto++;
}



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
								utn_getCadena(listaT[indice].descripcion, 30, 5, "\nIngrese descripcion[Metales-Maderas-Suministros-Bioquimicos]: ", "Error...\n");

									mostrarTipos(listaTipo, tamTipo);

									if(utn_getEntero(&listaT[indice].tipoId, 3, "Ingrese id tipo: ", "El id ingresado no es valido.\n", 1000, 1003) == 0)
									{
										listaT[indice].idTransporte = eTransporte_ObtenerID();
										listaT[indice].isEmpty = 0; //lleno el lugar
										 mostrarTransportes(listaT, tamT, listaTipo, tamTipo);
										retorno = 1;
									}


							}


					}


	return retorno;
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


//MOSTRAR
void mostrarTransporte(eTransporte transporte, eTipo* listaTipo, int sizeTipo)
{
	char descripcionTipo[30];

	cargarDescripcionTipo(descripcionTipo, transporte.tipoId, listaTipo, sizeTipo);

	printf("|%-20d|%-25s|%-25d|%-25.2f|%-18s|\n", transporte.idTransporte, descripcionTipo, transporte.cantidadBultos, transporte.pesoCarga, transporte.descripcion);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

}



void mostrarTransportes(eTransporte* listaT, int tamT, eTipo* listaTipo, int sizeTipo)
{
	int anchoColumnaIDT = -20;
	int anchoColumnaTipo = -25;
	int anchoColumnaCantidad = -25;
	int anchoColumnaCarga = -25;
	int anchoColumnaDesc = -18;

	  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");
	  printf("|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaIDT, " IDT", anchoColumnaTipo,
	         " Tipo", anchoColumnaCantidad, "Cantidad", anchoColumnaCarga, "Carga", anchoColumnaDesc, "Descricpion");
	  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+\n");

		if(listaT != NULL && tamT > 0 && listaTipo != NULL && sizeTipo > 0)
		{
			for(int i = 0; i < tamT; i++)
			{
					if((*(listaT+i)).isEmpty == 0)
					{
						mostrarTransporte((*(listaT+i)), listaTipo, sizeTipo);
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



int cargarDescripcionTransporte(char* descripcion, int idTransporteAux, eTransporte* listaT, int sizeT)
{
	int retorno = 0;

	if(descripcion != NULL && listaT!=NULL && sizeT > 0)
	{

		for(int i = 0; i < sizeT; i++)
		{
			if((*(listaT+i)).idTransporte == idTransporteAux)
			{
				strcpy(descripcion, (*(listaT+i)).descripcion);
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}















































































