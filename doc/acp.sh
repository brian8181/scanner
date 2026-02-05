#!/bin/bash

source $HOME/bin/color.sh

PrintRed "\nAuto-committing changes to git repository...\n"
git add .
PrintYellow "\nChanges staged for commit.\n"
git commit -m "Auto-commit changes"
PrintYellow "\nChanges committed.\n"
git push
PrintGreen "\nChanges pushed to remote repository.\n"
git log --oneline -5
PrintGreen "\nLast 5 commits displayed.\n"
