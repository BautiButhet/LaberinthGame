#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define DIM 50

/*
(Para acordarme)
ARRIBA 0 w
ABAJO 1 s
DERECHA 2 d
IQUIERDA 3 a
X son columnas
Y son filas
*/
int menujugar();
void moverse(char laberint[DIM][DIM],int f, int c);


void aleatorio()
{
    char laberint[DIM][DIM];
    int direcc=1, repetir=1;
    int movimiento=0;
    int x=0, y=0, opc=1,i=0,j=0;
    int f=0,c=0,n=0;
    FILE *arch;

    while (repetir==1)
    {
        for (i=0;i<DIM;i++){
            for(j=0;j<DIM;j++)
                laberint[i][j]=NULL;
        }
        opc=1;
        printf("\n\n\n\n\n\n\n\t\t%c Ingres la Cantidad de FILAS (el alto) del laberinto (MAX 50)(MIN 5): ",16);
        scanf("%i", &f);
        printf("\n\t\t%c Ingres la Cantidad de COLUMNAS (el ancho) del laberinto (MAX 50)(MIN 5): ",16);
        scanf("%i", &c);

    //para la maquina q genere un laberinto aleatorio
        while (opc==1)
        {
            srand(time(NULL));
            for(y=0;y<f;y++){
                for(x=0;x<c;x++){
                    if((( y>0 && y<(f-1) && x>0 && x<(c-1) ) && (rand()%5<3))  ||  (x==(c-2)&& y==(f-1))){
                        laberint[y][x]=' ';
                    }
                    else{
                        laberint[y][x]=177; // 176, 178, 219 para cambiar las paredes me sirven estos (en ascii)
                    }
                }
            }
            x=0;
            y=0;
            arch=fopen("Laberint.dat", "w");
            if(arch != NULL){
            //ESCRIBE EL LABERINTO EN EL ARCHIVO
                n = fwrite (laberint, sizeof (laberint), 1, arch);
                if(n!= 1){
                    printf("Error al grabar");
                }
            //CIERRA EL ARCHIVO
                if( fclose(arch)!=0){
                    printf("Error al cerrar");
                }
            }
            else{
                printf("Error al crear el archivo");
            }

        //evalua q sea resolvible
            x=1;
            y=1;
            direcc=1;
            laberint[1][1]='-';
            for(movimiento=0;(!(x==(c-2) && y==(f-1))) && movimiento<=((c-1)*(f-1)) && x<c && y<f;movimiento++){
                switch(direcc)
                {
                    case 0:
                    {
                    if(laberint[y][x+1]==' '|| laberint[y][x+1]=='-'){
                        x=x+1;      /*DERECHA*/
                        direcc=2;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y-1][x]==' '|| laberint[y-1][x]=='-'){
                        y=y-1;      /*ARRIBA*/
                        direcc=0;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x-1]==' '|| laberint[y][x-1]=='-'){
                        x=x-1;      /*IQUIERDA*/
                        direcc=3;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y+1][x]==' '|| laberint[y+1][x]=='-'){
                        y=y+1;      /*ABAJO*/
                        direcc=1;
                        laberint[y][x]='-';
                        break;
                    }
                }
                    case 1:
                    {
                    if(laberint[y][x-1]==' '|| laberint[y][x-1]=='-'){
                        x=x-1;
                        direcc=3;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y+1][x]==' '|| laberint[y+1][x]=='-'){
                        y=y+1;
                        direcc=1;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x+1]==' '|| laberint[y][x+1]=='-'){
                        x=x+1;
                        direcc=2;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y-1][x]==' '|| laberint[y-1][x]=='-'){
                        y=y-1;
                        direcc=0;
                        laberint[y][x]='-';
                        break;
                    }
                }
                    case 2:
                    {
                    if(laberint[y+1][x]==' '|| laberint[y+1][x]=='-'){
                        y=y+1;
                        direcc=1;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x+1]==' '|| laberint[y][x+1]=='-'){
                        x=x+1;
                        direcc=2;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y-1][x]==' '|| laberint[y-1][x]=='-'){
                        y=y-1;
                        direcc=0;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x-1]==' '|| laberint[y][x-1]=='-'){
                        x=x-1;
                        direcc=3;
                        laberint[y][x]='-';
                        break;
                    }
                }
                    case 3:
                    {
                    if(laberint[y-1][x]==' '||laberint[y-1][x]=='-'){
                        y=y-1;
                        direcc=0;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x-1]==' '||laberint[y][x-1]=='-'){
                        x=x-1;
                        direcc=3;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y+1][x]==' '||laberint[y+1][x]=='-'){
                        y=y+1;
                        direcc=1;
                        laberint[y][x]='-';
                        break;
                    }
                    else if(laberint[y][x+1]==' '||laberint[y][x+1]=='-'){
                        x=x+1;
                        direcc=2;
                        laberint[y][x]='-';
                        break;
                    }
                }
            }
        }
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t%c%c%c BUSCANDO LABERINTO %c%c%c\t",157,155,157,157,155,157);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t%c%c%c BUSCANDO LABERINTO %c%c%c\t",155,157,155,155,157,155);
        if (!(x==(c-2)&&y==(f-1))){
 //         printf("NO tiene salida");
            opc=1;
        }
        else{
   //   printf("SI tiene salida!!");
        opc=0;
        }
        //para ver la resolucion que hace la maquina
    /*    printf("\n\n");
        for(y=0;y<f;y++){
            printf("\t");
            for(x=0;x<c;x++){
                printf("%c", laberint[y][x]);
            }
            printf("\n");
        }
        printf("\n");       */
    }

    //para jugar
        if (opc==0){
            arch=fopen("Laberint.dat", "rt");
            if(arch != NULL){
                n = fread (laberint, sizeof (laberint), 1, arch);
                if(n!= 1){
                    printf("Error al leer\n");
                }
                else{
                    moverse(laberint,f,c);
                }
                if( fclose(arch)!=0){
                    printf("Error al cerrar\n");
                }
            }
            else{
                printf("Error al abrir el archivo\n");
            }
        }
        repetir=menujugar();
        system("cls");
    }
    system("cls");
    return;
}

