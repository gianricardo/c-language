// O que o seguinte programa imprime?

#include <stdio.h> 
int main() { 
	int x = 1,  total = 0, y; 
	while  (x <= 10) { 
		y = x * x;
		printf("%d\n", y); 
		total += y; 
		++x; 
	} 
	printf("Total is %d\n", total); 
	return 0; 
}
/*1ª
x=1
y=1
total=1
x=2
2ª
x=2
y=4
total=5
x=3
3ª
x=3
y=9
total=14
x=4
4ª
x=4
y=16
total=30
x=5
5ª
x=5
y=25
total=55
x=6
6ª
x=6
y=36
total=91
x=7
7ª
x=7
y=49
total=140
x=8
8ª
x=8
y=64
total=204
x=9
9ª
x=9
y=81
total=285
x=10
10ª
x=10
y=100
total=385

Vai imprimir:
1
4
9
16
25
36
49
64
81
100
Total is 385
*/
