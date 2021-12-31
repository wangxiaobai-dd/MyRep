#!/usr/bin/python

import re

resultFile = open("result.txt", "w")
errorFile = open("error.txt", "w")

#\s+ 表示匹配多个空格
#PATTERN = re.compile(r'(^[0-9]*)(.*)(\[.*\])\s+\/(.*)\s+"(.*)\s+(.*):') #没去空格测试
#PATTERN = re.compile(r'(^[0-9]*)(.*)(\[.*\])[\/:="\.,](.*)"(.*):.*$')

#正则表达式 (记录号) (题名) (类型) 类型后面/:=., (责任者) 责任者后面"( (地点) : (出版社) , (时间)
PATTERN = re.compile(r'(^[0-9]*)(.*)(\[.*\])[\/:="\.,](.*)["\(](.*):([^,]*),(\d+,*\d*[^\)"]*)') 

with open('武术图书.txt', encoding="gbk") as f:
    for line in f:
        newline = re.sub('\s|\t|\n','', line) #去掉所有空格
        result = PATTERN.search(newline)
        if not result:
            pass
            print(line.strip(), file=errorFile) #处理失败项目
        else:
            for info in result.groups():
                pass
                info=info.replace("\"","")
                print(info, end='\t', file=resultFile) #结果文件
            print(file=resultFile) #换行
            
        
        
        
