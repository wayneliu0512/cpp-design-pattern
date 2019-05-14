#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    // <p>hello</p>
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";
    printf("<p>%s</p>", text);

    // <ul><li>hello</li><li>world</li></ul>
    string words[] = { "hello", "world" };
    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
      oss << "  <li>" << w << "</li>";
    oss << "</ul>";
    cout << oss.str() << endl;
    return 0;
}
