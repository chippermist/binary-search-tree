//TreeNode.h - Tree Node implementation and declaration
//Written by Chinmay Garg

#include <iostream>
#include <string>
using namespace std;

//TreeNode Struct using template typename DATA_TYPE
template<typename DATA_TYPE> struct TreeNode
{
	TreeNode(const DATA_TYPE& value, TreeNode<DATA_TYPE>* left = NULL, TreeNode<DATA_TYPE>* right = NULL)
   {
      Value = value;
      Left = left;
      Right = right;
   }
	//Points to the values
	DATA_TYPE Value;
	TreeNode<DATA_TYPE>* Left;
	TreeNode<DATA_TYPE>* Right;

   bool IsLeaf() const
   {
	   //IsLeaf() returns the values of Left and Right as NULL
      return Left == NULL && Right == NULL;
   }
};

//Transverse Funcion which prints out the tree
//takes in the root and the string value taken in by cin
template<typename DATA_TYPE> void Transversal(TreeNode<DATA_TYPE>* root)
{
//	if(root != NULL)
//	{
//		if(root->IsLeaf())
//		{
//			cout << value << "- " << root->Value << endl;
//			return;
//		}
//		else
//		{
//			cout << value << "+ " << root->Value << endl;
//
//			if((root->Left) > 0)
//				Transversal(root->Left, value+" ");
//			if((root->Right) > 0)
//				Transversal(root->Right, value+" ");
//		}
//}
//	else{
//		//prints out No Tree error if there is no tree
//		cout << "There is no tree" << endl;
//	}

	if((root->Value) == '\0')
	{
		cout << root->Value << " ";
		return;
	}
	else
	{
		Transversal(root->Left);
		cout << root->Value << " ";
		Transversal(root->Right);
	}
}

//Insert Function to insert the string into the tree
template<typename DATA_TYPE> void Insert(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& data)
{
	//creates a new node of (data) if the root is NULL
	if(root == NULL)
		root = new TreeNode<DATA_TYPE>(data);
	else 
		if(root->Value == data);	//assigns the data
		else if(root->Value> data)
			Insert(root->Left, data);
		else
			Insert(root->Right, data);

}

//Delete funtion to delete the string user asks for
template<typename DATA_TYPE> void Delete(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& value)
{
	//deletes the string at root
	//returns if root is NULL
	if(root == NULL)
		return;
	if(root->Value > value)
		Delete(root->Left, value);	//deletes the value at left when root->Value > value 
	else if(root->Value < value)
		Delete(root->Right, value);	//deletes the value at right when root->Value < value
	else
	{
		if(root->Left == NULL)
			root = root->Right;
		else if(root->Right == NULL)
			root = root->Left;
		else
		{
			//defines a new variable RMS of type TreeNode<DATA_TYPE>
			//sets it to root
			TreeNode<DATA_TYPE>* RMN = root;
			ReplaceParent(RMN, RMN->Left);
			//replaces the values on the right and left with function ReplaceParent
			delete RMN;
			//deletes the RMN pointer pointing to old value
		}
}
}

//Funtion to Replace Parent
//replaces the values on left and right and assigns them new values
template<typename DATA_TYPE> void ReplaceParent(TreeNode<DATA_TYPE>*& root, TreeNode<DATA_TYPE>*& RMN)
{
	if(RMN->Right != NULL)
	{
		ReplaceParent(root, RMN->Right);
	}
	else
	{
		root->Value = RMN->Value;
		root = RMN;
		RMN = RMN->Left;
	}
}