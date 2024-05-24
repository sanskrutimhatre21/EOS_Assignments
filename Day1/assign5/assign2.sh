
echo -e " 1.Date \n 2.Cal \n 3.ls \n 4.Pwd \n 5.Exit"
echo -n "Enter the choice :"
read choice 

case $choice in 

1)
	echo "Date :"
	date
	;;
2)
	echo"Calender :"
	cal
	;;
3)
	echo "ls :"
	ls 
	;;
4)
	echo -n "Current Directory :"
	pwd  
	;;
5)
	echo "Thank You !"
	;;
*)
	echo "Invalid choice !"
	;;

esac
