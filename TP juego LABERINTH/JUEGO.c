#include <unistd.h>
#include <time.h>
#include "aleatorio.c"
#include "intro.c"
void intro();
void aleatorio();
void niveles();
char mover(char laberint[][DIM],int level,int c,int f,char nombre[]);
void tiempos(char nombre[],int hor,int min,int seg);
void leerhighscore();

void main()
{
    intro();
    system("cls");
    char o=0;
    while (o != 4)
    {
            printf("\n\n\n\n\n\t\t\t ________________________~~MENU LABERINTH~~______________________");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|   1. Jugar laberintos aleatorios.");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|   2. Jugar 3 niveles en el menor tiempo.");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|   3. Ver Tiempos.");
            printf("\n\t\t\t|\t\t\t\t\t\t\t\t |");
            printf("\n\t\t\t|   4. Salir.");
            printf("\n\t\t\t|________________________________________________________________|");
            printf("\n\n\t\t\t\t\t   Introduzca opcion (1-4): ");

            gets(&o);

            system("cls");
            switch (o)
            {
                case '1': system("cls");
                        aleatorio();
                        break;

                case '2': system("cls");
                        niveles();
                        break;

                case '3': system("cls");
                        leerhighscore();
                        break;

                case '4': system("cls");
                        return;
            }
    }
    return;
}

