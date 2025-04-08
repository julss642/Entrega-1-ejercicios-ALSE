#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class MyHashSet {
    private:
        // Define the size of the hash set
        static const int SIZE = 1000;
        
        // Define the hash table
        vector<list<int>> table;
        
        // Hash function to map a key to an index
        int hash(int key) {
            return key % SIZE;
        }

    public:
        MyHashSet() {
            // Initialize the hash table with empty lists
            table.resize(SIZE);
        }
        
        void add(int key) {
            if (contains(key)) {
                return; // Key already exists, no need to add
            }
            int index = hash(key); // Get the index for the key
            table[index].push_back(key); // Add the key to the list at that index
        }
        
        void remove(int key) {
            if (!contains(key)) {
                return; // Key does not exist, no need to remove
            }
            int index = hash(key); // Get the index for the key
            auto& bucket = table[index]; // Get the list at that index
            // Find the key in the list and remove it
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (*it == key) {
                    bucket.erase(it); // Remove the key from the list
                    return; // Exit after removing
                }
            }
            
        }
        
        bool contains(int key) {
            int index = hash(key); // Get the index for the key
            auto& bucket = table[index]; // Get the list at that index
            // Check if the key exists in the list
            for (const int& k : bucket) {
                if (k == key) {
                    return true; // Key found
                }
            }
            return false; // Key not found
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */