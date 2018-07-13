/*
    You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

    2 painters cannot share a board to paint. That is to say, a board
    cannot be painted partially by one painter, and partially by another.
    A painter will only paint contiguous boards. Which means a
    configuration where painter 1 paints board 1 and 3 but not 2 is
    invalid.
    Return the ans % 10000003

    Input :
    K : Number of painters
    T : Time taken by painter to paint 1 unit of board
    L : A List which will represent length of each board

    Output:
         return minimum time to paint all boards % 10000003
    Example

    Input :
      K : 2
      T : 5
      L : [1, 10]
    Output : 50
*/

bool isPossible(int mid, int painters, vector<int> &boards) {
    int count = 1, sum = 0;
    for (int board: boards) {
        if (board > mid)
            return false;

        if (sum + board > mid) {
            sum = board;
            count++;
        }
        else
            sum += board;

        if (count > painters)
            return false;
    }

    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int total = 0;
    for (int c: C)
        total += c;

    int sol = INT_MAX;
    int start = 0, end = total;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(mid, A, C)) {
            sol = min(sol, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return (long long)sol * B % 10000003;
}
