void Loop(std::vector<int> v) {
	for (auto it : v)
		std::cout << it << " ";
}

void gLoop(std::vector<int> v, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
}

void RandomArray(int upperlimit, int size) {
	std::vector<int> x(size);
	for (int i = 0; i < size; i++) {
		x[i] = rand() % upperlimit;
	}
	std::cout << "{";
	for (int i = 0; i < size; i++) {
		std::cout << x[i] << "," << " ";
	}
	std::cout << "}";
}