while true
do
    echo "-----------------------------"
    echo " DIRECTORY MANAGEMENT MENU "
    echo "-----------------------------"
    echo "1. Navigate to a directory"
    echo "2. List directories"
    echo "3. Create a directory"
    echo "4. Rename a directory"
    echo "5. Delete a directory"
    echo "6. Show current directory"
    echo "7. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in

        1)  cur=$(pwd)
            echo "Current: $cur"
            echo "Enter absolute or relative path:"
            read path
            cd "$path" 2>/dev/null
            if [ $? -eq 0 ]; then
                echo "Successfully moved to $(pwd)"
            else
                echo "Directory not found!"
            fi
            ;;

        2)
            echo "Listing directories:"
            ls
            ;;

        3)
            echo "Enter directory name to create:"
            read dirname
            mkdir "$dirname"
            echo "Directory created successfully."
            ;;

        4)
            echo "Enter current directory name:"
            read oldname
            echo "Enter new directory name:"
            read newname
            mv "$oldname" "$newname"
            echo "Directory renamed successfully."
            ;;

        5)
            echo "Enter directory name to delete:"
            read delname
            rm -r "$delname"
            echo "Directory deleted successfully."
            ;;

        6)
            echo "Current directory:"
            pwd
            ;;

        7)
            echo "Exiting..."
            break
            ;;

        *)
            echo "Invalid choice! Try again."
            ;;

    esac
done

