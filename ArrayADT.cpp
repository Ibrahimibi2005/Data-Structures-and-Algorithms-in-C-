#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
void Display(Array Arr)
{
    int i = 0;
    for (i; i < Arr.length; i++)
    {
        cout << Arr.A[i] << endl;
    }
}
int main()
{
    Array arr;
    int n;
    cout << "Enter size of an array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "Enter the number of numbers: ";
    cin >> n;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr.A[i];
    arr.length = n;

    Display(arr);

    return 0;
}