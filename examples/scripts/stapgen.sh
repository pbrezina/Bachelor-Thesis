#!/bin/bash

FILE=$1
INPUT=`cat | tr " " "\n"`
FIRST=(`echo ${INPUT[0]} | tr "/" "\n"`)

for f in $INPUT; do
    LAST=(`echo $f | tr "/" "\n"`)
done

cat << EOF
#!/usr/bin/stap

global start_time;
global end_time;
global add_comma;

function print_delta(str, start, end) {
    if (@2 ==  "csv") {
        printf("%s%d", (add_comma ? "," : ""), end - start);
    } else {
        printf("%-45s: %10d us\n", str, end - start);
    }
}

probe begin {
    if (@3 != "auto") {
        printf("Ready... please execute \"%s\"\n\n", @1);
    }
}

probe process(@1"/${FIRST[0]}").function("main") {
    add_comma = 0;
}

probe process(@1"/${LAST[0]}").function("main").return {
    printf("\n");
}
EOF

i=0
for f in $INPUT; do
    function=(`echo $f | tr "/" "\n"`)
    cat << EOF

/* ---------------------------------------- $f */
probe process(@1"/${function[0]}").function("${function[1]}") {
    start_time[$i] = gettimeofday_us();
}

probe process(@1"/${function[0]}").function("${function[1]}").return {
    end_time[$i] = gettimeofday_us();
    print_delta("${function[1]}", start_time[$i], end_time[$i]);
    
    add_comma = 1;
}
EOF
    let i+=1
done
