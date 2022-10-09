/*# mini-Calculadora-Cientifica-em-C
Projeto nota Final  - miniCalculadora Cientifica em C*/
#include <stdio.h>
#include <stdlib.h>

  //funcao soma
float soma (float num1, float num2)
{
    float resultado = num1 + num2;
    return resultado;
}
// funcao subtracao
float subtracao (float num1, float num2){
float resultado = num1 - num2;
    return resultado;
}
// funcao multiplicacao
float multiplicacao (float num1, float num2){
float resultado = num1 * num2;
    return resultado;
}
//funcao divisao
float divisao(float num1, float num2){
  float resultado=num1/num2;
  return resultado;
}
//funcao da raiz
float raiz(float num1, float num2) {

    int n, i; 
    float resultado=0;
    //for(i=0; i>=10;i++);
    num1 = num2;
    for (n = 0; n < 10; ++n){
    num2 = num2/2 + num1/(2*num2);
     resultado=num2;
   }
  return resultado;
  }
// funcao da potencia
float potencia(float num1, float num2){
  
   float resultado=1, i; 
   for(i=0; i<num2; i++){
   resultado*=num1;
	 resultado=resultado;
   }
  return resultado;
}
//funcao fatorial
float fatorial(float num1, float num2){
    num2 = 1;

    float resultado;
    for (int i = 1; i <= num1; i++) {
        num2 *= i;
     resultado=num2;
    }
  return resultado; 
  }
//função segundo grau
float raiz_grau2(float num1, float num2, float num3){
#include <math.h>
  float resultado;

    float delta, raiz;
    num1=0;
  float resul_tado[4];
  
    printf("Entre com os valores de A, B e C da equação: ");
    scanf("%f%f%f", &num1, &num2, &num3);

    delta=(num2*num2)-4*num1*num3;
    raiz=sqrt(delta);

    if(delta>=0){
        resul_tado[0]=(-num2+raiz)/(2*num1);
        resul_tado[1]=resul_tado[0];
        resul_tado[2]=(-num2-raiz)/(2*num1);
        resul_tado[3]=resul_tado[2];

        printf("As raizes reais da equação são:\n\t[X1=%.3f; X2=%.3f]\n", resul_tado[1], resul_tado[3]);
    }else{
        printf("A equação de 2o grau n possui raizes reais!\n");
    }
return resultado; 
  }


// escopo principal do codigo
int main(void) {
    
float resultado_raiz[3];
float resultado1[0], resultado2, numero2, numero3;
int operacao;

//label de retorno pós submissao de limpeza
pos_limpeza:
printf("Número: ");
scanf("%f", &resultado1[0]);

//repetiçao do menu
while (operacao != 11)
{
    printf("\nNúmero: %.2f\n", resultado1[0]);
   printf("--*=*=*=*=*Calculadora*=*=*=*=*--\n\n");
        printf("press [1] -- SOMAR\n");
        printf("press [2] -- SUBTRAIR\n");
        printf("press [3] -- MUTIPLICAR\n");
        printf("press [4] -- DIVIDIR\n");
        printf("press [5] -- RAIZ\n");
        printf("press [6] -- POTÊNCIAÇÃO\n");
        printf("press [7] -- FATORIAL\n");
        printf("press [8] -- RAIZES REAIS DO SEGUNDO GRAU\t(ao executar este comando, automaticamente o numero inserido por você será apagado\nao fim, escolha uma das duas raizes para continuar!\n");
      //  printf("press [9] -- RAIZES REAIS DO TERCEIRO GRAU\n");
        printf("press [10] -- LIMPAR\n");
        printf("press [11] -- SAIR\n\n");
    scanf("%d", &operacao);

  switch (operacao){
    case 1:{
      printf("\n%.2f + ", resultado1[0]);
        scanf("%f", &numero2);



        float soma(float num1, float num2);

        resultado2 = soma(resultado1[0], numero2);
        resultado1[0] = resultado2;break;
    }
    case 2:{
      printf("\n%.2f - ", resultado1[0]);
      scanf("%f", &numero2);

      float subtracao(float num1, float num2);

      resultado2 = subtracao(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
      
    }
    case 3:{
      printf("\n%.2f * ", resultado1[0]);
      scanf("%f", &numero2);

      float multiplicacao(float num1, float num2);

      resultado2 = multiplicacao(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
    }
    case 4:{
      printf("\n%.2f / ", resultado1[0]);
      scanf("%f", &numero2);

      float divisao(float num1, float num2);

      resultado2 = divisao(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
    }
    case 5:{
      printf("\n√%.1f ", resultado1[0]);
      //scanf("%f", &numero2);
      numero2=resultado1[0];
      float raiz(float num1, float num2);
      resultado2 = raiz(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
    }
    case 6:{
      printf("\n%.2f elevado à ", resultado1[0]);
      scanf("%f", &numero2);

      float potencia(float num1, float num2);

      resultado2 = potencia(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
    }
    case 7:{
      float fatorial(float num1, float num2);

      resultado2 = fatorial(resultado1[0], numero2);
      resultado1[0] = resultado2;break;
    }
    case 8:{
    float raiz_grau2(float num1, float num2, float num3);

      resultado2=raiz_grau2(resultado_raiz[0], resultado_raiz[1], resultado_raiz[2]);
      
    }
    case 9: {
      // raizes de terceiro grau
    }
    case 10:{
      goto pos_limpeza;
    }
    case 11:{
      printf("Fime de execução!");
      exit(0);
    }
  }
 }
}
