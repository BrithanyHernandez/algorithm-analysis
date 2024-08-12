#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arreglo, int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int> izquierda(elementosIzq);
    vector<int> derecha(elementosDer);

    for (int i = 0; i < elementosIzq; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < elementosDer; j++) {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < elementosIzq && j < elementosDer) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (j < elementosDer) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while (i < elementosIzq) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
}

void MergeSort(vector<int>& arreglo, int inicio, int final) {
    if (inicio < final) {
        int mitad = inicio + (final - inicio) / 2;
        MergeSort(arreglo, inicio, mitad);
        MergeSort(arreglo, mitad + 1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

void imprimirArreglo(const vector<int>& arreglo) {
    cout << endl;
    for (int i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

vector<int> ingresarArreglo() {
    int cantidad;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> cantidad;

    vector<int> arreglo(cantidad);
    cout << "Ingrese los " << cantidad << " elementos del arreglo:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> arreglo[i];
    }

    return arreglo;
}

void ejecutarMergeSort() {
    vector<int> arreglo = ingresarArreglo();

    cout << "Arreglo original:" << endl;
    imprimirArreglo(arreglo);

    MergeSort(arreglo, 0, arreglo.size() - 1);

    cout << "\nValores ordenados:" << endl;
    imprimirArreglo(arreglo);
}

int main() {
    ejecutarMergeSort();

    return 0;
}

