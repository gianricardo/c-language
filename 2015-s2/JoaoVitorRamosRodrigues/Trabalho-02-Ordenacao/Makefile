CPPUNIT_PATH=/diretorio do cppunit

INCLUDE_DIR=$CPPUNIT_PATH)/include

LIB_DIR=$(CPPUNIT_PATH)/lib
LIBS=-lcppunit
CPPFLAGS=-I$(INCLUDE_DIR)
LDFLAGS=-L$(LIB_DIR) $(LIBS)
all: tda_ordenacao
tda_ordenacao: tda_ordenacao.o tda_ordena.o tda_ordenacao_funcoes.o
	g++ -o tda_ordenacao.c tda_ordenacao.o tda_ordenacao.o tda_ordenacao.o $(LDFLAGS)
tda_ordena.o: tda_ordenacao.h
	g++ -c tda_ordena.h $(CPPFLAGS)
tda_ordenacao_funcoes.o: tda_ordenacao.h
	g++ -c tda_ordenacao_funcoes.h $(CPPFLAGS)
