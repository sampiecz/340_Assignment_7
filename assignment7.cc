/***********************************************************
 CSCI 340 - Assignment 7 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: April 4, 2018 
 Purpose: 
 ************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::vector;
using std::random_shuffle;
using std::cout;
using std::endl;
using std::swap;
using std::setw;

// forward declarations
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) );
bool less_than ( int e1, int e2 );
bool greater_than ( int e1, int e2 );
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) );
void print_vector ( vector < int >& v, int pos, int size );

const int HEAP_SIZE = 50;

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

/***************************************************************
  
 Name: build_heap 

 Use: Builds a heap using a vector with ints in it. Then calls
 heapify until the vector is organized into a max heap.

 Parameters: A reference to an integer vector v, an int 
 containing the heap's size, and a pointer to a function that 
 compairs two integers.

 Returns: None. 

 ***************************************************************/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    for( int i = heap_size / 2; i >= 1; i-- )
    {
        heapify(v, heap_size, i, compar);
    }
}

/***************************************************************
  
 Name: heapify 

 Use: This function heapifies the tree at the root position r
 assuming r's two subtrees are already heaps.

 Parameters: A reference to a vector of type int. An int that
 contains the size of the heap, int r for root, and a function
 that compares two integer values.

 Returns: None. 

 ***************************************************************/
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )
{
    int left = 2*r;
    int right = 2*r+1;
    int big;
    int temporary;

    if( left <= heap_size && compar(v[left], v[r]))
    {
        big = left;
    }
    else
    {
        big = r;
    }
    if( right <= heap_size && compar(v[right], v[big]))
    {
        big = right;
    }
    if( big!= r )
    {
        temporary = v[r];
        v[r] = v[big];
        v[big] = temporary;
        heapify(v, heap_size, big, compar);
    }
}

/***************************************************************
  
 Name: less_than 

 Use: Compares two ints, if the first int is less than the 
 second int it returns true.

 Parameters: Two ints, the first one is e1 and the second one e2. 

 Returns: A bool. 

 ***************************************************************/
bool less_than ( int e1, int e2 )
{
    if ( e1 < e2 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
  
 Name: greater_than 

 Use: Compares two ints, if the first int is less than the 
 second int it returns true.

 Parameters: Two ints, the first one is e1 and the second one e2.

 Returns: A bool. 

 ***************************************************************/
bool greater_than ( int e1, int e2 )
{
    if ( e1 > e2 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
  
 Name: heap_sort 

 Use: Implementation of heap sort algorithm. 

 Parameters: A reference to a vector v, an integer describing
 the size of the heap. A pointer to a function called compar. 

 Returns: None. 

 ***************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    int i;

    for( i = heap_size; i >= 2; i-- )
    {
        v[i] = extract_heap(v, heap_size, compar);
    }

    reverse( v.begin() + 1, v.end());
}

/***************************************************************
  
 Name: extract_heap 

 Use: Returns the top value and deletes it. Also sets new max
 element, or top element whatever you want to call it. 

 Parameters: A reference to an int vector, a reference to an
 int called heap_size, and a pointer to a function that takes
 two ints as arguments.

 Returns: An integer. 

 ***************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )
{
    int delete_me;

    delete_me = v[1];

    v[1] = v[heap_size];

    heap_size = heap_size -1;

    heapify( v, heap_size, 1, compar );

    return delete_me;

}

/***************************************************************
  
 Name: print_vector 

 Use: Prints a vector starting at pos until the size. 

 Parameters: A reference to an int vector v, and two ints pos
 and size. 

 Returns: None. 

 ***************************************************************/
void print_vector ( vector < int >& v, int pos, int size )
{
    const int ITEM_W = 5;
    const int NO_ITEMS = 8;

    vector<int>::const_iterator it;
	int counter = 0;
    for (it = v.begin() + 1; it != v.end(); it++)
    {
        cout << setw(ITEM_W) << *it;
        if (counter % NO_ITEMS == 7)
        { 
            cout << endl;
        }

        counter++;
	}

	cout << endl;

}
