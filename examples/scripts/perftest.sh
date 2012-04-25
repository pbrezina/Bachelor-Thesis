#!/bin/bash

PROGRAMS=$1
PARAMS=$2
COUNT=$3
FUNCTIONS=$4

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

NAME=`basename $0`
TMPDIR=`mktemp -d -q /tmp/${NAME}.XXXXXX`
if [ $? -ne 0 ]; then
  echo "$0: Unable to create temp file, exiting..."
  exit 1
fi

for program in $PROGRAMS; do
    make BIN=$TMPDIR/bin -f $DIR/../Makefile -C $DIR/.. $program &> /dev/null
    if [ $? -ne 0 ]; then
      echo "$0: Unable to build program ${program}, exiting..."
      exit 1
    fi
done

. $DIR/stapgen.sh                \
    &> $TMPDIR/probes.stap  \
    < $FUNCTIONS

cat > $TMPDIR/test.sh << EOF
#!/bin/bash

for i in {1..$COUNT}; do
    for program in $PROGRAMS; do
      $TMPDIR/bin/\$program $PARAMS &> /dev/null
    done
done
EOF

ADDCOMMA=0
while read f; do
    if [ $ADDCOMMA -eq 1 ]; then
        echo -n ","
    fi
    
    ADDCOMMA=1
    function=(`echo $f | tr "/" "\n"`)
    echo -n ${function[1]}
done < $FUNCTIONS
echo

stap -c "bash $TMPDIR/test.sh" \
     $TMPDIR/probes.stap       \
     $TMPDIR/bin               \
     csv                       \
     auto
     
rm -fr $TMPDIR
