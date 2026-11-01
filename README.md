# MP3 Tag Reader and Editor in C

A command-line application developed in **C** to read, display, and edit metadata stored in MP3 audio files using ID3v2 tag processing and binary file handling.

---

## Project Overview

The **MP3 Tag Reader and Editor** is a file-handling application that allows users to access and modify metadata information embedded in MP3 audio files without changing the actual audio content.

MP3 files contain metadata known as ID3 tags, which store information about a song, such as its title, artist, album, release year, genre, and comments.

This application provides two major functionalities:

- **View Mode:** Extracts and displays the existing metadata of an MP3 file.
- **Edit Mode:** Allows users to modify selected metadata fields and save the updated information back into the MP3 file.

The project is developed using modular programming principles and demonstrates practical implementation of C programming concepts, particularly binary file operations, pointers, structures, dynamic memory allocation, and command-line argument handling.

##  Features

### 1. View MP3 Metadata
- Reads metadata from an MP3 file.
- Displays song information in a structured format.
- Supports viewing:
  - Song Title
  - Artist Name
  - Album Name
  - Release Year
  - Genre
  - Comments

### 2. Edit MP3 Metadata
- Modify individual metadata fields.
- Update song information through command-line arguments.
- Save the modified tags into the MP3 file.
- Preserve the original audio data.

### 3. Command-Line Interface
- Supports command-line arguments for different operations.
- Provides separate options for viewing and editing metadata.
- Makes the application simple and efficient to use.

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Core application development |
| ID3v2 | MP3 metadata processing |
| File Handling | Reading and writing MP3 files |
| Pointers | Memory and data manipulation |
| Structures | Organizing metadata |
| Dynamic Memory Allocation | Managing data at runtime |
| Command-Line Arguments | Handling user operations |

##  Project Structure

```text
MP3-Tag-Reader-and-Editor/
│
├── main.c          # Main function and program execution
├── mp3.h           # Structure definitions and function declarations
├── view.c          # Functions for reading and displaying MP3 tags
├── edit.c          # Functions for modifying MP3 metadata
│
├── sample.mp3      # Sample MP3 file for testing
│
└── README.md       # Project documentation
```

*Note: Update the file structure if your actual project contains additional source or header files.*

##  Installation and Execution

### Prerequisites

- GCC Compiler
- Linux / Ubuntu / WSL environment
- Basic knowledge of command-line operations

### Step 1: Clone the Repository

```bash
git clone https://github.com/divya-0615/MP3-Tag-Reader-and-Editor.git
```

### Step 2: Navigate to the Project Directory

```bash
cd MP3-Tag-Reader-and-Editor
```

### Step 3: Compile the Program

```bash
gcc main.c view.c edit.c -o mp3tag
```

### Step 4: Run the Application

**View Mode**

```bash
./mp3tag -v sample.mp3
```

**Edit Mode**

```bash
./mp3tag -e sample.mp3 -t "New Song Title"
```

Replace the sample filename and metadata values with your desired inputs.

## Supported Editing Options

| Option | Description |
|---|---|
| `-t` | Edit Song Title |
| `-A` | Edit Artist Name |
| `-a` | Edit Album Name |
| `-y` | Edit Release Year |
| `-C` | Edit Content/Comment |
| `-c` | Edit Genre |

## 🧠 Key Concepts Implemented

This project helped strengthen my understanding of:

1. **File Handling:** Reading and writing MP3 files in binary mode.
2. **Structures:** Organizing and managing MP3 metadata.
3. **Pointers:** Accessing and manipulating data efficiently.
4. **Dynamic Memory Allocation:** Managing memory for variable-length metadata.
5. **String Manipulation:** Processing metadata strings and frame information.
6. **Command-Line Arguments:** Implementing user operations through `argc` and `argv`.
7. **ID3v2 Structure:** Understanding metadata frames and their representation in MP3 files.
8. **Modular Programming:** Dividing the application into separate functional modules.

##  Learning Outcomes

- Developed practical experience in C programming and systems-level file operations.
- Understood the internal organization of ID3v2 metadata.
- Learned how to extract and modify binary file information.
- Improved problem-solving and debugging skills.
- Gained experience in designing modular, command-line-based applications.

## Future Enhancements

- Support for additional ID3 versions.
- Improved metadata validation and error handling.
- Support for more metadata frames.
- Enhanced user interaction and help documentation.

## 👩‍💻 Author

**Divya Ambadas Adam**

Electronics and Telecommunication Engineering

GitHub: [@divya-0615](https://github.com/divya-0615)

---

*Developed as a C programming project to explore binary file handling, metadata processing, and modular software development.*
