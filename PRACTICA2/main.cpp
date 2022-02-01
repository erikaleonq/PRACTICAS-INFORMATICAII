#include <iostream>

//LIBRERIAS INCLUIDAS PARA GENERAR LA CADENA DE CARACTERES ALEATORIA EN EL PROBLEMA 2
#include <cstdlib>
#include <ctime>


using namespace std;

//-------------------------------------------------------------FUNCIONES------------------------------------------------------------------

//PROBLEMA 2
void cadenaAleatoria(char *);

//PROBLEMA 3
bool funcionVerif(char *, char *);

//PROBLEMA 5
int contarDigitos(int);
void int_A_char(int , char *);

//PROBLEMA 9
int contarCaracteres(char *);

//PROBLEMA 11
void enumerarColumnas();

//PROBLEMA 17
bool num_amigable(int ,int );


//----------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Ingrese el numero del problema que desea ver: ";
    cin >> n;
    switch (n) {


    //GENERA UN ARREGLO DE 200 LETRAS MAYUSCULAS ALEATORIAS Y CUENTA CUANTAS VECES SE REPITE CADA UNA
    case 2: {
        char CadenaAleatoria[200];
        cadenaAleatoria(CadenaAleatoria);
        cout<<CadenaAleatoria;
        cout<<endl;

        char letras[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        unsigned int cont=0;
        for(int i=0 ; i<26 ; i++){
            for(int j=0 ; j<200 ; j++){
                if(letras[i]==CadenaAleatoria[j]){
                    cont++;
                }
            }
            cout<<letras[i]<<" : "<<cont<<endl;
            cont=0;
        }
    }
        break;

    //COMPARA DOS CADENAS DE CARACTERES
    case 3: {
        char cad1[30], cad2[30];
        cout << "Ingrese la primera cadena de caracteres: ";
        cin >> cad1;
        cout << "Ingrese la segunda cadena de caracteres: ";
        cin >> cad2;

        cout<<funcionVerif(cad1,cad2)<<endl;
    }
        break;

    //RECIBE UN NUMERO INT Y LO CONVIERTE A CADENA DE CARACTERES
    case 5: {
        int num;
        cout<<"Ingrese un numero: ";
        cin>>num;

        char cadena[contarDigitos(num)];
        int_A_char(num, cadena);
    }
        break;

    //RECIBE UNA CADENA Y ELIMINA LOS CARACTERES REPETIDOS
    case 7: {
        char cadena[20], cadenaSinRep[20];
        bool verif=false;
        int posicion=1;
        cout << "Ingrese una cadena de caracteres: ";
        cin >> cadena;
        cadenaSinRep[0]=cadena[0]; //El primer caracter de la cadena ingresada siempre va a ser el mismo que el de la cadena sin repeticiones

        for(int i=1; cadena[i]!='\0';i++){ //Recorremos la cadena hasta que encuentre el caracter de fin de cadenas.
            for(int j=i-1; (cadena[j]!='\0') && (j>=0); j--){ //Recorremos la caadena de nuevo pero de atras hacia adelante
                if(cadena[i]!=cadena[j]){
                    verif=true;
                }
                else{
                    verif=false;
                    break; //En el momento en el que se encuentre que dos caracteres son iguales rompemos el ciclo para que ese caracter no se incluya
                }
            }
            if(verif==true){
                cadenaSinRep[posicion]=cadena[i];
                posicion++;
                verif=false;//Reiniciamos la verificacion
            }

        }
        cout<<"Original: "<<cadena<<endl;
        cout<<"Sin repetidos: "<<cadenaSinRep<<endl;

    }
        break;

    //RECIBE UNA CADENA DE CARACTERES, LOS SEPARA EN NUMEROS DE N CIFRAS, SUMA ESTOS NUMEROS E IMPRIME EL RESULTADO
    case 9: {
        int n, num_caracteres=0, numerofinal=0, verif=0,sumaCharAint=0, mod=1;
        char cad_num[20];
        cout << "Ingrese el numero por el que quiere dividir la cadena de caracteres: ";
        cin >> n;
        cout << "Ingrese la cadena de caracteres: ";
        cin >> cad_num;
        num_caracteres=contarCaracteres(cad_num);
        char copiaCad_num[n];
        int posicion=n-1;

        while(verif<=contarCaracteres(cad_num)){
            for(int i=num_caracteres; i>=0 && posicion>=0 && cad_num[i]!='\0'; i--){ //Copia la cadena nueva con el numero n de caracteres
                copiaCad_num[posicion]=cad_num[i-verif];//Se le resta verif para que en el segundo ciclo se poscione en el i correcto
                if(copiaCad_num[posicion]!='\0') //Verificamos que no tome las posiciones con caracter de final de cadena
                    sumaCharAint=sumaCharAint+(copiaCad_num[posicion]-'0')*mod;
                else
                    break;
                mod=mod*10;
                posicion--;
            }
            numerofinal=numerofinal+sumaCharAint;
            //REINICIO TODOS LOS VALORES
            posicion=n-1;
            mod=1;
            sumaCharAint=0;
            verif=verif+n;
            }
        cout<<"Original: "<<cad_num;
        cout<<"Suma: "<<numerofinal<<endl;
}
        break;

    //MANEJA LAS RESERVAS Y CANCELACIONES DE UNA SALA DE CINE
    case 11:{
        char asientos[15][20];
        int opcion=0, contFILAS=65;
        bool loop=true;

        //CREAMOS LA MATRIZ DE ASIENTOS DISPONIBLES
        enumerarColumnas();
        for(int filas=0; filas<15; filas++){
            cout<<"||"<<char(contFILAS)<<"||";
            for(int columnas=0; columnas<20; columnas++){
                if(columnas<10){
                    cout<<" ";
                    asientos[filas][columnas]='-';
                    cout<<asientos[filas][columnas];
                    cout<<" ";
                    }
                else if(columnas>9 && columnas<21){
                    cout<<"  ";
                    asientos[filas][columnas]='-';
                    cout<<asientos[filas][columnas];
                    cout<<" ";
                }
            }
            cout<<endl;
            contFILAS++;
        }
        contFILAS=65;

        cout<<"1. Realizar una reserva."<<endl;
        cout<<"2. Cancelar una reserva."<<endl;
        cout<<"0. Salir."<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>>opcion;

        if(opcion==0) //SALIRSE DEL PROGRAMA
            loop=false;


        while(loop){

            char escfila;
            int esc_columna, esc_fila;
            cout<<"Ingrese la letra en mayuscula de la fila deseada: ";
            cin>>escfila;
            esc_fila=int(escfila)-64; //ENUMERACION DE LAS FILAS
            cout<<"Ingrese el numero de columna deseado: ";
            cin>>esc_columna;

            for(int filas=0; filas<15; filas++){
                for(int columnas=0; columnas<20; columnas++){
                    if(filas==esc_fila-1 && columnas==esc_columna-1 && opcion==1){ //CAAMBIAMOS DE DISPONIBLE A OCUPADO
                        asientos[filas][columnas]='+';
                            }
                    else if(filas==esc_fila-1 && columnas==esc_columna-1 && opcion==2){ //CAMBIAMOS DE OCUPADO A DISPONIBLE
                        asientos[filas][columnas]='-';
                        }

                    }
                }
            //IMPRIMIMOS LA MATRIZ DE ASIENTOS ACTUALIZADA
            enumerarColumnas();
            for(int filas=0; filas<15; filas++){
                cout<<"||"<<char(contFILAS)<<"||";
                for(int columnas=0; columnas<20; columnas++){
                    //cout<<asientos[filas][columnas];
                    if(columnas<10){
                        cout<<" ";
                        cout<<asientos[filas][columnas];
                        cout<<" ";
                        }
                    else if(columnas>9 && columnas<21){
                        cout<<"  ";
                        cout<<asientos[filas][columnas];
                        cout<<" ";
                    }
                }
                cout<<endl;
                contFILAS++;
             }
            contFILAS=65;

            cout<<"1. Realizar una reserva."<<endl;
            cout<<"2. Cancelar una reserva."<<endl;
            cout<<"0. Salir."<<endl;
            cout<<"Ingrese la opcion deseada: ";
            cin>>opcion;

            if(opcion==0)
                loop=false;
            }
        }
        break;

    //VERIFICA SI UNA MATRIZ ES UN CUADRADO MAGICO
    case 12: {
        int orden;
        bool verif=true;
        cout<<"Ingrese el orden de la matriz: ";
        cin>>orden;
        int matriz[orden][orden];


        cout<<"Ingrese la matriz fila por fila, separe los numeros por espacio y las filas por enter"<<endl;

        for(int fila=0; fila<orden; fila++){
            for(int columna=0; columna<orden; columna++){
                cin>>matriz[fila][columna];
            }
        }

        //MUESTRO LA MATRIZ
        cout<<"***************MATRIZ INGRESADA**************"<<endl;
        for(int fila=0; fila<orden; fila++){
            for(int columna=0; columna<orden; columna++){
                cout<<matriz[fila][columna]<<" ";
            }
            cout<<endl;
        }

        //CONFIRMAMOS QUE NINGÚN NÚMERO SE REPITE
        for(int fila=0; fila<orden; fila++){
            for(int columna=0; columna<orden; columna++){
                for(int filaux=0; filaux<orden; filaux++){
                    for(int columnaux=0; columnaux<orden; columnaux++){
                        if(matriz[fila][columna]==matriz[filaux][columnaux] && fila!=filaux && columna!=columnaux){
                            verif=false;
                            break;
                        }
                    }
                }
            }
        }
        if(verif==false){
            cout<<"La matriz NO es un cuadrado magico. Hay dos numeros iguales"<<endl;
            break;
        }
        //CALCULO DE LA CONSTANTE MAGICA: Suma que debe aparecer en cada fila, columna y diagonal
        int constMagica=0;
        for(int fila=0; fila<orden; fila++){
            for(int columna=0; columna<orden; columna++){
                constMagica=constMagica+matriz[fila][columna];
            }
        }
        constMagica=constMagica/orden;

        //CONFIRMAMOS QUE LAS SUMAS SEAN IGUAL AL NUMERO MAGICO
        int sumaFila=0, sumaColumna=0, sumaDiagonal=0, columnaux=0;
        for(int fila=0; fila<orden; fila++){
            sumaDiagonal=sumaDiagonal+matriz[fila][columnaux]; //CONFIRMACION DE DIAGONAL
            for(int columna=0; columna<orden; columna++){
                sumaFila=sumaFila+matriz[fila][columna];  //CONFIRMACION DE FILAS
                sumaColumna=sumaColumna+matriz[columna][fila]; //CONFIRMACION COLUMNAS
            }
            if(sumaFila!=constMagica || sumaColumna!=constMagica){                //CONFIRMACION DE FILAS Y COLUMNAS
                verif=false;
                break;
            }
            sumaFila=0;
            sumaColumna=0;
            columnaux++;
        }

        if(sumaDiagonal!=constMagica){                //CONFIRMACION DE DIAGONAL
            verif=false;
        }

        if(verif==false){   //IMPRIMO SI ES CUADRADO MAGICO O NO
            cout<<"La matriz NO es un cuadrado magico."<<endl;
        }
        else if (verif==true){
            cout<<"La matriz es un cuadrado magico."<<endl;
        }
    }
        break;


    //RECIBE UN NUMEROI Y SUMA LOS NUMEROS AMIGABLES MENORES A EL
    case 17: {
        int num ,sum_amigables=0;
            cout<<"Ingrese un numero: ";
            cin>>num;
            for( int i=220;i<num;i++){//Recorre todos los numeros menores que el numero ingresado desde 220 que es el primer numero amigable
                for( int j=220;j<num;j++){
                   if(num_amigable(i,j)==true && i!=j){
                       sum_amigables=sum_amigables+i;//Sumando los numeros amigables encontrados
                             }
                        }
            }
           cout<<"El resultado de la suma es: "<<sum_amigables<<endl;
    }
        break;
    }
    return 0;
}

