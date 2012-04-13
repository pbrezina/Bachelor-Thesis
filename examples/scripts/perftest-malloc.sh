#!/bin/bash

die () {
    echo >&2 "$@"
    exit 1
}

[ "$#" -eq 4 ] || die "4 argument required, $# provided"
echo $1 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $1 provided"
echo $2 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $2 provided"
echo $3 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $3 provided"
echo $4 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $4 provided"

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-malloc-std perftest-malloc-talloc-size \
      perftest-malloc-talloc-tmpctx perftest-malloc-talloc-pool-exact \
      perftest-malloc-talloc-pool-guess" \
     "$1 $2 $3" \
     $4 \
     $DIR/../src/performance/malloc/_stap_tests