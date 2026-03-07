// 6. Imprimir con cuidado
void imprimir_grupo(const char* titulo, char* v[], int n) {
    cout << "\n" << titulo << ":" << endl;
    for (int i = 0; i < n; i++) {
        
        int len = longitud_palabra(v[i]);

        for(int j = 0; j < len; j++) {
            cout << *(v[i]+j);
        }
        cout << "\n";
    }
}