/***********************************************************
 CSCI 340 - Assignment 7 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: April 4, 2018 
 Purpose: 
 ************************************************************/

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
    // create our heap array
    int heap[heap_size];

    // iterate until we are one less than heap size -- remember 
    // heap starts at 1 becuase garbage / null value in root
    for( int k = 1; k < heap_size; k++ )
    {
        // set the current position in the array to the current
        // position in the vector that we are iterating over
        // basically filling the array with one value per iteration
        heap[k] = v[k];

        // if the element in the heap equals the element in the
        // vector we need to call heapify  
        if( compar( heap[k], v[k]) != false )
        {
            heapify( v, heap_size, compar ); 
        }
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
    // Loops through every element in vector starting at position 2
    for( int i = 2; i < heap_size; i++ )
    {
        // if the vector's value at index i is greater than the value at index i + 1
        // then the value at index i-1 is equal to the value at index i+1
        if ( v[i] > v[i+1] )
        {
            v[i-1] = v[i+1];
        }
        // otherwise set the index i-1 equal to the current index
        else
        {
            v[i-1] = v[i];
        }
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
}

/***************************************************************
  
 Name: heap_sort 

 Use: 

 Parameters:  

 Returns: None. 

 ***************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    int x = 1;
    int i = heap_size -1;
    while( i > x )
    {
        swap( v[i], v[x] );
        x++;
        i--;
    }
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
    // These allow us to re arrange heaps and max value after deletion
    vector<int>::const_iterator i = v.begin() + 1;
    vector<int>::const_iterator j = v.end() + 1;

    // This allows us to return max value to user after it has been deleted
    int index = *i;

    // This deletes the current max value
    v.erase(i);

    // This swaps the first value of the heap with the heaps last value
    swap(v[*i], v[*j]);

    // This returns the value that was at the top of the heap 
    return index;
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
    // pretty sure this is wrong -- but partially proper
    /*
    const int ITEM_W = 5;
    const int NO_ITEMS = 8;
    vector<int>::const_iterator it;
    for (it = v.at(pos); it != v.at(size); it++)
    {
        cout << setw(ITEM_W) << *it;
        if ((it - v.at(pos) % NO_ITEMS == 7)
        { 
            cout << endl;
        }
	}
    */

    // I know I know this isn't what they want
    // but I need to see if I can get this working first
    vector<int>::const_iterator it;
    for( it = v.begin() + 1; it != v.end(); it++ )
    {
        cout << v[*i] << endl;
    }
}
