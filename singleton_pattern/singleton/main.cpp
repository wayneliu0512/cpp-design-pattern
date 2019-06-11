#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class SingletonDatabase
{
public:
    SingletonDatabase(SingletonDatabase&) = delete;
    void operator=(SingletonDatabase&) = delete;

    static SingletonDatabase& get_instance(){
        static SingletonDatabase database;
        return database;
    }

    int get_population(const string& name) {
        return capitals[name];
    }

private:
    SingletonDatabase() {
        cout << "Intializing database\n";
        ifstream ifs("capitals.txt");

        string s1;
        string s2;

        while(getline(ifs, s1)) {
            getline(ifs, s2);
            int population = stoi(s2);
            capitals[s1] = population;
        }
    }
    map<string, int> capitals;
};

int main()
{
    string city = "Taipei";
    cout << city << " has population "
         << SingletonDatabase::get_instance().get_population(city)
         << endl;
    return 0;
}
