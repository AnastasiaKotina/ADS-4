// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    while (left <= right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            return count;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += cbinsearch(arr, len, second);
    }
    return count/2;
}
