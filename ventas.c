#include <stdio.h>
#include <stdlib.h>

#include "ventas.h"

struct Venta {

    int anio;
    int cant;

};

VentaPtr cargarVentaNula() {

    VentaPtr aux = (VentaPtr)malloc( sizeof (Venta) );

    if( aux == NULL ) {
        printf("Error al solicitar memoria.\n");
        exit(1);
    }

    setAnio(aux,-1);
    setCant(aux,-1);

    return aux;

};

void cargarVentasNulas(VentaPtr ventas[] ,int t) {

    for(int i=0; i<t; i++) {
        ventas[i] = cargarVentaNula();
    }

};

void cargarVentasDesdeTxt(VentaPtr ventas[]) {

    FILE * archivo = fopen("ventas.txt", "r");

    if( archivo == NULL ) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    int i=0;

    while( !feof(archivo) ) {

        int a,c;

        fscanf(archivo,"%d,%d\n", &a, &c );

        setAnio(ventas[i],a);
        setCant(ventas[i],c);

        i++;

    }

    fclose(archivo);

};

void mostrarVenta(VentaPtr v) {

    if(getAnio(v) != -1) {
        printf("\n---------------------\n");
        printf("    Anio: %d\n", getAnio(v));
        printf("    Cant: %d", getCant(v));
    }

};

void mostrarVentas(VentaPtr ventas[], int t) {

    for(int i=0; i<t; i++) {
        mostrarVenta(ventas[i]);
    }

    printf("\n---------------------\n");

};

void mostrarVentasDesdeTxt() {

    FILE * archivo = fopen("ventas.txt", "r");

    if( archivo == NULL ) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }


    while( !feof(archivo) ) {

        VentaPtr aux = cargarVentaNula();

        int a,c;

        fscanf(archivo,"%d,%d\n", &a, &c);

        setAnio(aux,a);
        setCant(aux,c);

        mostrarVenta(aux);

        free(aux);

    }

    fclose(archivo);

    printf("\n---------------------\n");

};

void buscarVentaPorAnio(VentaPtr ventas[], int a ,int t) {

    for(int i=0; i<t; i++) {

        if( ventas[i]->anio == a ) {
            printf("\nVenta encontrada anio %d cantidad %d\n", a, getCant(ventas[i]));
            return;
        }

    }

    printf("\nAnio %d no encontrado\n",a);

};

void calcularPromedioVentas(VentaPtr ventas[], int t) {

    int acum = 0;

    for(int i=0; i<t; i++) {

        if( getAnio(ventas[i]) != -1 ){

            acum += getCant(ventas[i]);

        }

    }

    if(acum > 0){
        printf("\nEl promedio de ventas es de: %.2f\n\n", (float)acum / t);
    } else {
        printf("\nNo se pudo calcular el promedio\n\n");
    }
};

VentaPtr ingresarVentaPorTeclado() {

    int a,c;

    VentaPtr aux = cargarVentaNula();

    printf("    Ingresa anio: ");
    scanf("%d",&a);
    setAnio(aux,a);

    printf("    Ingresa cantidad: ");
    scanf("%d",&c);
    setCant(aux,c);

    return aux;
}

void agregarVenta(VentaPtr ventas[], int t) {


    for(int i=0; i<t; i++) {

        if( ventas[i]->anio == -1 ) {
            printf("\n-------------- Agrega una venta --------------\n\n");
            ventas[i] = ingresarVentaPorTeclado();

            return;

        }
    }

    printf("\nNo hay cupo para agregar un estudiante\n");

};

void modificarVenta(VentaPtr ventas[], int t, int a) {

    for(int i=0; i<t; i++) {

        if(getAnio(ventas[i]) == a) {

            free(ventas[i]);
            printf("\n-------------- Modifica la venta con el anio %d --------------\n\n", a);
            ventas[i] = ingresarVentaPorTeclado();

            return;

        }
    }

    printf("\nNo se encontro el anio %d para modificar la venta!\n",a);
};

void eliminarVenta(VentaPtr ventas[], int t, int a) {

    for(int i=0; i<t; i++) {

        if(getAnio(ventas[i]) == a){

            ventas[i] = cargarVentaNula();
            printf("\nAnio %d eliminado con exito\n",a);
            return;

        }

    }

    printf("\nNo se encontro la venta con el anio %d para eliminarlo\n",a);
};

void guardarVentas(VentaPtr ventas[], int t) {

    FILE * archivo = fopen("ventas.txt", "w");

    if( archivo == NULL ) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    for(int i=0; i<t; i++) {

        if(getAnio(ventas[i]) != -1){
            fprintf(archivo,"%d,%d\n",getAnio(ventas[i]) , getCant(ventas[i])  );
        }

    }

    fclose(archivo);

};

void destruirVenta(VentaPtr v) {
    free(v);
};

void destruirVentas(VentaPtr ventas[], int t) {

    for(int i=0; i<t; i++) {
        destruirVenta(ventas[i]);
    }

};

int getAnio(VentaPtr venta) {
    return venta->anio;
};

int getCant(VentaPtr venta) {
    return venta->cant;
};

void setAnio(VentaPtr venta, int a) {
    venta->anio = a;
};

void setCant(VentaPtr venta, int c) {
    venta->cant = c;
};







