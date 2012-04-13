#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-malloc-std perftest-malloc-talloc-size \
      perftest-malloc-talloc-tmpctx perftest-malloc-talloc-pool-exact \
      perftest-malloc-talloc-pool-guess" \
     "100000 100" \
     100 \
     $DIR/../src/performance/malloc/_stap_tests