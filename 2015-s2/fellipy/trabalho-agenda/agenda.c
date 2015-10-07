// Trabalho agenda
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
Função para abrir o arquivo agenda.txt, em modos diferentes.

@param caminho é a string que contem o nome do arquivo, e 
@param modo é referente ao jeito que vai abrrir o arquivo;
testa se o arquivo existe, e pode ser aberto, caso contrario imprime a seguinte mensagem de erro;

@return um ponteiro para o arquivo.
*/
FILE *AbreAgenda(char caminho[30], char modo){



  FILE *agenda;
  switch (modo){
    case 'l': agenda=fopen("agenda.txt","rt"); break;
    case 'i': agenda=fopen("agenda.txt","a+b"); break;
  }
  if (agenda==NULL){
    printf("Não foi possivel abrir arquivo!\n");
    exit(0);
  }

}

void fechaAgenda(FILE*agenda){
/**
Função para fechar agenda
*/
  fclose(agenda);

}

struct dados{

/**
Struct que contem as variáveis principais do programa,
que serao usadas para cadastro e comparacao, afim de manipular o arquivo.
*/
  char nome[100];
  int dia,mes,ano,celular;
  char twitter[100];
  char facebook[100];

};

void cadastro(){


/**
Função para cadastro de contatos, é void pois não retorna nada, apenas passa para o arquivo
as variaveis d.nome, d.aniversario, d.celular, d.twitter e d.facebook.

define o prefixo para chamar as variaveis contidas na struct;
chamada para a funcao que abre o arquivo agenda.txt;
define o modo com que o arquivo sera aberto de acordo com a funcao AbreAgenda;
espera as entradas do teclado e armazena nas variaveis de tipo char ou int respectivamente;
escreve no arquivo agenda.txt as variáveis obtidas, na mesma sequencia anterior;
chama a funcao responsavel por fechar a agenda.
*/


  struct dados d;
  FILE *agenda;
  agenda = AbreAgenda("agenda.txt",'i');

  printf("\n\nNome do contato: ");
  scanf("%s",d.nome);

  printf("Data de aniversário (dd.mm.aaaa): ");
  scanf("%d.%d.%d",&d.dia,&d.mes,&d.ano);

  printf("Celular (Somente numeros): ");
  scanf("%d",&d.celular);

  printf("Twitter: ");
  scanf("%s",d.twitter);

  printf("Facebook: ");
  scanf("%s",d.facebook);
  fprintf(agenda,"%s %d.%d.%d %d %s %s\n",d.nome,d.dia,d.mes,d.ano,d.celular,d.twitter,d.facebook);

 fechaAgenda(agenda);
 system("clear || cls");
}
void exclui(){
}
void altera(){

}
void consulta_data(){

/**
Funcao responsavel por consultar aniversariantes por data, ela recebe tres entradas inteiras do usuario,
no formato dd.mm.aaa e armazena dd em sdia, mm em smes e aaaa em sano, e depois varre todo o arquivo em busca
dessas variaveis, afim de encontrar a mesma sequencia para que possa imprimir o nome do aniversariante dessa data.

define o prefixo para a chamada das variaveis contidas em struct;
define as variaveis que serao usadas para a comparacao;
chama a funcao para abrir o arquivo agenda.txt;
define o modo com que o arquivo sera aberto;
escreve na tela para o usuario inserir a data;
espera a entrada do usuario e armazena nas respectivas variaveis sdia,smes e sano;
enquanto nao chegar ao final do arquivo, o ! nega e feof significa file end of file, do arquivo agenda.txt;
o programa escaneia do arquivo agenda.txt,
os dados de cada contato e armazena temporariamente nas respectivas variaveis contidas em struct;
então se a variavel sdia, que contem o dia que o usuario digitou, for igual ao dia que está sendo lido no
momento pelo programa;
e se o mesmo acontecer para o mes e ano;
o programa imprime o nome do aniversariante;
chama a funcao para fechar a agenda.
*/



  struct dados d;
  int sdia,smes,sano;
  FILE*agenda;
  agenda=AbreAgenda("agenda.txt",'l');
  printf("Digite uma data (dd.mm.aaa): ");
  scanf("%d.%d.%d",&sdia,&smes,&sano);
  while(!feof(agenda)){
    fscanf(agenda,"%s %d.%d.%d %d %s %s ",d.nome,&d.dia,&d.mes,&d.ano,&d.celular,d.twitter,d.facebook);
      if (sdia == d.dia ){
        if(smes == d.mes){
          if(sano == d.ano){
            printf("Aniversariante: %s\n",d.nome);
          }
        }
      }
    }
    fechaAgenda(agenda);
}
void consulta_mes(){

/**
Função que consulta os aniversariantes de um determinado mes, essa funcao e responsavel por analisar um inteiro fornecido
pelo usuario, e comparar com  a variavel d.mes, se elas forem iguais ele imprime o nome do aniversariante e depois pula
de linha para que um novo nome possa ser inserido.

define o prefixo para as variaveis contidas em struct;
define a variavel para ser comparada com a variavel mes que esta em struct;
chama a funçao responsavel por abrir o arquivo;
define o modo com que o arquivo sera aberto;
imprime na tela para o usuario inserir um mes de consulta;
espera o numero inteiro que o usuario ira fornecer e armazena na variavel definida no começo da funcao;
imprime aniversariantes do mes e pula de linha para que seja exibida a lista;
enquanto nao chegar ao final do arquivo, o programa vai ler os dados de cada pessoa, linha por linha;
le os dados e armazena nas variaveis;
compara a variavel smae, que o usuario escolheu, com a variavel mes, contida termporariamente em struct;
se forem iguais o programa imprime o nome do aniversariante;
chama a funcao para fechar a agenda;
*/

  struct dados d;
  int smes;
  FILE*agenda;
  agenda=AbreAgenda("agenda.txt",'l');
  printf("Digite um mes: ");
  scanf("%d",&smes);
  printf("Aniversariantes do mes:\n");
  while(!feof(agenda)){
    fscanf(agenda,"%s %d.%d.%d %d %s %s ",d.nome,&d.dia,&d.mes,&d.ano,&d.celular,d.twitter,d.facebook);
      if(smes == d.mes){
            printf("%s\n",d.nome);
          }
    }
    fechaAgenda(agenda);
}
void consulta_inicial(){

/**
Função para pesquisar contatos pela inicial do nome, e imprimir o dia de aniversario, ela é responsavel como as outras
duas, por comparar uma variavel que o usuario escolhe com uma variavel existente no arqivo, e retornar o nome e
data de aniversario

define prefixo para as variaveis contidas em struct;
define uma variavel do tipo char, para a inicial que usuario deseja;
chama a funcao para abrir o arquivo;
abre o arquivo em modo leitura;
escreve na tela para o usuario inserir uma inicial;
limpa o buffer do teclado;
espera o usuario entrar com a letra;
executa o laço ate o final do arquivo;
armazena os dados nas variaveis contidas em struct, temporariamente;
se o char que o usuario inseriu for igual ao char contido na primeira posicao da string nome;
o programa imprime o nome e a data de aniversario referente a incial;
chama a funcao responsavel por fechar o arquivo.
*/

struct dados d;
  char inicial;
  FILE*agenda;
  agenda=AbreAgenda("agenda.txt",'l');
  printf("Digite uma inicial (em caixa alta): ");
  fflush(stdin);
  scanf(" %c",&inicial);
  while(!feof(agenda)){
    fscanf(agenda,"%s %d.%d.%d %d %s %s ",d.nome,&d.dia,&d.mes,&d.ano,&d.celular,d.twitter,d.facebook);
      if (inicial==d.nome[0]){
      printf("Nome: %s   Aniversário: %d.%d.%d\n",d.nome,d.dia,d.mes,d.ano);
    }
  }
  fechaAgenda(agenda);
}
void ordena_nome(){
}
void ordena_mes(){
}

