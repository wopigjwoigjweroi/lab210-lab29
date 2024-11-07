// Include header files
#include <iostream>
#include <map>
#include <list>
#include <array>
#include <fstream>

using namespace std; 

// Define function prototype 
void populateChange(map<string,array<list<string>, 3>>& map, int time);

// Define function for population change
void populateChange(map<string,array<list<string>, 3>>& map, int time) {

    // Iteration of time periods 
    for (int i = 0; i < time; ++i) {

        cout << "Time Period: " << i + 1 << endl; 
        
    // Iteration of each area of the forest 
    for (auto& part : map) {

        string mapName = part.first;

        auto& list = part.second; 

        // Tree Growth 
        list[0].push_back("New Tree"); 

        // Rabbit Reproduction
    if (!list[0].empty()) {

          list[1].push_back("Newborn Rabbit"); 
        }

        // Predation on Rabbit 
    if (!list[1].empty()) {

            list[1].pop_front(); 
        }

        cout << "Map: " << mapName << " , Trees: " << list[0].size() << ", Rabbit #: " << list[1].size() << ", Predator # " << list[2].size() << endl; 
        
    }
        
    }
}

}; 
