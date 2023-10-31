#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"

//Se tiene el archivo ventas.txt, con la estructura:
//1989;120003
//1990;233100
//2019;111022
//Donde se almacenan los años y cantidad de unidades vendidas de algún producto. Se pide cargar
//estos valores en un array de la Struct pertinente. Una vez cargado el array, realizar la búsqueda
//secuencial para encontrar algún año, y mostrar por pantalla el promedio de ventas por año.

int main()
{
    int t = 10; //t tiene q ser mayor o igual a las ventas que hay en el txt

    VentaPtr ventas[t];

    cargarVentasNulas(ventas, t);

    cargarVentasDesdeTxt(ventas);

    //mostrarVentas(ventas, t);

    mostrarVentasDesdeTxt();

    buscarVentaPorAnio(ventas,1978,t);
    buscarVentaPorAnio(ventas,206,t);

    calcularPromedioVentas(ventas, t);

    agregarVenta(ventas, t); //add por teclado

    modificarVenta(ventas, t, 2300); //update por teclado

    //eliminarVenta(ventas, t, 1990); //delete

    guardarVentas(ventas, t); //Actualiza los  add, update, delete de las ventas al txt

    destruirVentas(ventas, t);

    return 0;
}






