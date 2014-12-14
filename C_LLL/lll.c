//===========
//Description
//===========
//This program illustrates the basics of a linear linked list(LLL) in C
//using recursive algorithms
//This program is only intended for educational purposes/demonstrations

//======
//Author
//======
//William Harrington (http://www.github.com/wrh2)

//===========
//Explanation
//===========
//Linear linked lists (LLL) are an important data structure in 
//computer science. They are used to implement many common abstract 
//data types and so it is essential to understand how to work with them
//efficiently. Recursive solutions are normally the best way to work with 
//a linear linked list. Therefore, I made this program to demonstrate how
//one can work with a simple linear linked list in C recursively.

//header files
#include <stdlib.h> //standard library
#include <stdio.h> //standard input/output

//struct for nodes
struct node{
  int val; //for holding some integer value
  struct node * next; //points to the next node in the list
};

//recursive function for adding up the values in the nodes of the LLL
int sum(struct node * temp)
{
  if(!temp) return 0; //temp is null we are at the end of the list
  else return temp->val + sum(temp->next); //otherwise keep adding them up!
}

//recursive function for displaying nodes in LLL
//from beginning to end
void display(struct node * temp)
{
  if(!temp) return; //when temp is NULL we've reached the end so return
  printf("%d\n",temp->val); //display the value held in the node
  display(temp->next); //recursive function call, goes to next node
}

//recursive function for displaying node in LLL
//from end to beginning
void displayReverse(struct node * temp)
{
  if(!temp) return; //when temp is NULL we've reached the end so return
  displayReverse(temp->next); //recursive function call
  //goes to the end of the LLL
  printf("%d\n", temp->val); //display the value held in the node
}

//recursive function for creating linear linked list
//note this function adds to the end of the list
//**a good exercise would be to ask yourself how to do this but at the start
//of the list**
void create(struct node ** temp, int value)
{
  //temp is NULL so we've reached the end of the list
  //now let's add a node
  if(!(*temp))
    {
      (*temp)=(struct node *)malloc(sizeof(struct node)); //dynamically allocate memory
      (*temp)->val = value; //store value
      (*temp)->next = NULL; //set next pointer to NULL
    }
  else create(&(*temp)->next, value); //go to next node
}

//main function
int main()
{
  //Local variables
  struct node * head; //head is a pointer to a node
  int i; //this is just some arbitrary integer we are going to store in the LLL

  head = NULL; //initialize LLL

  //create the LLL
  printf("Creating linear linked list..\n"); //display msg
  for(i=0;i<10;i++){
    create(&head,i); //call recursive function for creating the LLL 
  }
  printf("Linear linked list created successfully!\n"); //display success msg

  printf("Press enter to display nodes from beginning to end"); //display msg
  getchar(); //waits for key press
  //display values in LLL from beginning to end
  display(head);

  printf("Press enter to display nodes from end to beginnging"); //display msg
  getchar(); //waits for key press
  //display values in LLL from end to beginning
  displayReverse(head);

  printf("Press enter to add up the values in the nodes"); //display msg
  getchar(); //waits for key press
  //add up values in LLL
  int result = sum(head);
  printf("Sum of the nodes is %d\n",result); //display result

  return 0; //end of program
}

