#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"
#include "queue"
#include "City.h"
#include "Flight.h"
#include "fstream"

const double MAX_DISTANCE = 1e9;

class Graph {
private:
    std::unordered_map<std::string, std::vector<Flight>> adjacencyList; // store the flights between cities
    std::unordered_map<std::string, double> latitude;
    std::unordered_map<std::string, double> longitude;
    std::string currentCity;
public:
    Graph() = default;


    Graph(const std::vector<City> &cities, double maxDistance) {
        // create a map and add the latitude and longitude of each city
        for (const auto &city: cities) {
            latitude[city.getName()] = city.getLatitude();
            longitude[city.getName()] = city.getLongitude();
        }

        // create a flight between each pair of cities
        for (int i = 0; i < cities.size(); i++) {
            for (int j = 0; j < cities.size(); j++) {
                if (i != j) { // if the cities are different
                    double distance = Flight::calculateDistance(cities[i], cities[j]);
                    if (distance <= maxDistance) { // if the distance is less than the maxDistance
                        Flight flight(cities[i].getName(), cities[j].getName(), distance);
                        adjacencyList[cities[i].getName()].push_back(flight);
                    }
                }
            }
        }

    }

    std::vector<std::string> findRoute(const std::string &origin, const std::string &destination) {
        std::unordered_set<std::string> visited; // create a vector to store visited cities
        std::vector<std::string> path = dfs(origin, destination, visited);// call the dfs function
        return path;
    }

    // dfs
    std::vector<std::string>
    dfs(const std::string &origin, const std::string &destination, std::unordered_set<std::string> &visited) {
        if (origin == destination) {
            std::vector<std::string> route;
            route.push_back(origin); // add the destination to the route
            return route;
        }

        visited.insert(origin); // add the origin to the visited set
        for (const auto &flight: adjacencyList[origin]) {
            if (visited.find(flight.getDestination()) ==
                visited.end()) {  //  if the destination city has not visited yet
                std::vector<std::string> path = dfs(flight.getDestination(), destination, visited); // recursive call

                if (!path.empty()) {
                    path.insert(path.begin(), origin); // insert origin to the beginning of the path
                    return path;
                }
            }
        }

        return {}; // if the route does not exist
    }

    // bfs
    /*  std::vector<std::string> bfs(const std::string &origin, const std::string &destination) {
          std::queue<std::vector<std::string>> queue; //   to store the paths
          std::unordered_set<std::string> visited;  //  visited cities

          queue.push({origin});

          while (!queue.empty()) {
              std::vector<std::string> path = queue.front(); //   first path from the queue
              queue.pop(); // remove the path from the queue

              std::string last = path.back(); // get the last city from the path

              if (last == destination) {
                  return path;
              }

              if (visited.find(last) == visited.end()) { //  last city has not visited yet
                  visited.insert(last);  // set like visited

                  for (const auto &flight: adjacencyList[last]) {
                      std::vector<std::string> new_path = path;
                      new_path.push_back(flight.getDestination());
                      queue.push(new_path);
                  }
              }
          }
          return {};
      }
  */

    std::vector<std::string> shortestPath(const std::string &origin, const std::string &destination) {
        std::unordered_map<std::string, double> distance; // store distances from the start city to all others
        std::unordered_map<std::string, std::string> previous; // store the previous city on the shortest path to each city
        std::unordered_set<std::string> unvisited; // set all cities as unvisited

        // distances to all cities except start as infinity
        for (const auto &cityPair: adjacencyList) {

            if (cityPair.first == origin)
                distance[cityPair.first] = 0; // origin
            else
                distance[cityPair.first] = MAX_DISTANCE; // other cities as infinity

            unvisited.insert(cityPair.first);        // unvisited
        }

        while (!unvisited.empty()) {
            std::string current;
            double minDistance = MAX_DISTANCE;      // minimum distance to infinity
            for (const auto &city: unvisited) {
                // 1 find the city with the minimum distance
                if (distance[city] < minDistance) {
                    minDistance = distance[city]; // update the minimum distance
                    current = city;                // update the current city
                }
            }

            unvisited.erase(current);              // remove from the unvisited set
            for (const auto &flight: adjacencyList[current]) { //  check through all flights of the current
                double newDist = distance[current] + flight.getDistance(); // calculate the new distance
                // 2
                if (newDist <
                    distance[flight.getDestination()]) { // if the new distance is less than the current distance
                    distance[flight.getDestination()] = newDist; // update the distance
                    previous[flight.getDestination()] = current; // update the previous city
                }
            }
        }

        std::vector<std::string> path;
        std::string current = destination; // start from the destination
        while (current != origin) {
            path.push_back(current); // add the current city to the path
            current = previous[current]; // update the current city
        }
        path.push_back(origin); // add the origin

        std::reverse(path.begin(), path.end()); // reverse because we started from the destination

        return path;
    }

