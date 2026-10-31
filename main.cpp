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
    //simulate the 100 years of policy rollouts
    for(int i = 1; i <= 100; i++) {
        simulateYear(m, i);

        if(i%5==0) {
            cout << "Year: " << i << endl;
            printMap(m);
        }
    }


    //run simulation steps

    for(int i = 1; i <=100; i++){
        simulateYear(m,i);
        if(i%5 == 0){
            printMap(m);
        }
    }

    return 0;

}



//placeholder data loading
void loadData(map<string, array<list<string>, 3>> &m, string f) {
    //read line by line
    //input into proper map and sub locaiton

    ifstream in(f);

    string a;
    string b;
    string c;

    while(getline(in, a, ',') && getline(in, b, ',') && getline(in, c)){
        int i = 2;//foliage

        if(b == "tree"){ //tree
            i = 0;
        }
        if(b == "animal"){ //animal
            i = 1;
        }
        m[a][i].push_back(c); //add to mapping

    }
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
    
    string e[3] = {"Forestry policy", "Hunting policy", "Climate event"};
    string n[3] = {"trees", "animals", "foliage"};

    //pick rand forest type

    auto p = m.begin();
    int r = rand() % m.size();

    for(int k = 0; k < r; k++) {
        p++;
    }

    int i = rand() % 3;
    list<string> &l = (*p).second[i];
    cout << "Year " << y << ": " << e[i] << " in " << (*p).first << endl;

    if(l.empty()) {
        cout << "no " << n[i] << " left to change" << endl;
        return;
    }

    if(rand() % 2 == 0) {
        cout << "added " << l.front() << endl;
        l.push_back(l.front());
    } else {
        cout << "removed " << l.front() << endl;
        l.pop_front();
    }
}