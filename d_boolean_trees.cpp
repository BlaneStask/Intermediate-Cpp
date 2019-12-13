// Description: This program outputs true(t) or false(f) when evaluating the
// dynamic boolean expression tree given, after it has been modified

#include <iostream>
#include <string>
using namespace std;

class binary_tree_node{
public:
    typedef char value_type;

    binary_tree_node();
    
    int data(){return data_field;}
    binary_tree_node* left(){return left_field;}
    binary_tree_node* right(){return right_field;}
    bool evaluate();
    void modify(string path, char symbol);
   
private:
    value_type data_field;
    binary_tree_node* left_field;
    binary_tree_node* right_field;
};


binary_tree_node::binary_tree_node(){
    cin >> data_field;
    left_field = NULL;
    right_field = NULL;
    //creation of tree nodes
    if(data_field == '^' || data_field == '|' || data_field == '&'){
        left_field = new binary_tree_node();
        right_field = new binary_tree_node();
    }
    //if not, make a left node
    else if(data_field == '!'){
        left_field = new binary_tree_node();
    }
}


bool binary_tree_node::evaluate(){
    if(data_field == 't') return true;
    if(data_field == 'f') return false;
    //different operators
    if(data_field == '!')
        return !left_field->evaluate();
    if(data_field == '|')
        return left_field->evaluate() || right_field->evaluate();
    if(data_field == '&')
        return left_field->evaluate() && right_field->evaluate();
    if(data_field == '^')
        return left_field->evaluate() ^ right_field->evaluate();

    return 0;
}
    
void binary_tree_node::modify(string path, char symbol){
    //at target location for path
    if(path == ""){
        data_field = symbol;
        return;
    }
    //left side
    if(path[0] == 'l'){
        path = path.substr(1);
        return left_field->modify(path, symbol);
    }
    //right side
    if(path[0] == 'r'){
        path = path.substr(1);
        return right_field->modify(path, symbol);
    }
}

int main(){
    //take integers for number of nodes and queries/modify operations
    int n, m;
    cin >> n >> m;
    binary_tree_node* root = new binary_tree_node();
    //takes in the path and command to modify/evaluate the tree
    for(int i = 0; i < m; i++){
        string command, path;
        char symbol;
        cin >> command;
        if (command == "eval"){
            if(root->evaluate() == 0){
                cout << "f" << endl;
            }
            else{
                cout << "t" << endl;
            }
        }
        else if(command == "mod"){
            cin >> path >> symbol;
            root->modify(path, symbol);
        }
    }
}
