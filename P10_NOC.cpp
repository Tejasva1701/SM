#include <iostream>
#include <vector>

using namespace std;

class Metrics {
public:
    string Name;
    vector<Metrics*> subclasses;

    void addSubclass(Metrics* subclass) {
        subclasses.push_back(subclass);
    }

    int calculateNOC() {
        return subclasses.size();
    }
};

int main() {
    // Example usage
    Metrics baseClass;
    baseClass.Name = "BaseClass";

    // Creating four subclasses
    Metrics subclass1;
    subclass1.Name = "Subclass1";
    baseClass.addSubclass(&subclass1);

    Metrics subclass2;
    subclass2.Name = "Subclass2";
    baseClass.addSubclass(&subclass2);

    Metrics subclass3;
    subclass3.Name = "Subclass3";
    baseClass.addSubclass(&subclass3);

    Metrics subclass4;
    subclass4.Name = "Subclass4";
    baseClass.addSubclass(&subclass4);

    // Calculate and display the NOC
    int noc = baseClass.calculateNOC();
    cout << "Number of Children (NOC) for " << baseClass.Name << ": " << noc << endl;

    return 0;
}
