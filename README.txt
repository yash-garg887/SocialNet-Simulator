# Project Compilation and Execution Instructions

## Requirements
- A Linux or macOS terminal, or Git Bash on Windows.
- g++ compiler installed and available in PATH. (c++17 or higher)

## Compilation Instructions
1. Open a terminal (or Git Bash on Windows).
2. Navigate to project directory(wherever you save it)
3. Run the shell script to compile the project:
    chmod +x build.sh
    ./build.sh

## How to Use different Commands:
- Output behaviour of  `DEGREES OF SEPARATION <username1> <username2>`
    it gives 1 output if `username1` and `username2` are friends
    and 2 if they are not friends but seperated by a friend and so on.

- Input Specification for `ADD POST <username> <post content>`
    I have assumed that post content is not in quotes so , while giving this
    command as input don't give another command in same line.
    else it will store whole thing in `post content` so no command would be performed.

- All other commands are in the expected format as in the assignment statement pdf
    so one can use them as per the expected i/o behaviour!
    
- For terminating give a string "!stop" as input (without quotes)