#include <iostream>
#include <fstream> //Para trabajar con archivos de texto
#include <string>

using namespace std;

//--------------------------------------------FUNCIONES--------------------------------------------------------

void Archivo_a_Binario(); //Convierte el archivo Original a Binario.
string Decimal_a_Binario(char); //Convierte una letra a binario.
string Binario_a_letra(string);

//APLICACION
void inicio_admin();
void datos_adminCodificados();

//-------------------------------------------------------------------------------------------------------------
int main()
{
    while (true){

    int punto;
    cout << "1. Codificar archivos de texto."<<endl;
    cout << "2. Decodificar el archivo generado por el programa anterior."<<endl;
    cout << "3. Sistema de registro de usuarios."<<endl;
    cout << "Ingrese ejercicio que desee ver: ";
    cin >> punto;
    switch (punto) {
    case 1:{

        int metodo_cod;
        cout << "Ingrese el metodo de codificacion que desee emplear (1 o 2): ";
        cin >> metodo_cod;

        switch (metodo_cod) {

        case 1:{
        Archivo_a_Binario();

        ifstream archivo_binario;
        ofstream archivoCodificado;
        unsigned int n;
        string num, bin_semilla="", bin_codificado="", bin_aux, ArchivoSalida="";

        cout << "Ingrese el nombre del archivo en donde se guardara la informacion codificada: ";
        cin >> ArchivoSalida; //EL USUARIO ELIGE EL NOMBRE DEL ARCHIVO DONDE SE GUARDARA LA INFORMACION CODIFICADA

        int bloque=1, ceros=0, unos=0;
        archivo_binario.open("ArchivoBinario.txt"); //Abrimos el archivo binario de escritura creado para usarlo como lectura
        archivoCodificado.open(ArchivoSalida);

        cout<<"Ingrese una semilla: ";
        cin >> n;
        cout<<endl;

        while ((archivo_binario.good()) && (bin_semilla.length()<n)){
            for(int i=0;bin_semilla.length()<n;i++){
                num=archivo_binario.get(); //Obtengo caracter a caracter la informacion del archivo binario
                bin_semilla=bin_semilla + num; //Usamos bin_semilla para guardar el binario creado con la semilla
                        }
                    if (bloque==1){ //En el bloque uno cambiamos los ceros por unos y viceversa
                        bin_codificado=bin_semilla;
                        for(unsigned int i=0; bin_semilla.length()>i; i++){
                            if(bin_semilla[i]=='0'){
                                bin_codificado[i]='1';
                                }
                            else {
                                bin_codificado[i]='0';
                            }
                        }
                        bloque=2;
                        }
                    else { //Para los siguientes bloques contamos los unos y ceros en el bloque anterior SIN CODIFICAR
                        for(unsigned int i=0; bin_aux.length()>i; i++){
                            if(bin_aux[i]=='0'){
                                ceros++;
                            }
                            else{
                                unos++;
                            }
                            }
                        if(ceros==unos){ //Se cambian ceros por uno y viceversa
                            bin_codificado=bin_semilla;
                            for(unsigned int i=0; bin_semilla.length()>i; i++){
                                if(bin_semilla[i]=='0'){
                                    bin_codificado[i]='1';
                                    }
                                else {
                                    bin_codificado[i]='0';
                                        }
                                    }
                                        }
                        else if (ceros>unos){ //Se invierte cada dos digitos
                            bin_codificado=bin_semilla;
                            for(unsigned int i=1; bin_semilla.length()>i; i+=2){
                                if(bin_semilla[i]=='0'){
                                    bin_codificado[i]='1';
                                                       }
                                else if(bin_semilla[i]=='1'){
                                    bin_codificado[i]='0';
                                                }
                                              }
                                            }
                        else if (ceros<unos){ //Se invierte cada tres digitos
                            bin_codificado=bin_semilla;
                            for(unsigned int i=2; bin_semilla.length()>i; i+=3){
                                if(bin_semilla[i]=='0'){
                                    bin_codificado[i]='1';
                                            }
                                else if(bin_semilla[i]=='1'){
                                    bin_codificado[i]='0';
                                                }
                                        }
                                    }
                        }
                archivoCodificado<<bin_codificado; //Escribimos el binario codificado en el archivo

                //REINICIAMOS LAS VARIABLES
                bin_aux=bin_semilla; //bin_aux nos permite tener el valor del anterior bloque sin codificar
                bin_semilla="";
                bin_codificado="";
                ceros=0;
                unos=0;
    }
            archivo_binario.close();
            archivoCodificado.close();
    }
        break;

    case 2: {
        Archivo_a_Binario();

        ifstream archivo_binario;
        ofstream archivoCodificado;

        unsigned int n;
        string num, bin_semilla="", ArchivoSalida="";
        cout << "Ingrese el nombre del archivo en donde se guardara la informacion codificada: ";
        cin >> ArchivoSalida;
        archivo_binario.open("ArchivoBinario.txt"); //Abrimos el archivo binario de escritura creado para usarlo como lectura
        archivoCodificado.open(ArchivoSalida);
        cout<<"Ingrese una semilla: ";
        cin >> n;
        cout<<endl;
        while ((archivo_binario.good()) && (bin_semilla.length()<n)){
            for(int i=0;bin_semilla.length()<n;i++){
                num=archivo_binario.get();
                bin_semilla=bin_semilla + num; //Usamos bin_semilla para guardar el binario creado con la semilla
                        }
            bin_semilla=bin_semilla[n-1] + bin_semilla; //Tomamos el ultimo caracter y se lo anadimos al string original
            bin_semilla.pop_back();   //esto hace que quede al inicio de la cadena
            //Elimina el ultimo elemento del string

            archivoCodificado<<bin_semilla;
            bin_semilla="";
        }
        archivo_binario.close();
        archivoCodificado.close();
    }
        break;
    }
    }
        break;

        //EJERCICIO 2
    case 2: {
        int metodo_codificacion;
        cout << "Ingrese el metodo que se uso para codificar: ";
        cin >> metodo_codificacion;
        string ArchivoEntrada="", ArchivoSalida="";
        cout << "Ingrese el nombre del archivo codificado: ";
        cin >> ArchivoEntrada;
        cout << "Ingrese el nombre del archivo en donde se guardara la informacion decodificada: ";
        cin >> ArchivoSalida;
        switch (metodo_codificacion) {
        case  1: {
            string binario, binario_semilla="", binario_decodif="", bin_aux;
            ifstream archivo_codificado;
            ofstream archivo_decodificado;
            archivo_codificado.open(ArchivoEntrada);
            archivo_decodificado.open(ArchivoSalida);
            unsigned int n, bloque=1, ceros=0, unos=0;
            cout<<"Ingrese la semilla que uso para codificar: ";
            cin >> n;
            cout<<endl;
            while (archivo_codificado.good()){
                while ((!archivo_codificado.eof()) && (binario_semilla.length()<n)) {
                    for(int i=0;binario_semilla.length()<n;i++){
                        binario=archivo_codificado.get();
                        binario_semilla=binario_semilla + binario; //Usamos binario_aux para guardar el binario creado con la semilla
                                }
                    if (bloque==1){
                        binario_decodif=binario_semilla; //creamos binario_decodif para guardar el binario decodificado
                        for(unsigned int i=0; binario_semilla.length()>i; i++){
                            if(binario_semilla[i]=='0'){
                                binario_decodif[i]='1';
                                }
                            else {
                                binario_decodif[i]='0';
                                }
                            }
                        bloque=2;
                        }
                     else{
                        for(unsigned int i=0; bin_aux.length()>i; i++){
                            if(bin_aux[i]=='0'){
                                ceros++;
                                    }
                            else{
                                unos++;
                                }
                            }
                        if (ceros==unos){
                            binario_decodif=binario_semilla;
                            for(unsigned int i=0; binario_semilla.length()>i; i++){
                                if(binario_semilla[i]=='0'){
                                    binario_decodif[i]='1';
                                    }
                                else {
                                    binario_decodif[i]='0';
                                    }
                                }
                            }
                        else if (ceros>unos){ //Se invierte cada dos digitos
                            binario_decodif=binario_semilla;
                            for(unsigned int i=1; binario_semilla.length()>i; i+=2){
                                if(binario_semilla[i]=='0'){
                                    binario_decodif[i]='1';
                                    }
                                else if(binario_semilla[i]=='1'){
                                    binario_decodif[i]='0';
                                    }
                                }
                            }
                        else if (ceros<unos){ //Se invierte cada tres digitos
                            binario_decodif=binario_semilla;
                            for(unsigned int i=2; binario_semilla.length()>i; i+=3){
                                if(binario_semilla[i]=='0'){
                                    binario_decodif[i]='1';
                                    }
                                else if(binario_semilla[i]=='1'){
                                    binario_decodif[i]='0';
                                    }
                                }
                            }
                        }
                    string binario="";
                    bool verif=true;
                    while(verif==true){
                        binario=binario_decodif+binario;
                        verif=false; //PARA QUE NO ENTRE CON EL MISMO NUMERO
                        }
                    string letra=Binario_a_letra(binario);
                    archivo_decodificado<<letra;
                    bin_aux=binario_decodif;
                    binario_semilla="";
                    binario_decodif="";
                    ceros=0;
                    unos=0;
                    verif=true;
                    }
                }

                archivo_codificado.close();
                archivo_decodificado.close();
            }
                break;

            case 2: {
                ifstream archivo_codificado;
                ofstream archivo_decodificado;
                unsigned int n;
                string binario, binario_semilla="", binario_decodificado="";
                archivo_codificado.open(ArchivoEntrada); //Abrimos el archivo binario de escritura creado para usarlo como lectura
                archivo_decodificado.open(ArchivoSalida);
                cout<<"Ingrese la semilla que uso para codificar: ";
                cin >> n;
                cout<<endl;
                while (archivo_codificado.good()){
                    while ((!archivo_codificado.eof()) && (binario_semilla.length()<n)) {
                        for(int i=0;binario_semilla.length()<n;i++){
                            binario=archivo_codificado.get();
                            binario_semilla=binario_semilla + binario; //Usamos bin_semilla para guardar el binario creado con la semilla
                                }
                        for(unsigned int i=0; i<n-1 ; i++){
                           binario_decodificado=binario_semilla[n-1] + binario_semilla;
                           binario_decodificado.pop_back();
                           binario_semilla=binario_semilla[n-1] + binario_semilla;
                           binario_semilla.pop_back();
                        }
                        archivo_decodificado<<binario_decodificado;
                        binario_semilla="";
                    }
                    archivo_codificado.close();
                    archivo_decodificado.close();
                }

            }
                break;
            }
        }
            break;

    //APLICACION
    case 3: {
        int opcion;
        cout<<endl;
        cout << "Usuario administrador: erikaleonq    clave: clavedeacceso"<<endl;
        cout <<endl;
        cout << "Bienvenido!"<<endl;
        cout << "1. Acceder como usuario administrador."<<endl;
        cout << "2. Acceder como usuario."<<endl;
        cout << "Digite la opcion que desea realizar: ";
        cin >> opcion;
        switch (opcion) {
        case 1: {
            inicio_admin();
            ifstream arch_sudo, arch_datos;
            char letra_sudo, letra_datos;
            arch_sudo.open("sudo.txt");
            arch_datos.open("archivo_codifAdmin.txt");
            while((arch_datos.good()) && (arch_sudo.good())) {
                letra_datos=arch_datos.get();
                letra_sudo=arch_sudo.get();
                if(letra_datos != letra_sudo){
                   arch_datos.close();
                   arch_sudo.close();
                   cout << "USUARIO O CLAVE INCORRECTA. INTENTE DE NUEVO."<<endl;
                   cout <<endl;
                   inicio_admin();
                   arch_sudo.open("sudo.txt");
                   arch_datos.open("archivo_codifAdmin.txt");
                                }
            }
            cout << "INICIO DE SESION EXITOSO."<<endl;
            cout << endl;
            arch_datos.close();
            arch_sudo.close();

            ofstream registro_usuarios;
            registro_usuarios.open("registro_usuarios.txt", ios::app);
            string cedula="", clave="", saldo="";
            cout << "REGISTRO DE USUARIO."<<endl;
            cout <<"Ingrese la cedula del nuevo usuario: ";
            cin >> cedula;
            cout <<"Ingrese la clave del nuevo usuario (Recuerde no usar espacios): ";
            cin >> clave;
            cout <<"Ingrese el saldo del nuevo usuario: ";
            cin >> saldo;
            cout <<"USUARIO NUEVO REGISTRADO"<<endl;
            registro_usuarios<<cedula<<" "<<clave<<" "<<saldo<<endl;;
            registro_usuarios.close();
        }
            break;

        case 2: {
            ofstream archTemp;
            ifstream datos_usuarios; //Archivo de lectura en donde se encuentran los datos de los usuarios registrados
            datos_usuarios.open("registro_usuarios.txt");
            archTemp.open("archTemp.txt"); //Archivo temporal de escritura
            string cedula="", clave="", cedula_reg, clave_reg, saldo_reg;
            bool usuarioEncontrado=false;
            cout << "Ingrese su cedula: ";
            cin >> cedula;
            cout << "Ingrese su clave: ";
            cin >> clave;
            cout << endl;
            while(datos_usuarios.good()){
                datos_usuarios >> cedula_reg; //Lee la cedula registrada (leera hasta el primer espacio que encuentre)
                datos_usuarios >> clave_reg;
                datos_usuarios >> saldo_reg; //Leo el saldo para completar la linea de escritura
                if (((cedula_reg != cedula) || (clave_reg != clave)) && (datos_usuarios.good())){
                    while (((cedula_reg != cedula) || (clave_reg != clave)) && (datos_usuarios.good())){
                        archTemp << cedula_reg <<" "<<clave_reg<<" "<< saldo_reg<<endl;
                        datos_usuarios >> cedula_reg;
                        datos_usuarios >> clave_reg;
                        datos_usuarios >> saldo_reg;
                             }
                }

                else if((cedula_reg == cedula) && (clave_reg == clave)){
                    usuarioEncontrado=true;
                    int opcion_usuario;
                    cout << "Recuerde que hacer uso de alguna de las siguientes opciones tiene un costo de 1000 COP."<<endl;
                    cout << "1. Consultar saldo."<<endl;
                    cout << "2. Retirar dinero."<<endl;
                    cout << "0. Salir."<<endl;
                    cout << "Ingrese una opcion: ";
                    cin >> opcion_usuario;
                    cout << endl;
                    int saldoActual=atoi(saldo_reg.c_str());
                    switch (opcion_usuario) {
                    case 1: {
                        saldoActual=saldoActual-1000;
                        cout << "Saldo en cuenta: "<< saldo_reg <<"COP"<<endl;
                        cout << "Costo de la operacion: 1000COP" <<endl;
                        cout << "Su saldo actual es: " << saldoActual <<"COP"<< endl;

                        archTemp << cedula_reg <<" "<<clave_reg<<" "<< saldoActual<<endl;
                            }
                        break;
                        saldo_reg=saldoActual;
                    case 2: {
                        int monto_retirado;
                        cout << "Ingrese el monto que desee retirar: ";
                        cin >> monto_retirado;
                        cout << endl;
                        saldoActual -= monto_retirado;
                        cout << "Saldo en cuenta antes de la operacion: "<< saldo_reg <<"COP"<<endl;
                        cout << "Costo de la operacion: 1000COP" <<endl;
                        cout << "Su saldo actual es: " << saldoActual <<"COP"<< endl;

                        archTemp << cedula_reg <<" "<<clave_reg<<" "<< saldoActual<<endl;

                    }
                        saldo_reg=saldoActual;
                        break;
                    }
                }
            }
            if (usuarioEncontrado==false){
                cout << "NO SE ENCONTRO EL USUARIO"<<endl;
            }
            datos_usuarios.close();
            archTemp.close();
            remove("registro_usuarios.txt"); //Elimina el archivo sin modificaciones
            rename("archTemp.txt", "registro_usuarios.txt"); //Cambia el nombre del archivo temporal por el nombre del archivo sin modificaciones

        }
            break;
        }
    }
        break;
    }
}
    return 0;
}