int main(void){


/**
Função principal do programa, onde é definido a ordem que cada funcao acima sera executada juntamente com seus parametros
define uma variavel de tipo inteiro, que o usuario vai escolher de 1 a 9 no menu que é impresso nas linhas seguintes;
espera a entrada do usuario para escolher uma das opçoes;
define um intervalo onde é valida a opcao que o usuario escolheu;
entra no laço de escolha de opcao, switch que aceita para a variavel opcao, inteiros de 1 a 9;
caso o usuario entre com um valor diferente do intervalo o programa imprime o erro;
repete a pergunta para o usuario, caso contrario o programa encerra assim que a funcao que ele havia escolhido termine;
espera a entrada do usuario;
a funçao system("clear || cls"), limpa a tela para que nao fique muito poluida com os dados impressos;
*/


int opcao;
printf("\n\t\tAGENDA\n\n");
printf("Escolha uma das opçoẽs a seguir:\n");
printf("1-Cadastrar pessoa;\n");
printf("2-Excluir pessoa;\n");
printf("3-Alterar dados de um contato;\n");
printf("4-Consultar aniversariante de uma data;\n");
printf("5-Consultar aniversariante de um mes;\n");
printf("6-Consultar aniversariante pela inicial;\n");
printf("7-Mostrar agenda ordenada por nome;\n");
printf("8-Mostrar agenda ordenada por mes de aniversarios;\n");
printf("9-Sair.\n\n");
printf("Opçao: ");

scanf("%d",&opcao);

while(0<opcao<10){
  switch(opcao){
    case 1: system("clear || cls");cadastro(); break;
    case 2: system("clear || cls");exclui(); break;
    case 3: system("clear || cls");altera(); break;
    case 4: system("clear || cls");consulta_data(); break;
    case 5: system("clear || cls");consulta_mes(); break;
    case 6: system("clear || cls");consulta_inicial(); break;
    case 7: system("clear || cls");ordena_nome(); break;
    case 8: system("clear || cls");ordena_mes(); break;
    case 9:
      printf("\n\nFinalizando!\n\n");
      exit(0);
    default: printf("Opção invalida!\n");
    }
    printf("\n\t\tAGENDA\n\n");
    printf("Escolha uma das opçoẽs a seguir:\n");
    printf("1-Cadastrar pessoa;\n");
    printf("2-Excluir pessoa;\n");
    printf("3-Alterar dados de um contato;\n");
    printf("4-Consultar aniversariante de uma data;\n");
    printf("5-Consultar aniversariante de um mes;\n");
    printf("6-Consultar aniversariante pela inicial;\n");
    printf("7-Mostrar agenda ordenada por nome;\n");
    printf("8-Mostrar agenda ordenada por mes de aniversarios;\n");
    printf("9-Sair.\n\n");
    printf("Opçao: ");
    scanf("%d",&opcao);
}
}


/**
Considerações finais:
Faltou implementar as funçoes de exclusao de contato, alteração de dados de um contato, ordenar a agenda pelo nome e pelo mes de aniversarios;
*/
