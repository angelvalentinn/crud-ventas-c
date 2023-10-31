#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct Venta Venta;

typedef Venta * VentaPtr;


VentaPtr cargarVentaNula();

void cargarVentasNulas(VentaPtr ventas[],int t);

void cargarVentasDesdeTxt(VentaPtr ventas[]);

void mostrarVenta(VentaPtr v);

void mostrarVentas(VentaPtr ventas[], int t);

void mostrarVentasDesdeTxt();

void buscarVentaPorAnio(VentaPtr ventas[], int a ,int t);

void calcularPromedioVentas(VentaPtr ventas[], int t);

VentaPtr ingresarVentaPorTeclado();

void agregarVenta(VentaPtr ventas[], int t);

void modificarVenta(VentaPtr ventas[], int t, int a);

void eliminarVenta(VentaPtr ventas[], int t, int a);

void guardarVentas(VentaPtr ventas[], int t);

void destruirVentas(VentaPtr ventas[], int t);

int getAnio(VentaPtr venta);

int getCant(VentaPtr venta);

void setAnio(VentaPtr venta, int a);

void setCant(VentaPtr venta, int c);

#endif // VENTAS_H_INCLUDED








