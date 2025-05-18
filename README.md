# 🔍 Inverted Search Project

### 📌 Overview
The **Inverted Search** project is a command-line tool written in **C** that builds an **inverted index** from multiple text files. It allows efficient word-based searching by mapping each word to the files and line numbers where it occurs. This mimics the core functionality of a basic search engine.

---

### 💡 What is Inverted Search?
An **inverted index** is a data structure that maps content (like words) to their locations in a collection of files.

**Example:**
```
Word: apple
Found in:
- file1.txt (line 3)
- file2.txt (line 7)
```
This approach significantly improves the speed and efficiency of search operations across large sets of text data.

---

### ⚙️ Features
- ✅ Create inverted index from multiple files  
- ✅ Search for a word and list all its occurrences  
- ✅ Display complete database  
- ✅ Add new files and update the index  
- ✅ Save and load database from backup file  
- ✅ File validation (ignores duplicates/empty files)

---

### 🧠 Learning Outcomes
- Understanding and implementation of **Hash Tables**  
- Usage of **Linked Lists** for dynamic data handling  
- Efficient **File I/O** in C  
- Handling large datasets with optimized data structures  
- CLI design and menu-driven interaction

---

### 🛠️ Technologies Used
- **Language:** C  
- **Concepts:** File Handling, Hashing, Linked Lists, Dynamic Memory Allocation  

---

### 📁 File Structure
```
inverted_search/
│
├── main.c               → Program entry point & menu
├── create_database.c    → Builds the inverted index
├── display_database.c   → Displays the index data
├── search.c             → Searches for a word
├── update_database.c    → Adds new files
├── save_database.c      → Saves the index to file
├── load_database.c      → Loads the index from file
├── hash_function.c      → Hash function logic
├── file_validation.c    → Validates input files
├── macros.h             → Macro definitions and headers
└── README.md            → Project documentation
```

---

### 📥 How to Compile
Use any C compiler (GCC recommended):

```bash
gcc *.c -o inverted_search
```

---

### ▶️ How to Run
```bash
./inverted_search
```

---

### 🧪 Sample Menu Output
```
Welcome to Inverted Search Engine

1. Create Database
2. Display Database
3. Search Word
4. Update Database
5. Save Database
6. Load Database
7. Exit
Enter your choice:
```

---

### 🧪 Sample Search Output
```
Enter the word to search: network

Word found in:
- file1.txt (line 2)
- file3.txt (line 6)
```

---

### 🔧 Prerequisites
- C Compiler (GCC or Clang)
- Terminal or command prompt
- One or more text files with readable content

---










