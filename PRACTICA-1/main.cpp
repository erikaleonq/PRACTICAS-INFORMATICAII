#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Ingrese el problema que desea ver: ";
    cin>>n;
    switch (n) {
    case 2: {
        cout<<"Programa que muestra la minima combinacion de billetes y monedas para la siguiente cantidad de dinero"<<endl;
        int dinero_ini, cant_bi=0;
        cout<<"Ingrese la cantidad de dinero: ";
        cin >> dinero_ini;

        int bill_mon[10] = {50000,20000,10000,5000,2000,1000,500,200,100,50};

        for(int i=0; i<10; i++){
            cant_bi=dinero_ini/bill_mon[i];
            dinero_ini=dinero_ini%bill_mon[i];
            cout<<bill_mon[i]<<" : "<<cant_bi<<endl;
            cant_bi=0;
        }
        cout<<"Faltante : "<<dinero_ini<<endl;
    }
        break;

    case 4: {
        cout<<"Programa que muestra la hora despues de pasado un tiempo"<<endl;
        int num1,num2,min_verf1,horas_verf1,min_verf2,horas_verf2,min,horas_aux=0,horas,tiempo;
        cout<<"Ingrese la hora en formato 24h: ";
        cin>>num1;
        min_verf1=num1%100; //MINUTOS DE LA HORA INGRESADA
        horas_verf1=num1/100; //HORAS DE LA HORA INGRESADA

        //VERIFICACION DEL FORMATO 24H
        while((min_verf1>59)||(horas_verf1>23)){
            cout<<"Ingrese la hora en formato 24h: ";
            cin>>num1;
            min_verf1=num1%100;
            horas_verf1=num1/100;
        }
        cout<<"Ingrese el tiempo de duracion: ";
        cin>>num2;
        min_verf2=num2%100;
        horas_verf2=num2/100;

        //VERIFICACION FORMATO 24H
        while((min_verf2>59)||(horas_verf2>23)){
            cout<<"Ingrese el tiempo de duracion: ";
            cin>>num2;
            min_verf2=num2%100;
            horas_verf2=num2/100;
        }
        min=(num1%100)+(num2%100);
        while(min>59){
            horas_aux++;
            min=min%60;
                     }
        horas=(num1/100)+(num2/100)+horas_aux;
        tiempo=min+(horas*100);
        if(tiempo>2359){
            tiempo=tiempo-2400;
        }
        cout<<"La hora es: "<<tiempo<<endl;

    }
        break;

    case 5: {
        cout<<"Programa que muestra la figura de un rombo"<<endl;
        int N;
        cout<<"Ingrese un numero impar: ";
        cin >>N;
        while(N%2==0){
            cout<<"Ingrese un numero impar: ";
            cin >>N;
        }

        for (int i=1; i<N-i; i++){
            for(int j=0;j<=N/2-i;j++){
                cout<<" ";
            }
            for(int h=1; h<=2*i-1; h++){
                cout<<"*";
            }
            cout<<endl;
        }
        for (int i=0; i<=N-i; i++){
            for(int j=N-1;j>=N-i;j--){
                cout<<" ";
            }

            for(int h=N; h>=2*i+1; h--){
                cout<<"*";
            }
            cout<<endl;
        }

    }
        break;

    case 7: {
        cout<<"Suma de los numeros pares menores a n en la serie de Fibonacci"<<endl;
        int num, sum_fibo=1, fibo_aux=0,sum=0;
        cout<<"Ingrese un numero: ";
        cin >>num;

        while(sum_fibo<num){ //Confirmo que la suma sea siempre menor que el numero ingresado
            fibo_aux=sum_fibo-fibo_aux; //numero anterior del actual (sum_fibo)
            sum_fibo=sum_fibo+fibo_aux;

            //COMPROBANDO QUE TOME LOS NUMEROS PARES Y DIFERENTES AL NUMERO INGRESADO
            if ((sum_fibo%2==0)&(sum_fibo!=num)){
                sum=sum_fibo+sum;
            }
        }
        cout<<"El resultado de la suma es: "<<sum<<endl;
    }
        break;

    case 9: {
        cout<<"Suma de todos los digitos de n elevados a si mismos"<<endl;
        int N,div,mod,pot=1,sum=0;
        cout << "Ingrese un numero: ";
        cin >> N;

        div=N/10;
        mod=N%10; //ULTIMO DIGITO

        while (div>1){ //SI PONEMOS DE CONDICION div>=0 SE QUEDA EN UN CICLO INFINITO
            pot=1;
            for(int i=1;i<=mod;i++){
                pot=mod*pot; //POTENCIA DEL DIGITO CON SI MISMO
            }
            sum=pot+sum;
            mod=div%10;
            div=div/10;
                        }
        //POTENCIA DEL PRIMER DIGITO
        pot=1;
        for(int i=1;i<=mod;i++){
            pot=mod*pot;
        }
        sum=sum+pot;
        cout<<"El resultado de la suma es: "<<sum<<endl;

    }
        break;

    case 11: {
        cout<<"Minimo comun multiplo de los numeros menores a n"<<endl;
        int N,num,num_aux,bin=1, mcm;
        cout<<"Ingrese un numero: ";
        cin>>N;
        num=N;
        num_aux=N-1;
        mcm=N*num_aux;
        while(bin==1){
             for (int num=N;num>=1;num--){
                if(mcm%num!=0){
                  mcm=N*(N+num_aux);
                  num_aux++;
                  break;
                }
                if(num==1){
                  cout<<"El minimo comun multiplo es: "<<mcm<<endl;
                  bin=0;
                     }
                     }
                      }
    }
        break;

    case 13: {
        cout<<"Suma de todos los numeros primos menores que n"<<endl;
        int N,cont_primo=0,sum=0;
        cout<<"Ingrese un numero: ";
        cin>>N;
        //RECORRIENDO LOS NUMEROS HASTA N
        for(int i=2; i<N; i++){
            cont_primo=0;
            //BUSCANDO NUMEROS PRIMOS
            for(int j=1; j<=i; j++){
                if(i%j==0){
                cont_primo++;
                    }
            }
            //SI SON PRIMOS LOS VA SUMANDO
            if(cont_primo==2){
            sum=i+sum;
                }
        }
        cout<<"El resultado de la suma es: "<<sum<<endl;
    }
        break;

    case 14: {
        cout<<"Numero palindromo mas grande obtenido por lo multiplicacion de dos numeros de tres digitos"<<endl;
        int mul,div,mod,sum=0,palin=0, mult1, mult2;
        //RECORREMOS LOS NUMEROS DE 100 A 999
        for(int i=100; i<=999; i++){
            for(int j=100; j<=i; j++){
                mul=i*j; //MULTIPLICAMOS CADA COMBINACION POSIBLE
                div=mul;
                sum=0;

                //ARMANDO EL NUMERO DE ATRAS PARA ADELANTE (CONFIRMAR SI ES PALINDROMO)
                while (div>0){
                    mod=div%10;
                    sum=sum*10+mod;
                    div=div/10;
                }

                //SI SUM==MUL EL NUMERO ES PALINDROMO
                if(sum==mul){
                    //SE VA GUARDANDO EL MAS GRANDE
                    if(palin<mul){
                        palin=mul;
                        mult1=i;
                        mult2=j;
                    }
                }
            }
        }
        cout<<mult1<<"*"<<mult2<<"="<<palin<<endl;
    }
        break;

    case 15: {
        cout<<"Suma de la diagonal de una espiral nxn"<<endl;
        int N, num=1, sum=2, res=0;
        cout<<"Ingrese un numero impar: ";
        cin>>N;

        //VERIFICACION DE NUMERO IMPAR
        while(N%2==0){
        cout<<"Ingrese un numero impar: ";
        cin>>N;}

        for(int i=0; i<(N-1)/2;i++){
            //SIEMPRE SON CUATRO NUMEROS A SUMAR
            for(int j=0; j<4; j++){
                res=res+num;
                num=num+sum;
            }
            //CADA CUANTOS NUMEROS SUMA
            sum=sum+2;
        }
        res=res+num;
        cout<<"En una espiral "<<N<<"x"<<N<<" la suma es: "<<res<<endl;
    }
        break;

    case 17: {
        cout<<"Numero triangular que tiene n divisores"<<endl;
        int k, cont=0, trian;
        cout<<"Ingrese el numero de divisores: ";
        cin>>k;
        for (int i=1; cont<=k ; i++){
                cont=0;
                //NUMERO TRIANGULAR EN LA POSICION i
                trian=i*(i+1)/2;
                //ENCUENTRO LOS DIVISORES DEL NUMERO
                for(int j=1; j<=trian; j++){
                    if(trian%j==0){
                        cont++;
                    }
                    }
                }
        cout<<"El numero es: "<<trian<< " que tiene "<<cont<<" divisores."<<endl;
    }
        break;
    }
    return 0;
}
