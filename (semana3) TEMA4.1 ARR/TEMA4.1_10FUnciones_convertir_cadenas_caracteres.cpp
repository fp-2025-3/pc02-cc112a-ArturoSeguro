//10. FUNCIONES PARA CONVERTIR CADENAS DE CARACTERES




#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    //EJERCICIO 10.1 -- CONvertir cadena a número
    int x= atoi("123");             //123
    double y= atof("3.14");         //3.14

    /*
    . No detectan errores correctamente
    . atoi confia demasiado en el usuario
    */



    
    //EJERCICIO 10.2 -- COnversión caracter por caracter (manual)
    int numero= 0;

    for(const char* p= "123"; *p != '\0'; p++){
        numero= numero*10 + (*p - '0');
    }
    //Acaso "numero" no es solo un entero, cómo se convierte en cadena??????????
    //
    //
    //Note como una cadena se convierte en número usando solo punteros y ASCII





    return 0;
}