void niveles()
{
    time_t inicio=0;
    time_t fin=0;
    time_t pausas=0;
    time_t seg=0,min=0,hor=0;
    int c=0,f=0,repetir=1,i=0;
    char continuar='p',op='p';
    char nombre[DIM];


    while(repetir==1){
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNombre del Jugador: ");
    scanf("%s", &nombre);
    for(i=0;i<nombre[i];i++){
        if(nombre[i]>96 && nombre[i]<123){
            nombre[i]=nombre[i]-32;
        }
    }


    char nivel1[DIM][DIM] = {{177,177,177,177,177,177,177,177,177,177,177,177},
                            {177,32,177,32,32,32,32,32,32,32,177,177},
                            {177,32,32,32,177,32,177,177,177,32,32,177},
                            {177,177,177,32,32,177,32,32,177,177,32,177},
                            {177,32,32,32,177,177,32,32,32,32,177,177},
                            {177,32,177,177,177,32,32,177,177,32,177,177},
                            {177,32,32,32,177,32,32,177,32,32,32,177},
                            {177,177,177,32,32,32,32,177,32,177,32,177},
                            {177,32,32,32,177,177,177,32,32,177,32,177},
                            {177,32,177,177,177,177,32,177,177,32,32,177},
                            {177,32,32,32,32,32,32,32,177,32,32,177},
                            {177,177,177,177,177,177,177,177,177,177,32,177}};

    char nivel2[DIM][DIM] = {{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
                            {177,32,32,32,32,32,177,32,32,32,32,32,177,32,32,32,177,32,177,177,177,177},
                            {177,32,177,32,32,177,32,177,32,177,32,32,177,177,177,32,32,177,32,32,177,177},
                            {177,32,177,177,32,32,32,177,177,32,177,32,32,32,32,32,177,177,32,177,32,177},
                            {177,32,32,32,32,177,32,32,32,177,177,177,32,177,177,32,32,177,177,177,32,177},
                            {177,177,177,177,32,177,177,32,32,32,32,32,32,177,177,32,177,32,32,32,177,177},
                            {177,32,177,32,32,177,177,32,177,177,177,32,32,32,32,177,177,177,177,177,32,177},
                            {177,32,177,177,32,177,177,177,32,32,177,32,177,177,32,32,177,32,177,32,177,177},
                            {177,177,32,32,32,177,177,32,32,32,177,32,177,177,32,177,177,32,32,32,32,177},
                            {177,32,32,177,177,32,32,32,177,32,177,32,177,32,32,32,177,177,177,177,32,177},
                            {177,177,32,177,177,32,177,177,32,177,32,32,177,32,177,177,177,32,177,32,177,177},
                            {177,32,32,32,32,32,177,177,177,32,32,32,177,32,32,32,32,32,177,32,32,177},
                            {177,32,177,177,177,32,177,177,32,177,177,32,32,177,177,32,177,32,177,177,32,177},
                            {177,32,32,177,32,32,32,177,177,32,32,177,32,177,32,32,177,32,32,32,32,177},
                            {177,177,32,32,177,32,32,32,177,32,32,177,32,32,177,177,32,177,177,32,177,177},
                            {177,32,177,32,177,177,32,177,32,177,32,177,32,177,177,32,32,32,32,32,177,177},
                            {177,32,177,32,32,177,32,32,32,177,32,32,32,32,177,32,177,177,177,32,177,177},
                            {177,177,32,177,32,177,177,177,32,32,177,32,177,177,32,32,177,32,177,32,32,177},
                            {177,177,177,32,32,177,177,177,177,32,32,177,32,177,177,32,32,32,177,177,32,177},
                            {177,177,32,32,177,32,32,32,177,32,177,177,32,32,32,32,177,177,32,177,32,177},
                            {177,177,32,32,32,32,177,32,32,32,32,32,177,177,32,32,177,32,32,32,32,177},
                            {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,32,177}};

    char nivel3[DIM][DIM] = {{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
                            {177,32,32,32,32,32,177,32,32,32,32,32,177,32,32,32,177,32,177,177,177,32,32,32,32,32,32,32,177,32,32,32,177,177,32,32,32,177,177,32,32,177},
                            {177,32,177,32,32,177,32,177,32,177,32,32,177,177,177,32,32,177,32,32,177,177,32,32,177,32,177,177,177,32,177,177,32,177,177,32,32,177,32,32,32,177},
                            {177,32,177,177,32,32,32,177,177,32,177,32,32,32,32,32,177,177,32,177,32,32,32,177,32,32,177,177,177,177,32,32,32,177,32,177,177,177,32,177,32,177},
                            {177,32,32,32,32,177,32,32,32,177,177,177,32,177,177,32,32,177,177,177,32,177,177,32,177,32,32,177,177,32,32,177,32,177,32,32,32,177,32,177,32,177},
                            {177,177,177,177,32,177,177,32,32,32,32,32,32,177,177,32,177,32,32,32,32,177,177,32,177,32,177,177,32,177,32,177,177,32,32,32,177,32,32,177,177,177},
                            {177,32,177,32,32,177,177,32,177,177,177,32,32,32,32,177,177,177,177,177,32,177,177,32,177,32,32,177,177,32,32,177,177,32,177,32,177,177,32,177,177,177},
                            {177,32,177,177,32,177,177,177,32,32,177,32,177,177,32,32,177,32,177,32,32,177,177,32,177,177,32,32,32,32,177,32,177,177,32,32,177,32,32,32,177,177},
                            {177,177,32,32,32,177,177,32,32,32,177,32,177,177,32,177,177,32,32,32,32,32,32,177,177,32,177,177,177,32,177,32,32,177,177,32,32,32,177,177,32,177},
                            {177,32,32,177,177,32,32,32,177,32,177,32,177,32,32,32,177,177,177,32,32,177,177,32,32,177,32,32,32,32,177,32,177,32,177,32,32,177,32,32,32,177},
                            {177,177,32,177,177,32,177,177,32,177,32,32,177,32,177,177,177,32,177,32,177,177,177,32,177,177,177,32,177,177,177,32,32,177,32,32,32,177,177,32,32,177},
                            {177,32,32,32,32,32,177,177,177,32,32,32,177,32,32,32,32,32,177,32,32,177,177,177,32,177,177,32,32,32,177,177,32,177,32,177,32,32,177,32,32,177},
                            {177,32,177,177,177,32,177,177,32,177,177,32,32,177,177,32,177,32,177,177,32,177,32,177,32,177,32,177,177,32,32,32,32,32,177,177,32,32,32,177,32,177},
                            {177,32,32,177,32,32,32,177,177,32,32,177,32,177,32,32,177,32,32,32,32,32,32,32,32,32,177,177,177,177,32,177,177,32,177,32,32,177,177,32,32,177},
                            {177,177,32,32,177,32,32,32,177,32,32,177,32,32,177,177,32,177,177,32,177,177,177,32,177,177,32,32,177,32,32,177,177,32,177,177,32,32,177,32,177,177},
                            {177,32,177,32,177,177,32,177,32,177,32,177,32,177,177,32,32,32,32,32,177,32,177,32,32,177,32,32,32,177,32,177,177,32,177,177,177,32,177,32,32,177},
                            {177,32,177,32,32,177,32,32,32,177,32,32,32,32,177,32,177,177,177,32,177,177,177,32,177,177,32,177,177,32,32,32,177,32,32,32,32,32,177,177,32,177},
                            {177,177,32,177,32,177,177,177,32,32,177,32,177,177,32,32,177,32,177,32,32,32,177,177,177,32,32,32,32,32,177,177,177,177,177,177,32,177,32,177,32,177},
                            {177,177,177,32,32,177,177,177,177,32,32,177,32,177,177,32,32,32,177,177,32,177,32,32,32,177,177,177,32,177,177,32,32,177,177,32,32,32,177,32,32,177},
                            {177,177,32,32,177,32,32,32,177,32,177,177,32,32,32,32,177,177,32,32,177,32,32,177,177,32,32,32,32,177,32,32,177,177,32,32,177,32,32,32,177,177},
                            {177,177,32,32,32,32,177,32,32,32,32,32,177,177,32,32,177,32,32,32,32,32,32,32,32,32,177,177,177,32,32,32,32,32,32,32,32,177,32,32,32,177},
                            {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,32,177}};

        system("cls");
        c=12;
        f=12;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPresione cualquier tecla para INICIAR NIVEL 1\n\n");
        system("pause -> NULL");
        inicio = time(NULL);
        continuar=mover(nivel1,1,c,f,nombre);
        if (continuar=='o'){
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNIVEL 1 NO superado\n\n");
            sleep(1.5);
            system("cls");
            repetir=menujugar();
        }
        else{
            fin=time(NULL);
            seg=fin-inicio;
            if(seg>=60){
                        min=seg/60;
                        seg=seg-(min*60);
                    }
                    else if(min>=60){
                        hor=min/60;
                        min=min-(hor*60);
                    }
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   De momento su tiempo es [ %.2d:%.2d:%.2d ]\n\n",hor, min, seg);
            seg=seg+(min*60);
            printf("\n\n\n\t\t\t\t\tPresione cualquier tecla para INICIAR NIVEL 2\n\n");
            system("pause -> NULL");
            inicio=time(NULL);
            c=22;
            f=22;
            continuar=mover(nivel2,2,c,f,nombre);
            if (continuar=='o'){
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNIVEL 2 NO superado\n\n");
                sleep(1.5);
                system("cls");
                repetir=menujugar();
            }
            else{
                fin=time(NULL);
                seg+=fin-inicio;
                if(seg>=60){
                        min=seg/60;
                        seg=seg-(min*60);
                    }
                    else if(min>=60){
                        hor=min/60;
                        min=min-(hor*60);
                    }
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   De momento su tiempo es [ %.2d:%.2d:%.2d ]\n\n",hor, min, seg);
                seg=seg+(min*60);
                printf("\n\n\n\t\t\t\t\tPresione cualquier tecla para INICIAR NIVEL 3\n\n");
                system("pause -> NULL");
                inicio=time(NULL);
                c=42;
                f=22;
                continuar=mover(nivel3,3,c,f,nombre);
                if (continuar=='o'){
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNIVEL 3 NO superado\n\n");
                    sleep(1.5);
                    system("cls");
                    repetir=menujugar();
                }
                else{
                    fin = time(NULL);
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tUsted completo los 3 NIVELES!!!");
                    seg += fin - inicio;
                    if(seg>=60){
                        min=seg/60;
                        seg=seg-(min*60);
                    }
                    else if(min>=60){
                        hor=min/60;
                        min=min-(hor*60);
                    }
                    printf("\n\n\t\t\t\t\t   Su tiempo es [ %.2d:%.2d:%.2d ]\n\n",hor, min, seg);
                    tiempos(nombre,hor,min,seg);
                    printf("\n\n\t\t\t\tPresione cualquier tecla para continuar");
                    system("pause -> NULL");
                    system("cls");
                    repetir=menujugar();
                }

            }
        }
        system("cls");
    }
    return;
}

char mover(char laberint[][DIM],int level,int c,int f,char nombre[])
{
    int i=0, j=0;
    char tecla='p';
    int x=1,y=1,cont=0;

    system ("cls");
    laberint[1][1]=219;

    while((tecla!='o') && (!(x==(c-2)&& y==(f-1))))
    {
        cont=0;
        for(i=0; i<=10; i++){
            if(nombre[i]!=NULL)
                cont++;
        }
        printf("\n\t\t\t\t  _________ ");
        for(j=0; j<=(cont+9); j++){
            printf("_");
        }
        printf("\n\t\t\t\t | NIVEL %i | Jugador: %s |",level,nombre);
        printf("\n\t\t\t\t  %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c",238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238);
        for(j=0; j<=(cont); j++){
            printf("%c",238);
        }
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
        system("cls");
        if((x==(c-2)&& y==(f-1))){
           printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNIVEL %i COMPLETADO!!\n\n", level);
           sleep(1.5);
           system("cls");
        }
    }
    return tecla;
}

void tiempos(char nombre[],int hor,int min,int seg)
{
    int c;
    FILE *arch;
    int i=0,j=0,k=0,l=0,a=0;
    char tiemp[DIM][DIM];
    char temporal[DIM];
    int list=0,cont=0,conta=0,p=1,v[DIM],compara1=0,compara2=0;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            tiemp[i][j]=NULL;
            temporal[j]=NULL;
        }
    }
    arch=fopen("Highscores.dat","rt");
    if(arch==NULL){
        arch=fopen("Highscores.dat","wt");
    }
    c=fread(tiemp,sizeof tiemp,1, arch);

    while(p==1){
        if(tiemp[1][3]==NULL){
            list=0;
        }
        else{
            list=tiemp[(list+1)][3];
        }
        if(tiemp[list+1][4]==NULL){
            tiemp[(list+1)][0]=hor;
            tiemp[(list+1)][1]=min;
            tiemp[(list+1)][2]=seg;

            tiemp[(list+1)][4]=(1);
            p=0;
        }
        else{
            p=1;
        }
        tiemp[(list+1)][3]=list+2;
    }


    for(j=0; j<10; j++){
        tiemp[list][j]=nombre[j];
        cont++;
        if(nombre[j]=='\0'){
            cont=cont-1;
            break;
        }
    }
    for(i=0; i<list; i++){
        for(j=0; j<=cont; j++){
            if(tiemp[i][j]==tiemp[list][j]){
                conta++;
                a=i;
            }
        }
        i++;
        conta=conta-1;
        if(conta==cont)
            break;
        conta=0;
    }
    if (conta==cont){
        compara1=tiemp[list+1][1];
        compara2=tiemp[list+1][2];
        if(tiemp[a+1][1]>compara1 || (tiemp[a+1][1]==compara1 && tiemp[a+1][2]>=compara2)){
            tiemp[a+1][0]=tiemp[list+1][0];
            tiemp[a+1][1]=compara1;
            tiemp[a+1][2]=compara2;
            tiemp[list+1][0]=NULL;
            tiemp[list+1][1]=NULL;
            tiemp[list+1][2]=NULL;
            tiemp[list+1][3]=NULL;
            tiemp[list+1][4]=NULL;
            for(j=0; j<=cont; j++){
                tiemp[list][j]=NULL;
            }
        }
        else{
            for(j=0; j<=cont; j++){
                tiemp[list][j]=NULL;
            }
            tiemp[list+1][0]=NULL;
            tiemp[list+1][1]=NULL;
            tiemp[list+1][2]=NULL;
            tiemp[list+1][3]=NULL;
            tiemp[list+1][4]=NULL;
        }
    }
    cont=0;
    arch=fopen("Highscores.dat","wt");
    if(arch==NULL){
        perror("Error al abrir archivo\n");
        exit(1);
    }
    c=fwrite(tiemp,sizeof tiemp,1, arch);

    if(c!=1){
        perror("Error al guardad archivo\n");
    }
    c=fclose(arch);
    if(c!=0){
        perror("error al cerrar\n");
    }
    return;
}

