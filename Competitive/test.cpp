#include<bits/stdc++.h>
using namespace std;
#include "4.cpp"

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main() {
	c_p_c();

	BinaryTree<int> obj;
	obj.insert(10);
	obj.insert(8);
	obj.insert(6);
	obj.insert(4);
	obj.insert(2);
	std::cout << "\n--------------------------------------------------\n";
	std::cout << "---------------Displaying Tree Contents---------------";
	std::cout << "\n--------------------------------------------------\n";
	obj.printInorder();
	std::cout << std::endl;
	obj.printPreorder();
	std::cout << std::endl;
	obj.printPostorder();
	// b.inorder(root);
	return 0;
}
