#!/bin/bash

source colors.sh

echo -e "\n$(PrintRed 'Auto-committing changes to git repository...')\n"
git add .
echo -e "$(PrintYellow 'Changes staged for commit.')\n"
git commit -m "Auto-commit changes"
echo -e "$(PrintYellow 'Changes committed.')\n"
git push
echo -e "$(PrintGreen 'Changes pushed to remote repository.')\n"
git log --oneline -5
echo -e "$(PrintGreen 'Last 5 commits displayed.')\n"
