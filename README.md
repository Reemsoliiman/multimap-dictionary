Multimap Dictionary in C
Overview
A Multimap Dictionary is an abstract data type that stores a collection of key-value pairs, where each key can be associated with multiple values, and keys are maintained in sorted order. This implementation uses a sorted linked list in C, where each ListNode contains a key (an integer) and a ListValue (a sorted linked list of integer values). The list of keys is sorted in ascending order, and multiple values can be associated with each key.
Data Structure

ListNode: Represents a key-value pair, with fields:
key: An integer key.
value: A ListValue structure (a linked list of values).
next: Pointer to the next ListNode.


ListValue: A linked list of values for a key, with each Node containing:
entry: An integer value.
next: Pointer to the next Node.


List: The main multimap structure, with a pointer to the head ListNode and a size field.

Supported Operations

Add Pairs: Insert a (key, value) pair, creating a new key if it doesn't exist or adding a value to an existing key.
Remove Pairs: Delete all values associated with a key.
Remove Value: Delete a specific (key, value) pair.
Modify Values: Replace a specific value for a key with a new value.
Print Values: Display all values associated with a given key.

How to Run

Prerequisites:
A C compiler (e.g., GCC).
A Unix-like environment (Linux, macOS) or Windows with a compatible compiler (e.g., MinGW).


Clone the Repository:git clone https://github.com/your-username/multimap-dictionary-c.git
cd multimap-dictionary-c


Compile the Program:gcc -o multimap main.c List.c Operation.c Menu.c


Run the Program:./multimap


On Windows, use multimap.exe instead.


Interact with the Menu:
The program provides an interactive menu to:
Add pairs (new key or values to an existing key).
Remove all values for a key.
Modify a specific value for a key.
Print all values for a key.
Remove a specific value for a key.
Exit the program.


Follow the prompts to input keys and values (positive integers only).



Example Use Cases

Contact Management:
Store multiple phone extensions (values) for an employee ID (key).
Example: Key = 101, Values = [1001, 1002, 1003].


Tag-Based Search:
Associate multiple items (values) with a category ID (key).
Example: Key = 1 (Fruit), Values = [10 (Apple), 20 (Banana), 30 (Cherry)].


Event Logging:
Record multiple event IDs (values) for a user ID (key).
Example: Key = 5 (User), Values = [1, 2, 3] (Login events).



Performance Discussion
Time Complexity

Add Pairs: O(n + m), where n is the number of keys (to find/insert the key in the sorted list) and m is the number of values for that key (to insert the value in sorted order).
Remove Pairs: O(n), where n is the number of keys (to find the key and free its value list).
Remove Value: O(n + m), where n is the number of keys (to find the key) and m is the number of values (to find and remove the specific value).
Modify Values: O(n + m), where n is the number of keys (to find the key) and m is the number of values (to find and modify the value).
Print Values: O(n + m), where n is the number of keys (to find the key) and m is the number of values (to traverse and print).

Pros of Using a Sorted Linked List

Memory Efficiency: Only allocates memory for existing nodes, with no overhead for empty slots.
Dynamic Size: Easily grows or shrinks as keys/values are added or removed.
Sorted Order: Maintains keys and values in sorted order, useful for ordered traversal or display.

Cons of Using a Sorted Linked List

Slow Operations: All operations are O(n + m) due to linear traversal, inefficient for large datasets compared to hash tables (O(1) average case) or balanced trees (O(log n)).
No Random Access: Must traverse from the head to find a key or value.
Complexity for Multiple Values: Managing a linked list of values per key adds overhead to operations.

When to Use

Suitable for small datasets or applications prioritizing sorted order and memory efficiency.
For large datasets, consider a hash table for O(1) average-case operations or a balanced tree (e.g., AVL or Red-Black) for O(log n) operations.

Potential Improvements

Input Validation: Enhance validation to handle non-integer inputs more robustly (e.g., clear input buffer properly).
Memory Management: Add checks for memory allocation failures in malloc.
Duplicate Values: The current AddPairs checks for duplicate values, which may not always be desired; consider allowing duplicates if appropriate.
Data Types: Extend to support non-integer keys/values (e.g., strings) for broader use cases.

License
This project is licensed under the MIT License (adjust as needed).
