## 01. Delete Alternate Nodes

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1)

### Problem Description

**Task:** Given a singly linked list, delete all the nodes present at even positions. The first node is considered to be at position 1. After deleting the alternate nodes, return the modified linked list.

#### Examples

##### Example 1

- **Input:**
```text
list[] = [1, 2, 3, 4, 5, 6]Output: [1, 3, 5]
```
- **Explanation:** The nodes at even positions, 2, 4, and 6, are deleted. The remaining linked list is 1 → 3 → 5.

##### Example 2

- **Input:**
```text
list[] = [99, 59, 42, 20] Output: [99, 42] Explanation: The nodes at positions 2 and 4, 59 and 20, are deleted. The remaining linked list is 99 → 42.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-09 20:07:11
- **Status:** Correct
- **Marks:** 2

```cpp
/* Structure of Linked List Node
class Node
{
    int data;
    Node *next;

    Node(int x){
        int data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    void deleteAlt(Node *head) {
        // code here
        if(head == NULL || head->next == NULL){
            return;
        }
        
        Node* temp = head;
        
        
        while(temp != NULL && temp->next != NULL){
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            temp = temp->next;
            
        }
    }
};
```

*Generated on: 11/9/2026, 8:07:31 PM*