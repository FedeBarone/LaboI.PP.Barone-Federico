/*
 * transporte.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int idTransporte;
	char descripcion[50];
	float pesoCarga;
	int cantidadBultos;
	int tipoId;//fk
	int isEmpty;

}eTransporte;

/**
 * \fn int inicializarHojaRuta(eTransporte*, int)
 * \brief Busco que el isEmpty sea verdadero para poder inicializar el array de struct sin basura
 *
 * \param listaH
 * \param sizeH
 * \return retorna 0 si salio todo bien, -1 si salio todo mal.
 */
int inicializarTransporte(eTransporte* listaT, int size);



/**
 * \fn int buscarIndiceLibreHojaRuta(eTransporte*, int)
 * \brief Busca un indice libre, si lo encuentra devuelve el valor que tiene
 *
 * \param listaH
 * \param sizeH
 * \return  retorna el valor del indice, si no lo encuentra retorno -1
 */
int buscarIndiceLibreT(eTransporte* listaT, int size);



/**
 * \fn int buscarTransportePorId(eTransporte*, int, int)
 * \brief  busca que el id coincida y este ocupado para tomar el indice
 *
 * \param listaT
 * \param size
 * \param idT
 * \return
 */
int buscarTransportePorId(eTransporte* listaT, int size, int idT);



/**
 * \fn void mostrarTransporte(eTransporte, eTipo*, int)
 * \brief
 *
 * \param transporte
 * \param listaTipo
 * \param sizeTipo
 */
void mostrarTransporte(eTransporte transporte, eTipo* listaTipo, int sizeTipo);



/**
 * \fn void mostrarTransportes(eTransporte*, int, eTipo*, int)
 * \brief
 *
 * \param listaT
 * \param tamT
 * \param listaTipo
 * \param sizeTipo
 */
void mostrarTransportes(eTransporte* listaT, int tamT, eTipo* listaTipo, int sizeTipo);



/**
 * \fn int ordenarTransportes(eTransporte*, int, int)
 * \brief
 *
 * \param listaT
 * \param tamT
 * \param ordenamiento
 * \return
 */
int ordenarTransportes(eTransporte* listaT, int tamT);



#endif  /*TRANSPORTE_H_*/




















