#include <iostream>

int main() {
    int input1[] = {0, 10, 20, 30, 40, 50};
    int input2[] = {0, 5, 10, 15, 20, 25};
    int result[6]; // max possible matches
    int i = 0, j = 0, k = 0;

    for (int x = 0; x < 12; x++) {
        if (i < 6 && j < 6) {
            if (input1[i] == input2[j]) {
                result[k++] = input1[i];
                i++;
                j++;
            } else if (input1[i] < input2[j]) {
                i++;
            } else {
                j++;
            }
        }
    }

    // Print result
    std::cout << "Common elements: ";
    for (int a = 0; a < k; a++) {
        std::cout << result[a] << " ";
    }
    std::cout << std::endl;

    return 0;
}
