echo "Enter first filename: "
read file1
echo "Enter second filename: "
read file2




cmp --silent $file1 $file2 && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###'



