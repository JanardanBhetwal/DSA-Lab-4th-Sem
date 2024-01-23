// Represent polynomial equation using Linked list to perform addition of two polynomials.

#include <iostream>
using namespace std;

struct Node
{
    float coeff;
    int index;
    Node *next;
    Node(int ind, float cof)
    {
        next = NULL;
        index = ind;
        coeff = cof;
    }
};

Node *insertAndSort(Node *head, int ind, float cof)
{
    Node *temp = new Node(ind, cof);
    if (head == NULL)
    {
        return temp;
    }
    if (head->index < temp->index)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->index > temp->index)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *add(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *head3 = NULL;
    while (curr1 != NULL || curr2 != NULL)
    {
        if (curr1 == NULL || curr1->index < curr2->index)
        {

            head3 = insertAndSort(head3, curr2->index, curr2->coeff);
            curr2 = curr2->next;
        }
        else if (curr2 == NULL || curr1->index > curr2->index)
        {

            head3 = insertAndSort(head3, curr1->index, curr1->coeff);
            curr1 = curr1->next;
        }
        else
        {
            head3 = insertAndSort(head3, curr1->index, curr1->coeff + curr2->coeff);
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
    }
    return head3;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->coeff << "x^" << curr->index << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int index;
    float coeff;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    int n1, n2;
    cout << "Enter the number of terms of first and second equation:";
    cin >> n1 >> n2;
    cout << "Enter the values for first equation:";
    do
    {
        cout << "Index:";
        cin >> index;
        cout << "Coeff:";
        cin >> coeff;
        head1 = insertAndSort(head1, index, coeff);
        n1--;
    } while (n1 > 0);
    cout << "Enter the values for second equation:";
    do
    {
        cout << "Index:";
        cin >> index;
        cout << "Coeff:";
        cin >> coeff;
        head2 = insertAndSort(head2, index, coeff);
        n2--;
    } while (n2 > 0);
    printList(head1);
    printList(head2);
    head3 = add(head1, head2);
    printList(head3);
    return 0;
}