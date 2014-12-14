//===========
//Description
//===========
//This program illustrates the basics of a linear linked list(LLL) in C++
//using recursive algorithms
//This program is only intended for educational purposes/demonstrations

//======
//Author
//======
//William Harrington (http://github.com/wrh2)

//===========
//Explanation
//===========
//Linear linked lists (LLL) are an important data structure in computer science. They are used to
//implement many common abstract data types. Therefore, it is essential to understand how to work
//with them efficiently. Recursive solutions are normally the best way to work with a LLL.
//I made this program to demonstrate how one can work with a simple LLL in C++ recursively.
//If you looked at my demo on LLL in C, you will probably notice how much easier it is to do the
//exact same thing in C++.

//header files
#include <iostream>
using namespace std;

//struct for nodes of the LLL
struct node
{
  int val; //arbitrary integer value
  node * next; //next points to another node
};

//this function recursively adds to the end of a LLL
void create(node * & temp, int value)
{
  if(!temp) //temp is NULL we've reached the end of the LLL
    {
      temp = new node; //dynamically allocate memory for new node
      temp->val = value;
      temp->next = NULL;
    }
  else create(temp->next, value); //recursive function call, go to end of LLL
}

//this function recursively displays the nodes in a LLL from beginning to end
void display(node * temp)
{
  if(!temp) return; //temp is NULL we've reached the end of the LLL
  cout<<temp->val<<endl; //display value in node
  display(temp->next); //go to next node
}

//this function recursively displays the nodes in a LLL from end to beginning
void displayRev(node * temp)
{
  if(!temp) return; //temp is NULL we've reached the end of the LLL
  displayRev(temp->next); //go to the next node until we reach the end
  cout<<temp->val<<endl; //display value in node
}

//this function recursively adds the values in the nodes
int sum(node * temp)
{
  if(!temp) return 0; //temp is NULL we've reached the end of the LLL
  else return temp->val + sum(temp->next); //otherwise keep adding up nodes
}
//main function
int main()
{
  //Local variables
  node * head; //head is a pointer to a node
  
  cout<<"Creating LLL..."<<endl; //display msg
  head = NULL; //initialize the LLL
  for(int i=0; i<10; i++) create(head,i); //creates LLL where each node has the value of i for each iteration
  cout<<"LLL successfully created! Press enter to display the nodes"<<endl; //display msg
  cin.get(); //waits for key press
  cout<<"Displaying nodes from beginning to end"<<endl; //display msg
  display(head); //display nodes from beginning to end
  cout<<"Displaying nodes from end to beginning"<<endl; //display msg
  displayRev(head); //display nodes from end to beginning
  cout<<"The sum of the nodes is "<<sum(head)<<endl; //sum of the nodes
  return 0; //end of program
}
