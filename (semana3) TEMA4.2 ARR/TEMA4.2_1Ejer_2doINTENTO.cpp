#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;





//
//
//
//Función1      -->--> Identifica el inicio de cada palabra y guarda su dirección
int separar_palabras(char* texto, char* palabras[]){
    // no entiendo para nada a que se refiere

    //--> Supuestamente hay que poner en cada elemento de palabras[i] el inicio de cada palabra de texto[]
    int contador= 0;
    bool dentroDePalabra = false;

    for(int i=0; *(texto+i)!= '\0'; i++){     //buen truquito usar texto[i]!= '\0', es la condición perfecta
        //la condición puesta en el for detiene el bucle hasta encontrar el final, que como es un arreglo de caracter siempre tiene que ser '\0'
        
        if(*(texto+i)!= ' '){         //mientras el elemento que se este evaluando sea alnum(), distinto de espacio ' '
            if(!dentroDePalabra){
                //-->Es el inicio de una nueva palabra. GUardamos la dirección
                palabras[contador]= (texto+i);
                contador++;
                dentroDePalabra= true;      //Se activa la condición, diciendo que he entrado en una nueva palabra
            }
        }else{
            //si encontramos un espacio, ya no estamos en una palabra
            dentroDePalabra= false;         //Se desactiva mi condición, diciendo que hemos salido de la palabra --> después entraremos a otra, pero ahora estamos afuera
        }
    }

    return contador;        // Retornamos cuántas palabras se encontraron ((aqui fueron bien malignos, como esperaban que supiera eso))
}
/*
Por qué usan "&texto[i]; " y "texto[i];", si texto esta declarado com un arreglo de punteros?
es decir que debería ser "(texto+i)" y "*(texto+i)"
//
//
1. "(texto+i)" y "*(texto+i)" --> PERFECT porque esta declarado como char* texto --> el cual es un puntero al primer elemento (primera letra) del texto
2. "palabras[contador]" tiene que quedarse así, porque esta declarado como "char* palabras[]" --> es decir que sí o sí es un arreglo y en este caso es de punteros por lo que hay que igualarlo con los de su mismo tipo
*/





//
//
//
//Función2                      -->--> Cuenta caracteres hasta encontrar un espacio o el final
int longitud_palabra(const char* p){
    //int i=0;
    //no se me ocrurre como utilizarlo
    /*
    do{
        if(*(p+i)== '\0'){
            break;
        }
        i++;
    }while(*(p+i)== '\0');

    return i;
    */

    //--> supuestamente me he equivocado
    int longitud= 0;
    //mientras no sea fin de cadena Y no sea un espacio
    while( *(p+longitud)!= '\0' && *(p+longitud)!= ' '){
        longitud++;
    }

    return longitud;
}
/*
acá se debería volver "longitud+1" cierto?
//
//
NO, en cada bucle se añade uno, como se analizan 3 elementos, se hacen 3 aumentos y por eso queda "=3" y esta perfecto así
*/





//
//
//
//Función3
int comparar_palabras(const char* a, const char* b){
    //es totalmente innecesario. NO creo que ayude a resolver el problema

    //--> sí importa. para ordenar alfabeticmaente (a eso se referia)
    int i=0;
    //comparamos letra a letra mientras no se4 acaben las palabras
    while( *(a+i)!= ' ' && *(a+i)!= '\0' && *(b+i)!= ' ' && *(b+i)!= '\0'){
        // Convertimos a minúsculas temporalmente...
        //por supuesto que es necesario analizar o los 2 mayusculas o los 2 minúsculas, de otra forma dará errores, por ejemplo el caso de analizar una mayuscula con un minúscula
        char letraA= tolower( *(a+i)); 
        char letraB= tolower( *(b+i));

        if(letraA< letraB){
            return -1;              //"a" va antes
        }

        if(letraA> letraB){
            return 1;              //"a" va después
        }

        i++;
    }

    //SI llegamos aqui, una es prefijo de la otra (ej: "sol" y "soles")
    //la más corta va primero
    int lenA= longitud_palabra(a);
    int lenB= longitud_palabra(b);

    if(lenA < lenB){
        return -1;
    }

    if(lenA > lenB){
        return 1;
    }
    return 0;                   //si retorna 0 "a" y "b" son exactamente la misma palabra
}
/*
Supongo de una forma inteligente voy a tener que usar este dato "-1" o "1" o "0" para hacer un swap()
entre los punteros que deseo, (recordando que esos punteros estan en el arreglo de punteros de cortas[] o largas[])
*/





