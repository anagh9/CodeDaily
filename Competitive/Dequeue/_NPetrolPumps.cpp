// petrol[] = {4, 8, 7, 4};
// dist[] = {6, 5, 3, 5};
// expl : dist of 1 to 2 pp is 6 , 2 - 3 is 5, 3 - 4 is 3,  4 to 1st is 5

// o/p : 2

// petrol[] = {4,8}
// dist[] = {5,6}

// o/p: 2

// petrol[] = {8,9,4}
// dist[] = {5,10,12}

// o/p: -1


int firstPetrolPump(int petrol[], int dist[], int n) {
	for (int i = 0; i < n; ++i)
	{
		int curr_petrol = 0;
		int end = i;
		while (true) {
			curr_petrol += (petrol[end] - dist[end]);
			if (curr_petrol < 0)
				break;
			end = (end + 1) % n;
			if (end == i)
				return (start + 1)
			}
	}
	return -1;
}