//-----------------------------------------------------FUNCIONES-----------------------------------------------------

//PROBLEMA 2
    void cadenaAleatoria(char *CadenaAleatoria){
        srand(time(NULL)); //Necesario para que rand no cree los mismo numeros
        for(int i=0 ; i<200 ; i++){
            //Por notación:
            CadenaAleatoria[i]=65+rand()%(91-65);
            //variable = limite inicial + rand() % (limite superior+1 - limite inferior)
        }
    }

//PROBLEMA 3
bool funcionVerif(char *cad1, char *cad2){
    bool verif=false;
    int cont1=0, cont2=0;

    //longitud de las cadenas
    for(int i=0 ; cad1[i]!='\0' ; i++)
        cont1++;
    for(int i=0 ; cad2[i]!='\0' ; i++)
        cont2++;

    if(cont1==cont2){
        for(int i=0; (cad1[i]!='\0' && cad2[i]!='\0') ; i++){
            if (cad1[i]==cad2[i]){
                verif=true;
            }
            else{
                verif=false;
                break;
            }
        }
    }
    return verif;
}

//PROBLEMA 5
int contarDigitos(int num){
    int mod=0, cont=0;
    for(int i=0; num>0 ; i++){
        mod=num%10;
        num=num/10;
        cont++;
    }
    return cont;
}
void int_A_char(int num, char *cadena){

    //CONTAMOS LOS DIGITOS DEL NUMERO
    int cont=contarDigitos(num), mod=0;
    for(int i=0; num>0 ; i++){
        mod=num%10;
        cadena[cont-1]=(mod+'0');
        num=num/10;
        cont--;
    }
    cout<<cadena<<endl;
}

