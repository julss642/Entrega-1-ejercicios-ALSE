#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <functional> // Para greater

using namespace std;
// ---------- Ejercicio 1: Lectura de archivo y almacenamiento en set ----------
void ejercicio1() {
    set<string> palabrasUnicas;
    ifstream archivo("sampleFile.txt");
    
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string palabra;
    while (archivo >> palabra) {
        // Limpieza de la palabra
        palabra.erase(remove_if(palabra.begin(), palabra.end(), ::ispunct), palabra.end());
        transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        
        if (!palabra.empty()) {
            palabrasUnicas.insert(palabra);
        }
    }

    cout << "\n--- Palabras únicas en el archivo (Ejercicio 1) ---\n";
    for (const auto& p : palabrasUnicas) {
        cout << p << endl;
    }
}

// ---------- Ejercicio 2: Frecuencia de palabras con map ----------
void ejercicio2() {
    map<string, int> frecuencia;
    ifstream archivo("sampleFile.txt");
    
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string palabra;
    while (archivo >> palabra) {
        palabra.erase(remove_if(palabra.begin(), palabra.end(), ::ispunct), palabra.end());
        transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        
        if (!palabra.empty()) {
            frecuencia[palabra]++;
        }
    }

    cout << "\n--- Frecuencia de palabras (Ejercicio 2) ---\n";
    for (const auto& [palabra, count] : frecuencia) {
        cout << palabra << ": " << count << endl;
    }
}

// ---------- Ejercicio 3: Cola de prioridad (priority_queue) ----------
void ejercicio3() {
    struct Tarea {
        int prioridad;
        string descripcion;
        // Ordenar de mayor a menor prioridad
        bool operator<(const Tarea& otra) const { return prioridad < otra.prioridad; }
    };

    priority_queue<Tarea> colaTareas;
    colaTareas.push({3, "Revisión de informes"});
    colaTareas.push({1, "Preparar presentación"});
    colaTareas.push({4, "Responder correos urgentes"});
    colaTareas.push({2, "Reunión con el equipo"});
    colaTareas.push({5, "Planificar nueva estrategia"});

    cout << "\n--- Tareas por prioridad (Ejercicio 3) ---\n";
    while (!colaTareas.empty()) {
        auto t = colaTareas.top();
        cout << "[" << t.prioridad << "] " << t.descripcion << endl;
        colaTareas.pop();
    }
}

// ---------- Ejercicio 4: find_if para buscar primer número par ----------
void ejercicio4() {
    vector<int> numeros = {7, 13, 9, 8, 15, 6, 21};
    auto esPar = [](int n) { return n % 2 == 0; };
    auto it = find_if(numeros.begin(), numeros.end(), esPar);

    cout << "\n--- Primer número par (Ejercicio 4) ---\n";
    if (it != numeros.end()) {
        cout << *it << " (posición " << distance(numeros.begin(), it) << ")\n";
    } else {
        cout << "No hay números pares.\n";
    }
}

// ---------- Ejercicio 5: Ordenamiento personalizado de vector<pair> ----------
void ejercicio5() {
    vector<pair<int, string>> datos = {
        {5, "manzana"}, {2, "banana"}, {8, "naranja"}, {1, "uva"}, {7, "pera"}
    };

    // Ordenar descendente por el primer elemento del par (int)
    sort(datos.begin(), datos.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    cout << "\n--- Datos ordenados descendentemente (Ejercicio 5) ---\n";
    for (const auto& [num, fruta] : datos) {
        cout << "{" << num << ", " << fruta << "}\n";
    }
}

// ---------- Menú principal ----------
int main() {
    int opcion;
    do {
        cout << "\n----- MENÚ STL -----\n"
                  << "1. Palabras únicas en archivo (set)\n"
                  << "2. Frecuencia de palabras (map)\n"
                  << "3. Cola de prioridad (priority_queue)\n"
                  << "4. Buscar primer número par (find_if)\n"
                  << "5. Ordenar pares descendente (sort personalizado)\n"
                  << "0. Salir\n"
                  << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}