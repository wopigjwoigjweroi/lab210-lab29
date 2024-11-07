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

// Main function that initializes data for software 
int main() {

    // Map initializes parts of the forest 
    map<string, array<list<string>, 3>> forestArea;

    // External file reads key data
    fstream filename("forest_data.txt"); 

    string species, areaTitle; 

    // Populating forest with file data 
    while (filename >> areaTitle >> species) {

        if (species == "Tree") {

            forestArea[areaTitle][0].push_back("Tree");
        } else if (species == "Rabbit") {

            forestArea[areaTitle][1].push_back("Rabbit"); 
        } else if (species == "Predator") {

            forestArea[areaTitle][2].push_back("Predator"); 
        }
    
    }

    filename.close(); 

    // Oversee population change for the next 10 time intervals 
    populateChange(forestArea, 10); 
    
}
