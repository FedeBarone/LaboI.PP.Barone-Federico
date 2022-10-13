/*
 * tipo.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int idTipo;//pk
	char descripcion[30];

}eTipo;

/**
 * \fn int cargarDescripcionTipo(char*, int, eTipo*, int)
 * \brief
 *
 * \param descripcion
 * \param idTipoAux
 * \param tipos
 * \param tamT
 * \return
 */
int cargarDescripcionTipo(char* descripcion, int idTipoAux, eTipo* tipos, int tamT);



/**
 * \fn int mostrarTipos(eTipo*, int)
 * \brief
 *
 * \param tipos
 * \param tamT
 * \return
 */
int mostrarTipos(eTipo* tipos, int tamT);


#endif  /*TIPO_H_*/
































