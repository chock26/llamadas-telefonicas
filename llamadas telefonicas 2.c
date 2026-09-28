//programa que lee el importe de n llamadas telefonicas, valida n e imprime n es valida o invalida
#include <stdio.h>
int main(){
    int n;
    printf("Dame el numero de llamadas: ");
    scanf("%d", &n);
    if(n > 0){
        printf("n es valida\n");        
        int total_seg=0;
        int total_min=0;
        float total_sub=0, total_imp=0, total_gral=0;
        for(int i=1; i<=n; i++){
            int segundos;
            printf("Llamada %d duracion en segundos: ", i);
            scanf("%d", &segundos);
            if(segundos > 0){
                int minutos = segundos / 60;
                if(segundos % 60 != 0){
                    minutos = minutos+1;
                }
                float subtotal;
                if(minutos > 3){
                    subtotal = 9.0 + (minutos-3)*1.0;
                } else {
                    subtotal = minutos*3.0;
                }
                float impuesto = subtotal * 0.16;
                float total = subtotal + impuesto;                
                printf("segundos: %d\n", segundos);
                printf("minutos: %d\n", minutos);
                printf("subtotal: %.2f\n", subtotal);
                printf("impuesto: %.2f\n", impuesto);
                printf("total: %.2f\n", total);
                total_seg = total_seg + segundos;
                total_min = total_min + minutos;
                total_sub = total_sub + subtotal;
                total_imp = total_imp + impuesto;
                total_gral = total_gral + total;
            } else {
                printf("duracion invalida\n");
                i = i - 1;
            }
        }       
        printf("\n     RESUMEN     \n");
        printf("Total segundos: %d\n", total_seg);
        printf("Total minutos: %d\n", total_min);
        printf("Total subtotal: %.2f\n", total_sub);
        printf("Total impuestos: %.2f\n", total_imp);
        printf("Total gral: %.2f\n", total_gral);
    } else {
        printf("n es NO valida");
    }
}