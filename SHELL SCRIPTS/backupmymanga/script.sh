for i in `ls $1`
do
	if [ -d $i ]
	then
		echo $i
	fi	
done 
