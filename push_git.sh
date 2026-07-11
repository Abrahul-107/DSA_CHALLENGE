#!/bin/bash

set -euo pipefail

REPO_DIR="/Users/paridar/Desktop/learning/DSA_CHALLENGE"
SOURCE_DIR="$REPO_DIR/Graph"
DEST_DIR="$REPO_DIR/Graph/Adhoc"
REMOTE_URL="https://github.com/Abrahul-107/DSA_CHALLENGE.git"

cd "$REPO_DIR"

# Verify this is the actual repository.
if [ ! -d ".git" ]; then
    echo "Error: $REPO_DIR is not a Git repository."
    echo "Clone the repository first:"
    echo "git clone $REMOTE_URL \"$REPO_DIR\""
    exit 1
fi

# Ensure origin points to the correct GitHub repository.
if git remote get-url origin >/dev/null 2>&1; then
    git remote set-url origin "$REMOTE_URL"
else
    git remote add origin "$REMOTE_URL"
fi

# Make sure the local branch contains the latest remote changes.
git fetch origin

CURRENT_BRANCH=$(git branch --show-current)

if [ -z "$CURRENT_BRANCH" ]; then
    CURRENT_BRANCH="main"
    git switch -c main
fi

if git show-ref --verify --quiet refs/remotes/origin/main; then
    git pull --rebase origin main
fi

mkdir -p "$DEST_DIR"

FOUND_FILES=0

# Move and commit each top-level .cpp file separately.
for file in "$SOURCE_DIR"/*.cpp; do
    [ -f "$file" ] || continue

    FOUND_FILES=1

    filename=$(basename "$file")
    destination="$DEST_DIR/$filename"
    commit_message="${filename%.cpp}"

    echo "Moving and committing: $filename"

    mv "$file" "$destination"

    git add "$destination"

    if git diff --cached --quiet; then
        echo "No changes detected for $filename; skipping commit."
    else
        git commit -m "$commit_message"
    fi
done

if [ "$FOUND_FILES" -eq 0 ]; then
    echo "No .cpp files found directly inside:"
    echo "$SOURCE_DIR"
    exit 0
fi

git branch -M main
git push -u origin main

echo "All .cpp files were moved to Graph/Adhoc, committed separately, and pushed."