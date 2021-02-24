#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

struct Node
{
    int data;
    Node *link;
};
Node *head = NULL; // Head Node is globally defined.

void Print(Node *head) // For printing elements of the linked list
{
    Node *temp1; //pointer to node temp1 stores the adddress of the first node after the head node;
    temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->link;
    }
}

void Beginning_insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = head;
    head = temp;
}

void insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *temp1;
        temp1 = head; // temp1 = &node_A
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
}

void pos_insert(int x, int pos)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        cout << "EMPTY LIST, ELEMENT APPENDED AT THE END! " << endl;
    }
    else
    {
        int i = 1;
        Node *temp1;
        temp1 = head;
        while (i < pos)
        {
            temp1 = temp1->link;
            i++;
        }
        temp->link = temp1->link;
        temp1->link = temp;
    }
}
void pos_delete(int pos)
{
    int i = 1;
    Node *temp1;
    temp1 = head;
    while (i < pos)
    {
        temp1 = temp1->link;
        i++;
    }
    Node *temp;
    temp = temp1->link;
    temp1->link = temp->link;
}
int main()
{
    fast_cin();
    // //  <-------Creating A new node at the beginning------->

    // Node *temp = new Node(); //new operator returns a pointer to the operand
    //                          //temp is a pointer to Node.

    // // Adding data and link in the node
    // temp->data = 3; //"temp->data" is same as "(*temp).data"
    // temp->link = NULL;

    // // Connecting new node to the head node
    // A = temp;

    /* ALL THESE LINES OF CODES ARE REDUCED USING Beginning_insert & Print function
    
    
    // int x;
    // cin >> x;
    // Node *temp = new Node();
    // temp->data = x;
    // temp->link = NULL;
    // head = temp;

    // cin >> x;
    // Node *temp2 = new Node();
    // temp2->data = x;
    // temp2->link = NULL;
    // temp->link = temp2;

    // Node *temp1 = head;
    // while(temp1!= NULL)
    // {
    //     cout << temp1->data << " ";
    //     temp1 = temp1->link;
    // }

............................................... */

    /* IMPLEMENTING FUNCTIONS 

    int x,n;
    cout << "no. of new nodes: " ;
    cin >> n;
    while(n--)
    {
        cin >> x;
        Beginning_insert(x);
    }
    cout << "List: ";
    Print(head);

    //OUTPUT CONSOLE:
    no. of new nodes: 3
    1
    2
    3
    List: 3 2 1

............................................... */

    /* 

    <-------INSERT AT END(NORMAL INSERT)------->
        // int x, n;
        // cout << "no. of new nodes: ";
        // cin >> n;
        // while (n--)
        // {
        //     cin >> x;
        //     insert(x);
        // }
        // cout << "List: ";
        // Print(head);

    
    OUTPUT CONSOLE:
    no. of new nodes: 3
    1
    2
    3
    List: 1 2 3 
............................................... */
    /*


    //INSERTING IN THE MIDDLE

    int pos;
    int x, n;
    cout << "no. of new nodes: ";
    cin >> n;
    while (n--)
    {
        cin >> x;
        insert(x);
    }
    cout << "List: ";
    Print(head);
    cout << endl;
    cout << "New element: ";
    cin >> x;
    cout << "Enter position of new element : ";
    cin >> pos;
    pos_insert(x,pos);
    cout << "List: ";
    Print(head);

    //Console Output :

        no. of new nodes: 3
        1 2 4
        List: 1 2 4 
        New element: 3
        Enter position of new element : 2
        List: 1 2 3 4


............................................... */
    /* 

    // <--------- Deleting an element --------->
    int x, n;
    cout << "no. of new nodes: ";
    cin >> n;
    while (n--)
    {
        cin >> x;
        insert(x);
    }
    cout << "List: ";
    Print(head);
    cout << endl;
    pos_delete(4);      //delete position is 4;
    cout << "List: ";
    Print(head);

    //CONSOLE OUTPUT: 
        no. of new nodes: 10
        1 2 3 4 5 6 7 8 9 10
        List: 1 2 3 4 5 6 7 8 9 10    //delete position is already mentioned in code
        List: 1 2 3 4 6 7 8 9 10 

        
............................................... */
}
