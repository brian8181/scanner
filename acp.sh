#!/bin/bash

source colors.sh

PrintRed "\nAuto-committing changes to git repository...\n"
git add .
PrintYellow "Changes staged for commit.\n"
git commit -m "Auto-commit changes"
PrintYellow "Changes committed.\n"
git push
PrintGreen "Changes pushed to remote repository.\n"
git log --oneline -5
PrintGreen "Last 5 commits displayed.\n"
