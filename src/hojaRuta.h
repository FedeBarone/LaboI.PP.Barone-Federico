/*
 * hojaRuta.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Federico Barone 1ero J
 */

#ifndef HOJARUTA_H_
#define HOJARUTA_H_



typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;



typedef struct
{
	int idHoja;
	int transporteId;
	float precioViaje;
	float kmsTotales;
	int isEmpty;
	eFecha fecha;

}eHojaRuta;

/**
 * \fn int inicializarHojaRuta(eHojaRuta*, int)
 * \brief Busco que el isEmpty sea verdadero para poder inicializar el array de struct sin basura
 *
 * \param listaH
 * \param sizeH
 * \return retorna 0 si salio todo bien, -1 si salio todo mal.
 */
int inicializarHojaRuta(eHojaRuta* listaH, int sizeH);



/**
 * \fn int buscarIndiceLibreHojaRuta(eHojaRuta*, int)
 * \brief Busca un indice libre, si lo encuentra devuelve el valor que tiene
 *
 * \param listaH
 * \param sizeH
 * \return  retorna el valor del indice, si no lo encuentra retorno -1
 */
int buscarIndiceLibreHojaRuta(eHojaRuta* listaH, int sizeH);



/**
 * \fn int altaHojaRuta(int, eHojaRuta*, int, eTransporte*, int, eTipo*, int)
 * \brief
 *
 * \param idAux
 * \param listaH
 * \param tamH
 * \param listaT
 * \param tamT
 * \param listaTipo
 * \param tamTipo
 * \return
 */
int altaHojaRuta(eHojaRuta* listaH, int tamH, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo);



/**
 * \fn void mostrarHojaRuta(eHojaRuta)
 * \brief
 *
 * \param hojaRuta
 */
void mostrarHojaRuta(eHojaRuta hojaRuta , eTransporte* listaT, int sizeT);


/**
 * \fn void mostrarHojasRuta(eHojaRuta*, int)
 * \brief
 *
 * \param listaH
 * \param sizeH
 */
void mostrarHojasRuta(eHojaRuta* listaH, int sizeH,eTransporte* listaT, int sizeT);

#endif  /*HOJARUTA_H_*/

































































