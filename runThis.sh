#!/bin/bash

OSQI=/usr/bin/osqueryi

gcc chkThis.c -o chkThis
gcc doThis.c -o doThis

./doThis &
doThis_PID=$!

sleep 2

echo 
$OSQI --version

echo
echo "================================"
echo "Checking with executable PRESENT"
./chkThis $doThis_PID
$OSQI "select pid, path, cwd, cmdline, on_disk from processes where pid=$doThis_PID;"

rm ./doThis

echo 
echo "================================"
echo "Checking with executable DELETED"
./chkThis $doThis_PID
$OSQI "select pid, path, cwd, cmdline, on_disk from processes where pid=$doThis_PID;"

echo

kill $doThis_PID 
rm chkThis