    // output the shortest path to the file
    void shortestPathToMyMaps(const std::vector<std::string> &shortestPath, std::string &filePath) {
        std::ofstream file;
        file.open(filePath);

        file << "WKT,Name" << std::endl;
        file << "\"LINESTRING(";

        // output the path to the file
        for (int i = 0; i < shortestPath.size(); i++) {
            file << longitude[shortestPath[i]] << " " << latitude[shortestPath[i]];
            if (i != shortestPath.size() - 1) {
                file << ",";
            }
        }

        file << ")\",Shortest Path between " << shortestPath[0] << " -> "
             << shortestPath[shortestPath.size() - 1]
             << std::endl;
    }

    std::vector<Flight> kruskalMST() {
        std::vector<Flight> mst;

        // create a map  and set the parent of each city to itself because each city is a separated
        std::unordered_map<std::string, std::string> parent;
        for (const auto &cityPair: adjacencyList) {
            parent[cityPair.first] = cityPair.first;
        }

        //  create a vector and add all the edges to the vector
        std::vector<Flight> edges;
        for (const auto &cityPair: adjacencyList) {
            for (const auto &flight: cityPair.second) {
                edges.push_back(flight);
            }
        }

        // sort the edges by distance
        std::sort(edges.begin(), edges.end(),
                  [](const Flight &a, const Flight &b) {
                      return a.getDistance() < b.getDistance();
                  });

        for (const auto &edge: edges) {
            std::string originParent = findParent(parent, edge.getOrigin()); // find the parent of the origin
            std::string destinationParent = findParent(parent,
                                                       edge.getDestination()); // find the parent of the destination
            if (originParent != destinationParent) { // parents are different
                mst.push_back(edge); // add the edge to the mst
                parent[originParent] = destinationParent; // update the parent
            }
        }

        return mst;
    }

    void printMST(const std::vector<Flight> &mst, const std::string &path) {
        std::ofstream file;
        file.open(path);

        // output the mst to the file
        file << "Name" << std::endl;
        for (const auto &edge: mst) {
            file << edge.getOrigin() << " -> " << edge.getDestination() << std::endl;
        }
    }

    // find the parent of the city
    std::string findParent(std::unordered_map<std::string, std::string> &parent, const std::string &city) {
        if (parent[city] != city) {
            parent[city] = findParent(parent, parent[city]); // path compression, update the parent
        }
        return parent[city];
    }

    void MSTToMyMaps(const std::vector<Flight> &mst, std::string &filePath) {
        std::ofstream file;
        file.open(filePath);

        file << "WKT,Name" << std::endl;

        // output the mst to the file
        for (const auto &edge: mst) { // for each edge in the mst
            file << "\"LINESTRING(" << longitude[edge.getOrigin()] << " " << latitude[edge.getOrigin()] << ","
                 << longitude[edge.getDestination()] << " " << latitude[edge.getDestination()] << ")\",Between "
                 << edge.getOrigin() << " -> " << edge.getDestination() << std::endl;
        }

    }

    // display all available cities
    void displayAvailableCities() {
        std::cout << "You are now in " << currentCity << ". You can go to: " << std::endl;
        for (int i = 0; i < adjacencyList[currentCity].size(); i++) { // display all available cities
            currentCity = adjacencyList[currentCity][i].getOrigin(); // set the current city
            std::cout << i + 1 << ". " << adjacencyList[currentCity][i].getDestination() << " ("
                      << adjacencyList[currentCity][i].getDistance() << " km) " << std::endl;

            if (i + 1 == adjacencyList[currentCity].size()) { // if the last city
                std::cout << i + 2 << "." << " Exit" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    // move to the city
    void moveToCity(const std::string &city) {
        if (adjacencyList.find(city) != adjacencyList.end()) {
            currentCity = city; // if we have the city in the list, set the current city
        }
    }

    // get the current available cities
    std::vector<std::string> getCurrentAvailableCities() {
        std::vector<std::string> availableCities;
        for (const auto &i: adjacencyList[currentCity]) { // get all available cities from the current special city
            availableCities.push_back(i.getDestination());
        }
        return availableCities;
    }

#endif // ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

};
