echo "enter a number:"
read n
remainder=0
new=0
while [ $n -gt 0 ] 
do
	remainder=$((  $n % 10 ))
	new=$(($new * 10 + $remainder))
	n=$(( $n / 10 ))
done

echo " the reversed number: $new"
 
