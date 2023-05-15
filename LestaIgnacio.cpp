#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n_tipos = 3;
    int n_operarios = 6;
    int i;
    int precio[n_tipos] = {50, 40, 60}; // precio de venta de caja de cada tipo
    int cantidad[n_tipos] = {0}; // cantidad total de alfajores de cada tipo
    int entregas_con_error = 0; // cantidad total de entregas con error
    int fuera_de_produccion[n_operarios] = {0}; // cantidad fuera de produccion elaborada por cada operario
    int tipo, operario, cantidad_entregada;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
    	system("cls");
        printf("Ingrese el tipo de alfajor (0 = chocolate, 1 = dulce de leche, 2 = fruta, 3 = mixto): ");
        scanf("%d", &tipo);
        while(i < 100) {
          printf("Ingrese el numero de operario (1-6): ");
          scanf("%d", &operario);
          if(operario <= 6 && operario >= 1) break;
          else {
          	system("cls");
            printf("Numero invalido\n");

        		}
          i++;
      	}
        printf("Ingrese la cantidad entregada: ");
        scanf("%d", &cantidad_entregada);
        system("cls");

        if (cantidad_entregada % 6 != 0) {
            entregas_con_error++;
            fuera_de_produccion[operario-1] += cantidad_entregada % 6;
        }

        cantidad[tipo] += cantidad_entregada;
        printf("Desea ingresar otra produccion? (s/n): ");
        scanf(" %c", &continuar);
    }
    system("cls");
    printf("Cantidad total de entregas con error: %d\n", entregas_con_error);

    int ganancia_total = 0;
    for (int i = 0; i < n_tipos; i++) {
        int ganancia_tipo = precio[i] * (cantidad[i] / 6);
        printf("Ganancia por cajas de %s: $%d\n", i == 0 ? "chocolate" : (i == 1 ? "dulce de leche" : "fruta"), ganancia_tipo);
        ganancia_total += ganancia_tipo;
    }
    printf("Ganancia total: $%d\n", ganancia_total);

    printf("Cantidad fuera de produccion elaborada por cada operario:\n");
    for (int i = 0; i < n_operarios; i++) {
        printf("Operario %d: %d\n", i+1, fuera_de_produccion[i]);
    }

    return 0;
}
