#!/bin/bash env
function main() {
regular_expr="^[0-9]+$"
    if [[ $# -eq 1 && $1 =~ $regular_expr ]]
    then
        if ! (("$1" % 4)) && ( (("$1" % 100)) || ! (("$1" % 400)) )
        then
            echo true
        else
             echo false
        fi
    else
        echo 'Usage: leap.sh <year>'
        return 1
    fi
}

main "$@"
