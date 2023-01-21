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

        vector<int> current;
        current.push_back(temp);
        current.push_back(count);
        solution.push_back(current);
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

    for (int i = 1; i < solution.size(); i++)
    {
        bool flag = false;

        for (int j = 0; j < solution.size() - i; j++)
        {
            if (solution[j + 1][1] > solution[j][1])
            {
                // Swapping element
                swap(solution[j][0], solution[j + 1][0]);

                // Swapping frequency
                swap(solution[j][1], solution[j + 1][1]);

                flag = true;
            }
        }

        if (!flag)
        {
            // return solution;
            break;
        }
    }

    // for(int i=0; i<solution.size(); i++) {
    //     for(int j=0; j<solution[0].size(); j++) {
    //         cout<<solution[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"\n\n";

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


/*
#include <bits/stdc++.h>

using namespace std;



/*
 * Write the regular expression in the blank space below
*
regex regularExpression("(someString)(.*)");


int main()
{
    int query;
    cin >> query;

    vector<string> result(query, "False");
    for (int i = 0; i < query; i++) {
        string someString;
        cin >> someString;

        if (regex_match(someString, regularExpression)) {
            result[i] = "True";
        }
    }

    ofstream fileOut(getenv("OUTPUT_PATH"));
    for (string res: result) {
        fileOut << res << endl;
    }

    return 0;
}
*/