#!/usr/bin/python

with open('a.txt') as f:
    tempList = []
    newList = []
    flag = True
    for line in f:
        line = line.strip()
        if line=='---':
            if len(tempList) > 0:
                newList.append(tempList)
            tempList = []
        else:
            tempList.append(line)
    newList.append(tempList)
    print newList
        
