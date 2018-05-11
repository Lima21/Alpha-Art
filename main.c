/*
 * Licenciatura em Engenharia Informática
 * Gonçalo Lima - Nº17494
 * Samuel Rodrigues - Nº17495
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
/*
 *
 */

void menu() {

    int i=0;
    printf("   #");
    for(i=0; i < 72; i++) {
        printf("=");
    }
    printf("#\n   # * Alpha Art");
    for(i=0; i < 60; i++) {
        printf(" ");
    }
    printf("#\n");
    printf("   #");
    for(i=0; i < 72; i++) {
        printf("-");
    }
    printf("#\n   # * Software de gestão de uma Galeria de Arte");
    for(i=0; i < 28; i++) {
        printf(" ");
    }
    printf("#");
    printf("\n   #");
    for(i=0; i < 72; i++) {
        printf("=");
    }
    printf("#\n\n");
    printf("\n\t 1. Comprar uma nova peça de Arte\n\t 2. Listar todas as peças comercializadas\n\t 3. Informações sobre Peças\n\t 4. Listar Informações por Tipo\n");
    printf("\t 5. Alterar Preço\n\t 6. Calcular Lucro Médio\n\t 7. Peças com preço de compra acima da média\n\t 8. Número de Peças existente\n\t 9. Peças com Preço de Venda Mais Alto\n");
    printf("\t10. Total de Lucro\n\t11. Peças com média de preços de venda mais alto\n\t12. Calcular IVA\n\t 0. Sair\n");
}

int comprarPeca(float precoCompra[], float precoVenda[], char tipoPeca[],int codP[], int total) {
    char tipo;
    float valores=0;

    do {
        printf("\n\n\t\t\tQue tipo de peça deseja comprar?\nP - Pintura\nE - Escultura\nA - Arquitetura\nO - Outros\n\n#");
        scanf(" %c", &tipo);
    } while(tipo != 'A' && tipo != 'P' && tipo != 'E' && tipo != 'O');

    tipoPeca[total] = tipo;
    printf("\nPreço de Compra:");
    scanf("%f", &valores);
    precoCompra[total] = valores;
    printf("Preço de Venda:");
    scanf("%f", &valores);
    precoVenda[total] = valores;
    codP[total] = total + 1;
    printf("Código gerado automaticamente: %06i\n\n", codP[total]);
}

void listarPecas(char tipoPeca[], int codP[], int total) {
    int i;
    printf("\n\t\tPeça(s) comercializadas(s) pela Galeria:\n ");
    for(i = 0; i < total; i++) {
        printf("\n%06i - ", codP[i]);
        printf(" %c", tipoPeca[i]);
    }
    printf("\n\n");
}

void listarCod(float precoCompra[], float precoVenda[], char tipoPeca[],int codP[], int total) {
    int cod=0, i=0, nexiste=0;

    printf("Introduza o código:");
    scanf("%i", &cod);
    printf("\n\n\t\tInformações Relativas à peça com o código %06i\n\n", cod);
    for(i=0; i < total; i++) {
        if(cod == codP[i]) {
            printf("\n\nPreço de Compra: %.2f€\n", precoCompra[i]);
            printf("Preço de Venda: %.2f€\n", precoVenda[i]);
            printf("Tipo de Peça: %c\n\n\n", tipoPeca[i]);
            nexiste = 1;
            return 0;
        }
    }

}

void listarTipo(float precoCompra[], float precoVenda[], char tipoPeca[],int codP[], int total) {
    int i=0, cont=0;
    char tipo;
    
    do {
        printf("Introduza o tipo de Peça:");
        scanf(" %c", &tipo);
    } while(tipo != 'A' && tipo != 'P' && tipo != 'E' && tipo != 'O');
    
    printf("\n\n\t\tInformações Relativas ao Tipo de Peça %c\n\n", tipo);
    
    for(i=0; i < total; i++) {
        if(tipo == tipoPeca[i]) {
            printf("\n\nPreço de Compra: %.2f€\n", precoCompra[i]);
            printf("Preço de Venda: %.2f€\n", precoVenda[i]);
            printf("Código da Peça: %06i\n", codP[i]);
            cont++;
        }
    }
    printf("\n\nExiste(m) %i peça(s) do tipo %c\n", cont, tipo);
    printf("\n\n");


}

void alterarPreco(float precoVenda[], int total) {

    int i=0;
    int cod=0;
    float preco = 0;

    printf("Introduza o código:");
    scanf("%i", &cod);
    printf("\n\n\t\tAlterar o preço da peça com o código %06i\n\n", cod);
    if(cod <= total ) {
        printf("Preço de venda: %.2f€", precoVenda[cod-1]);
        printf("\nNovo preço de Venda: ");
        scanf("%f", &preco);
        precoVenda[cod-1] = preco;
        printf("\n\n");
    }
}

float calcLucro(float precoCompra[], float precoVenda[], int total) {
    float compra=0, venda = 0, lucro=0;
    int i=0;
    for(i=0; i < total; i++) {
        compra+= precoCompra[i];
        venda += precoVenda[i];
    }
    return  (venda - compra);
}

void compraMedia(float precoCompra[], int codP[], char tipoPeca[], int total) {
    int i =0;
    float media_compra = 0;
    for(i=0; i < total; i++) {
        media_compra += precoCompra[i];

    }
    media_compra /= total;
    printf("\t\tPeças com preço de Compra acima da média\n\n");
    
    for(i=0; i < total; i++) {
        if(precoCompra[i]> media_compra) {
            printf("\nCódigo da Peça: %06i - ", codP[i]);
            printf("Tipo de Peça: %c", tipoPeca[i]);
        }

    }
    printf("\n\n\n\n");
}


