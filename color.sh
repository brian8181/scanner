#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

# FILE: 'color.sh'
# VERSION: '0.0.1'
# FILE_DATE: 'Fri Nov  8 08:30:00 PM CST 2024'
# INFO: define colors

export FMT_BRIGHT='\x1B[1m'
export FMT_DIM='\x1B[2m'
export FMT_UNDELINE='\x1B[4m'
export FMT_BLINK='\x1B[5m'
export FMT_INVERT='\x1B[7m'
export FMT_HIDDEN='\x1B[8m'
export FMT_STRICKOUT='\x1B[9m'
export FMT_RESET_BRIGHT='\x1B[21m'
export FMT_RESET_DIM='\x1B[22m'
export FMT_RESET_UNDELINE='\x1B[24m'
export FMT_RESET_BLINK='\x1B[25m'
export FMT_RESET_INVERT='\x1B[27m'
export FMT_RESET_HIDDEN='\x1B[28m'
export FMT_RESET='\x1B[0m'
export FMT_RESET_BOLD='\x1B[21m'
export FMT_RESET_REVERSE='\x1B[27m'
export FMT_BOLD='\x1B[1m'
export FMT_REVERSE='\x1B[7m'
export FMT_FG_DEFAULT='\x1B[39m'
export FMT_FG_BLACK='\x1B[30m'
export FMT_FG_RED='\x1B[31m'
export FMT_FG_GREEN='\x1B[32m'
export FMT_FG_YELLOW='\x1B[33m'
export FMT_FG_BLUE='\x1B[34m'
export FMT_FG_MAGENTA='\x1B[35m'
export FMT_FG_CYAN='\x1B[36m'
export FMT_FG_LIGHT_GREY='\x1B[37m'
export FMT_FG_DARK_GREY='\x1B[90m'
export FMT_FG_LIGHT_RED='\x1B[91m'
export FMT_FG_LIGHT_GREEN='\x1B[92m'
export FMT_FG_LIGHT_YELLOW='\x1B[93m'
export FMT_FG_LIGHT_BLUE='\x1B[94m'
export FMT_FG_LIGHT_MAGENTA='\x1B[95m'
export FMT_FG_LIGHT_CYAN='\x1B[96m'
export FMT_FG_WHITE='\x1B[97m'
export FMT_BG_BLACK='\x1B[40m'
export FMT_BG_RED='\x1B[41m'
export FMT_BG_GREEN='\x1B[42m'
export FMT_BG_YELLOW='\x1B[43m'
export FMT_BG_BLUE='\x1B[44'
export FMT_BG_MAGENTA='\x1B[45m'
export FMT_BG_CYAN='\x1B[46m'
export FMT_BG_LIGHT_GREY='\x1B[47m'
export FMT_BG_DEFUALT='\x1B[49m'
export FMT_BG_DARK_GREY='\x1B[100m'
export FMT_BG_LIGHT_RED='\x1B[101m'
export FMT_BG_LIGHT_GREEN='\x1B[102m'
export FMT_BG_LIGHT_YELLOW='\x1B[103m'
export FMT_BG_LIGHT_BLUE='\x1B[104m'
export FMT_BG_LIGHT_MAGENTA='\x1B[105m'
export FMT_BG_LIGHT_CYAN='\x1B[106m'


function Print2
{
    COLOR="$1"
    TEXT="$2"
    echo ${COLOR}"${TEXT}"${FMT_RESET}
}


function Print
{
    COLOR="$1"
    TEXT="$2"
    echo -e ${COLOR}"${TEXT}"${FMT_RESET}
}

function PrintReset
{
    echo -e ${FMT_RESET}
}

function PrintResetBold
{
    echo -e ${FMT_RESET_BOLD}
}

function PrintResetBright
{
    echo -e ${FMT_RESET_BRIGHT}
}

function PrintResetDim
{
    echo -e ${FMT_RESET_DIM}
}

function PrintResetUnderline
{
    echo -e ${FMT_RESET_UNDELINE}
}

function PrintResetInvert
{
    echo -e ${FMT_RESET_INVERT}
}

function PrintResetReverse
{
    echo -e ${FMT_RESET_REVERSE}
}

function PrintResetHidden
{
    echo -e ${FMT_RESET_HIDDEN}
}

function PrintResetBlink
{
    echo -e ${FMT_RESET_Blink}
}

function PrintBlack
{
    Print $FMT_FG_BLACK $1
}

function PrintWhite
{
    Print $FMT_FG_WHITE $1
}

function PrintGrey
{
    Print $FMT_FG_GREY $1
}

function PrintDarkGrey
{
    Print $FMT_FG_DARK_GREY $1
}

function PrintLightGrey
{
    Print $FMT_FG_LIGHT_GREY $1
}

function PrintGreen
{
    Print $FMT_FG_GREEN $1
}

function PrintLightGreen
{
    Print $FMT_FG_LIGHT_GREEN $1
}
function PrintRed
{
    Print $FMT_FG_RED $1
}

function PrintLightRed
{
    Print $FMT_FG_LIGHT_RED $1
}

function PrintBlue
{
    Print $FMT_FG_BLUE $1
}

function PrintLightBlue
{
    Print $FMT_FG_LIGHT_BLUE $1
}

function PrintYellow
{
    Print $FMT_FG_YELLOW
}

function PrintLightYellow
{
    Print $FMT_FG_YELLOW
}

function PrintCyan
{
    Print $FMT_FG_CYAN $1
}

function PrintLightCyan
{
    Print $FMT_FG__LIGHT_CYAN $1
}

function PrintMagenta
{
    Print $FMT_FG_MAGENTA $1
}

function PrintLightMagenta
{
    Print $FMT_FG_LIGHT_MAGENTA $1
}

function PrintReverse
{
    Print $FMT_REVERSE $1
}

function PrintUnderline
{
    Print $FMT_UNDELINE $1
}

function PrintBold
{
    Print $FMT_BOLD $1
}

function PrintReverse
{
    Print $FMT_REVERSE $1
}

function PrintInvert
{
    Print $FMT_INVERT $1
}

function PrintBright
{
    Print $FMT_BRIGHT $1
}

function PrintDim
{
    Print $FMT_DIM $1
}

function PrintHidden
{
    Print $FMT_HIDDEN $1
}
function PrintStrickout
{
    Print $FMT_STRICKOUT $1
}

function PrintBlink
{
    Print $FMT_BLINK $1
}
