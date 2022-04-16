/*
 ============================================================================
 Name        : TP_1.c
 Author      : Tomas
 Version     :
 Copyright   : MIT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);

	int km = 0;
	int opciones;

	int precioAerolineas = 0;
	int precioLatam = 0;

	int contador = 0;

	float pCreditoLatam;
	float pDebitoLatam;
	float pBitcoinLatam;
	float pUnitarioLatam;
	float pDiferenciaLatam;

	float pCreditoAerolineas;
	float pDebitoAerolineas;
	float pBitcoinAerolineas;
	float pUnitarioAerolineas;


	do {

		printf("AGENCIA DE VIAJES\n 1- Ingresar kilómetros \n 2- Ingresar precio de cada vuelo \n 3- Calcular los costos \n 4- Informar resultados \n 5- Carga forzada de datos \n 6- Salir \n");
		scanf("%d", &opciones);

		switch(opciones) {
			case 1:
				printf("Ingrese los kilometros recorridos");
				scanf("%d", &km);

				while(km <= 0) {
					printf("Error. Ingrese los kilometros recorridos");
					scanf("%d", &km);
				}
			break;
			case 2:
				printf("Ingrese precio del vuelo de Aerolineas");
				scanf("%d", &precioAerolineas);
				while (precioAerolineas <= 0) {
					printf("Error. Ingrese correctamente el precio");
					scanf("%d", &precioAerolineas);
				}

				printf("Ingrese precio del vuelo de Latam");
				scanf("%d", &precioLatam);
				while (precioLatam <= 0) {
					printf("Error. Ingrese correctamente el precio");
					scanf("%d", &precioLatam);
				}

			break;
			case 3:
				if (precioAerolineas > 0 && precioLatam > 0 && km > 0) {

					funcCalcAerolineas(precioLatam, precioAerolineas, km, &pCreditoAerolineas, &pDebitoAerolineas, &pBitcoinAerolineas, &pUnitarioAerolineas);



					funcCalcLatam(precioLatam, precioAerolineas, km, &pCreditoLatam, &pDebitoLatam, &pBitcoinLatam, &pUnitarioLatam, &pDiferenciaLatam);


					printf("Se realizaron los calculos correctamente...\n");

					contador = 1;

				} else {
					printf("\n Error. Falta cargar algun dato. Intente nuevamente.\n");
				}
			break;
			case 4:

				if (contador == 1) {


				printf("\nPrecios Aerolineas: \n"
						"\nPrecio con tarjeta de credito:$ %.2f"
						"\nPrecio con tarjeta de debito:$ %.2f"
						"\nPrecio con bitcoin:$ %.2f"
						"\nEl precio unitario es:$ %.2f"
						"\n\nPrecios Latam:"
						"\nPrecio con tarjeta de credito:$ %.2f"
						"\nPrecio con tarjeta de debito:$ %.2f"
						"\nPrecio con bitcoin:$ %.2f"
						"\nEl precio unitario es:$ %.2f"
						"\nLa diferencia de precio es de:$ %.2f"
						,pCreditoAerolineas, pDebitoAerolineas, pBitcoinAerolineas, pUnitarioAerolineas, pCreditoLatam, pDebitoLatam, pBitcoinLatam, pUnitarioLatam, pDiferenciaLatam);
				} else {
					printf("\nNo se realizo ningun calculo.");
				}
			break;
			case 5:
				km = 7090;
				precioLatam = 159339;
				precioAerolineas = 162965;

				funcCalcAerolineas(precioLatam, precioAerolineas, km, &pCreditoAerolineas, &pDebitoAerolineas, &pBitcoinAerolineas, &pUnitarioAerolineas);

				funcCalcLatam(precioLatam, precioAerolineas, km, &pCreditoLatam, &pDebitoLatam, &pBitcoinLatam, &pUnitarioLatam, &pDiferenciaLatam);

				printf("\nPrecios Aerolineas: \n"
				"\nPrecio con tarjeta de credito:$ %.2f"
				"\nPrecio con tarjeta de debito:$ %.2f"
				"\nPrecio con bitcoin:$ %.2f"
				"\nEl precio unitario es:$ %.2f"
				"\n\nPrecios Latam:"
				"\nPrecio con tarjeta de credito:$ %.2f"
				"\nPrecio con tarjeta de debito:$ %.2f"
				"\nPrecio con bitcoin:$ %.2f"
				"\nEl precio unitario es:$ %.2f"
				"\nLa diferencia de precio es de:$ %.2f\n"
				,pCreditoAerolineas, pDebitoAerolineas, pBitcoinAerolineas, pUnitarioAerolineas, pCreditoLatam, pDebitoLatam, pBitcoinLatam, pUnitarioLatam, pDiferenciaLatam);
			break;
		}


	}while (opciones != 6);
	return EXIT_SUCCESS;



}
