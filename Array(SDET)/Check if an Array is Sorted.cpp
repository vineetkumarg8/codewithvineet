//Iterative approach – O(n) Time and O(1) Space

bool isSorted(const vector<int>& arr)
{
    // For an array to be sorted, every
    // element must be greater than the 
    // previous element
    for (int i = 1; i < arr.size(); i++)
        if (arr[i - 1] > arr[i])
            return false;

    return true;
}
