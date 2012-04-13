#!/bin/bash

die () {
    echo >&2 "$@"
    exit 1
}

[ "$#" -eq 3 ] || die "3 argument required, $# provided"
echo $1 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $1 provided"
echo $2 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $2 provided"
echo $3 | grep -E -q '^[0-9]+$' || die "Numeric argument required, $3 provided"

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

bash $DIR/perftest.sh \
     "perftest-calloc-std perftest-calloc-talloc" \
     "$1 $2" \
     $3 \
     $DIR/../src/performance/calloc/_stap_tests