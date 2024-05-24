

echo -n"Enter two number :"
read num1 num2 num3 

max=0 

if [ $num1 -gt $num2 && $num1 -gt $num3 ]
then 
	echo "num1 is greater "
	max=$num1

elif [ $num2 -gt $num1 && $num2 -gt $num3]
then 
	echo "num2 is greater "
	max=$num2
else 
	echo "num3 is greater "
	max=$num3
fi 

echo "maximium  value = $max"

