#!/bin/sh
# This script mimics the actual behavior of an SVG to TH2 converter that
# expects exactly one filename argument.

test -n "$1" || exit 1
test -z "$2" || exit 2

cat <<EOF
scrap s_p_foo1 -projection plan -scale [1000 100 m]
point 50 50 continuation -text "Foo bar"
endscrap
EOF