//
//
//
//Función4                      -->-->  Clasifica usando la función de longitud
void clasificar(char* palabras[], int n, 
                char* cortas[], int& nc,
                char* largas[], int& nl){
    //Aqui puedo entender que debo poner las palabras del texto y agregarlas
    //En los arreglos de cortas y largas --> solo que hay un error, eso significaría que en el main debería ver "char cortas[60]" definido, no entiendo para que lo declararn defrente como arreglo de púnteros "char* palabras[60]" o acaso su intención es dejar intacto el arreglo "texto[]" y usar los arreglos de puntero "palabras", "cortas", "largas" , como direcciones para trabajar y conseguir lo que el problema pide???
    //Ahora, no veo el sentido del arreglo de puntero "palabras", acaso no es necesario con "cortas" y "largas" nada más?????? --> además como planean que sepamos la longitud de cada palabra???? --> puedo entender que se puede saber el inicio de cada palabra (ya que cada espacio es un ' ') (Su dirección) y puntearlo en el respectivo arreglo, pero cómo logro saber si puntearlo en cortas[] o largas[] y aparte cómo quieren que lo puntiemos? si puntero el inicio de palabras por ejemplo:: cortas[1], luego cómo puedo de alguna forma guardar su "final", si lo dejo así no me sirve de nada cierto?, quiza necesite un arrelgo de tamaños[]

    //--> DEBO USAR longirud_palbras() para saber cál será el final de cada uno                   
    nc= 0;
    nl= 0;

    //El "n" lo consigo en separar palabras, aqui hay un lazo muy importante que se tendrá que tomar en cuenta para escribir el main()
    for(int i=0; i<n; i++){
        //Usamos la función que creamos antes
        if( longitud_palabra( palabras[i])<= 3){            //aqui si se tienen que quedar con la sintaxis de palabras[i], porque "*(palabras+i)" seria incorrecto --> todo dependerá de como se declara en los argumentos de la función
            cortas[nc]= palabras[i];
            nc++;
        }else{
            largas[nl]= palabras[i];
            nl++;
        }
    }
}





//
//
//
//Función5                          --> ordenamientoBURBUJA intercmabiando punteros
void ordenar(char* v[], int n){
    //por alfabetismo
    //no tengo ni idea de como hacerlo ya que no tengo ni idea de como se puntean las palabras (solo primeras letras de cada palabra? o también las últimas letras para saber su longitud??? cómo??? siento que hay mil formas de hacerlo)

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){         //--> solo por no poner el "j" TODO ME ESTAB AFALLANDO --> listo ahora sí
            //si la palabra j es "mayor" (alfabeticamente posterior) que j+1
            if( comparar_palabras(v[j], v[j+1])> 0){                            //-->--> Aca se devolverá el valor que programe en "comparar_palabras()"
                //Intercambiamos LAS FLECHAS (punteros), no el texto
                swap(v[j], v[j+1]);
            }
        }
    }
}




//
//
//
//Función6                      -->--> Imprimir con cuidado
void imprimir_grupo(const char* titulo, char* v[], int n){
    //Qué diablos será "v[]"?
    //--> v[] es un nombre genérico. AHí entrará el cortas[] o largas[]

    cout << "\n" << titulo << ":" << endl;
    for(int i=0; i<n; i++){
        //OJO: No podemos hacer "cout << v[i]" porque imprimiría
        //desde la palabra hasta el final de la frase original
        //IMPRIMIRÉ letra por letra hasta el espacio

        int len= longitud_palabra(v[i]);

        for(int j=0; j<len; j++){
            cout << *(v[i]+j);
        }
        cout << "\n";
    }
}



int main(){
    char texto[300];
    cout << "Ingrese texto: ";
    cin.getline(texto, 300);

    char* palabras[60];
    int n;

    char* cortas[60];
    int nc;

    char* largas[60];
    int nl;

    // 1. Separar
    n = separar_palabras(texto, palabras);

    // 2. Clasificar
    clasificar(palabras, n, cortas, nc, largas, nl);

    // 3. Ordenar ambos grupos
    ordenar(cortas, nc);
    ordenar(largas, nl);

    // 4. Imprimir
    imprimir_grupo("Palabras cortas", cortas, nc);
    imprimir_grupo("Palabras largas", largas, nl);

    return 0;
}
