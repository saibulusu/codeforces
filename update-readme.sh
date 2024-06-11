# Directory containing the .cpp files
DIRECTORY="./"  # You can change this to the specific directory path if needed

cpp_files=()

# Iterate through all .cpp files in the directory
for file in "$DIRECTORY"/*.cpp; do
  if [[ -f "$file" ]]; then  # Check if the file exists
    file_name=$(basename "$file")
    file_name="${file_name%.cpp}"

    cpp_files+=("$file_name")
  fi
done

# Function to sort the array
sort_array_custom() {
  local -n arr=$1  # Use nameref to pass array by reference

  # Custom sort function
  mapfile -t arr < <(
    for item in "${arr[@]}"; do
      # Extract the numeric and letter parts
      num=${item//[!0-9]/}
      letter=${item//[0-9]/}
      # Print the numeric part padded to 10 digits followed by the letter and the original item
      printf "%010d%s %s\n" "$num" "$letter" "$item"
    done | sort | awk '{print $2}'
  )
}

sort_array_custom cpp_files

get_problem_list() {
  local response=$(curl -s "https://codeforces.com/api/problemset.problems")
}

get_problem_name() {
  local problem_id="$1"
  local problem_list="$2"

  local problem_name=$(echo "$problem_list" | jq -r ".result.problems[] | select(.contestId == $problem_id / 1000 and .index == \"$((problem_id % 1000))\") | .name")
  echo "$problem_name"
}

readme_content=""
for file in "${cpp_files[@]}"; do
  local problem_id="$file"
  local problem_list=$(get_problem_list)
  local problem_name=$(get_problem_name "$problem_id" "$problem_list")
  
  readme_content+="- [$problem_name]($file.cpp)\n"
done

echo -e "$readme_content" > README.md

git config --global advice.detachedHead false
git config user.email "sai.bulusu@gmail.com"
git config user.name "saibulusu"
git add .
git commit -m "Updating README.md"
git push
