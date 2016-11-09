#include <stdio.h>
#include <stdlib.h>
#define N 50

int menu(int tabla[N][N], int disparos_pos[10], char disparos_dir[10]);
int imprimir_tabla(int tabla[N][N]);
int estadistica(int tabla[N][N]);
int lanzar_bola(int tabla[N][N]);
int lanzar_10_bolas(int tabla[N][N], int disparos_pos[10], char disparos_dir[10]);

main(){

int tabla[N][N]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int disparos_pos[10] = {1, 5, 14, 22, 37, 48, 43, 40, 28, 19};
char disparos_dir[10]= {'i','i','d','i','d','d','i','d','d','i'};

menu(tabla,disparos_pos,disparos_dir);
}

int menu(int tabla[N][N], int disparos_pos[10], char disparos_dir[10]){
    int num=0;

    printf("\n\nPinball:\n\n 1.Imprimir tablero.\n 2.Estadistica.\n 3.Lanzar una bola.\n 4.Lanzar diez bolas.\n");
    scanf("%d",&num);

    if (num==1)
        imprimir_tabla(tabla);
    if (num==2)
        estadistica(tabla);
    if (num==3)
        lanzar_bola(tabla);
    if (num==4)
        lanzar_10_bolas(tabla,disparos_pos,disparos_dir);
}

int imprimir_tabla(int tabla[N][N]){
    int i=0,j=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(tabla[i][j]==0)
                printf("  ");
            if(tabla[i][j]==1)
                printf("* ");
            if(tabla[i][j]>1)
                printf("%2d",tabla[i][j]-1);
        }
        printf("\n");
    }
    main();
}

int estadistica(int tabla[N][N]){
    int i=0, j=0, k=0;
    int numero_lineas=0;
    int numero_horizontales=0, numero_verticales=0, numero_diagonales_tipo1=0, numero_diagonales_tipo2=0;
    int mayor=0, horizontal_mayor=0, vertical_mayor=0, diagonal1_mayor=0, diagonal2_mayor=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(tabla[i][j]==1){
                tabla[i][j]=2;
                if(tabla[i][j+1]==1){           //obstaculo horizontal
                    tabla[i][j+1]=2;
                    k=0;
                    numero_horizontales++;
                    while(tabla[i][j+2+k]!=0){
                        tabla[i][j+2+k]=2;
                        k++;
                    }
                    if(2+k>horizontal_mayor)
                        horizontal_mayor=2+k;
                    if(2+k>mayor)
                            mayor=2+k;
                    numero_lineas++;
                }
                if(tabla[i+1][j]==1){           //obstaculo vertical
                    tabla[i+1][j]=2;
                    k=0;
                    numero_verticales++;
                    while(tabla[i+2+k][j]!=0){
                        tabla[i+2+k][j]=2;
                        k++;
                    }
                    if(2+k>vertical_mayor)
                        vertical_mayor=2+k;
                    if(2+k>mayor)
                            mayor=2+k;
                    numero_lineas++;
                }
                else{                           //obstaculo diagonal
                    if(tabla[i+1][j+1]==1){     //diagonal tipo "\"
                        tabla[i+1][j+1]=2;
                        numero_diagonales_tipo1++;
                        k=0;
                        while(tabla[i+2+k][j+2+k]!=0){
                            tabla[i+2+k][j+2+k]=2;
                            k++;
                        }
                        if(2+k>diagonal1_mayor)
                            diagonal1_mayor=2+k;
                        if(2+k>mayor)
                            mayor=2+k;
                        numero_lineas++;
                    }
                    if(tabla[i+1][j-1]==1){     //diagonal tipo "/"
                        tabla[i+1][j-1]=2;
                        numero_diagonales_tipo2++;
                        k=0;
                        while(tabla[i+2+k][j-2-k]!=0){
                            tabla[i+2+k][j-2-k]=2;
                            k++;
                        }
                        if(2+k>diagonal2_mayor)
                            diagonal2_mayor=2+k;
                        if(2+k>mayor)
                            mayor=2+k;
                        numero_lineas++;
                    }
                }
            }
        }
    }
    printf("\n%d %d %d %d ",numero_verticales,numero_horizontales,numero_diagonales_tipo2,numero_diagonales_tipo1);
    printf("%d %d %d %d ",vertical_mayor,horizontal_mayor,diagonal2_mayor,diagonal1_mayor);
    printf("%d %d\n",numero_lineas,mayor);
    //imprimir_tabla(tabla);
    main();
}

