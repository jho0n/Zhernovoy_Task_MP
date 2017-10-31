/*


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <vector>


using namespace std;

struct data
{
    int information;
};

int comp_more(data a, data b)
{
    if(a.information>b.information) return 1;
    else return 0;
}
int comp_less(data a, data b)
{
    if(a.information<b.information) return 1;
    else return 0;
}
void swap_data(data &a, data &b)
{
    data trash;
    trash.information=a.information;
    a.information=b.information;
    b.information=trash.information;
}
void get_data(data* mass, int size)
{
    for(int i=0;i<size;i++)
    {
        mass[i].information=rand()%100-50;
    }
}
void show_data(data* mass, int size)
{
    cout << "  ";
    for(int i=1;i<11;i++) cout << setw(5) << i; cout << endl;
    cout << "  ";
    for(int i=1;i<11;i++) cout << setw(5) << "-===="; cout << endl;

    for(int j=0; (j<=size/10) && (j*10<size);j++)
    {
        cout << setw(2) << j << "|";
        for(int i=j*10;(i<(j+1)*10) && (i<size);i++)
        {
            cout << setw(4) << mass[i].information << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void sort_incr(data* mass, int size)
{
    bool no_swap=false;
    bool swap=false;

    while(!no_swap)
    {
        swap=false;
        for(int i=0;i<size-1;i++)
        {

            if(comp_more(mass[i],mass[i+1]))
            {
                swap_data(mass[i],mass[i+1]);
                swap=true;
            }

        }
        if(!swap) no_swap = true;
    }
    cout << endl << setw(50) << "-ARRAY SORTED BY INREASING-" << endl << endl;
}
void sort_decr(data* mass, int size)
{
    bool no_swap=false;
    bool swap=false;

    while(!no_swap)
    {
        swap=false;
        for(int i=0;i<size-1;i++)
        {

            if(comp_less(mass[i],mass[i+1]))
            {
                swap_data(mass[i],mass[i+1]);
                swap=true;
            }

        }
        if(!swap) no_swap = true;
    }
    cout << endl << setw(50) << "-ARRAY SORTED BY DECREASING-" << endl << endl;
}


/*
int main(int argc, char *argv[])
{
    int size = 42;
    data* array =new data [size];
    get_data(array,size);
    show_data(array,size);

    sort_decr(array,size);
    show_data(array,size);

    sort_incr(array,size);
    show_data(array,size);

    return 0;
}
*/




