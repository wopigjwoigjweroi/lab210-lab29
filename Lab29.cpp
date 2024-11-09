// COMSC-210 | Lab-28/30 | Jeremiah Ortiz 

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

    // Test 1: Empty Forest

    cout << "Test 1: Empty Area\n"; 
    
    forestArea["Empty"]; 

    populateChange(forestArea, 1); 

    cout << "Expecting no change, there isn't a population.\n"; 

    // Test 2: Tree Growth only 

    cout << "Test 2: Forest Tree Growth.\n"; 

    forestArea["Trees"][0].push_back(string("Tree")); 

    populateChange(forestArea, 1); 

    cout << "Expecting tree growth only.\n"; 

    // Test 3: Fully occupied Forest

    cout << "Test 3: Full Forest.\n"; 

    forestArea["Full"][0].push_back(string("Tree")); 

    forestArea["Full"][1].push_back(string("Predator")); 

    forestArea["Full"][2].push_back(string("Rabbit")); 

    populateChange(forestArea, 1); 

    cout << "Expecting a flourishing forest.\n"; 

    // External file reads key data
    fstream filename("forest_data.txt"); 

    // Two string variables that represent life in forest and name for area
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

    // Close the data file 
    filename.close(); 

    // Oversee population change for the next 10 time intervals 
    populateChange(forestArea, 10); 

    return 0; 
}
