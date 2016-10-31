#include <iostream>
#include <algorithm>
#include<vector>
#include<sstream>
using namespace std;
#define Mid(n,r)((n+r)/2)
int Mybinarysearch(vector<int> list, int size, int value);
void  sorted_lowto_high(vector<int>& list);
void sorted_highto_low(vector<int>& list, vector<int> &hightolow);
int Median(vector<int> list, int size);
int Mean(vector<int> list,int size);
void driversearch();
void print(vector<int> list);
void get_nums(vector<int> & list);
void bubbleSort(vector<int> &list);
void QuickSort(vector<int> &list,int start,int end);
int partition(vector<int>& list,int start,int end);
//----
int Mode(vector<int> list);
void copy_vector(vector<int>&list,vector<int>& copy);
void selection_sort(vector<int>& a);
void merge_sort(vector<int>& a, int from, int to);
void merge(vector<int>& a, int from, int mid, int to);
void swap(int& a,int &b);
int min_position(vector<int>& a, int from, int to);
int min_positionHL(vector<int>& a, int from, int to);
void selection_sortHL(vector<int>& a);
//---
int main()
{
     system("clear");
     vector<int> list;
     vector<int> hightolow;
     vector<int> sort2;
     vector<int> sort3;
      vector<int> mode;
       vector<int> med;

     get_nums(list);
     cout<<"before organized"<<endl;
     print(list);
     copy_vector(list,sort2);
     copy_vector(list,sort3);
     copy_vector(list,mode);


     merge_sort(list,0,list.size()-1);
     cout<<"low to high. with merge_sort"<<endl;
     print(list);

     sorted_lowto_high(sort2);
     cout<<"low to high. with selection sort"<<endl;
     print(sort2);

    selection_sortHL(sort3);
    cout<<"high to low with  selection sort"<<endl;
    print(sort3);

         cout<<"Mode: ";
         cout<<Mode(mode);
         cout<<endl;



     cout<<"mean: ";
     cout<<Mean(list, list.size());
     cout<<endl;

     cout<<"meadian: ";
     cout<<Median(list, list.size());
     cout<<endl;





    return 0;
}
void selection_sort(vector<int>& a)
{
    int next;
   for (next = 0; next < a.size() - 1; next++)
   {
       int min_pos = min_position(a, next, a.size() - 1);
       if (min_pos != next)
            swap(a[min_pos], a[next]);
   }
}
int min_position(vector<int>& a, int from, int to)
{
   int min_pos = from;
   int i;
   for (i = from + 1; i <= to; i++)
      if (a[i] < a[min_pos]) min_pos = i;
   return min_pos;
}
void selection_sortHL(vector<int>& a)
{
    int next;
   for (next = 0; next < a.size() - 1; next++)
   {
       int min_pos = min_positionHL(a, next, a.size() - 1);
       if (min_pos != next)
            swap(a[min_pos], a[next]);
   }
}
int min_positionHL(vector<int>& a, int from, int to)
{
   int min_pos = from;
   int i;
   for (i = from + 1; i <= to; i++)
      if (a[i] > a[min_pos]) min_pos = i;
   return min_pos;
}
void swap(int& a,int &b)
{
    int temp = a;
       a = b;
       b= temp;
}

void merge_sort(vector<int>& a, int from, int to)
{

    if (from == to) return;
    int mid = (from + to) / 2;
    merge_sort(a,from,mid);
    merge_sort(a,mid+1,to);
   merge(a, from, mid, to);

}
void merge(vector<int>& a, int from, int mid, int to)
{
    int n = to - from + 1;
    int i1 = from;

    int i2 = mid + 1;
    int j = 0;
    vector<int> b(n);
    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
         {
            b[j] = a[i1];
            i1++;
         }
        else
        {
            b[j] = a[i2];
            i2++;
        }
         j++;
    }
    while (i1 <= mid)
    {
         b[j] = a[i1];
        i1++;
        j++;
    }
    while (i2 <= to)
    {
          b[j] = a[i2];
          i2++;
          j++;
    }
    for (j = 0; j < n; j++)
          a[from + j] = b[j];
  }

void QuickSort(vector<int> &list,int start,int end)
{
    if(start,end)
    {
    int p;
    p=partition(list, start,list.size());
    //left
    QuickSort(list,start,p-1);
    //right
    QuickSort(list,p+1,end);
    }
}

int partition(vector<int>& list,int start,int end)
{
    int pivot=list[end];
    int i=start-1;
    int j=start;
    for(;i<end-1;++j)
    {
        if(list[j]<list[pivot])
        {
            ++i;
            swap(list[i],list[j]);

        }
    }
    swap(list[j],list[end]);
    return (i+1);
}
void get_nums(vector<int> &list)
{
    string numbers;
    cout<<"please enter 10 numbers "<<endl;
    getline(cin,numbers);
          stringstream ss(numbers);
          int temp;
          while(ss >> temp)
              list.push_back(temp);
}

void  sorted_lowto_high(vector<int>& list)
{
   bubbleSort(list);
}
void sorted_highto_low(vector<int> &list,vector<int>&hightolow)
{
    for(int i = list.size()-1;i>=0;i--)
    {
        hightolow.push_back(list[i]);
    }
}
void copy_vector(vector<int>&list,vector<int>& copy)
{
    for(int i = 0;i<list.size();i++)
    {
        copy.push_back(list[i]);
    }
}

int Mean(vector<int> list,int size)
{
 int temp=0;
 int value=0;
 for(int i = 0;i<list.size()-1;i++)
 {
     temp=list[i];
     value= value+temp;
 }
 return(value/size);
}

int Median(vector<int> list, int size)
{
    selection_sort(list);
    return list[Mid(0,size)];
}

int Mode(vector<int> list)
{
    vector<int> count;
    int bigindex=0;
   // fill
    for(int i = list.size()-1;i>=0;i--)
        count.push_back(0);

    // count
    for(int i = 0;i<list.size()-1;i++)
     {
        for(int j=0;j<list.size()-1;j++)
        {
            if(list[i]==list[j])
                count[i]=count[i]+1;
         }
    }

    for(int i = 0;i<list.size()-1;i++)
    {
        if(count[bigindex]<=count[i])
        {
            bigindex=i;
        }

    }
    return list[bigindex];


}

void driversearch()
{
//    vector<int> Vlist;
//    int myreturn;
//    int value=5;
//    int list[10] = { 1,2,3,5,0,9,4,6,7,15 };
//    for(int i=0;i<7;++i)
//        Vlist.push_back(list[i]);
//    sort(list,list+7);

//  myreturn=  Mybinarysearch(list,10,value);
//          cout<<myreturn<<endl;
//}
}
int Mybinarysearch(vector<int> list, int size, int value)
{
   int low= 0;
   int mid;
   int high= size;
  while(low<=high)
   {
      mid= Mid(low,high);
      if(value==list[mid])
       return mid;
    else if(value< list[mid])
       high= mid-1;
    else if(value>list[mid])
       low= mid+1;
   }

}
void bubbleSort(vector<int> &list)
{
    bool swapped = true;
    while(swapped)
    {
      swapped = false;
      for(size_t i = 0; i<list.size()-1; ++i)
          if(list[i+1] < list[i])
          {
              swap(list[i], list[i+1]);
              swapped = true;
          }
   }
}
void print (vector<int>list)
{
    for(int i= 0 ;i<list.size();i++)
     {
        cout<<list[i];
        cout<<" ";
    }
    cout<<endl;
}

