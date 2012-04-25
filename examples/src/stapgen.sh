#! /bin/bash

FILE=$1
HEADER="#!/usr/bin/stap

global start_time;
global end_time;

function print_delta(str, start, end) {
    printf(\"%-45s: %10d us\n\", str, end - start);
}

probe begin {
    printf(\"Ready... please execute \\\"%s\\\"\n\n\", @1);
}"

truncate -s 0 $FILE

IFS_OLD=$IFS
IFS=`echo -en "\n\b"`

for line in $HEADER; do
    echo $line >> $FILE
done

i=0
while read f
do
    echo "probe process(@1).function(\"$f\") {" >> $FILE
    echo "    start_time[$i] = gettimeofday_us();" >> $FILE
    echo "}" >> $FILE
    echo >> $FILE
    echo "probe process(@1).function(\"$f\").return {" >> $FILE
    echo "    end_time[$i] = gettimeofday_us();" >> $FILE
    echo "    print_delta(\"$f\", start_time[$i], end_time[$i]);" >> $FILE
    echo "}" >> $FILE
    echo >> $FILE
    let i+=1
done

IFS=$IFS_OLD
