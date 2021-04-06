// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
        count++;
  return count;
}

int countPairs2(int *arr, int len, int value) {
int count = 0, x = 0, y = len - 1;
  while (x < y) {
    int mid = (x + y) / 2;
    if (value == arr[mid])
      break;
    else if (value > arr[mid])
      x = mid;
    else
      y = mid;
  }
  for (int i = y; i >= 0; i--)
    for (int j = 0; j < i; j++)
      if (arr[i] + arr[j] == value)
        count++;
      else if (arr[i] + arr[j] > value)
        break;
  return count;
}
int countPairs3(int* arr, int len, int value) {
int count = 0, left = 0, right = len - 1;
  while (left < right-1) {
    int middle = (left + right) / 2;
    if (arr[middle] <= value)
      left = middle;
    else
      right = middle;
  }
  for (int i = 0; i < left; i++) {
  int x = i + 1, y = left;
    while (x < y) {
      int mid = (x + y) / 2;
      if (arr[mid] < value - arr[i])
        x = mid + 1;
      else
        y = mid;
    }
    while (arr[x] == value - arr[i]) {
      count++;
      x++;
    }
  }
  return count;
}
