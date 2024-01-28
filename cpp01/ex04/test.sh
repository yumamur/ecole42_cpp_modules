#! /bin/bash

if [[ -z "./ex04" ]];
then
	make;
fi

# echo Replacing "$2" with "$3" in the file "$1"\n
./ex04 $1 $2 $3;
# echo
# printf "\033[32;1mFollowing occurrences will be replaced\033[m"
# echo
# cat $1 | grep --color $2
# echo
# echo Calling '`'diff $1 $1.replace'`'
# echo
# diff $1 $1.replace --side-by-side --suppress-common-lines | grep --color $3
vimdiff $1 $1.replace