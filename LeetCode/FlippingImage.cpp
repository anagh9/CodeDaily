// https://leetcode.com/problems/flipping-an-image/

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	int len = A.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j * 2 < len; j++) {
			if (A[i][j] == A[i][len - j - 1]) {
				A[i][j] ^= 1;
				A[i][len - j - 1] = A[i][j];
			}
		}
	}
	return A;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	int row = A.size(), col = A[0].size();
	for (int i = 0; i < row; i++)
		for (int j = 0; j <= (col - 1) / 2; j++)
		{
			int temp = A[i][j];
			A[i][j] = !A[i][col - j - 1];
			A[i][col - j - 1] = !temp;
		}

	return A;
}


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for (auto& v : A) {
		reverse(v.begin(), v.end());
		for (auto& n : v)
			n = !n;
	}
	return A;
}


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for_each(A.begin(), A.end(), [](auto & r) {reverse(r.begin(), r.end()); for_each(r.begin(), r.end(), [](auto & n) {n = !n;});});
	return A;
}