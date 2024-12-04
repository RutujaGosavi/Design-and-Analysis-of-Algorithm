/*Find all distinct subsets of a given set using BitMasking Approach
Given an array of integers arr[], The task is to find all its subsets. The subset can not contain duplicate elements, 
so any repeated subset should be considered only once in the output.
Examples: 
Input:  S = {1, 2, 2}
Output:  {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}
Explanation: The total subsets of given set are – {}, {1}, {2}, {2}, {1, 2}, {1, 2}, {2, 2}, {1, 2, 2}
Here {2} and {1, 2} are repeated twice so they are considered only once in the output
*/

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

void generateSubsets(int index, vector<int>& inputArray, vector<int>& currentSubset, vector<vector<int>>& resultSet) { 
	resultSet.push_back(currentSubset); 
	for (int i = index; i < inputArray.size(); i++) { 
		if (i != index && inputArray[i] == inputArray[i - 1]) 
			continue; 

		currentSubset.push_back(inputArray[i]); 
		generateSubsets(i + 1, inputArray, currentSubset, resultSet); 
		currentSubset.pop_back(); 
	} 
} 

vector<vector<int>> getAllSubsets(int inputArr[], int size) { 
	vector<int> inputArray(inputArr, inputArr + size); 
	vector<int> currentSubset; 
	sort(inputArray.begin(), inputArray.end()); 
	vector<vector<int>> resultSet; 
	generateSubsets(0, inputArray, currentSubset, resultSet); 
	return resultSet; 
} 

int main() { 
	int inputSet[] = { 1, 2 }; 
	vector<vector<int>> subsets = getAllSubsets(inputSet, 2); 

	for (auto subset : subsets) { 
		cout << "["; 
		for (int i = 0; i < subset.size(); i++) { 
			cout << subset[i]; 
			if (i < subset.size() - 1) { 
				cout << ", "; 
			} 
		} 
		cout << "], "; 
	} 

	return 0; 
} 

