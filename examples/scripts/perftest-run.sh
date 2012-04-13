#!/bin/bash

PREFIX=$1
COUNT=100
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# loops size pool-guess test-count
echo "Testing malloc: 1000"
bash $DIR/perftest-malloc.sh 1000   100 50000   $COUNT > ${PREFIX}test_malloc_1000
echo "Testing malloc: 10000"
bash $DIR/perftest-malloc.sh 10000  100 500000  $COUNT > ${PREFIX}test_malloc_10000
echo "Testing malloc: 50000"
bash $DIR/perftest-malloc.sh 50000  100 2500000 $COUNT > ${PREFIX}test_malloc_50000
echo "Testing malloc: 100000"
bash $DIR/perftest-malloc.sh 100000 100 5000000 $COUNT > ${PREFIX}test_malloc_100000

# loops array-length test-count
echo "Testing calloc: 1000"
bash $DIR/perftest-calloc.sh 1000   100 $COUNT > ${PREFIX}test_calloc_1000
echo "Testing calloc: 10000"
bash $DIR/perftest-calloc.sh 10000  100 $COUNT > ${PREFIX}test_calloc_10000
echo "Testing calloc: 50000"
bash $DIR/perftest-calloc.sh 50000  100 $COUNT > ${PREFIX}test_calloc_50000
echo "Testing calloc: 100000"
bash $DIR/perftest-calloc.sh 100000 100 $COUNT > ${PREFIX}test_calloc_100000

# loops increment test-count
echo "Testing realloc: 1000"
bash $DIR/perftest-realloc.sh 1000   100 $COUNT > ${PREFIX}test_realloc_1000
echo "Testing realloc: 10000"
bash $DIR/perftest-realloc.sh 10000  100 $COUNT > ${PREFIX}test_realloc_10000
echo "Testing realloc: 50000"
bash $DIR/perftest-realloc.sh 50000  100 $COUNT > ${PREFIX}test_realloc_50000
echo "Testing realloc: 100000"
bash $DIR/perftest-realloc.sh 100000 100 $COUNT > ${PREFIX}test_realloc_100000

# array-length string pool-guess test-count
echo "Testing concatenation: 1000"
bash $DIR/perftest-concat.sh 1000   "somestring" 5000   $COUNT > ${PREFIX}test_concat_1000
echo "Testing concatenation: 10000"
bash $DIR/perftest-concat.sh 10000  "somestring" 50000  $COUNT > ${PREFIX}test_concat_10000
echo "Testing concatenation: 50000"
bash $DIR/perftest-concat.sh 50000  "somestring" 250000 $COUNT > ${PREFIX}test_concat_50000
echo "Testing concatenation: 100000"
bash $DIR/perftest-concat.sh 100000 "somestring" 500000 $COUNT > ${PREFIX}test_concat_100000
