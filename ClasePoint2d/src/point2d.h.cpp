// Implementación de las funciones y operadores de la clase point2d
#include "../include/point2d.h" // Incluir la definición de la clase point2d
#include <cmath> // Incluir cmath para funciones matemáticas como sqrt

// Constructor por defecto
point2d::point2d(void) {
    x = 0.0; // Inicializar x a 0
    y = 0.0; // Inicializar y a 0
}

// Constructor general
point2d::point2d(int Xin, int Yin) {
    x = Xin; // Inicializar x con el valor proporcionado
    y = Yin; // Inicializar y con el valor proporcionado
}

// Constructor de copia
point2d::point2d(const point2d& c) {
    x = c.x; // Copiar el valor de x
    y = c.y; // Copiar el valor de y
}

// Métodos Getter

int point2d::getx() const {
    return x; // Devolver el valor de x
}

int point2d::gety() const {
    return y; // Devolver el valor de y
}

// Métodos Setter

void point2d::setx(int Xin) {
    x = Xin; // Establecer el valor de x
}

void point2d::sety(int Yin) {
    y = Yin; // Establecer el valor de y
}

// Sobrecarga del operador + (suma de dos puntos)
point2d point2d::operator+(const point2d &other) {
    point2d suma(x + other.x, y + other.y); // Sumar las coordenadas x e y
    return suma; // Devolver el resultado como un nuevo objeto point2d
}

// Sobrecarga del operador * (multiplicación por un escalar)
point2d point2d::operator*(const float &a) {
    point2d producto(x * a, y * a); // Multiplicar las coordenadas x e y por el escalar
    return producto; // Devolver el resultado como un nuevo objeto point2d
}

// Sobrecarga del operador / (división por un escalar)
point2d point2d::operator/(const float &a) {
    point2d cociente(x / a, y / a); // Dividir las coordenadas x e y por el escalar
    return cociente; // Devolver el resultado como un nuevo objeto point2d
}

// Sobrecarga del operador = (asignación)
point2d& point2d::operator=(const point2d &a) {
    x = a.x; // Asignar el valor de x
    y = a.y; // Asignar el valor de y
    return (*this); // Devolver el objeto actual
}

// Sobrecarga del operador == (igualdad)
int operator==(const point2d& a, const point2d& b) {
    return (a.x == b.x && a.y == b.y); // Comprobar si las coordenadas x e y son iguales
}

// Sobrecarga del operador != (desigualdad)
int operator!=(const point2d& a, const point2d& b) {
    return (a.x != b.x || a.y != b.y); // Comprobar si las coordenadas x o y son diferentes
}

// Sobrecarga del operador << (flujo de salida)
ostream& operator<<(ostream& co, const point2d &a) {
    co << "(" << a.x << ", " << a.y << ")"; // Imprimir las coordenadas en formato (x, y)
    return co; // Devolver el flujo de salida
}

// Método distance (calcular la distancia a otro punto)
float point2d::distance(const point2d &other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2)); // Calcular la distancia usando la fórmula de la distancia euclidiana
}

// Método distance (calcular la distancia a coordenadas específicas)
float point2d::distance(int x, int y) {
    return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2)); // Calcular la distancia usando la fórmula de la distancia euclidiana
}

// Método midpoint (calcular el punto medio con otro punto)
point2d point2d::midpoint(const point2d &other) {
    point2d mid((x + other.x) / 2, (y + other.y) / 2); // Calcular el punto medio
    return mid; // Devolver el punto medio como un nuevo objeto point2d
}

// Método midpoint (calcular el punto medio con coordenadas específicas)
point2d point2d::midpoint(int x, int y) {
    point2d mid((this->x + x) / 2, (this->y + y) / 2); // Calcular el punto medio
    return mid; // Devolver el punto medio como un nuevo objeto point2d
}

// Método unitary (calcular el vector unitario)
point2d point2d::unitary() {
    float mag = sqrt(x * x + y * y); // Calcular la magnitud del vector
    point2d unit(x, y); // Crear un nuevo objeto point2d con las mismas coordenadas
    unit = unit / mag; // Dividir las coordenadas por la magnitud para obtener el vector unitario
    return unit; // Devolver el vector unitario
}

// Método display (mostrar las coordenadas del punto)
void point2d::display(string name) {
    cout << name << "(" << x << ", " << y << ")" << endl; // Imprimir el nombre y las coordenadas del punto
}