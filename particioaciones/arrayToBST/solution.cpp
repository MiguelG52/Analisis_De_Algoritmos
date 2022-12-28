#include<bits/stdc++.h>
#include <fstream>
using namespace std;

typedef struct Node{
    int item;
    Node *left;
    Node *right;
}TreeNode;

class Solution {
	static public:
    	int count = 0;

	    TreeNode* sortedArrayToBST(vector<int>& nums) {
	        return helper(nums, 0, nums.size()-1);
	    }
    
	    TreeNode* helper(vector<int>& nums, int left, int right){
	        
	        //caso base
	        //Si el puntero izquiero es mayor al derecho -> return null;
	        if(left > right){
	            return NULL;
	        }
	        
	        // la mitad del array será la raiz del arbol
	        int mid = (left + right) / 2;
	        TreeNode* temp = new TreeNode(nums[mid]);
	        
	        //parte derecha del array que sera subarbol derecha
	        temp->left = helper(nums, left, mid-1);
	        
	        //parte derecha del array que sera subarbol derecha
	        temp->right = helper(nums, mid+1 , right);
	        return temp;
	    }
};


int main(){
    fstream excel("tabla");
    srand(time(NULL));
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
    	int size = rand()%(15-1);
		vector<int> v;
		
		for(int i=0; i<size; i++){
	    	if(i==0);
		}
    }
	return 0;
}
