#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
    "perftest-realloc-std perftest-realloc-talloc" \
    "100000 100" \
    100 \
    $DIR/../src/performance/realloc/_stap_tests