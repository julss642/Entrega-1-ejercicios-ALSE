#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class MyHashSet {
    private:
        // Definir el tamaño del conjunto hash
        static const int SIZE = 1000;
        
        // Definir la tabla hash
        vector<list<int>> table;
        
        // Función hash para mapear una clave a un índice
        int hash(int key) {
            return key % SIZE;
        }

    public:
        MyHashSet() {
            // Inicializar la tabla hash con listas vacías
            table.resize(SIZE);
        }
        
        void add(int key) {
            if (contains(key)) {
                return; // La clave ya existe, no es necesario agregarla
            }
            int index = hash(key); // Obtener el índice para la clave
            table[index].push_back(key); // Agregar la clave a la lista en ese índice
        }
        
        void remove(int key) {
            if (!contains(key)) {
                return; // La clave no existe, no es necesario eliminarla
            }
            int index = hash(key); // Obtener el índice para la clave
            auto& bucket = table[index]; // Obtener la lista en ese índice
            // Buscar la clave en la lista y eliminarla
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (*it == key) {
                    bucket.erase(it); // Eliminar la clave de la lista
                    return; // Salir después de eliminar
                }
            }
            
        }
        
        bool contains(int key) {
            int index = hash(key); // Obtener el índice para la clave
            auto& bucket = table[index]; // Obtener la lista en ese índice
            // Verificar si la clave existe en la lista
            for (const int& k : bucket) {
                if (k == key) {
                    return true; // Clave encontrada
                }
            }
            return false; // Clave no encontrada
        }
    };
    
    /**
     * Tu objeto MyHashSet será instanciado y llamado de la siguiente manera:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */