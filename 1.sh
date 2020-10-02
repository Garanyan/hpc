#!/bin/bash
for i in {100..1000}
do 
	r=$(( ${i} % 2 ))
	if [ ${r} -eq 0 ]
	then 
		echo ${i}
	fi
done

