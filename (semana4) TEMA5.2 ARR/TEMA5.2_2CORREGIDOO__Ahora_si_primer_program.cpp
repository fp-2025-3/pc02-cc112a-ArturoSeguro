#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Esto lo dejé al final---------------------------------------------------------------------------
                    // --- function6: Crear arreglo dinámico inicial ---
                    char* rellenarArregloDinamico(const string& frase, int tam){
                        char* PUNfrase1= new char[tam+1];

                        for(int i=0; i<tam; i++){
                            PUNfrase1[i]= frase[i];
                        }
                        PUNfrase1[tam]= '\0'; // Asegurar el terminador nulo

                        return PUNfrase1;
                    }

                    // --- function7: Eliminar espacios (Bubble Sort style) ---
                    int eliminarEspacios(char* PUNfrase2, int tam){
                        int ultimoIndice=0;
                        for(int i=0; i<tam-1; i++){
                            for(int j=0; j<tam-1-i; j++){
                                if(PUNfrase2[j]== ' '){
                                    swap(PUNfrase2[j], PUNfrase2[j+1]);
                                }
                            }
                        }
                        // Nota: Esto mueve los espacios al final, pero para calcular el nuevo tamaño real
                        // necesitamos buscar dónde empiezan los espacios al final.
                        // Una forma simple es iterar hasta encontrar el primer espacio tras ordenar.
                        int i = 0;
                        while(i < tam && PUNfrase2[i] != ' ') {
                            i++;
                        }
                        PUNfrase2[i] = '\0'; // Cortamos la cadena ahí
                        return i;
                    }

                    // --- function8: Convertir a minúsculas ---
                    void minusculas(char* PUNfrase2, int nuevoTam){
                        for(int i=0; i<nuevoTam; i++){
                            PUNfrase2[i]= tolower(PUNfrase2[i]);
                        }
                    }

                    // --- function10: Imprimir frase completa ---
                    void imprimir(char* PUNfrase2){ // No necesitamos tam si confiamos en el \0
                        cout << PUNfrase2 << "\n";
                    }



//Esto lo adelante al comeinzo---------------------------------------------------------------------------
// --- function11.3: Contar palabras ---
int soloNumeroPalabras(char* PUNfrase2, int tam){
    if (tam == 0) return 0;
    
    int cantidadPalabras= 0;
    
    // Verificar si la primera letra no es espacio
    if (PUNfrase2[0] != ' ') cantidadPalabras++;

    for(int i=1; i<tam; i++){
        // Si hay un espacio antes y ahora no es espacio -> Nueva palabra
        if(PUNfrase2[i-1]== ' ' && PUNfrase2[i]!= ' '){
            cantidadPalabras++;
        }
    }
    return cantidadPalabras;
}

// --- function11.2: Calcular longitud de la palabra actual ---
// CORREGIDO: Ahora verifica '\0' para no salirse de memoria
int longitudPalabra(int indice, char* PUNfrase2){
    int i=0;
    while(PUNfrase2[indice+i]!= ' ' && PUNfrase2[indice+i] != '\0'){
        i++;
    }
    return i;
}

// --- function11.4: Copiar caracteres a la nueva palabra ---
void rellenandoPunterosFinales(int indice, char* PUNfrase2, int longitudActual, char* PUNpalabraDestino){
    for(int i=0; i<longitudActual; i++){
        PUNpalabraDestino[i]= PUNfrase2[indice+i];
    }
    PUNpalabraDestino[longitudActual]= '\0'; // Importante: cerrar la cadena
}

// --- function11: Lógica principal de llenado ---
void RellenandoTOTALMENTEpunteros(char* PUNfrase2, int tam, char** PUNpalabras){
    int indicePalabra = 0; // Para controlar en qué fila de PUNpalabras estamos

    for (int i = 0; i < tam; i++) {
        // Detectar inicio de palabra:
        // Caso 1: Es el primer caracter y no es espacio.
        // Caso 2: El anterior era espacio y este no.
        bool esInicio = (i == 0 && PUNfrase2[i] != ' ') || (i > 0 && PUNfrase2[i-1] == ' ' && PUNfrase2[i] != ' ');

        if (esInicio) {
            int len = longitudPalabra(i, PUNfrase2);
            
            // CORREGIDO: Asignar DIRECTAMENTE al arreglo original, no a una variable local
            PUNpalabras[indicePalabra] = new char[len + 1];

            // Copiar contenido
            rellenandoPunterosFinales(i, PUNfrase2, len, PUNpalabras[indicePalabra]);
            
            indicePalabra++;
        }
    }
}

// --- function12: Imprimir arreglo de palabras ---
void ImprimirPalabras(int numeroPalabras, char** PUNpalabras){
    cout << "\n--- Palabras extraidas y longitud ---\n";
    for(int i=0; i<numeroPalabras; i++){
        // Como ya pusimos '\0' al final de cada palabra, podemos usar string.length() implícito o strlen
        // O simplemente imprimir directamente:
        cout << "Palabra: " << PUNpalabras[i] << " (Longitud: ";
        
        // Calculamos longitud simplemente contando hasta \0
        int len = 0;
        while(PUNpalabras[i][len] != '\0') len++;
        
        cout << len << ")\n";
    }
    cout << "\n";
}











//main
//
//
//
int main(){
    string frase;
    cout << "Ingrese su frase: ";
    getline(cin, frase);


                        //lo que adelanté (problemas 1.4, 1.5, ...)----------------------------------------------
                        // 1. Asignación Dinámica Inicial
                        int tam= frase.length();
                        char* PUNfrase2= rellenarArregloDinamico(frase, tam);

                        // 2. Contar Palabras
                        int numeroPalabras= soloNumeroPalabras(PUNfrase2, tam);
                        cout << "Numero de palabras detectadas: " << numeroPalabras << "\n";

                        // 3. Crear arreglo de punteros (char**)
                        char** PUNpalabras= new char*[numeroPalabras];

                        // 4. Rellenar cada puntero individual
                        RellenandoTOTALMENTEpunteros(PUNfrase2, tam, PUNpalabras);

                        // 5. Imprimir palabras individuales
                        ImprimirPalabras(numeroPalabras, PUNpalabras);





    //lo que dejé al final (problemas 1.1, 1.2, 1.3)----------------------------------------------
    cout << "------------------------------------------------\n";

    // 6. Normalizar frase original (Quitar espacios y minusculas)
    int nuevoTam = eliminarEspacios(PUNfrase2, tam);
    minusculas(PUNfrase2, nuevoTam);

    cout << "Frase normalizada: ";
    imprimir(PUNfrase2);

    // 7. Liberar memoria (Paso 1.7 del ejercicio)
    
    // Primero liberar cada palabra individual
    for(int i=0; i<numeroPalabras; i++){
        delete[] PUNpalabras[i];
    }
    // Luego liberar el arreglo de punteros
    delete[] PUNpalabras;
    
    // Finalmente liberar la frase original
    delete[] PUNfrase2;

    cout << "\n-------------END\n";
    return 0;
}