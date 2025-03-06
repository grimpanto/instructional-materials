// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 

#include<iostream>
#include<memory>

namespace bst {

    //Definition of Node for Binary search tree
    struct Node {
        Node(int data_): data(data_) {}
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    
    // To insert data in BST
    void insert(Node& root, int data) {
        auto fill_node = [data](auto& nodeptr){
            if (nodeptr)
                insert(*nodeptr, data);
            else
                nodeptr = std::make_unique<Node>(data);
        };
        if(data <= root.data) // if data to be inserted is lesser, insert in left subtree. 
            fill_node(root.left);
        else 		      // else, insert in right subtree. 
            fill_node(root.right);
    }

    
    //To search an element in BST, returns true if element is found
    bool search(const Node& root,int data) {
        auto search_helper = [data](const auto& nodeptr){
            if(nodeptr)
                return search(*nodeptr, data);
            return false;
        };
        if(root.data == data)
            return true;
        else if(data <= root.data)
            return search_helper(root.left);
        else 
            return search_helper(root.right);
    }
}


int main() {
	/*Code to test the logic*/
	auto root = bst::Node{15};// Create first node
	bst::insert(root,10);
	bst::insert(root,20);
	bst::insert(root,25);
	bst::insert(root,8);
	bst::insert(root,12);

	// Ask user to enter a number.  
	int number;
	std::cout<<"Enter number be searched\n";
	std::cin>>number;
    
	//If number is found, print "FOUND"
	if (bst::search(root, number)) 
		std::cout<<"Found\n";
	else 
		std::cout<<"Not Found\n";
}
