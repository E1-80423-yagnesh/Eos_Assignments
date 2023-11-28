#Write a shell script to display menu like “1. Date, 2. Cal, 3. Ls, 4. Pwd, 5. Exit” and
#execute the commands depending on user choice.

#!/bin/bash

while true;
do
 
    echo "Menu:"
    echo "1. Date"
    echo "2. Calendar"
    echo "3. List files"
    echo "4. Print working directory"
    echo "5. Exit"

    echo "enter choice from (1-5)"
    read choice

    case $choice in
        1)
            date
            ;;
        2)
            cal
            ;;
        3)
            ls
            ;;
        4)
            pwd
            ;;
        5)
            echo "Exit"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 5."
            ;;
    esac
done

