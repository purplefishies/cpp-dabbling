#!/bin/bash


cmake -B buildnew -S . -G "Ninja Multi-Config"  -DCMAKE_TOOLCHAIN_FILE=/home/jdamon/vcpkg/scripts/buildsystems/vcpkg.cmake 
cmake --build buildnew 




BLUE=$'\033[38;2;26;132;198m'
WHITE=$'\033[38;2;255;255;255m'
ORANGE=$'\033[38;2;254;95;0m'
YELLOW=$'\033[38;2;255;215;95m'
FUCHSIA=$'\033[38;2;255;0;135m'
RESET=$'\033[0m'

export QT_MESSAGE_PATTERN="\
%{time h:mm:ss.zzz} %{function}:\
%{if-debug}D ${BLUE}%{message}${RESET}%{endif}\
%{if-info}I ${WHITE}%{message}${RESET}%{endif}\
%{if-warning}W ${YELLOW}%{message}${RESET}%{endif}\
%{if-critical}C ${ORANGE}%{message}${RESET}%{endif}\
%{if-fatal}F ${FUCHSIA}%{message}${RESET}%{endif}"

buildnew/Debug/logtest
