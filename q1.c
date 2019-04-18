#include<stdio.h>
int a[100],b[100];
int heapsize_min=0;
int heapsize_max=0;
void max_heapify (int Arr[ ], int i, int N)
    {
        int left = 2*i ;              //left child
        int right = 2*i +1;
        int largest;           //right child
        if(left<= N && Arr[left] > Arr[i] )
              largest = left;
        else
             largest = i;
        if(right <= N && Arr[right] > Arr[largest] )
            largest = right;
        if(largest != i )
        {
            //swap (Arr[i] , Arr[largest]);
            int t = Arr[i];
            Arr[i] = Arr[largest];
            Arr[largest] = t;
            max_heapify (Arr, largest,N);
        } 
     }
void min_heapify(int Arr[ ] , int i, int N)
{
    int left  = 2*i;
    int right = 2*i+1;
    int smallest;
    if(left <= N && Arr[left] < Arr[i] )
         smallest = left;
    else
        smallest = i;
    if(right <= N && Arr[right] < Arr[smallest] )
        smallest = right;
    if(smallest != i)
    {
        //swap (Arr[ i ], Arr[ smallest ]);
        int t = Arr[i];
        Arr[i] = Arr[smallest];
        Arr[smallest] = t;
        min_heapify (Arr, smallest,N);
    } 
}
/*void build_maxheap (int Arr[ ])
    {
        for(int i = N/2 ; i >= 1 ; i-- )
        {
            max_heapify (Arr, i) ;
        }
    }
void build_minheap (int Arr[ ]) 
    {
        for( int i = N/2 ; i >= 1 ; i--)
        min_heapify (Arr, i);
    }*/
void insert_minheap(int Arr[], int a)
{
	heapsize_min = heapsize_min + 1;
	int i = heapsize_min;
	Arr[i] = a;
	while(i!= 1 && Arr[i/2] > a)
	{
		int t = Arr[i/2];
		Arr[i/2] = Arr[i];
		Arr[i] = t;
		i = i/2;
	}
}
void insert_maxheap(int Arr[], int a)
{
	heapsize_max = heapsize_max+1;
	int i = heapsize_max;
	Arr[i] = a;
	while(i!=1 && Arr[i/2]<a)
	{
		int t = Arr[i/2];
		Arr[i/2] = Arr[i];
		Arr[i] = t;
		i = i/2;
	}
}
void delete_minheap(int Arr[])
{
	Arr[1] = Arr[heapsize_min];
	heapsize_min = heapsize_min - 1;
	min_heapify(Arr,1,heapsize_min);

}
void delete_maxheap(int Arr[])
{
	Arr[1]=Arr[heapsize_max];
	heapsize_max=heapsize_max-1;
	max_heapify(Arr,1,heapsize_max);
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+1];
	int min_heap[n];
	int max_heap[n];
	heapsize_min = 0;
	heapsize_max = 0;
	float m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if(i==1)
		{
			printf("eas here %d\n", arr[i]);
			printf(" %f ", (double)arr[i]);
			m = (double)arr[i];
		}
		else if(m<arr[i])
		{
			if(i%2==0)
			{
				if(heapsize_min>0)
				{
					if(arr[i]<min_heap[1])
					{
						insert_maxheap(max_heap,m);
						m = (double)(m + arr[i])/2;
						insert_minheap(min_heap,arr[i]);
					}
					else 
					{
						insert_maxheap(max_heap,m);
						m = (double)(m+min_heap[1])/2;
						insert_minheap(min_heap,arr[i]);
					}
				}
				else
				{
					insert_minheap(min_heap,arr[i]);
					insert_maxheap(max_heap,m);
					m = (double)(m+arr[i])/2;
				}

			}
			else
			{
				if(heapsize_min>0)
				{
				if(arr[i]<min_heap[1])
				{
					m = (double)arr[i];
				}
				else
				{
					m = (double)min_heap[1];
					delete_minheap(min_heap);
					insert_minheap(min_heap,arr[i]);
				}
				}
			}
			printf(" %f ",(double)m);
		}
		else
		{
			if(i%2==0)
			{
				if(heapsize_max>0)
				{
				insert_minheap(min_heap,m);
				if(arr[i]<max_heap[1])
				{
					m = (double)(m+max_heap[1])/2;
					insert_maxheap(max_heap,arr[i]);
				}
				else
				{
					m = (double)(m+arr[i])/2;
					insert_maxheap(max_heap,arr[i]);
				}
				}
				else
				{
					insert_maxheap(max_heap,arr[i]);
					insert_minheap(min_heap,m);
					m = (double)(m+arr[i])/2;
				}
			}
			else
			{
				if(arr[i]>max_heap[1])
				{
					m = (double)arr[i];
				}
				else
				{
					m = (double)max_heap[1];
					delete_maxheap(max_heap);
					insert_maxheap(max_heap,arr[i]);
				}
			}
			printf(" %f ", (double)m);
		}
	}
}
