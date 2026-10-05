#include <stdio.h>
 
int main (int argc, char *argv[]) {
    char ID[10], nombre[20];
    int stock = 0, numVentas = 0, numReabastecer = 0;
    float precio = 0.0, ganancias = 0.0, total = 0.0, descuento = 0.0;
    int productoRegistrado = 0; 
    int opc, opc2;
    do {
        printf("\n SELECCIONE UNA OPCION: \n");
        printf("1.Registrar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion producto\n");
        printf("5.Mostrar ganancias\n");
        printf("6.Salir\n");
        printf(">> ");
        if (scanf("%d", &opc) != 1) {
            printf("Error: Entrada invalida. Por favor ingrese un numero.\n");
            while (getchar() != '\n'); 
            opc = 0; 
        }
        switch (opc)
        {
        case 1:
            if (productoRegistrado == 1) {
            printf("Aviso: Ya existe un producto registrado. Sus datos seran reemplazados.\n");
            }
            printf(" Registrar Producto \n");
            printf("ID: ");
            scanf("%s", ID);
            printf("Nombre: ");
            scanf("%s", nombre);
            printf("Stock inicial: ");
            while (scanf("%d", &stock) != 1 || stock < 0) {
                printf("Error: Ingrese un numero valido y positivo para el stock: ");
                while (getchar() != '\n');
            }
            printf("Precio unitario: ");
            while (scanf("%f", &precio) != 1 || precio < 0) {
                printf("Error: Ingrese un numero valido y positivo para el precio: ");
                while (getchar() != '\n');
            }
            productoRegistrado = 1;
            printf("Producto registrado exitosamente.\n");
            break;
        case 2:
            if (productoRegistrado == 0) {
                printf("Error: Primero debe registrar el producto (Opcion 1).\n");
                break;
            }
            printf("--- Vender Producto ---\n");
            printf("Producto actual: %s (Stock: %d | Precio: $%.2f)\n", nombre, stock, precio);
            printf("Ingrese las unidades que desea vender: ");
            while (scanf("%d", &numVentas) != 1 || numVentas < 0) {
                printf("Error: Ingrese una cantidad numerica valida: ");
                while (getchar() != '\n');
            }
            if (numVentas > stock){
                printf("Error: No se puede realizar la venta, no existe suficiente stock.\n");
                break;
            }
            printf("Ingrese el porcentaje de descuento a aplicar (0 a 100): ");
            while (scanf("%f", &descuento) != 1 || descuento < 0 || descuento > 100) {
                printf("Error: Ingrese un porcentaje de descuento valido (0-100): ");
                while (getchar() != '\n');
            }
            stock -= numVentas;
            float precioConDescuento = precio - (precio * (descuento / 100.0));
            total = numVentas * precioConDescuento;
            ganancias += total;
            printf("\nDetalle de venta:\n");
            printf("Unidades:\t\t%d\n", numVentas);
            printf("Precio original:\t$%.2f\n", precio);
            printf("Descuento:\t\t%.2f%%\n", descuento);
            printf("Total a pagar:\t\t$%.2f\n", total);
            printf("El nuevo stock es:\t%d\n", stock);
            break;
        case 3:
            if (productoRegistrado == 0) {
                printf("Error: Primero debe registrar el producto (Opcion 1).\n");
                break;
            }
            printf("--- Reabastecer Producto ---\n");
            printf("Producto actual: %s (Stock actual: %d)\n", nombre, stock);
            printf("Ingrese las unidades a agregar: ");
            while (scanf("%d", &numReabastecer) != 1 || numReabastecer < 0) {
                printf("Error: Ingrese una cantidad numerica valida: ");
                while (getchar() != '\n');
            }
            stock += numReabastecer;
            printf("El nuevo stock es: %d\n", stock);
            break;
        case 4:
            if (productoRegistrado == 0) {
                printf("No hay informacion. Registre el producto primero.\n");
                break;
            }
            printf("\n--- Informacion de Inventario ---\n");
            printf("Id\t\tNombre\t\tStock\t\tPrecio\n");
            printf("%s\t\t%s\t\t%d\t\t$%.2f\n", ID, nombre, stock, precio);
            break;
        case 5:
            printf("\nLas ganancias totales generadas son: $%.2f\n", ganancias);
            break;
        case 6:
            opc2 = 2; 
            printf("Saliendo del programa...\n");
            break;
        default:
            if (opc != 0) { 
                printf("Opcion invalida. Intente de nuevo.\n");
            }
            break;
        }
        if (opc != 6) {
            printf("\nDesea seleccionar otra opcion 1.Si/2.No: ");
            while (scanf("%d", &opc2) != 1 || (opc2 != 1 && opc2 != 2)) {
                printf("Error: Ingrese 1 para Si, o 2 para No: ");
                while (getchar() != '\n');
            }
        }
    } while(opc2 == 1);
    return 0;
}