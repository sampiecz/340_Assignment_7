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

 Use:  

 Parameters:  

 Returns: None. 

 ***************************************************************/
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )
{
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
}

/***************************************************************
  
 Name: extract_heap 

 Use: 

 Parameters:  

 Returns: An integer. 

 ***************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )
{
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
    for (it = v.at(pos); it != v.at(size); it++)
    {
        cout << setw(ITEM_W) << *it;
        if ((it - v.at(pos) % NO_ITEMS == 7)
        { 
            cout << endl;
        }
	}
}
