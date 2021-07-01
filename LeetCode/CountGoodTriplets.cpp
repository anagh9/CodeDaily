// https://leetcode.com/problems/count-good-triplets/submissions/

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
  int res = 0;
  int l = arr.size();
  for (int i = 0; i < l; i++) {
    for (int j = i + 1; j < l; j++) {
      if (abs(arr[i] - arr[j]) > a) {
        continue;
      }
      for (int k = j + 1; k < l; k++) {
        if (abs(arr[i] - arr[k]) <= c
            && abs(arr[j] - arr[k]) <= b) {
          res++;
        }
      }
    }
  }
  return res;
}



int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
  int limk = arr.size(), limj = arr.size() - 1, limi = arr.size() - 2, n = 0;

  for (int i = 0; i != limi; i++)
    for (int j = i + 1; j != limj; j++)

      if (abs(arr[i] - arr[j]) <= a)
        for (int k = j + 1; k != limk; k++)
          if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) n++;

  return n;
}