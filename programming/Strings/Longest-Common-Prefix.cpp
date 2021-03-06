/*
    Write a function to find the longest common prefix string amongst an array of strings.

    Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

    As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

    Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

    Example:

    Given the array as:

    [

      "abcdefgh",

      "aefghijk",

      "abcefgh"
    ]
    The answer would be “a”.
*/

string Solution::longestCommonPrefix(vector<string> &A) {

    string prefix;
    for (int i = 0; i < A[0].size() ; i++)
    {
        char a = A[0][i];
        int flag = 0;
        for (int j = 1; j < A.size(); j++)
        {
            if (i >= A[j].size() || a != A[j][i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            prefix.push_back(a);
        else
            break;
    }

    return prefix;
}
