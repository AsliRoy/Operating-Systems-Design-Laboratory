echo  "Enter filename : "
read filename
 
[ -w $filename ] && W="Write permission = yes" || W="Write permission = No"
 
[ -x $filename ] && X="Execute permission = yes" || X="Execute permission= No"
 
[ -r $filename ] && R="Read permission= yes" || R="Read permission = No"
 
echo "$W"
echo "$R"
echo "$X"
