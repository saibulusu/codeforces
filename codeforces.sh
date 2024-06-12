#!/bin/bash

# Function to make API request and retrieve problem list
get_problem_list() {
    local response=$(curl -s "https://codeforces.com/api/problemset.problems")
    echo "$response"
}

# Function to parse JSON response and find problem name by ID
get_problem_name() {
    local problem_id="$1"
    local problem_list="$2"

    local contestId="${problem_id%%[A-Z]*}"
    local index="${problem_id##*[0-9]}"

    local name=$(echo "$problem_list" | jq -r --arg contestId "$contestId" --arg index "$index" '.result.problems[] | select(.contestId == ($contestId | tonumber) and .index == $index) | .name')

    echo "$name"
}

# Main function
main() {
    local problem_id="$1"
    
    if [[ -z "$problem_id" ]]; then
        echo "Usage: $0 <problem_id>"
        exit 1
    fi

    local problem_list=$(get_problem_list)
    local problem_name=$(get_problem_name "$problem_id" "$problem_list")
    
    if [[ -z "$problem_name" ]]; then
        echo "Problem not found for ID $problem_id"
    else
        echo "Problem name for ID $problem_id: $problem_name"
    fi
}

main "$@"
