//
//  Graph.h
//  
//  Defines the Graph class.
//  You SHOULD modify this file.
//  You should not add any additional methods to this class.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef graph_hpp
#define graph_hpp

#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <optional>
#include <iostream>

using namespace std;

namespace csi281 {
    
    template<typename V>
    class Graph {
    public:
        // Add a vertex to the graph
        void addVertex(V vertex) {
            adjacencyList.emplace(vertex, unordered_set<V>());
        }
        
        // Add an edge to the graph
        // *from* is the starting vertex
        // *to* is the ending vertex
        // *bidirectional* is whether the edge should be in both directions
        // If *from* and/or *to* do not exist, they are added as vertices
        void addEdge(V from, V to, bool bidirectional = true) {
            adjacencyList[from].emplace(to);
            if (bidirectional) {
                adjacencyList[to].emplace(from);
            } else { // ensure the *to* vrtex is in the graph
                if (adjacencyList.find(to) == adjacencyList.end()) {
                    addVertex(to);
                }
            }
        }
        
        // Return the neighbors (as an unordered_set) for a vertex
        const unordered_set<V> &neighbors(const V &vertex) {
            // ensure we actually have this vertex in the graph
            assert (adjacencyList.find(vertex) != adjacencyList.end());
            return adjacencyList[vertex];
        }
        
        // Determines whether there is an edge between *from* and *to*
        // if either is not in the graph, return false
        bool edgeExists(const V &from, const V &to) {
            // YOUR CODE HERE
        }
        
        using Path = list<V>;
        // Figure out a path from a goal node back to
        // a start node using a map keeping track of each node and the
        // node that got to it (your explored map)
        Path pathMapToPath(unordered_map<V, V> &previousMap, V &goal) {
            Path path = Path();
            V *current, *previous = nullptr;
            current = &goal;
            do {
                path.push_front(*current);
                previous = current;
                current = &previousMap[*current];
            } while (*current != *previous);
            return path;
        }
        
        // Perform a depth-first search from *start*, looking for *goal*
        // Return a path if one is found using pathMathToPath (with explored)
        // or return nullopt if no path is found
        optional<Path> dfs(const V &start, const V &goal) {
            // how did we get to each node, and which ones have already been visited (dual purpose)
            unordered_map<V, V> explored = unordered_map<V, V>();
            // the start node came from nowhere, so we mark its parent as itself
            explored[start] = start;
            
            // YOUR CODE HERE
            // TIP: Start by defining a frontier and putting start onto it.
            // TIP: Follow the pseudocode from the slides from class
        }
        
        // Perform a breadth-first search from *start*, looking for *goal*
        // Return a path if one is found using pathMathToPath (with explored)
        // or return nullopt if no path is found
        optional<Path> bfs(const V &start, const V &goal) {
            // how did we get to each node, and which ones have already been visited (dual purpose)
            unordered_map<V, V> explored = unordered_map<V, V>();
            // the start node came from nowhere, so we mark its parent as itself
            explored[start] = start;
            
            // YOUR CODE HERE
            // TIP: Start by defining a frontier and putting start onto it.
            // TIP: Follow the pseudocode from the slides from class
            // TIP: This should be very similar to dfs
        }
        
        // Utility function if you need it
        void printExplored(unordered_map<V, V> um) {
            for (auto const& p: um) {
                cout << p.first << " : " << p.second;
                cout << endl;
            }
        }
        
        // Debug print out the contents of the graph
        void debugPrint() {
            for (auto const& p: adjacencyList) {
                cout << p.first << ": ";
                for (auto const& v: p.second) {
                    cout << v << ", ";
                }
                cout << endl;
            }
        }
    private:
        unordered_map<V, unordered_set<V>> adjacencyList = unordered_map<V, unordered_set<V>>();
    };
}


#endif /* graph_hpp */
