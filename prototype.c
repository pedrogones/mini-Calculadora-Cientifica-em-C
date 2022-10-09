#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

    // Função da adição
float adicao(float n1, float n2){

    float soma;
    soma = n1+n2;
    return soma;
}

    //Função da subtração
float subtracao(float n1, float n2){

    float diferenca;
    diferenca = n1-n2;
    return diferenca;
}

    //Função da multiplicação
float multiplicacao(float n1, float n2){

    float produto;
    produto = n1*n2;
    return produto;
}

    //Função da divisão
float divisao(float n1, float n2){

    float quociente;
    quociente = n1/n2;
    return quociente;
}

    //Função da potência
float potenciacao(float n1, float n2){

   float potencia, i;
   potencia = 1;

   for(i = 0; i < n2; i++){
        potencia *= n1;
   }

    return potencia;
}

    //Função da raiz quadrada
float radiciacao (float n1){

    int i;
    float raiz = n1;

    for(i = 0; i < 10; ++i)
          raiz = raiz/2 + n1/(2*raiz);

    return raiz;
}

    //Função fatorial
int fatorial(int n1){

    int aux;

    if(n1 == 1){
        aux = 1;
    }else{
        aux = n1*fatorial(n1-1); // Utilização de recursão
    }

    return aux;
}

    //Raízes de uma equação do 2 grau
void segundoGrau (float A, float B, float C){

    float delta, raiz_delta, i;
    float raizes[2];

    delta = (B*B) - (4*A*C);
    raiz_delta = delta;

    if(delta > 0){
        for(i = 0; i < 10; ++i){
            raiz_delta = raiz_delta/2 + delta/(2*raiz_delta);
    }
        }

    if(delta == 0){
        raiz_delta = 0;
    }

    if(delta < 0){
        printf("Não existem raízes reais!\n");
    }else{
        raizes[0] = (-B + raiz_delta)/(2*A);
        raizes[1] = (-B - raiz_delta)/(2*A);

        printf("x1 = %f\n", raizes[0]);  // Neste caso, o output foi posto
        printf("x2 = %f\n", raizes[1]); //  dentro da própria função.
    }
}
    //Raízes de uma equação do 3 grau
void terceiroGrau (double A, double B, double C, double D){

    double raizes[3];
    double e,f,g,h,i,j,k,l,m,n,p,r,s,t,u;
    int w;

    e = 2.7182818284590;

    f = ((3*C/A)-(B*B/(A*A)))/3;
    g = ((2*B*B*B/(A*A*A))-(9*B*C/(A*A))+(27*D/A))/27;
    h = (g*g/4)+(f*f*f/27);
    i = sqrt(((g*g/4)-h));
    j = exp(log10(i)/log10(e)/3);
    k = acos((-1)*(g/(2*i)));
    l = j*(-1);
    m = cos(k/3);
    n = sqrt(3)*sin(k/3);
    p = (B/3*A)*(-1);
    r = (-1)*(g/2)+sqrt(h);
    s = exp(log10(r)/log10(e)/3);
    t = (-1)*(g/2)-sqrt(h);
    u = exp(log10(t)/log10(e)/3);

    if(h>0) w=1;
    if(h<=0) w=3;
    if((f==0)&&(g==0)&&(h==0)) w=2;

    switch(w){
    case 1:
    raizes[0] = (s+u)-(B/3*A);
    raizes[1] = (-1)*(s+u)/2-(B/3*A);
    raizes[2] = (s-u)*sqrt(3)/2;
    printf("\n%lf\n%lf + i*%lf\n%lf - i*%lf", raizes[0], raizes[1], raizes[2], raizes[1], raizes[2]);
    printf("\n");
    break;

    case 2:
    raizes[0] = exp(log10(D/A)/log10(e)/3)*(-1);
    printf("x1 = %lf", raizes[0]);
    break;

    case 3:
    raizes[0] = 2*j*cos(k/3)-(B/3*A);
    raizes[1] = l*(m+n)+p;
    raizes[2] = l*(m-n)+p;
    printf("x1 = %lf\n", raizes[0]);
    printf("x2 = %lf\n", raizes[1]);
    printf("x3 = %lf\n", raizes[2]);
    break;

    }
}

