all: app

app: area.o app.o
	gcc area.o app.o -o app
    
area.o: area.c
	gcc -c area.c
    
app.o: app.c
	gcc -c app.c
    
#gerar documentação

docs: Doxyfile
	doxygen Doxyfile
    
