/*
 * menus.h
 *
 *  Created on: 10 oct. 2022
 *      Author: Federico
 */

#ifndef MENUS_H_
#define MENUS_H_




/**
 * \fn int mostrarMenuPrincipal()
 * \brief Muestra el menu principal de opciones
 *
 * \return retorna la opcion
 */
int mostrarMenuPrincipal();



/**
 * \fn int ejecutarMenuAltaTransporte()
 * \brief submenu que muestra el alta del transporte
 *
 * \return retorna la opcion
 */
int ejecutarMenuAltaTransporte();


/**
 * \fn int ejecutarMenuAltaHojaRuta()
 * \brief submenu que muestra el alta de la hoja de ruta
 *
 * \return retorna la opcion
 */
int ejecutarMenuAltaHojaRuta();
/**
 * \fn void darDeAltaTransporte(int*, eTransporte*, int, eTipo*, int)
 * \brief funcion que da de alta un transporte
 *
 * \param flagT si la bandera es igual a 1 doy de alta el transporte
 * \param listaT array de tipo eTransporte
 * \param tamT  tamanio transporte
 * \param listaTipo    array tipo eTipo
 * \param tamTipo    tamanio de tipo
 */
void darDeAltaTransporte(int* flagT,eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo);



/**
 * \fn void darDeAltaHojaRuta(int*, eHojaRuta*, int, eTransporte*, int, eTipo*, int)
 * \brief funcion que da de alta una hoja de ruta
 *
 * \param flagH si la bandera es igual a 1 doy de alta el transporte
 * \param listaH
 * \param tamH
 * \param listaT
 * \param tamT
 * \param listaTipo
 * \param tamTipo
 */
void darDeAltaHojaRuta(int* flagH, eHojaRuta* listaH, int tamH, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo);
/**
 * \fn void darBajaTransporte(int, eTransporte*, int, eTipo*, int)
 * \brief
 *
 * \param flagT
 * \param listaT
 * \param tamT
 * \param listaTipo
 * \param tamTipo
 */
void darBajaTransporte(int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo);





/**
 * \fn int ejecutarMenuListarTransporte()
 * \brief
 *
 * \return
 */
int ejecutarMenuListarTransporte();

/**
 * \fn void listarTransporte(int, eTransporte*, int, eTipo*, int)
 * \brief
 *
 * \param flagT
 * \param listaT
 * \param tamT
 * \param listaTipo
 * \param tamTipo
 */
void listarTransporte(int flagT, eTransporte* listaT, int tamT, eTipo* listaTipo, int tamTipo);


/**
 * \fn int ejecutarMenuListarTipos()
 * \brief
 *
 * \return
 */
int ejecutarMenuListarTipos();




/**
 * \fn void listarTipos(eTipo*, int)
 * \brief
 *
 * \param listaTipo
 * \param tamTipo
 */
void listarTipos( eTipo* listaTipo, int tamTipo);







/**
 * \fn int ejecutarMenuListarHojaRuta()
 * \brief
 *
 * \return
 */
int ejecutarMenuListarHojaRuta();





/**
 * \fn void listarHojaRuta(int, eHojaRuta*, int)
 * \brief
 *
 * \param flagH
 * \param listaH
 * \param tamH
 */
void listarHojaRuta(int flagH,eHojaRuta* listaH, int tamH, eTransporte* listaT, int sizeT);



/**
 * \fn int mostrarMenuInformes()
 * \brief
 *
 * \return
 */
int mostrarMenuInformes();

/**
 * \fn void ejecutarInformes(eTransporte*, int, eTipo*, int, eHojaRuta*, int)
 * \brief
 *
 * \param listaTransporte
 * \param sizeT
 * \param listaTipo
 * \param sizeTipo
 * \param listaH
 * \param sizeH
 */
void ejecutarInformes(eTransporte* listaTransporte,int sizeT, eTipo* listaTipo, int sizeTipo, eHojaRuta* listaH, int sizeH);

#endif /* MENUS_H_ */


















































