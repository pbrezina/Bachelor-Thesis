#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-calloc-std perftest-calloc-talloc" \
     "100000 100" \
     100 \
     $DIR/../src/performance/calloc/_stap_tests