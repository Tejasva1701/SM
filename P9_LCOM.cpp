#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Method {
public:
    string name;
    unordered_set<string> accessedAttributes;

    Method(string n) : name(n) {}

    void addAccessedAttribute(string attributeName) {
        accessedAttributes.insert(attributeName);
    }
};

class Metrics {
public:
    string Name;
    vector<Method> methods;

    void addMethod(string name) {
        methods.push_back(Method(name));
    }

    void addAttributeAccess(string methodName, string attributeName) {
        for (auto& method : methods) {
            if (method.name == methodName) {
                method.addAccessedAttribute(attributeName);
                break;
            }
        }
    }

    int calculateLCOM() {
        int disjointSets = 0;

        for (size_t i = 0; i < methods.size(); ++i) {
            for (size_t j = i + 1; j < methods.size(); ++j) {
                // Check if the sets of accessed attributes are disjoint
                unordered_set<string> intersectionSet;
                for (const auto& attribute : methods[i].accessedAttributes) {
                    if (methods[j].accessedAttributes.count(attribute) > 0) {
                        intersectionSet.insert(attribute);
                    }
                }

                if (intersectionSet.empty()) {
                    disjointSets++;
                }
            }
        }

        return disjointSets;
    }
};

int main() {
    // Example usage
    Metrics myClass;
    myClass.Name = "MyClass";

    // Adding methods to the class
    myClass.addMethod("methodA");
    myClass.addMethod("methodB");
    myClass.addMethod("methodC");

    // Adding attribute accesses (e.g., methodA accesses attributeX)
    myClass.addAttributeAccess("methodA", "attributeX");
    myClass.addAttributeAccess("methodB", "attributeY");
    myClass.addAttributeAccess("methodC", "attributeX");
    myClass.addAttributeAccess("methodC", "attributeZ");

    // Calculate and display the LCOM
    int lcom = myClass.calculateLCOM();
    cout << "Lack of Cohesion in Methods (LCOM) for " << myClass.Name << ": " << lcom << endl;

    return 0;
}
