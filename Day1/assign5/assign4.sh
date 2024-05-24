


echo -n "Enter the path :"
read path 


if [ -e $path ]
then 

	if [ -f $path ]
	then 	
			echo "path is of regular file "

	elif [ -d $path ]
	then 
			echo "path is of directory "

	else 
			echo "path is of something else "
	fi

else 
	echo "path doesnot exists "
fi

