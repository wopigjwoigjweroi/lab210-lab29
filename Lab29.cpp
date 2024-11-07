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

    for (int i = 0; i < time; ++i) {

        cout << "Time Period: " << i + 1 << endl; 

    }

    for (auto& part : map) {

        string mapName = part.first;

        auto& list = part.second; 

        list[0].push_back("New Tree"); 

        if (!list[0].empty()) {

          list[1].push_back("Newborn Rabbit"); 
        }

        
    }

    

}; 
