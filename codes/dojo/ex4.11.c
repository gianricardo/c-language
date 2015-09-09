#include <stdio.h>
int main(){
    int n;
    printf("Digite o primeiro número: ");
    scanf("%d",&n);
    int d,i,menor;
    menor=n;
    for(i=0;i<n-1;i++){
        printf("Digite o %dº número: ",i+2);
        scanf("%d",&d);
        if(d<menor) menor=d;
    }
    printf("O menor número é %d\n",menor);
/*printf("Quantos numeros?");
scanf("%d",&n);
while (n>0){
    printf("numero %d",n);
    scanf("%d")
    }*/
    return 0; 
}

