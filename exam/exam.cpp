#include <iostream>
#include <algorithm>

const int SIZE = 10; // ������� ����� ������ �� ��������

// ������� ��� ���������� ���� �������� �������� ������
double sumOfOddElements(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(arr[i]) % 2 != 0) { // �������� �� ���������
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    double arr[SIZE];

    // ���������� ������ (�� ���� ���� ��������� � ��������� ��� ����� ��������)
    std::cout << "Enter " << SIZE << " real numbers:\n";
    for (int i = 0; i < SIZE; ++i) {
        if (!(std::cin >> arr[i])) {
            std::cerr << "Invalid input. Please enter a valid real number.\n";
            return 1;
        }
    }

    // ���������� ���� �������� ��������
    double oddSum = sumOfOddElements(arr, SIZE);
    std::cout << "Sum of odd elements: " << oddSum << std::endl;

    // ����������� ������������� �� ���������� ��������
    auto maxElem = std::max_element(arr, arr + SIZE);
    auto minElem = std::min_element(arr, arr + SIZE);

    // ����������� ������� ������������� �� ���������� ��������
    int maxIndex = std::distance(arr, maxElem);
    int minIndex = std::distance(arr, minElem);

    // ����������� ������� �������� �� ������������ � ���������
    double product = 1.0;
    int start = std::min(maxIndex, minIndex) + 1;
    int end = std::max(maxIndex, minIndex);

    if (start < end) {
        for (int i = start; i < end; ++i) {
            product *= arr[i];
        }
    }
    else {
        std::cout << "No elements between max and min for product calculation.\n";
    }

    std::cout << "Product of elements between max and min: " << product << std::endl;

    // ���������� �������� �� ���������
    std::sort(arr, arr + SIZE, std::greater<double>());

    // ��������� ������������� ������
    std::cout << "Sorted array in descending order:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
