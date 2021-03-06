/*
    Given two sorted integer arrays A and B, merge B into A as one sorted array.

     Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
    TIP: C users, please malloc the result into a new array and return the result.
    If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

    Example :

    Input :
             A : [1 5 8]
             B : [6 9]

    Modified A : [1 5 6 8 9]
*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C (A);
    A.clear();
    int i = 0, j = 0;
    while (i < C.size() && j < B.size())
    {
        if (C[i] <= B[j])
            A.push_back(C[i++]);
        else
            A.push_back(B[j++]);

        if (i == C.size())
            while (j < B.size())
                A.push_back(B[j++]);
        else if (j == B.size())
            while (i < C.size())
                A.push_back(C[i++]);
    }
}
