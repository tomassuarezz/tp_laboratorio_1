/*
 * funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: tomil
 */

#include <stdio.h>
#include <stdlib.h>

int funcCalcAerolineas(int precioLatam, int precioAerolineas, int kilometros, float* pCredito, float* pDebito, float* pBitcoin, float* pUnitario, float* pDiferenciaPrecio) {

	int retorno;

	if(pCredito != NULL && pDebito != NULL  && pBitcoin != NULL && pUnitario != NULL) {
		*pDebito = (float) precioAerolineas - precioAerolineas * 10 / 100;
		*pCredito = (float) precioAerolineas + precioAerolineas * 25 / 100;
		*pBitcoin = (float) precioAerolineas / 4606954.55;
		*pUnitario = (float) precioAerolineas / kilometros;



		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}

int funcCalcLatam(int precioLatam, int precioAerolineas, int kilometros, float* pCredito, float* pDebito, float* pBitcoin, float* pUnitario, float* pDiferencia) {

	int retorno;

	if(pCredito != NULL && pDebito != NULL  && pBitcoin != NULL && pUnitario != NULL && pDiferencia != NULL) {
		*pDebito = (float) precioLatam - precioLatam * 10 / 100;
		*pCredito = (float) precioLatam + precioLatam * 25 / 100;
		*pBitcoin = (float) precioLatam / 4606954.55;
		*pUnitario = (float) precioLatam / kilometros;


	if(precioLatam > precioAerolineas) {
			*pDiferencia = precioLatam - precioAerolineas;
	} else {
			*pDiferencia = precioAerolineas - precioLatam;
	}

		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}
