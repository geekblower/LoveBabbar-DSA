#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'groupSort' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
*/

class Node {
    public:
    int temp;
    int count;
    Node* next = NULL;

    Node(int temp, int count) {
        this->temp = temp;
        this->count = count;
    }
};

Node *head = NULL;

vector<vector<int>> groupSort(vector<int> arr)
{
    vector<vector<int>> solution;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        int count = 0;

        while (i < arr.size() && arr[i] == temp)
        {
            i++;
            count++;
        }
        i--;

        // vector<int> current;
        // current.push_back(temp);
        // current.push_back(count);
        // solution.push_back(current);

        Node* newNode = new Node(temp, count);
        Node* curr = head;

        if(curr==NULL) {
            head = newNode;
            continue;
        }

        if(count > curr->count) {
            newNode->next = curr;
            head = newNode;
            continue;
        }

        while(curr->next!=NULL && curr->next->count>=count) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;




        /*
        for(int i=0; i<solution.size(); i++) {
            while(i<solution.size() && solution[i][1]<count) {
                i++;
            }

            if(i == solution.size()) {
                break;
            } else {

                for(int j=solution.size()-1; j>=i; j--) {
                    swap(solution[j][0], solution[j-1][0]);
                    swap(solution[j][1], solution[j-1][1]);
                }

            }
        }
        */
        // solution.push_back (current);
    }

    // for (int i = 1; i < solution.size(); i++)
    // {
    //     bool flag = false;

    //     for (int j = 0; j < solution.size() - i; j++)
    //     {
    //         if (solution[j + 1][1] > solution[j][1])
    //         {
    //             // Swapping element
    //             swap(solution[j][0], solution[j + 1][0]);

    //             // Swapping frequency
    //             swap(solution[j][1], solution[j + 1][1]);

    //             flag = true;
    //         }
    //     }

    //     if (!flag)
    //     {
    //         // return solution;
    //         break;
    //     }
    // }

    // for(int i=0; i<solution.size(); i++) {
    //     for(int j=0; j<solution[0].size(); j++) {
    //         cout<<solution[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"\n\n";



    Node* curr = head;

    while(curr != NULL) {
        vector<int> temp;

        temp.push_back (curr->temp);
        temp.push_back (curr->count);

        solution.push_back (temp);
        curr = curr->next;
    }

    return solution;
}

int main()
{
    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);
    */


    int arr_count;
    cout<<"Size : ";
    cin>>arr_count;

    vector<int> arr(arr_count);

    cout<<"Elements : ";
    for(int i=0; i<arr_count; i++) {
        int temp;
        cin>>temp;
        arr.push_back (temp);
    }

    /*
    for (int i = 0; i < arr_count; i++)
    {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }
    */

    vector<vector<int>> result = groupSort(arr);

    for (int i = 1; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];

            if (j != result[i].size() - 1)
            {
                cout << " ";
            }
        }

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    // fout << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}














#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMinimumTrips' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY weights as parameter.
 */

int getMinimumTrips(vector<int> weights) {
    sort(weights.begin(), weights.end());
    int count = 0;
    
    for(int i=0; i<weights.size(); i++) {
        if(weights[i] != weights[i+1] && weights[i] != weights[i-1]) {
            return -1;
        }
        
        if(weights[i] == weights[i+1] && weights[i+1] == weights[i+2]) {
            i += 2;
        } else if(weights[i] == weights[i+1]) {
            i += 1;
        }
        
        count++;
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string weights_count_temp;
    getline(cin, weights_count_temp);

    int weights_count = stoi(ltrim(rtrim(weights_count_temp)));

    vector<int> weights(weights_count);

    for (int i = 0; i < weights_count; i++) {
        string weights_item_temp;
        getline(cin, weights_item_temp);

        int weights_item = stoi(ltrim(rtrim(weights_item_temp)));

        weights[i] = weights_item;
    }

    int result = getMinimumTrips(weights);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
