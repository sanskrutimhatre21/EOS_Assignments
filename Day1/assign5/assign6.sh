



echo -n "Enter the year :"
read year 

if [  $year % 4==0 && $year % 100 !=0 ]
then
	echo -n "The year is leap year !"
else 
	echo -n "The year is not leap year !"
fi







