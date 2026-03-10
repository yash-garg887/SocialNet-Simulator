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


##Supported Commands

ADD_USER <username> Adds a new user to the network, initially with no friends and no posts.
ADD_FRIEND <username1> <username2> Establishes a bidirectional friendship between two existing usernames.
LIST_FRIENDS <username> Prints an alphabetically sorted list of the specified username’s friends.
SUGGEST_FRIENDS <username> <N> Recommends up to N new friends who are ”friends of a friend” but not already friends.
• Ranking: Recommendations are ranked by the number of mutual friends (descending). Ties are broken by alphabetical order of usernames.
• Edge Cases: If N is 0, output nothing. If fewer than N candidates exist, lists all available.
DEGREES_OF_SEPARATION <username1> <username2> Calculates the length of the shortest path of friendships between two usernames. If no path exists, reports-1

ADD POST <username> "<post content>" Adds a post whose content is the post_content string to the posts created by the specified user.
OUTPUT POSTS <username> <N> Outputs the most recent N posts of the user, in reverse chronological order. If N is -1, it outputs all the posts by the user. If there are fewer than N posts by the user,
then list all available posts.

Note: Usernames and postcontents are NOT case-sensitive. Forexample, the usernames Lakshay_coL106 and lakshay_COL106 are identical.


## How to Use different Commands:

- Output behaviour of  `DEGREES OF SEPARATION <username1> <username2>`
    it gives 1 output if `username1` and `username2` are friends
    and 2 if they are not friends but seperated by a friend and so on.

- Input Specification for `ADD POST <username> <post content>`
    I have assumed that post content is not in quotes so , while giving this
    command as input don't give another command in same line.
    else it will store whole thing in `post content` so no command would be performed.

- For terminating give a string "!stop" as input (without quotes)