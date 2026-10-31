//Maxwell Koegler | COMSC210 | LAB 29

//headers, outputs, and data structs
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// array indexes: 0 - trees, 1 - animals, 2 - foliage


void loadData(map<string, array<list<string>, 3>> &m, string f);
void printMap(map<string, array<list<string>, 3>> &m);
void simulateYear(map<string, array<list<string>, 3>> &m, int y);

int main() {
    srand(time(0));
    //map: key =forest type, val = array of 3 lists
    map<string, array<list<string>, 3>> m;

    loadData(m,"data.txt");
    cout << "Year 0" << endl;

    printMap(m);


    //mockup
    m["Old Growth"][0].push_back("Redwood");
    m["Old Growth"][1].push_back("Owl");
    m["Old Growth"][2].push_back("Fern");

    cout << "year 0" << endl;
    printMap(m);

    //run simulation steps

    for(int i = 1; i <=100; i++){
        simulateYear(m,i);

        if(i%5 == 0){
            printMap(m);
        }
    }

}



//placeholder data loading
void loadData() {
    //read line by line
    //input into proper map and sub locaiton
}

//function to print forest type and lists
//params: forest map
void printMap(map<string, array<list<string>, 3>> &m) {
    string n[3]={"Trees", "Animals", "Foilage"};

    //goes throuhg each forest type in the map
    for(auto &p : m) {
        cout << p.first << ":" << endl;
        for(int i = 0; i<3;i++){
            cout << " " << n[i] << ": ";
            for(auto &s : p.second[i]){
                cout << s << " ";
            }
            cout << endl;
        }

    }
    cout << endl;
}

//function to go forward one year
//params: forest map, year to sim
void simulateYear(map<string,array<list<string>,3>> &m, int y){
    //pick rand forest cond/type and event
    //forest policy: add/remove trees; climate event: add or remove foilage; hunting policy: add or remove animals
    //print what changed

    //example
    cout << "Year " << y << ": event example (old growth trees: " << m["Old Growth"][0].size() << ")" << endl;
}