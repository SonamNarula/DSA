## 01. Identical Linked Lists

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/identical-linked-lists/1)

### Problem Description

**Task:** Given two singly linked lists, head1 and head2, the task is to determine whether the two linked lists are identical. Two linked lists are considered identical if they have the same number of nodes and each corresponding node contains the same data in the same order. Examples:Input: head1: 1- > 2- > 3- > 4- > 5- > 6, head2: 99- > 59- > 42- > 20

#### Examples

##### Example 1

- **Output:**
```text
trueExplanation: As shown in the below figure, the two lists are identical.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-09 20:29:40
- **Status:** Correct
- **Marks:** 1

```cpp
/* Strucutre of a Node in linked list
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    bool areIdentical(Node *head1, Node *head2) {
        // code here
        

            Node* temp1 = head1;
            Node* temp2 = head2;

            while (temp1 != NULL && temp2 != NULL) {

                // Compare both node values
                if (temp1->data != temp2->data) {
                    return false;
                }

                // Move both pointers
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            // Both lists must end together
            return temp1==NULL && temp2==NULL;


        }
    
};
```

*Generated on: 11/9/2026, 8:29:54 PM*