void listarTudo(char tipoPeca[],int total) {
    int cont=0,i=0,a=0,e=0,p=0,o=0;
    printf("\n\n\t\tNúmero de Peças existentes por tipo:\n\n");
    for(i=0; i<total; i++) {
        if(tipoPeca[i]=='A') {
            a++;
        } else {
            if(tipoPeca[i]=='E') {
                e++;

            } else {
                if(tipoPeca[i]=='P') {
                    p++;

                } else {
                    o++;
                }
            }
        }
    }

    printf(" Existem %i peça(s) do tipo A \n Existem %i peça(s) do tipo E \n Existem %i peça(s) do tipo P \n Existem %i peça(s) do tipo O \n\n\n\n",a,e,p,o);


}


void precoAlto(float precoVenda[],int codP[], char tipoPeca[], int total,float precoCompra[]) {
    char tipo;
    int i = 0;
    float preco=0, preco_alto=0;
    
    do {
        printf("Introduza o tipo de peça: ");
        scanf(" %c", &tipo);
    } while(tipo != 'A' && tipo != 'P' && tipo != 'E' && tipo != 'O');
    
    printf("\n\n\t\tPeças do Tipo %c com Preço de Venda mais alto", tipo);
    for(i=0; i < total; i++) {
        if(tipoPeca[i] == tipo) {
            preco = precoVenda[i];
        }

        if(preco > preco_alto) {
            preco_alto = precoVenda[i];
        }
    }

    for(i=0; i < total; i++) {
        if(precoVenda[i] == preco_alto) {
            if(tipoPeca[i]==tipo) {
                printf("\n\nPreço de Compra: %.2f€", precoCompra[i]);
                printf("\nPreço de Venda: %.2f€", precoVenda[i]);
                printf("\nTipo de Peça: %c", tipoPeca[i]);
                printf("\nCódigo da Peça: %06i\n", codP[i]);
            }
        }
    }

    printf("\n\n");

}

void lucroaMedia( int total, float precoVenda[], int codP[], char tipoPeca[]) {
    int i = 0, ac=0, ec=0, pc=0, oc=0,af=0, ef=0, pf=0, of=0 ;
    float a=0, e=0, p=0, o=0, venda=0, maior=0;

    for(i=0; i<total; i++) {
        if(tipoPeca[i]=='A') {
            a += precoVenda[i];
            ac++;
        } else {
            if(tipoPeca[i]=='E') {
                e += precoVenda[i];
                ec++;

            } else {
                if(tipoPeca[i]=='P') {

                    p += precoVenda[i];
                    pc++;

                } else {
                    o+= precoVenda[i];
                    oc++;
                }
            }
        }
    }

    a /= ac;
    e /= ec;
    p /= pc;
    o /= oc;


    printf("\t\tTipo de peças com preço acima da média:\n\n");

    if(maior < a) {
        maior = a;
    }

    if(maior < e) {
        maior = e;
    }

    if(maior < p) {
        maior = p;
    }

    if(maior < o) {
        maior = o;
    }

    if(a == maior) {
        printf("A\n");
    }

    if(e == maior) {
        printf("E\n");
    }

    if(p == maior) {
        printf("P\n");
    }

    if(o == maior) {
        printf("O\n");
    }
    printf("\n\n");
}

void calcIva(float precoVenda[], int total) {
    int i = 0;
    float venda=0;
    for(i=0; i < total; i++) {
        venda += precoVenda[i];
    }
    venda*= 0.23;
    printf("\n\nIrá pagar %.2f€ de Iva\n\n", venda);
}



int main(int argc, char** argv) {
    float precoCompra[MAX], precoVenda[MAX], lucro=0, media_lucro=0;
    char tipoPeca[MAX];
    int codP[MAX], opcao=0, total=0;

    do {
        menu();
        printf("#");
        scanf("%i", &opcao);
        switch(opcao) {
        case 1:
            comprarPeca(precoCompra, precoVenda, tipoPeca, codP, total);
            total++;
            break;
        case 2:
            listarPecas(tipoPeca, codP, total);
            break;
        case 3:
            listarCod(precoCompra, precoVenda, tipoPeca, codP, total);
            break;
        case 4:
            listarTipo(precoCompra, precoVenda, tipoPeca, codP, total);
            break;
        case 5:
            alterarPreco(precoVenda, total);
            break;
        case 6:
            lucro = calcLucro(precoCompra, precoVenda,total);
            media_lucro = lucro/total;
            printf("\n\n\nLucro médio: %.2f€\n\n\n", media_lucro);
            break;
        case 7:
            compraMedia(precoCompra,codP,tipoPeca,total);
            break;
        case 8:
            listarTudo(tipoPeca, total);
            break;
        case 9:
            precoAlto(precoVenda,codP,tipoPeca, total, precoCompra);
            break;
        case 10:
            lucro = calcLucro(precoCompra, precoVenda,total);
            printf("Lucro: %.2f€\n\n", lucro);
            break;
        case 11:
            lucroaMedia(total, precoVenda, codP, tipoPeca);
            break;
        case 12:
            calcIva(precoVenda, total);
            break;
        case 0:
            printf("Trabalho realizado por:\nGonçalo Lima - nº17494\nSamuel Rodrigues - nº17495\n\n  ");
            break;
        default:
            printf("Opção inválida");
        }
    } while(opcao != 0);
    return (EXIT_SUCCESS);
}


