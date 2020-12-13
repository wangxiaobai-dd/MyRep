#!/bin/bash

GCH_TIME=`stat temp.h | grep -i Modify | awk -F. '{print $1}' | awk '{print $2$3}'| awk -F- '{print $1$2$3}' | awk -F: '{print $1$2$3}'`
echo ${GCH_TIME}
for line in `cat temp.h`
do
    result=$(echo ${line} | grep \")
    if [[ ${result} != "" ]]
    then
	line=${line##\"}
	line=${line%%\"}
	echo ${line}
	if [ `find . -name ${line} | xargs stat $1 | grep -i Modify | awk -F. '{print $1}' | awk '{print $2$3}'| awk -F- '{print $1$2$3}' | awk -F: '{print $1$2$3}'` -gt ${GCH_TIME} ]
	then
	    echo "touch aaa"
	    touch temp.h
	    exit
	fi
    fi
done
