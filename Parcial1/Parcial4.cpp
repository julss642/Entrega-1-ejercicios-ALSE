#include <iostream>
#include <cmath>

// Definir la estructura de un punto en 2D
struct Point {
    double x, y;
};

// Función para calcular la distancia entre dos puntos
// Se usa 'const Point&' para evitar copias innecesarias
inline double calcularDistancia(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point* puntos, int n) {
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        for (int i = 0; i < n; i++) {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        std::cout << "Usando puntos predeterminados...\n";
        for (int i = 0; i < n; i++) {
            puntos[i].x = static_cast<double>(i);
            puntos[i].y = static_cast<double>(i * i);
        }
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(const Point* puntos, int n, const Point& pUsuario, int& indiceCercano) {
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);
    indiceCercano = 0;
    
    for (int i = 1; i < n; i++) {
        double distanciaActual = calcularDistancia(puntos[i], pUsuario);
        if (distanciaActual < distanciaMinima) {
            distanciaMinima = distanciaActual;
            indiceCercano = i;
        }
    }
    return distanciaMinima;
}

// Función para calcular la distancia total de un arreglo de puntos recorridos en orden
double calcularDistanciaTotal(const Point* puntos, int n) {
    double distanciaTotal = 0.0;
    for (int i = 0; i < n - 1; i++) {
        distanciaTotal += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return distanciaTotal;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(const Point* puntos, int indiceMasCercano, double distancia) {
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main() {
    int n;
    do {
        std::cout << "Ingrese el número de puntos (mínimo 2): ";
        std::cin >> n;
        if (n < 2) {
            std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        }
    } while (n < 2);

    Point* puntos = new Point[n]; // Uso de memoria dinámica
    leerPuntos(puntos, n);

    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    mostrarResultado(puntos, indiceMasCercano, distancia);

    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "La distancia total de los puntos recorridos en orden es: " << distanciaTotal << std::endl;

    delete[] puntos; // Liberar memoria dinámica
    return 0;
}