void Archivo_a_Binario(){

    ifstream archivOriginal; //Para leer un archivo
    ofstream archivoBinario;
    string ArchivoEntrada="";

    cout<<"SI ES LA APP EL NOMBRE DEL ARCHIVO ES: datos_administrador.txt"<<endl;
    cout<<endl;
    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> ArchivoEntrada;
    archivOriginal.open(ArchivoEntrada);
    archivoBinario.open("ArchivoBinario.txt");

    string textoArchivo; //Guardamos el texto que haya del archivo en una variable
    while(archivOriginal.good()){
        getline(archivOriginal,textoArchivo);
        for(int i=0; textoArchivo[i]!='\0'; i++){ //Tomo letra por letra la linea leida
            archivoBinario<<Decimal_a_Binario(textoArchivo[i]); //Voy escribiendo en el archivo binario el retorno de la funcion
        }
    }
    archivOriginal.close();
    archivoBinario.close();
}

string Decimal_a_Binario(char letra){
    string letra_binaria;
    int div=letra, mod=0;

    while(div>0){
        mod=div%2;
        div=div/2;
        letra_binaria=to_string(mod)+letra_binaria;
    }
    while(letra_binaria.length()<8){ //Si no completa los 8 bits anado 0 al inicio del numero
        letra_binaria='0'+letra_binaria;
    }

    return letra_binaria;
}


