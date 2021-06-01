
void UnderstandingIterators() {
	for (auto x : array)
		cout << x << " ";

	//For Changing Array
	for (auto &x : array)
		cout << x * 3 << " ";

	for (auto _pos = array.begin(); _pos != array.end(); ++_pos) {
		cout << *_pos;
	}


	// For processing all Sum
	int array[] = { 1, 2, 3, 4, 5 };
	long sum = 0; // process sum of all elements
	for (int x : array) {
		sum += x;
	}
}


void UnderstandingPair() {
	pair<type1, type2> nameOfPair;
	pair<type1, type2> nameOfPair(val1, val2);
	pair<type1, type2> AnotherPair(nameOfPair); // It copies nameOfPairs into it
	pair<pair<pair<int , int>, string>, float> anything;
	pair<int , int >pb = make_pair(val, val2);
	p1.swap(p2) // Swaps the data of p1 and p2 (since C++11)
	swap(p1, p2) // Same (as global function) (since C++11)
	p1 == p2 // Returns whether p1 is equal to p2 (equivalent to p1.first==p2.first && p1.second==p2.second)
	p1 != p2 // Returns whether p1 is not equal to p2 (!(p1==p2))
	p1 < p2 //  Returns whether p1 is less than p2 (compares first or if equal second of both values)
	p1 > p2 //  Returns whether p1 is greater than p2 (p2<p1)
	p1 <= p2 // Returns whether p1 is less than or equal to p2 (!(p2<p1))
	p1 >= p2 // Returns whether p1 is greater than or equal to p2 (!(p1 < p2))
	cout << pb.first << pb.second << endl; //Accesing Pair
	cout << get<0>pb << get<1>pb << endl; //Equivalent to Previous Pair

}