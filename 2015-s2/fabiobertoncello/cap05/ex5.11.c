#include<stdio.h>

float arredondaInteiro(float numero);

float arredondaDezenas( float number);
float arredondaCentenas( float number);
float arredondaMilhares( float number);

int main(){
/* PROFESSOR NAO SEI O QUE ACONTECEU MAIS ISSO AQUI NAO COMPILA DE JEITO NENHUM 

O ERRO E :
  ex5.11.c:38:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*1000 +.5)/1000;
         ^
make: ** [ex5.11] Erro 1
fabio@FBERTONCELLO:~/Documentos/UFSC/Estrutura de dados$ make ex5.11
cc     ex5.11.c   -o ex5.11
ex5.11.c:2:21: error: macro parameters must be comma-separated
 #define floor(float x)
                     ^
ex5.11.c: In function ‘arredondaInteiro’:
ex5.11.c:23:10: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return (floor(merda+.5));
          ^
ex5.11.c: In function ‘arredondaDezenas’:
ex5.11.c:27:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*10 +.5)/10;
         ^
ex5.11.c: In function ‘arredondaCentenas’:
ex5.11.c:32:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*100 +.5)/100;
         ^
ex5.11.c: In function ‘arredondaMilhares’:
ex5.11.c:38:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*1000 +.5)/1000;
         ^
make: ** [ex5.11] Erro 1
fabio@FBERTONCELLO:~/Documentos/UFSC/Estrutura de dados$ make ex5.11
cc     ex5.11.c   -o ex5.11
ex5.11.c: In function ‘arredondaInteiro’:
ex5.11.c:26:10: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return (floor(merda+.5));
          ^
ex5.11.c: In function ‘arredondaDezenas’:
ex5.11.c:30:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*10 +.5)/10;
         ^
ex5.11.c: In function ‘arredondaCentenas’:
ex5.11.c:35:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*100 +.5)/100;
         ^
ex5.11.c: In function ‘arredondaMilhares’:
ex5.11.c:41:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*1000 +.5)/1000;
         ^
/tmp/ccN5jtiQ.o: na função `arredondaInteiro':
ex5.11.c:(.text+0xb5): referência indefinida para `floor'
/tmp/ccN5jtiQ.o: na função `arredondaDezenas':
ex5.11.c:(.text+0x104): referência indefinida para `floor'
/tmp/ccN5jtiQ.o: na função `arredondaCentenas':
ex5.11.c:(.text+0x15f): referência indefinida para `floor'
/tmp/ccN5jtiQ.o: na função `arredondaMilhares':
ex5.11.c:(.text+0x1ba): referência indefinida para `floor'
collect2: error: ld returned 1 exit status
make: ** [ex5.11] Erro 1
fabio@FBERTONCELLO:~/Documentos/UFSC/Estrutura de dados$ CLEAR
CLEAR: comando não encontrado
fabio@FBERTONCELLO:~/Documentos/UFSC/Estrutura de dados$ clear

fabio@FBERTONCELLO:~/Documentos/UFSC/Estrutura de dados$ make ex5.11
cc     ex5.11.c   -o ex5.11
ex5.11.c: In function ‘arredondaInteiro’:
ex5.11.c:26:10: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return (floor(merda+.5));
          ^
ex5.11.c: In function ‘arredondaDezenas’:
ex5.11.c:30:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*10 +.5)/10;
         ^
ex5.11.c: In function ‘arredondaCentenas’:
ex5.11.c:35:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*100 +.5)/100;
         ^
ex5.11.c: In function ‘arredondaMilhares’:
ex5.11.c:41:9: warning: incompatible implicit declaration of built-in function ‘floor’ [enabled by default]
  return floor(number*1000 +.5)/1000;
         ^
/tmp/ccjQ4N3Q.o: na função `arredondaInteiro':
ex5.11.c:(.text+0xb5): referência indefinida para `floor'
/tmp/ccjQ4N3Q.o: na função `arredondaDezenas':
ex5.11.c:(.text+0x104): referência indefinida para `floor'
/tmp/ccjQ4N3Q.o: na função `arredondaCentenas':
ex5.11.c:(.text+0x15f): referência indefinida para `floor'
/tmp/ccjQ4N3Q.o: na função `arredondaMilhares':
ex5.11.c:(.text+0x1ba): referência indefinida para `floor'
collect2: error: ld returned 1 exit status
make: ** [ex5.11] Erro 1
*/


	printf("mas que merda%f\n",arredondaInteiro(3.141549));
	printf("mas que merda%f\n",arredondaDezenas(3.14159));
	printf("mas que merda%f\n",arredondaCentenas(3.115564));
	printf("mas que merda%f\n",arredondaMilhares(3.14695));

return 0;
}

float arredondaInteiro(float merda){

	return (floor(merda+.5));
}

float arredondaDezenas(float number){
	return floor(number*10 +.5)/10;
}

float arredondaCentenas(float number){

	return floor(number*100 +.5)/100;
}


float arredondaMilhares(float number){

	return floor(number*1000 +.5)/1000;
}
