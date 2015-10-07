tda_funcoes.o: tda_funcoes.h tda_funcoes.c tda_agenda.h
	g++ -c tda_funcoes.cpp -I
	g++ -c tda_agenda.c -I
clean
	-rm -f *.o tda_agenda *

CPPUNIT_PATH=/diretorio_onde_esta_o_cppunit
INCLUDE_DIR=$CPPUNIT_PATH)/include
LIB_DIR=$(CPPUNIT_PATH)/lib
LIBS=-lcppunit
CPPFLAGS=-I$(INCLUDE_DIR)
LDFLAGS=-L$(LIB_DIR) $(LIBS)
all: tda_agenda
tda_agenda: tda_agenda.o tda_agenda.h tda_funcoes.h
	g++ -o tda_agenda tda_agenda.o tda_agenda.h tda_funcoes.h $(LDFLAGS)
tda_agenda.o: tda_agenda.cpp tda_agenda.h
	g++ -c tda_agenda.cpp $(CPPFLAGS)
tda_funcoes.c: tda_funcoes.h tda_funcoes.cpp tda_agenda.h
	g++ -c tda_funcoes.cpp $(CPPFLAGS)

tda_agenda.o: tda_agenda.c
	g++ -c tda_agenda.cpp $(CPPFLAGS)
clean
	-rm -f *.o tda_agenda *~
