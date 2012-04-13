#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-concat-strcat perftest-concat-strcat-pool \
      perftest-concat-strncat perftest-concat-strncat-pool \
      perftest-concat-memcpy perftest-concat-memcpy-pool \
      perftest-concat-append \
      perftest-concat-append-pool-exact perftest-concat-append-pool-guess \
      perftest-concat-append-parent-pool-exact perftest-concat-append-parent-pool-guess \
      perftest-concat-buffer \
      perftest-concat-buffer-pool-exact perftest-concat-buffer-pool-guess \
      perftest-concat-buffer-parent-pool-exact perftest-concat-buffer-parent-pool-guess" \
     "100000 somestring 500001" \
     100 \
     $DIR/../src/performance/concat/_stap_tests
