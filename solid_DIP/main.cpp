#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct RelationshipsBrowser
{
    virtual vector<Person> find_all_children_of(string name) = 0;
};

struct Relationships : RelationshipsBrowser // low-level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(string name) override{
        vector<Person> result;
        for(auto& relation : relations) {
            Person first, second;
            Relationship rel;
            tie(first, rel, second) = relation;
            if (first.name == name && rel == Relationship::parent) {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research // high-level
{
    Research(RelationshipsBrowser& browser) {
        for (auto& child : browser.find_all_children_of("John")) {
            cout << "John has a child called " << child.name << endl;
        }
    }
//    Research(Relationships relationships)
//    {
//        auto& relations = relationships.relations;
//        for(auto& relation : relations) {
//            Person first, second;
//            Relationship rel;
//            tie(first, rel, second) = relation;
//            if (first.name == "John" && rel == Relationship::parent) {
//                cout << "John has a child called " << second.name << endl;
//            }
//        }
//    }
};

int main()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
    return 0;
}
