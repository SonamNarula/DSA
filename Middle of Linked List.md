## 01. Middle of Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1)

### Problem Description

**Task:** Given a linked list, You have to return the value of the middle node of the linked list. If the number of nodes is odd, return the middle node value.If the number of nodes is even, there are two middle nodes, so return the second middle node value.Examples:Input:

#### Examples

##### Example 1

- **Output:**
```text
3Explanation: The given linked list is 1- > 2- > 3- > 4- > 5 and its middle is 3. Input: Output: 7 Explanation: The given linked list is 2- > 4- > 6- > 7- > 5- > 1 so, there are two middle node 6 and 7, return the second middle node as 7.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-11-09 20:10:40
- **Status:** Correct
- **Marks:** 0

```cpp
/* Linked List Node Structure
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast!= NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-09-10 11:28:47
- **Status:** Correct
- **Marks:** 2

```cpp
/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */
class Solution {
  public:
    int getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};
```

*Generated on: 11/9/2026, 8:10:58 PM*