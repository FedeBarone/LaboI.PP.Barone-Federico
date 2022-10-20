/*
 * informes.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Federico
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/**
 * \fn void informarTransportesPorTipo(eTransporte*, int, eTipo*, int)
 * \brief muestra los transportes de un tipo seleccionado
 *
 * \param listaTransporte pArray de tipo eTransporte
 * \param sizeT tamanio del array lista transporte
 * \param listaTipo pArray de tipo eTipo
 * \param sizeTipo tamanio del array listaTipo
 */
void mostrarTransportesTipoSeleccionado(eTransporte* listaTransporte, int sizeT, eTipo* listaTipo, int sizeTipo);




/**
 * \fn void informarHojasRutaFechaSeleccionada(eHojaRuta*, int)
 * \brief Muestra las hojas de ruta efectuadas en una fecha seleccionada
 *
 * \param listaHojaRuta pArray de tipo eHojaRuta
 * \param sizeH tamanio del array listaHojaRuta
 */
void mostrarHojasRutaFechaSeleccionada(eHojaRuta* listaHojaRuta, int sizeH,eTransporte* listaT, int sizeT);

/**
 * \fn void importeTotalTransporteSeleccionado(eHojaRuta*, int, eTransporte*, int, eTipo*, int)
 * \brief informa el total de la suma del precio de viaje de un transporte seleccionado
 *
 * \param listaH
 * \param sizeH
 * \param listaT
 * \param sizeT
 * \param listaTipo
 * \param sizeTipo
 */
void informarImporteTotalTransporteSeleccionado(eHojaRuta* listaH, int sizeH, eTransporte* listaT, int sizeT, eTipo* listaTipo, int sizeTipo);



/**
 * \fn void importeTotalTipoFechaSeleccionada(eHojaRuta*, int, eTransporte*, int, eTipo*, int)
 * \brief informa el total de la suma del precio de viaje de un tipo en una fecha seleccionada
 *
 * \param listaH
 * \param sizeH
 * \param listaT
 * \param sizeT
 * \param listaTipo
 * \param sizeTipo
 */
void informarImporteTotalTipoFechaSeleccionada(eHojaRuta* listaH, int sizeH, eTransporte* listaT, int sizeT, eTipo* listaTipo, int sizeTipo);

#endif /* INFORMES_H_ */




