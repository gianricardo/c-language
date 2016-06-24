#include "comum.h"

const char* codigo_erro_cstr(codigo_erro erro_n){
    switch (erro_n) {
        case SUCESSO :
            return "SUCESSO";
        case INVALIDO :
            return "INVALIDO";
        case BAD_ALLOCATION:
            return "BAD_ALLOCATION";
        case POSICAO_INVALIDA:
            return "POSICAO_INVALIDA";
        case ESTADO_INVALIDO:
            return "ESTADO_INVALIDO";
        case OVERFLOW:
            return "OVERFLOW";
        case UNDERFLOW:
            return "UNDERFLOW";
        case DUPLICADO:
            return "DUPLICADO";
        case VALOR_INVALIDO:
            return "VALOR_INVALIDO";
        default:
            return "CODIGO DESCONHECIDO";
    }
}
