#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "20850X Superposition.","Wish","you","A","great","success","in","the","New","Season!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}

