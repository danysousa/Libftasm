#! /bin/sh

BASE="./tests"
TMP="$BASE/tmp"
mkdir -p "$TMP"

ERRORS=0

CLEAR="\033[00m"
RED="\033[31m"
GREEN="\033[32m"
HILIGHT="\n\n\033[35;4;1m"

################# GENERIC ##################
echo $HILIGHT"##################################### Generic tests ...$CLEAR"
generic_src="$BASE/generic.c"
generic_bin="$TMP/generic"
gcc -Wl,-no_pie -I. -L. -lfts "$generic_src" -o "$generic_bin"
if $generic_bin; then
    echo $GREEN"--> TEST SUCCESS: generic"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: generic"$CLEAR
fi


################# FT_PUTS ##################
set -e
echo $HILIGHT"##################################### Testing ft_puts() ..."$CLEAR

puts_src="$BASE/puts.c"
puts_bin="$TMP/puts"
ft_puts_bin="$TMP/ft_puts"
gcc -Wl,-no_pie -I. -L. -lfts "$puts_src" -o "$puts_bin"
gcc -Wl,-no_pie -I. -L. -lfts -D "FT_PUTS" "$puts_src" -o "$ft_puts_bin"

$puts_bin > "${puts_bin}.out"
$ft_puts_bin > "${ft_puts_bin}.out"

if diff "${puts_bin}.out" "${ft_puts_bin}.out" &> /dev/null; then
    echo $GREEN"--> TEST SUCCESS: ft_puts()"$CLEAR
else
    ((ERRORS++))
    echo $RED"--> TEST FAILED: ft_puts() (run 'vimdiff ${puts_bin}.out ${ft_puts_bin}.out' to show diffs)"$CLEAR
fi



if [[ $ERRORS -gt 0 ]]; then
    echo ${HILIGH}${RED}"FAILED TESTS: $ERRORS"$CLEAR
    exit 1
else
    echo ${HILIGHT}${GREEN}"EVERYTHING IS OK !"$CLEAR
    exit 0
fi