int main(){

    setlocale(LC_ALL, "Portuguese"); // Habilitar o uso de acentuação

    int opcao;
MENU:
    printf("Calculadora:\n\n");
    printf("1 -> Operações aritméticas e fatorial\n");
    printf("2 -> Raízes de uma equação do segundo grau\n");
    printf("3 -> Raízes de uma equação do terceiro grau\n\n");
    scanf("%d", &opcao);

    if(opcao == 1){
        float n1, n2;
        char operador;

        printf("\n");
        printf("Legenda:\n\n");
        printf("+ -> Soma\n");
        printf("- -> Subtração\n");
        printf("* -> Multiplicação\n");
        printf("/ -> Divisão\n");
        printf("^ -> Potência\n");
        printf("] -> Raiz quadrada\n");
        printf("! -> Fatorial\n");
        printf("C -> Limpar\n");
        printf("R -> Retornar ao menu anterior\n\n");
LIMPEZA:
        scanf("%f", &n1);
        if(n1 == 'C'){
            printf("Limpo!\n\n");
            goto LIMPEZA;
        }
        if(n1 == 'R'){
            printf("\n");
            goto MENU;
        }
RETORNO:
        scanf(" %c", &operador);
        if(operador == 'C'){
            printf("Limpo!\n\n");
            goto LIMPEZA;
        }
        if(operador == ']'){
            float raiz;
            raiz = radiciacao(n1); // Chamando a função
            n1 = raiz; // Atualizando o valor de n1 para que as operações sejam contínuas.
            printf("%f", raiz);
            goto RETORNO;
        }

        if(operador == '!'){
            int aux = (int)n1;

            if((n1 - aux) != 0){ // Aviso caso o usuário tente obter o fatorial de um número não inteiro.
                printf("Só há fatorial de número inteiro!\n");
                goto LIMPEZA;
            }else{
                int resultado;
                resultado = fatorial(n1);
                printf("%d", resultado);
                n1 = resultado;
                goto RETORNO;
            }
        }

        if(operador == 'R'){
            printf("\n");
            goto MENU;
        }

        scanf("%f", &n2);
        if(n2 == 'C'){
            printf("Limpo!\n\n");
            goto LIMPEZA;
        }
        if(n2 == 'R'){
            printf("\n");
            goto MENU;
        }

        if(operador == '+'){
            float soma;
            soma = adicao(n1,n2);
            n1 = soma;
            printf("%f", soma);
            goto RETORNO;
        }

        else if(operador == '-'){
            float diferenca;
            diferenca = subtracao(n1,n2);
            n1 = diferenca;
            printf("%f", diferenca);
            goto RETORNO;
        }

        else if(operador == '*'){
            float produto;
            produto = multiplicacao(n1,n2);
            n1 = produto;
            printf("%f", produto);
            goto RETORNO;
        }

        else if(operador == '/'){
            float quociente;
            quociente = divisao(n1,n2);
            n1 = quociente;
            printf("%f", quociente);
            goto RETORNO;
        }

        else if(operador == '^'){
            float potencia;
            potencia = potenciacao(n1,n2);
            n1 = potencia;
            printf("%f", potencia);
            goto RETORNO;
        }

        else{
            printf("\n");
            printf("Operador inválido!\n");
            printf("Insira novamente a operação:\n\n");
            printf("%f", n1);
            goto RETORNO;
        }
    }

    if(opcao == 2){
        float A,B,C;
        char opcao;
RETORNO2:
        printf("Insira os coeficientes A,B e C: ");
        scanf("%f %f %f", &A,&B,&C);

        segundoGrau (A,B,C);

        printf("C -> Calcular outras raízes\n");
        printf("R -> Voltar ao menu anterior\n");
SCAN:
        scanf(" %c", &opcao);

        if(opcao == 'C'){
            printf("\n");
            goto RETORNO2;
        }else if(opcao == 'R'){
            printf("\n");
            goto MENU;
        }else{
            printf("Opção inválida!\n");
            printf("Insira a opção novamente:\n\n");
            goto SCAN;
        }
    }

    if(opcao == 3){
        double A,B,C,D;
        char opcao;
RETORNO3:
        printf("Insira os coeficientes A,B,C, e D: ");
        scanf("%lf %lf %lf %lf", &A, &B, &C, &D);

        terceiroGrau (A,B,C,D);

        printf("C -> Calcular outras raízes\n");
        printf("R -> Voltar ao menu anterior\n");
SCAN2:
        scanf(" %c", &opcao);

        if(opcao == 'C'){
            printf("\n");
            goto RETORNO3;
        }else if(opcao == 'R'){
            printf("\n");
            goto MENU;
        }else{
            printf("Opção inválida!\n");
            printf("Insira a opção novamente:\n\n");
            goto SCAN2;
        }
    }
    else{
        printf("Opção inválida!\n\n");
        goto MENU;
    }

return 0;
}
