#include <iostream>
#include <string>

using namespace std;

struct NodoEstudiante {
    string primerNombre;
    int codigoEstudiantil;
    double nota;
    NodoEstudiante* sig;
};

NodoEstudiante* cab = nullptr;

           
void registrar() {
    NodoEstudiante* nuevo = new NodoEstudiante;
    cout << "Primer Nombre del estudiante: ";
    cin >> nuevo->primerNombre;
    cout << "Código Estudiantil: ";
    cin >> nuevo->codigoEstudiantil;
    cout << "Nota: ";
    cin >> nuevo->nota;
    nuevo->sig = nullptr;

    if (!cab) {
        cab = nuevo;
    } else {
        NodoEstudiante* aux = cab;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}


void mostrar() {
    NodoEstudiante* aux = cab;
    while (aux != nullptr) {
        cout << "Nombre: " << aux->primerNombre 
             << ", Código: " << aux->codigoEstudiantil 
             << ", Nota: " << aux->nota << endl;
        aux = aux->sig;
    }
}

void ordenarPorCodigo() {
    if (!cab) return;
    NodoEstudiante* aux2 = cab;
    while (aux2->sig != nullptr) {
        NodoEstudiante* aux = cab;
        while (aux->sig != nullptr) {
            if (aux->codigoEstudiantil > aux->sig->codigoEstudiantil) {
                swap(aux->primerNombre, aux->sig->primerNombre);
                swap(aux->codigoEstudiantil, aux->sig->codigoEstudiantil);
                swap(aux->nota, aux->sig->nota);
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

void ordenarPorNota() {
    if (!cab) return;
    NodoEstudiante* aux2 = cab;
    while (aux2->sig != nullptr) {
        NodoEstudiante* aux = cab;
        while (aux->sig != nullptr) {
            if (aux->nota < aux->sig->nota) {
                swap(aux->primerNombre, aux->sig->primerNombre);
                swap(aux->codigoEstudiantil, aux->sig->codigoEstudiantil);
                swap(aux->nota, aux->sig->nota);
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}


void encontrarMayorNota() {
    if (!cab) return;
    NodoEstudiante* mayor = cab;
    NodoEstudiante* aux = cab->sig;
    while (aux != nullptr) {
        if (aux->nota > mayor->nota) {
            mayor = aux;
        }
        aux = aux->sig;
    }
    cout << "Estudiante con mayor nota: " << mayor->primerNombre 
         << " con nota " << mayor->nota << endl;
}

void encontrarMenorNota() {
    if (!cab) return;
    NodoEstudiante* menor = cab;
    NodoEstudiante* aux = cab->sig;
    while (aux != nullptr) {
        if (aux->nota < menor->nota) {
            menor = aux;
        }
        aux = aux->sig;
    }
    cout << "Estudiante con menor nota: " << menor->primerNombre 
         << " con nota " << menor->nota << endl;
}

void calcularPromedio() {
    if (!cab) return;
    double suma = 0;
    int contador = 0;
    NodoEstudiante* aux = cab;
    while (aux != nullptr) {
        suma += aux->nota;
        contador++;
        aux = aux->sig;
    }
    cout << "Promedio de notas: " << suma / contador << endl;
}

void menu() {
    int opcion;
    do {
        cout << "Menu" << endl;
        cout << "1. Ingresar datos de estudiantes" << endl;
        cout << "2. Ordenar y mostrar lista de estudiantes por codigo" << endl;
        cout << "3. Ordenar y mostrar lista de estudiantes por nota" << endl;
        cout << "4. Mostrar mayor, menor y promedio de notas" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                ordenarPorCodigo();
                mostrar();
                break;
            case 3:
                ordenarPorNota();
                mostrar();
                break;
            case 4:
                encontrarMayorNota();
                encontrarMenorNota();
                calcularPromedio();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 5);
}

int main() {
    menu();
    return 0;
}
