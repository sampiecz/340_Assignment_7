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

 Use: 

 Parameters:  

 Returns: None. 

 ***************************************************************/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
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

 Use: 

 Parameters:  

 Returns: A bool. 

 ***************************************************************/
bool less_than ( int e1, int e2 )
{
}

/***************************************************************
  
 Name: greater_than 

 Use: 

 Parameters:  

 Returns: A bool. 

 ***************************************************************/
bool greater_than ( int e1, int e2 )
{
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

 Use: 

 Parameters: A reference to an int vector v, and two ints pos
 and size. 

 Returns: None. 

 ***************************************************************/
void print_vector ( vector < int >& v, int pos, int size )
{
}
