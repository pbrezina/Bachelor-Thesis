#!/bin/bash

die () {
    echo >&2 "$@"
    exit 1
}

[ "$#" -eq 4 ] || die "4 argument required, $# provided"
echo $1 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $1 provided"
echo $3 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $3 provided"
echo $4 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $4 provided"

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-concat-strcat perftest-concat-strcat-pool \
      perftest-concat-strncat perftest-concat-strncat-pool \
      perftest-concat-memcpy perftest-concat-memcpy-pool \
      perftest-concat-append \
      perftest-concat-append-parent-pool-exact perftest-concat-append-parent-pool-guess \
      perftest-concat-buffer \
      perftest-concat-buffer-parent-pool-exact perftest-concat-buffer-parent-pool-guess" \
     "$1 $2 $3" \
     $4 \
     $DIR/../src/performance/concat/_stap_tests
