#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
private:
    int timestamp; // Variable para llevar el control del tiempo de publicación de los tweets.
    unordered_map<int, unordered_set<int>> following; // Mapa que asocia un usuario con el conjunto de usuarios a los que sigue.
    unordered_map<int, vector<pair<int, int>>> tweets; // Mapa que asocia un usuario con una lista de sus tweets (cada tweet tiene un timestamp y un ID).

public:
    Twitter() {
        timestamp = 0; // Inicializa el timestamp en 0.
    }

    // Método para que un usuario publique un tweet.
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId}); // Agrega el tweet con el timestamp actual y luego incrementa el timestamp.
    }

    // Método para obtener el feed de noticias de un usuario.
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // Cola de prioridad para ordenar los tweets por timestamp (de mayor a menor).

        // Añadir los tweets del usuario al feed.
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet); // Agrega los tweets del usuario a la cola de prioridad.
        }

        // Añadir los tweets de los usuarios que sigue al feed.
        for (int followeeId : following[userId]) {
            for (auto &tweet : tweets[followeeId]) {
                pq.push(tweet); // Agrega los tweets de los usuarios seguidos a la cola de prioridad.
            }
        }

        vector<int> res; // Vector para almacenar los IDs de los tweets en el feed.
        int count = 0; // Contador para limitar el feed a los 10 tweets más recientes.
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second); // Agrega el ID del tweet más reciente al resultado.
            pq.pop(); // Elimina el tweet más reciente de la cola.
            count++; // Incrementa el contador.
        }
        return res; // Devuelve el feed de noticias.
    }

    // Método para que un usuario siga a otro.
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) // Un usuario no puede seguirse a sí mismo.
            following[followerId].insert(followeeId); // Agrega el followeeId al conjunto de usuarios seguidos por followerId.
    }

    // Método para que un usuario deje de seguir a otro.
    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId)) // Verifica si el usuario ya sigue al followeeId.
            following[followerId].erase(followeeId); // Elimina el followeeId del conjunto de usuarios seguidos por followerId.
    }
};

int main() {
    Twitter twitter;

    // Usuario 1 publica un tweet con ID 5
    twitter.postTweet(1, 5);

    // Usuario 1 obtiene su feed de noticias
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "Feed de Usuario 1: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    // Usuario 1 sigue al Usuario 2
    twitter.follow(1, 2);

    // Usuario 2 publica un tweet con ID 6
    twitter.postTweet(2, 6);

    // Usuario 1 obtiene su feed de noticias nuevamente
    feed = twitter.getNewsFeed(1);
    cout << "Feed de Usuario 1 después de seguir al Usuario 2: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    // Usuario 1 deja de seguir al Usuario 2
    twitter.unfollow(1, 2);

    // Usuario 1 obtiene su feed de noticias nuevamente
    feed = twitter.getNewsFeed(1);
    cout << "Feed de Usuario 1 después de dejar de seguir al Usuario 2: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    return 0;
}
