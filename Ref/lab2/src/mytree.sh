#!/bin/bash
function read_dir(){
    for file in `ls $1`       #注意此处这是两个反引号，表示运行系统命令
    do
        if [ -d $1"/"$file ];  #注意此处之间一定要加上空格，否则会报错
        then
        echo "$2"$file        #注意此处的$2一定要加上双引号，否则空格会被忽略掉
        read_dir $1"/"$file "$2""    "
        elif [ -f $1"/"$file ];
        then
        echo "$2"$file  
        fi
    done
}   
read_dir . ""