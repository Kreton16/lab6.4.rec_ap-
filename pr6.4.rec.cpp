#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int Minimum(int* mas, const int size, int& mini, int i) {
    
    if(i < size) {
        if (mini > abs(mas[i]))
            mini = abs(mas[i]);
        i++;
        Minimum(mas, size, mini, i);
    }
    return mini;
}

void Create(int* c, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        c[i] = Low + rand() % (High - Low + 1);
        i++;
        Create(c, size, Low, High, i);
    }
}

void Print(int* c, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << c[i];
        i++;
        Print(c, size, i);
    }
}

void Print_changed(int* mas, const int size, int i)
{
    if (i < size) {
        cout << mas[i] << " ";
        i++;
        Print_changed(mas, size, i);
    }
}

void Add_even(int* npmas, int* mas, int np, const int size, int k, int i)
{
    if( i < size - np - 1)
    {
        mas[i + 1] = mas[i + k];
        k++;
        i++;
        Add_even(npmas, mas, np, size, k, i);
    }
}

void Add_odd_1(int* mas, int* npmas, const int size, int np, int j, int& i)
{
        if(i < size - 1)
        {
            mas[i] = npmas[j++];
            i++;
            Add_odd_1(mas, npmas, size, np, j, i);
        }   
}
void Add_odd_2(int* mas, int* npmas, const int size, int np, int j, int& i)
{
    
        if (i < size)
        {
            mas[i] = npmas[j++];
            i++;
            Add_odd_2(mas, npmas, size, np, j, i);
        }
    
}

void Add_odd(int* mas, int* npmas, const int size, int np, int j, int i)
{

    if (size % 2 == 0)
    {
        i = np;
        Add_odd_1(mas, npmas, size, np, j, i);
    }
    else
    {
        i = np + 1;
        Add_odd_2(mas, npmas, size, np, j, i);
    }
}

int in_Sum(int* mas, const int size, int& sum, int i, int j) {
    if (j < size) {
        sum += abs(mas[j]);
        j++;
        in_Sum(mas, size, sum, i, j);
    }
    return sum;
}

int Sum(int* mas, const int size, int& sum, int i, int j) {
    if (i < size) {
        if (mas[i] == 0) {
            j = i + 1;
            in_Sum(mas, size, sum, i, j);
        }
        i++;
        Sum(mas, size, sum, i, j);
    }
    return sum;
}
void Create_odd(int* mas, int* npmas, const int size, int& np, int i) {
   if( i < size)
    {
        if (i % 2 == 1) {
            npmas[np] = mas[i]; np++;
        }
        i++;
        Create_odd(mas, npmas, size, np, i);
    }
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    int mini = 101;
    int k = 2, s = 0, min, n, np = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    cout << "n = ";
    cin >> n;
    int* mas;
    int* npmas;
    npmas = new int[n / 2];
    mas = new int[n];
    int Low = -100;
    int High = 100;
    Create(mas, n, Low, High, i);
    Print(mas, n, i);
    cout << endl;
    min = Minimum(mas, n, mini, i);
    cout << "Min = " << min << endl;
    sum = Sum(mas, n, sum, i, j);
    cout << "Sum = ";
    cout << sum << endl;
    Create_odd(mas, npmas, n, np, i);
    Add_even(npmas, mas, np, n, k, i);
    Add_odd(mas, npmas, n, np, j, i);
    Print_changed(mas, n, i);


    delete[]npmas;
    delete[]mas;

    return 0;

}