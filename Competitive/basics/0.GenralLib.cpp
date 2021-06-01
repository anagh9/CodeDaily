void Loop(std::vector<int> vect) {
	for (auto it : vect)
		std::cout << it << " " << std::endl;
}

void deb(int x) {
	std::cout << "#x :" << x << std::endl;
}


template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
	std::cout << firstArg << std::endl; // print first argument
	print(args...); // call print() for remaining arguments
}