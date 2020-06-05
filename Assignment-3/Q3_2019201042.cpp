#include<iostream>
#include <fstream>
#include <cmath>
#define chunk 524288
using namespace std;

void merge(long long arr[], long long l, long long m, long long r) 
{   
    long long i, j, k; 
    long long n1 = m - l + 1; 
    long long n2 = r - m; 

    long long L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(long long arr[], long long l, long long r) 
{ 
    if (l < r) 
    { 
        long long m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 

        merge(arr, l, m, r); 
    } 
}
void heapify(long long arr[],long long index[], long long n, long long i) 
{ 
    long long largest = i; 
    long long l = 2 * i + 1; 
    long long r = 2 * i + 2; 
    if (l < n && arr[l] < arr[largest]) 
        largest = l;  
    if (r < n && arr[r] < arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        swap(index[i],index[largest]);
        heapify(arr,index, n, largest); 
    } 
} 
int main(int argc,char ** argv) 
{ 
    ifstream in;
    ofstream final_out;
    in.open(argv[1]);
    final_out.open("final_output.txt");
    long long val,count=0,i,j,n_files,k;
    string name="outfile",fname;
    while(in>>val)
    {
        count++;
    }
    cout<<count<<endl;
    in.close();

    n_files = ceil((float)(count*1.0)/(float)(chunk*1.0));
    cout<<n_files<<endl;

    ofstream out[n_files];
    in.open(argv[1]);
    for(i=1;i<=n_files;i++)
    {
        long long *arr = (long long *)malloc(chunk * sizeof(long long));
        fname=name+to_string(i)+".txt";
        out[i-1].open(fname);
        for(j=0;j<chunk;j++)
        {
            if(in>>val)
            {
                arr[j]=val;
            }
            else
            {
                break;
            }
        }
        mergeSort(arr,0,j-1);
        for(k=0;k<j;k++)
        {
            out[i-1]<<arr[k]<<endl;
        }
        out[i-1].close();
    }
    long long count1=0;
    j=0;
    long long heap[n_files+1];
    long long index[n_files+1];
    ifstream tr[n_files];
    for(i=1;i<=n_files;i++)
    {
        fname=name+to_string(i)+".txt";
        tr[i-1].open(fname);
        tr[i-1]>>val;
        heap[j]=val;
        index[j]=i;
        j++;
    }
    long long startIdx = (n_files/2) - 1;
    //cout<<startIdx<<endl;
    for(i=startIdx;i>=0;i--)
    {
        heapify(heap,index,n_files,i);
    }
    count1=0;
    long long top,top1,n,z,x;
    n=n_files;

    while(count1<count-n_files)
    {
        top=heap[0];
        top1=index[0];
        //cout<<top1<<endl;
        swap(heap[0],heap[n-1]);
        swap(index[0],index[n-1]);
        n--;
        heapify(heap,index,n,0);

        if(tr[top1-1]>>val)
        {
            heap[n]=val;
            index[n]=top1;
            n++;
            startIdx = (n/2) - 1;
            for(z=startIdx;z>=0;z--)
            {
                heapify(heap,index,n_files,z);
            }
        }
        final_out<<top<<"  "<<top1<<endl;
        count1++;
    }
    /*for(i=0;i<n_files;i++)
    {
        //cout<<heap[i]<<" "<<index[i]<<"  ";
        //final_out<<heap[i]<<endl;
        //final_out<<heap[i]<<"  "<<index[i]<<endl;
    }*/
    return 0; 
} 