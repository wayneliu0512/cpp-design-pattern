#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product
{
    string name;
    Color color;
    Size size;
};

// Break Open-Closed Principle-------------------------------------------
struct ProductFilter
{
    vector<Product*> by_color(vector<Product*> items, Color color)
    {
        vector<Product*> result;
        for (auto& i : items) {
            if (i->color == color)
                result.push_back(i);
        }
        return result;
    }

    vector<Product*> by_size(vector<Product*> items, Size size)
    {
        vector<Product*> result;
        for (auto& i : items) {
            if (i->size == size)
                result.push_back(i);
        }
        return result;
    }

    vector<Product*> by_size_and_color(vector<Product*> items, Size size
                                       , Color color)
    {
        vector<Product*> result;
        for (auto& i : items) {
            if (i->size == size && i->color == color)
                result.push_back(i);
        }
        return result;
    }
};
//-----------------------------------------------------------------------

// New Solution for keep open-closed principle---------------------------
template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
    virtual vector<T*> filter(vector<T*> items,
                              Specification<T>& spec) = 0;
};

struct BetterProductFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product*> items,
                      Specification<Product>& spec) override{
        vector<Product*> result;
        for (auto& item : items)
            if (spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color_;
    ColorSpecification(Color color) : color_(color){}
    bool is_satisfied(Product* item) override{
        return item->color == color_;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size_;
    SizeSpecification(Size size) : size_(size){}
    bool is_satisfied(Product* item) override{
        return item->size == size_;
    }
};

template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T> &first,
                     Specification<T> &second) :
        first(first), second(second){}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};
//-----------------------------------------------------------------------

int main()
{
    Product apple { "Apple", Color::Red, Size::Small };
    Product tree { "Tree", Color::Green, Size::Large };
    Product house { "House", Color::Blue, Size::Large };

    vector<Product*> items { &apple, &tree, &house };

// Break Open-Closed Principle-------------------------------------------

//    ProductFilter pf;
//    auto green_thing = pf.by_color(items, Color::Green);
//    for (auto& item : green_thing)
//        cout << item->name << " is green" << endl;

// ----------------------------------------------------------------------


// New Solution for keep open-closed principle---------------------------
    BetterProductFilter bf;
    ColorSpecification green(Color::Green);
    for(auto&item : bf.filter(items, green)) {
        cout << item->name << " is green" << endl;
    }
// ----------------------------------------------------------------------


    return 0;
}
