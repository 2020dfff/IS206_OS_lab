#!/bin/bash
function read_dir(){
    for file in `ls $1`       # 注意此处两个反引号，表示运行系统命令
    do
        if [ -d $1"/"$file ];  # 注意此处[]一定要加上空格，否则会报错
        then
        read_dir $1"/"$file $2
        elif [ "${file##*.}" = "c" ]||[ "${file##*.}" = "h" ];then # 判断后缀  
            grep -q -e "$2" "$1""/""$file";
            stategrep=$?;
            if [ $stategrep = 0 ];then
                grep -n -e $2 $1"/"$file | while read -r line;
                do       
                    echo $1"/"$file":""$line"  # 注意此处的$line一定要加上双引号
                done

            fi
        fi
    done
}   
# 进行简单的参数数量判断
if [ $# -eq 2 ];
then
read_dir $1 $2
elif [ $# -eq 1 ];
then
read_dir . $1
else
echo 'error';
exit;
fi