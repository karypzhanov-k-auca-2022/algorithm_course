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

const double MAX_DISTANCE = 1e9;

class Graph {
private:
    std::unordered_map<std::string, std::vector<Flight>> adjacencyList;
    std::unordered_map<std::string, double> latitude;
    std::unordered_map<std::string, double> longitude;

public:
    Graph() = default;

    Graph(const std::vector<City> &cities, double maxDistance) {
        for (const auto &city: cities) {
            latitude[city.getName()] = city.getLatitude();
            longitude[city.getName()] = city.getLongitude();
        }

        for (int i = 0; i < cities.size(); i++) {
            for (int j = 0; j < cities.size(); j++) {
                if (i != j) {
                    double distance = Flight::calculateDistance(cities[i], cities[j]);
                    if (distance <= maxDistance) {
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

    void shortestPathToMyMaps(const std::vector<std::string> &shortestPath, std::string &filePath) {
        std::ofstream file;
        file.open(filePath);

        file << "WKT,Name" << std::endl;
        file << "\"LINESTRING(";

        for (int i = 0; i < shortestPath.size(); i++) {
            file << longitude[shortestPath[i]] << " " << latitude[shortestPath[i]];
            if (i != shortestPath.size() - 1) {
                file << ",";
            }
        }

        file << ")\",Shortest Path" << std::endl;
    }

    // этот код вроде работает но нужно проверить на корректность и понять потому пока не понимаю как он работает
    std::vector<Flight> kruskalMST() {
        std::vector<Flight> mst;

        std::unordered_map<std::string, std::string> parent;
        for (const auto &cityPair: adjacencyList) {
            parent[cityPair.first] = cityPair.first;
        }

        std::vector<Flight> edges;
        for (const auto &cityPair: adjacencyList) {
            for (const auto &flight: cityPair.second) {
                edges.push_back(flight);
            }
        }
        std::sort(edges.begin(), edges.end(),
                  [](const Flight &a, const Flight &b) {
                      return a.getDistance() < b.getDistance();
                  });

        for (const auto &edge: edges) {
            std::string originParent = findParent(parent, edge.getOrigin());
            std::string destinationParent = findParent(parent, edge.getDestination());
            if (originParent != destinationParent) {
                mst.push_back(edge);
                parent[originParent] = destinationParent;
            }
        }

        return mst;
    }

    void printMST(const std::vector<Flight> &mst, const std::string &path) {
        std::ofstream file;
        file.open(path);

        file << "Name" << std::endl;
        for (const auto &edge: mst) {
            file << edge.getOrigin() << " -> " << edge.getDestination() << std::endl;
        }
    }

    std::string findParent(std::unordered_map<std::string, std::string> &parent, const std::string &city) {
        if (parent[city] != city) {
            parent[city] = findParent(parent, parent[city]); // Путь сжатия: привязываем вершину к корню компоненты
        }
        return parent[city];
    }

    void MSTToMyMaps(const std::vector<Flight> &mst, std::string &filePath) {
        std::ofstream file;
        file.open(filePath);

        file << "WKT,Name" << std::endl;

        for (const auto &edge: mst) {
            file << "\"LINESTRING(" << longitude[edge.getOrigin()] << " " << latitude[edge.getOrigin()] << ","
                 << longitude[edge.getDestination()] << " " << latitude[edge.getDestination()] << ")\",MST"
                 << std::endl;
        }

    }


#endif // ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_GRAPH_H

};
