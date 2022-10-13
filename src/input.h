/*
 * input.h
 *
 *  Created on: 9 oct. 2022
 *      Author: Federico
 */

#ifndef INPUT_H_
#define INPUT_H_


/**
 * \fn int utn_getCadena(char*, int, int, char*, char*)
 * \brief  Obtiene una cadea
 *
 * \param pAux
 * \param limit
 * \param retry
 * \param msg
 * \param msgError
 * \return
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);


/**
 * \fn int getCadena(char*, int)
 * \brief
 *
 * \param pAux
 * \param limit
 * \return
 */
int getCadena(char* pAux, int limit);


/**
 * \fn int isChar(char[])
 * \brief
 *
 * \param str
 * \return
 */
int isChar(char str[]);



/**
 * \fn int utn_getFlotante(float*, int, char*, char*, float, float)
 * \brief   verifica que el numero sea flotante
 *
 * \param pFloat
 * \param retry
 * \param msg
 * \param msgError
 * \param min
 * \param max
 * \return
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int getFloat(float*pAux);

int isFloat(char* pAux);


/**
 * \fn int utn_getEntero(int*, int, char*, char*, int, int)
 * \brief  Verifica que el numero sea entero
 *
 * \param pEntero
 * \param retry
 * \param msg
 * \param msgError
 * \param min
 * \param max
 * \return
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int getInt(int* pAux);

int isInt(char *pAux);

int strLwr(char* str);

int normalizeStr(char* str);


#endif /* UTN_H_ */