void leerhighscore()
{
    int c;
    FILE *arch;
    int i=0,j=0,k=0,l=0;
    char tiemp[DIM][DIM];
    char temporal[DIM];
    int list=0,cont=1,p=1,v[DIM];
    int mejormin1=(60), mejormin2=(60), mejormin3=(60),mejorseg1=(60), mejorseg2=(60), mejorseg3=(60);
    char nombre1[DIM],nombre2[DIM],nombre3[DIM];

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            tiemp[i][j]=NULL;
            temporal[j]=NULL;
            nombre1[j]=NULL;
            nombre2[j]=NULL;
            nombre3[j]=NULL;
        }
    }
    arch=fopen("Highscores.dat","rt");
    if(arch==NULL){
        perror("Error al abrir archivo--\n");
        exit(1);
    }
    c=fread(tiemp,sizeof tiemp,1, arch);

    while(p==1){
        if(tiemp[1][3]==NULL){
            list=0;
        }
        else{
            list=tiemp[(list+1)][3];
        }
        if(tiemp[list+1][4]==NULL){
            p=0;
        }
        else{
            p=1;
        }
        tiemp[(list+1)][3]=list+2;
    }


    i=1;
    for (i=1;tiemp[i][4]!=NULL;i++)
    {
        if((tiemp[i][1]<mejormin1 && tiemp[i][1]<=mejormin2 && tiemp[i][1]<=mejormin3) || (tiemp[i][1]==mejormin1 && tiemp[i][2]<=mejorseg1))
        {
                mejormin3=mejormin2;
                mejormin2=mejormin1;
                mejormin1=tiemp[i][1];
                mejorseg3=mejorseg2;
                mejorseg2=mejorseg1;
                mejorseg1=tiemp[i][2];
                for(j=0; j<=10; j++){
                    nombre3[j]=nombre2[j];
                    nombre2[j]=nombre1[j];
                    nombre1[j]=tiemp[i-1][j];
                }
        }
        else if(tiemp[i][1]>=mejormin1 && tiemp[i][1]<mejormin2 && tiemp[i][1]<=mejormin3 || (tiemp[i][1]==mejormin2 && tiemp[i][2]<=mejorseg2))
        {
                mejormin3=mejormin2;
                mejormin2=tiemp[i][1];
                mejorseg3=mejorseg2;
                mejorseg2=tiemp[i][2];
                for(j=0; j<=10; j++){
                    nombre3[j]=nombre2[j];
                    nombre2[j]=tiemp[i-1][j];
                }
        }
        else if(tiemp[i][1]>=mejormin1 && tiemp[i][1]>=mejormin2 && tiemp[i][1]<mejormin3 || (tiemp[i][1]==mejormin3 && tiemp[i][2]<=mejorseg3))
        {
                mejormin3=tiemp[i][1];
                mejorseg3=tiemp[i][2];
                for(j=0; j<=10; j++){
                    nombre3[j]=tiemp[i-1][j];
                }
        }
        else
        {
            tiemp[i][4];
        }
        i++;
    }
    cont=0;
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c    ~~ MEJORES 3 ~~\t%c%c%c%c%c%c%c%c%c%c",201,184,205,184,205,184,205,184,205,205,205,184,205,
           184,205,184,205,184,205,187);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c    1. ",186);
    for(j=0; j<=10; j++){
        printf("%c",nombre1[j]);
        if(nombre1[j]!=NULL)
            cont++;
    }
    for(j=0; j<(10-cont); j++){
        printf(" ");
    }
    cont=0;
    printf(" [ 00:%.2i:%.2i ]",mejormin1,mejorseg1);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    if(mejormin2!=60){
        printf("\n\t\t\t\t%c    2. ",186);
        for(j=0; j<=10; j++){
            printf("%c",nombre2[j]);
            if(nombre2[j]!=NULL)
                cont++;
        }
        for(j=0; j<(10-cont); j++){
            printf(" ");
        }
        cont=0;
        printf(" [ 00:%.2i:%.2i ]",mejormin2,mejorseg2);
    }
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    if(mejormin3!=60){
        printf("\n\t\t\t\t%c    3. ",186);
        for(j=0; j<=10; j++){
            printf("%c",nombre3[j]);
            if(nombre3[j]!=NULL)
                cont++;
        }
        for(j=0; j<(10-cont); j++){
            printf(" ");
        }
        printf(" [ 00:%.2i:%.2i ]",mejormin3,mejorseg3);
    }
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c\t\t\t\t\t %c",186,186);
    printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,
           205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf("\n\n\n\n\n\t\t\t\tPresione cualquier tecla para ver LISTA COMPLETA\n\n");
    system("pause -> NULL");
    system("cls");
    printf("\t\t\t       %c%c\t\t\t\t\t\t%c%c",200,187,201,188);
    printf("\n\t\t\t\t%c\t\t\t\t\t\t%c",186,186);
    printf("\n\t\t\t\t%c     ~~ mejores TIEMPOS de cada jugador ~~     %c",186,186);
    printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,194);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n\t\t\t\t%c\t\t        %c        \t\t%c",186,124,186);
    printf("\n\t\t\t\t%c\tJUGADOR:        %c     \tTIEMPO:\t\t%c",124,124,124);
    printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,193);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
    for(i=0,k=1; tiemp[k][4]!=NULL; i++,k++){
        printf("\n\t\t\t\t|\t ");
        cont=0;
        for(j=0; j<=10; j++){
            printf("%c",tiemp[i][j]);
            if(tiemp[i][j]!=NULL)
                cont++;
        }
        for(j=0; j<(20-cont); j++){
            printf(" ");
        }
        printf(" [ ");
        for(l=0; l<3; l++){
            printf("%.2d:", tiemp[k][l]);
        }
        printf(" ]\t|");
        printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,180);
        k++;
        i++;
    }

    c=fclose(arch);
    if(c!=0){
        perror("error al cerrar\n");
    }

    printf("\n\n\n\n\t\t\t\t\tPresione cualquier tecla para CERRAR\n\n");
    system("pause -> NULL");
    system("cls");
    return;
}


