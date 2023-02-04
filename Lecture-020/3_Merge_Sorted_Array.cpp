#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2) {
    vector<int> ans;

    int i=0, j=0;
    int size1 = arr1.size();
    int size2 = arr2.size();

    while(i < size1 && j < size2) {
        while(i < size1 && j < size2 && arr1[i] < arr2[j]) {
            ans.push_back (arr1[i++]);
        }

        while(i < size1 && j < size2 && arr1[i] > arr2[j]) {
            ans.push_back (arr2[j++]);
        }

        while(i < size1 && j < size2 && arr1[i] == arr2[j]) {
            ans.push_back (arr2[i++]);
            ans.push_back (arr2[j++]);
        }
    }

    while(i < size1) {
        ans.push_back (arr1[i++]);
    }

    while(j < size2) {
        ans.push_back (arr1[i++]);
    }

    return ans;
}

int main() {
    int size1, size2;
    vector<int> arr1;
    vector<int> arr2;

    cout<<"Enter the size of first array : ";
    cin>>size1;

    cout<<"Enter the elements of first array : ";
    for(int i=0; i<size1; i++) {
        int temp;
        cin>>temp;
        arr1.push_back (temp);
    }

    cout<<"Enter the size of second array : ";
    cin>>size2;

    cout<<"Enter the elements of second array : ";
    for(int i=0; i<size2; i++) {
        int temp;
        cin>>temp;
        arr2.push_back (temp);
    }

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);
    
    cout<<"Merged Array : ";
    for(int i:mergedArray) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

/*

Ek bholi bhali pyari, mastani si ladki hai...
Kuchh pagal si, kuchh deewani si ladki hai...
Jiske har ek kirdaar me dil dubna chahe...
Wo kuchh aisi ankahi kahani si ladki hai...

Bhatak gya tha anant andhere galiyon me main...
Us andhere ko roshan kiya ek parwaani se ladki hai...

Kon kehta hai dharti pe bhagwan nahi milte...
Meri najro me samai wo ek ruhani se ladki hai...

Jiske najro ki gehrai me guftgu krta hai ye dil...
Mujhe smbhalti wo pawan ganga ki pani si ladki hai...

In chand labjo me kaise btau main roop uska...
Mai usme doob gya, wo kisi sagar ke jawani si ladki hai...







*/