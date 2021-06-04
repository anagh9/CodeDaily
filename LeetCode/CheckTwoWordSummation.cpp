// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/submissions/

/**
The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).

The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, which is then converted into an integer.

For example, if s = "acb", we concatenate each letter's letter value, resulting in "021". After converting it, we get 21.
You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.

Example 1:

Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
Example 2:

Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
Output: false
Explanation:
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.

**/


int stringInt(string s) {
	map<char, int> mp;
	mp.insert({'a', 0});
	mp.insert({'b', 1});
	mp.insert({'c', 2});
	mp.insert({'d', 3});
	mp.insert({'e', 4});
	mp.insert({'f', 5});
	mp.insert({'g', 6});
	mp.insert({'h', 7});
	mp.insert({'i', 8});
	mp.insert({'j', 9});

	string str = " ";
	for (auto &x : s) {
		str += to_string(mp[x]);
	}
	return stoi(str);
}

bool isSumEqual(string fw, string sw, string tw) {
	return (stringInt(fw) + stringInt(sw) == stringInt(tw));
}

// Better Approach

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
	for (char &c : firstWord)  c -= 'a' - '0';
	for (char &c : secondWord) c -= 'a' - '0';
	for (char &c : targetWord) c -= 'a' - '0';
	return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
}


/*** Python Implementation **/

class Solution:
	def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
	def f(s):
		g = {
	'a': 0,
	'b': 1,
	'c': 2,
	'd': 3,
	'e': 4,
	'f': 5,
	'g': 6,
	'h': 7,
	'i': 8,
	'j': 9
}
a = ""
    for i in s :
    a += str(g[i])
	         return int(a)
	                return f(firstWord) + f(secondWord) == f(targetWord)

