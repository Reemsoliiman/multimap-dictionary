#  Multimap Dictionary in C

## 📌 Overview

This project implements a **Multimap Dictionary** — an abstract data type that maps each unique key to **multiple values**. Keys are kept in **sorted order**, and values associated with a key are also stored in sorted fashion. The data structure is built using a **sorted linked list** in C.

Each key appears only once, but can be associated with **multiple values**, and all operations maintain sort order.

---

## 🧱 Data Structure Design

### 🔹 `ListNode` (Key-Value Node)

* `key`: An integer key.
* `value`: Pointer to a `ListValue` (linked list of values).
* `next`: Pointer to the next `ListNode`.

### 🔸 `ListValue` (Value Node)

* `entry`: An integer value.
* `next`: Pointer to the next value in the list.

### 🧩 `List` (Multimap)

* `head`: Points to the first `ListNode`.
* `size`: Total number of unique keys in the dictionary.

---

## ⚙️ Supported Operations

* **Add Pair**: Add a `(key, value)` pair. Creates a new key if not found.
* **Remove Key**: Delete a key and all its associated values.
* **Remove Value**: Remove a specific `(key, value)` pair.
* **Modify Value**: Replace a specific value under a key.
* **Print Values**: Print all values associated with a key.

---

## 🧪 How to Run

### ✅ Prerequisites:

* C compiler
* Terminal / Command Line

### 📥 Clone the Repository

```bash
git clone https://github.com/Reemsoliiman/multimap-dictionary.git
cd multimap-dictionary
```

### 🛠️ Compile the Program

```bash
gcc -o multimap main.c List.c Operation.c Menu.c
```

### ▶️ Run the Program

```bash
./multimap       # On Unix/macOS
multimap.exe     # On Windows
```

---

## 🖱️ Interactive Menu

Use the terminal menu to:

* Add new key-value pairs
* Remove keys or individual values
* Modify specific values
* Print values by key
* Exit program

📌 Input should be **positive integers only**.

---

## 💡 Example Use Cases

| Use Case             | Description                                                                                            |
| -------------------- | ------------------------------------------------------------------------------------------------------ |
| **Contact Manager**  | Store multiple phone extensions for an employee ID. <br> e.g., `Key = 101 → [1001, 1002, 1003]`        |
| **Tag-Based Search** | Associate multiple item IDs with a category. <br> e.g., `Key = 1 (Fruits) → [10 (Apple), 20 (Banana)]` |
| **User Event Logs**  | Track multiple events for a user ID. <br> e.g., `Key = 5 (User) → [1, 2, 3]`                           |

---

## ⏱️ Performance

| Operation    | Time Complexity |
| ------------ | --------------- |
| Add Pair     | O(n + m)        |
| Remove Key   | O(n)            |
| Remove Value | O(n + m)        |
| Modify Value | O(n + m)        |
| Print Values | O(n + m)        |

> Where `n` = number of keys, `m` = number of values under a key

---

## ✅ Pros

* Low memory overhead
* Dynamic sizing
* Keeps keys/values sorted (no extra sorting needed)

## ⚠️ Cons

* Slower than hash maps for large datasets
* No random access (must traverse)
* Complex nested list management

---

## 🧠 When to Use

* ✅ For **small to medium datasets**
* ✅ When **sorted output** is important
* ❌ Not ideal for high-performance use — consider using a **hash table** or **balanced tree** for large-scale apps

---

## 🚀 Potential Improvements

* Improve input validation (handle non-integer/invalid inputs)
* Add checks for memory allocation failures
* Allow duplicate values for more flexible use cases
* Extend support to string keys/values for broader applicability
* Implement file I/O to save/load multimap data
* Add unit tests for better reliability
