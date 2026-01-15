// Experiment 1:
// Do the following:
//         1.        Write the recurrence relation for the above function.
//         2.        Using the Master Theorem, find the asymptotic time complexity and clearly state which case of the theorem is applied.
//         3.        Modify the given code to:
//         •        count the number of operations performed, and depth of the recursion tree
//         •        measure the execution time (in milliseconds)
// Print the number of operations and time taken for different input sizes n

// Name: Hunar Katyal
// UID: 24BDA70085


#include <bits/stdc++.h>
using namespace std;

class exp1
{
public:
    long long count = 0;
    // int depth;


    int complexRec(int n)
    {
        int depth;
        if (n <= 2)
        {
            return 0;
        }

        int p = n;
        while (p > 0)
        {
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                temp[i] = i ^ p;
                count++;
            }
            p >>= 1;
        } // n/2

        vector<int> small(n);
        for (int i = 0; i < n; i++)
        {
            small[i] = i * i;
            count++;
        } // n

        if (n % 3 == 0)
        {
            reverse(small.begin(), small.end());
            count+=n/2;
        }
        else
        {
            reverse(small.begin(), small.end());
            count+=n/2;
        } // n/2

        int a = complexRec(n / 2);
        int b = complexRec(n / 2);
        int c = complexRec(n / 2);

        depth = max(max(a,b),c) + 1;

        return depth;
    }
};


int main()
{
    exp1 experiment1;
    using namespace std::chrono;

    auto start = high_resolution_clock::now(); // start stopwatch

    int depth = experiment1.complexRec(10000); // function call
    
    auto end = high_resolution_clock::now(); //end stopwatch
    
    auto duration = duration_cast < milliseconds > (end-start); // calculate time
    
    cout << endl <<"Number of iterations: " <<experiment1.count << endl; 
    cout << "Time taken: " << duration.count() << "ms" << endl;
    cout << "depth of the recursive function: " << depth << endl;
}


// 1. Recurrence relation: T(n) = 3T(n/2) + 5n/2;
// 2. a = 3, b = 2, k = 1;
//     case 1 : a > b^k;
//     T(n) = O(n^(log (base 2) 3))
// 3. modified.
