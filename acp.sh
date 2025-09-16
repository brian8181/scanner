#!/bin/bash

echo "Auto-committing changes to git repository..."
git add .
echo "Changes staged for commit."
git commit -m "Auto-commit changes"
echo "Changes committed."
git push
echo "Changes pushed to remote repository."
git log --oneline -5
echo "Last 5 commits displayed."
