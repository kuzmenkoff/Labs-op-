#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int size, n = -1;
    cout << "Enter number of elements: "; cin >> size;
    TNode* tree = GenerateTree(size);
    int levels = NumOfLevels(tree);
    cout << "There are " << levels << " levels in this tree.\n";
    while(n > levels || n < 0) {
        cout << "n = "; cin >> n;
        if (n > levels || n < 0) {
            cout << "Wrong!\n";
        }
    }
    cout << "All elements of the tree:\n";
    PrintTree(tree);
    cout << endl;
    cout << "There are " << NumOnTheLevel(tree, n, 0, 0) << " elements on the " << n << "th level of the tree.\n";
    cout << n << "th level: ";
    PrintLevel(tree, n, 0); cout << endl;

}