string Binario_a_letra(string letra_binaria){
    int decimal=0, pot=1;
    char letra;
    string letrafinal="";

    for(int i=letra_binaria.length()-1; i>=0; i--){
        if(letra_binaria[i]=='1'){
            decimal=decimal+pot;
        }
        pot=pot*2;
    }
    letra=decimal;
    letrafinal=letra;

    return letrafinal;
}


//FUNCION QUE PIDE LOS DATOS DE ADMINISTRADOR
void inicio_admin(){
    ofstream datos_admin;
    string nom_usuario="", clave_admin="";
    cout <<endl;
    cout << "ADMINISTRADOR"<<endl;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nom_usuario;
    cout << "Ingrese su clave: ";
    cin >> clave_admin;
    cout << endl;
    datos_admin.open("datos_administrador.txt");
    datos_admin<<nom_usuario<<clave_admin;
    datos_admin.close();
    datos_adminCodificados();
}


//FUNCION PARA CODIFICAR LOS DATOS INGRESADOS POR EL USUARIO ADMINISTRADOR
void datos_adminCodificados(){
    Archivo_a_Binario();
    ifstream arch_binario;
    ofstream archivoCodificado;
    string num, bin_semilla="";
    arch_binario.open("ArchivoBinario.txt"); //Abrimos el archivo binario de escritura creado para usarlo como lectura
    archivoCodificado.open("archivo_codifAdmin.txt");

    //La semilla de codificacion sera 4
    while (arch_binario.good()){
        while ((!arch_binario.eof()) && (bin_semilla.length()<4)) {
            for(int i=0;bin_semilla.length()<4;i++){
                num=arch_binario.get();
                bin_semilla=bin_semilla + num; //Usamos bin_semilla para guardar el binario creado con la semilla
                    }
            bin_semilla=bin_semilla[3] + bin_semilla; //Tomamos el caracter en la penultima posicion y se lo anadimos al string original
            bin_semilla.pop_back();   //esto hace que quede al inicio de la cadena
            //Elimina el ultimo elemento del string

            archivoCodificado<<bin_semilla;
            bin_semilla="";
        }
        arch_binario.close();
        archivoCodificado.close();
    }
}