void moverse(char laberint[DIM][DIM],int f, int c)
{
    int i=0, j=0;
    char tecla='p';
    int x=1,y=1;

    system ("cls");
    laberint[1][1]=219;

    while((tecla!='o') && (!(x==(c-2)&& y==(f-1))))
    {
        printf("\t\t\t\t  ___________ _________ ");
        printf("\n\t\t\t\t | LABERINTO | %2i x %2i |",f,c);
        printf("\n\t\t\t\t  %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c",238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238);
        printf("\n\n");
        for(i=0;i<f;i++)
        {
            printf("\t\t\t\t");
            for(j=0;j<c;j++)
            {
                printf("%c", laberint[i][j]);
            }
            printf("\n");
        }
        printf("\n\t\tIngrese movimiento con a(%c),w(%c),s(%c),d(%c). Presione 'o' para ABANDONAR: ",17,30,31,16);
        scanf("%c", &tecla);
        system("cls");
        if (tecla=='w'){
            if((laberint[y-1][x]==' ') || (laberint[y-1][x]=='-')){
                laberint[y][x]='-';
                y--;
                laberint[y][x]=219;
            }
        }
        else if (tecla=='s'){
            if((laberint[y+1][x]==' ') || (laberint[y+1][x]=='-')){
                laberint[y][x]='-';
                y++;
                laberint[y][x]=219;
            }
        }
        else if (tecla=='a'){
            if(laberint[y][x-1]==' ' || laberint[y][x-1]=='-'){
                laberint[y][x]='-';
                x--;
                laberint[y][x]=219;
            }
        }
        else if (tecla=='d'){
            if(laberint[y][x+1]==' ' || laberint[y][x+1]=='-'){
                laberint[y][x]='-';
                x++;
                laberint[y][x]=219;
            }
        }
        if((x==(c-2)&& y==(f-1))){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLaberinto superado!!\n\n");
            sleep(1.5);
            system("cls");
        }
    }
    return;
}

int menujugar()
{
    char o=0, repetir=0;
    while (o != 2)
    {
            printf("\n\n\n\n\n\n\n\t\t\t ________________________________________________________________\n");
            printf("\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|\t   1. Jugar de nuevo.");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|\t   2. Volver al Menu.");
            printf("\n\t\t\t|________________________________________________________________|");
            printf("\n\n\t\t\t\t\t   Introduzca opcion (1-2): ");


            gets(&o);
            system("cls");
            switch(o)
            {
                case '1': repetir=1;
                        return repetir;

                case '2': repetir=0;
                        return repetir;
            }
    }
    return repetir;
}

