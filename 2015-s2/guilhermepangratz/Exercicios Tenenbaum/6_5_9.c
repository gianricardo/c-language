//Tenenbaum exercicio 6.5.9 -- Gera a saida no terminal e em um txt

#include <stdio.h>

int main () {
    
    //abre o arquivo
    FILE *f = fopen("somas de quadrados.txt", "w+");
    
    // i[6] é o vetor com os contadores, q1 e q2 armazenam os quadrados que serão testados
    int i[6], q1, q2; 
    
    //cabeçalhos
    printf("%4s%4s%4s%4s%4s%4s = %10s%10s\n", "a1","a2", "a3", "a4", "a5", "a6", "a1^2+a2^2+a3^2 |", "| a4^2+a5^2+a6^2");
    fprintf(f ,"%4s%4s%4s%4s%4s%4s = %10s%10s\n", "a1","a2", "a3", "a4", "a5", "a6", "a1^2+a2^2+a3^2 |", "| a4^2+a5^2+a6^2");
    
    //Varia os numeros obedecendo a regra d oexercicio: a1 <= a2 <= a3 <= 20 e a1 < a4 <= a5 <=a6 <= 20
    for (i[0] = 0 ; i[0] < 20  ; i[0]++ ){
        for (i[1] = i[0] ; i[1] <= 20 ; i[1]++ ){
            for (i[2] = i[1] ; i[2] <= 20 ; i[2]++ ){
                for (i[3] = (i[0] + 1) ; i[3] <= 20 ; i[3]++ ){
                    for (i[4] = i[3] ; i[4] <= 20 ; i[4]++ ){
                        for (i[5] = i[4] ; i[5] <= 20 ; i[5]++ ){
                            
                            q1 = i[0]*i[0] + i[1]*i[1] + i[2]*i[2]; // a1^2+a2^2+a3^2
                            q2 = i[3]*i[3] + i[4]*i[4] + i[5]*i[5]; // a4^2+a5^2+a6^2
                            
                            //Saida no txt
                            if ( q1 == q2) {
                                fprintf(f, "%4d%4d%4d%4d%4d%4d = %10d%10d", i[0],
                                        i[1], i[2], i[3], i[4], i[5], q1, q2);
                                fprintf(f, "\n");
                            }
                            
                            //Saida no terminal
                            if ( q1 == q2) {
                                printf("%4d%4d%4d%4d%4d%4d = %10d%10d", i[0],
                                        i[1], i[2], i[3], i[4], i[5], q1, q2);
                                printf("\n");
                            }
                            
                        }
                    }
                }
            }
        }
    }
    
    fclose(f);
    
    return 0;
}
