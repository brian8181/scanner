#!/bin/bash

echo "Auto-committing changes to git repository..."
git add .
echo -e "Changes staged for commit.\n"
git commit -m "Auto-commit changes"
echo -e "Changes committed.\n"
git push
echo -e "Changes pushed to remote repository.\n"
git log --oneline -5
echo -e "Last 5 commits displayed.\n"
