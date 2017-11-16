i=1
k=1
echo "Enter the numbers of elements in the array:"
read n
echo "enter the value of each array element:"
while [ $i -le $n ]
do
read num
arr[$k]=`expr $num`
i=$(( $i + 1 ))
k=$(( $k + 1 ))
done
i=1
while [ $i -le $n ]
do
j=1
while [ $j -le $n ]
do
m=$(( $j + 1 ))
if [ ${arr[$j]} -gt ${arr[$m]} ]
then
temp=${arr[$j]}
arr[$j]=${arr[$m]}
arr[$m]=$temp
fi
j=$(( $j + 1 ))
done
i=$(( $i + 1 ))
done
i=1
echo "The sorted array is as follows:"
while [ $i -le $n ]
do  
echo "${arr[$i]}" 
i=$(( $i + 1 ))
done


