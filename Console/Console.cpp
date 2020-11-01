// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../MySet/MySet.h" 
#include "../MySet/OrderedSet.h"
using namespace std;
int main()
{
    // OrderedSet s1({ 1,2,3,20,13,9 });
    // OrderedSet s2 = s1.getLarger(0);
    //OrderedSet s1({ 5,4,3,2,1 });
    //OrderedSet s2({ 3,4,5,8,10 });

    OrderedSet s3 = Set::merge(OrderedSet({ 1,2 }), OrderedSet({ 3,4 }));
    // OrderedSet s4 = s1.getLarger(4);
    // OrderedSet s5 = s1.getLarger(19);
    // OrderedSet s6 = s1.getLarger(20);
    // OrderedSet s7 = s1.getLarger(21);

    // cout << s3.containsAll(OrderedSet({ 2,3,20,13,9 })) << endl;
    cout << s3 << endl;
    
    /* 
    cout << s1 << endl;
    cout << s3.getLarger(3) << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl; 
    */



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
