echo "Enter options ranging between 1 to 4:"
read option 
case $option in
"1") echo `cat /etc/passwd`;;
"2") echo `who -u`;;
"3") echo `pwd`;;
"4") echo "Not found";;
esac