int lanzar_bola(int tabla[N][N]){
    char direccion;
    int posicion;
    int i=0, j=0, num=2;

    printf("\nEscriba una posicion inicial (de 1 a 50):\n");
    scanf("%d", &posicion);

    printf("\nEscriba una direccion de impulso (i=izquierda, d=derecha):\n");
    scanf("%c", &direccion);                        //este scanf pilla el "enter" que introducimos al confirmar el scanf anterior
    scanf("%c", &direccion);

    j=posicion-1;
    tabla[i][j]=num;                                //Num >=2 para que, a la hora de imprimir, no se confunda con los obstáculos (1).

    while(i<(N-1)){
        if(tabla[i+1][j]==0){
            i++;
            num++;
            tabla[i][j]=num;
        }
        if(tabla[i+1][j]==1){                      //si hay un obstaculo
            if(direccion=='i'){                    //impulso izquierda
                if(tabla[i][j-1]==0){              //va hacia donde le hemos dado el impulso (si puede)
                    j--;
                    num++;
                    tabla[i][j]=num;
                }
                if(tabla[i][j-1]==1){
                    direccion='d';                  //Cambiamos el impulso
                }
            }
            if(direccion=='d'){                     //Impulso drerecha
                if(tabla[i][j+1]==0){               //Va hacia donde le hemos dado el impulso (si puede)
                    j++;
                    num++;
                    tabla[i][j]=num;
                }
                if(tabla[i][j+1]==1){
                    direccion='i';
                }
            }
        }
    }
    imprimir_tabla(tabla);
}

int lanzar_10_bolas(int tabla[N][N], int disparos_pos[10], char disparos_dir[10]){
    int i=0, j=0, k=0;
    for(i=0;i<10;i++){
        j=0;
        tabla[j][disparos_pos[i]]=2;                    //Marcamos las posiciones por donde pasa una bola con el numero 2. Así, a la hora de imprimir, no se confundirán con un asterisco.
        while(j<(N-1)){
            if((tabla[j+1][disparos_pos[i]])==0){       //Si no hay obstáculo...
                tabla[j+1][disparos_pos[i]]=2;
                j++;
            }
            if((tabla[j+1][disparos_pos[i]])>1){        //Si no hay obstáculo, pero ya ha pasado una bola por ahi...
                tabla[j+1][disparos_pos[i]]++;
                j++;
            }
            if((tabla[j+1][disparos_pos[i]])==1){
                if(disparos_dir[i]=='i'){
                    k=0;
                    if((tabla[j][disparos_pos[i]-1])>1 && k==0){
                        tabla[j][disparos_pos[i]-1]++;
                        disparos_pos[i]--;
                        k=1;
                    }
                    if((tabla[j][disparos_pos[i]-1])==0 && k==0){
                        tabla[j][disparos_pos[i]-1]=2;
                        disparos_pos[i]--;
                        k=1;
                    }
                    if((tabla[j][disparos_pos[i]-1])==1){
                        disparos_dir[i]='d';
                    }
                }
                if(disparos_dir[i]=='d'){
                    k=0;
                    if((tabla[j][disparos_pos[i]+1])>1 && k==0){
                        tabla[j][disparos_pos[i]+1]++;
                        disparos_pos[i]++;
                        k=1;
                    }
                    if((tabla[j][disparos_pos[i]+1])==0 && k==0){
                        tabla[j][disparos_pos[i]+1]=2;
                        disparos_pos[i]++;
                        k=1;
                    }
                    if((tabla[j][disparos_pos[i]+1])==1){
                        disparos_dir[i]='i';
                    }
                }
            }
        }
    }
    imprimir_tabla(tabla);
}