//PROBLEMA 9

int contarCaracteres(char *cadena){
    int cont=0;
    for(int i=0; cadena[i]!='\0' ; i++){
        cont++;
    }
    return cont-1;
}

//PROBLEMA 11

void enumerarColumnas(){
    cout<<"******************************ASIENTOS DISPONIBLES******************************"<<endl;
    cout<<"     ";
    for(int i=0; i<20; i++){
        cout<<" ";
        cout<<i+1;
        cout<<" ";
    }
    cout<<endl;
}

//PROBLEMA 17
bool num_amigable(int num1,int num2){
    int sum_divisores_num1=0,sum_divisores_num2=0;

    //DIVISORES PRIMER NUMERO
     for (int i=1; i<num1; i++){
        if (num1%i == 0){//Para encontrar los divisores
            sum_divisores_num1=sum_divisores_num1+i; //i es el divisor encontrado
        }
     }

     if(sum_divisores_num1==num2){ //compruebo si la suma de los divisores de num1 es igual a num2
         //DIVISORES SEGUNDO NUMERO
         for (int i=1; i<num2; i++){
            if (num2%i == 0){
                sum_divisores_num2=sum_divisores_num2+i;
            }
         }
    }
     if(sum_divisores_num2==num1){
         return true;
     }
     else {
         return false;
     }
}





















