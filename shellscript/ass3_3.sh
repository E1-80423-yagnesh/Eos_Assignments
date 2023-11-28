#Write a shell script to accept the name from the user and check whether user entered
#name is file or directory. If name is file display its size and if it is directory display its
#contents.

#!/bin/bash

echo "enter name : "
read name
#to check if path exists: test -e path
# to check if path is of directory: test -d path
# to check if path is of file: test -f path
if [ -e "$name" ]
then
    if [ -f "$name" ] 
	then
        res=`stat -c %s $name`
			echo "file: $name (length: $res bytes)"
    
	elif [ -d "$name" ] 
	then
        res=`stat -c %U $name`
			echo "dir : $name (user: $res)"
        ls "$name"
    
	else
        echo "$name exists but is neither a file nor a directory."
    fi
else
    echo "$name does not exist."
fi

