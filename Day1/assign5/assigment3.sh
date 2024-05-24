
function prime 
{
flag =1 

for((i=2; i<num/2 ;i++))
do

if [ $num % i==0 ]
then 
	flag =0;
	break
fi
done

if [ flag ]
then 
	echo -n "The number is a prime number "
else 
	echo -n "The number is not a prime number "
fi
}


echo -n "Enter the number :"
read num 
prime

