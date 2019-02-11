#include <vector>
#include <iostream>

/* print function for vectors
* \param std::vector vetor to be printed
*/
template<class T>
void print(T& v){
    for(auto i: v){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}
template <class T>
void merge(T& v, int lo, int mid, int hi){
    T a(v.size());
    int i = lo;
    int j = mid+1;
    int k = lo;

    while(i<mid+1 && j<hi+1){
        if(v[i]<v[j]){
            a[k]=v[i];
            i++;
        }else{
            a[k]=v[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        for(int c=j;c<hi+1;c++){
            a[k]=v[c];
            k++;
        }
    }else{
        for(int c=i;c<mid+1;c++){
            a[k]=v[c];
            k++;
        }
    }
    for(int c=lo; c<hi+1; c++){  
        v[c]=a[c];
    }

}

/* sort the array using mergesort
 * \param array
 * \param int lowest index
 * \param int highest index
 */
template <class T>
void mergeSort(T& v, int lo, int hi){
    if(lo < hi){
        int mid = (hi-lo)/2;
        mergeSort(v, lo, mid);
        mergeSort(v, mid+1, hi);
        merge(v, lo, mid, hi);
    }
}
int main(){
    std::vector<int> v ={3,2,5,8,10};
    print(v);
    mergeSort(v,0,v.size()-1);
    print(v);
}
