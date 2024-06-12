DIRECTORY="./"

cpp_files=()

for file in "$DIRECTORY"/*.cpp; do
  if [[ -f "$file" ]]; then
    file_name=$(basename "$file")
    file_name="${file_name%.cpp}"

    cpp_files+=("$file_name")
  fi
done

sort_array_custom() {
  local -n arr=$1

  mapfile -t arr < <(
    for item in "${arr[@]}"; do
      num=${item//[!0-9]/}
      letter=${item//[0-9]/}
      printf "%010d%s %s\n" "$num" "$letter" "$item"
    done | sort | awk '{print $2}'
  )
}

sort_array_custom cpp_files

get_problem_list() {
  local response=$(curl -s "https://codeforces.com/api/problemset.problems")
  echo "$response"
}

get_problem_name() {
  local contestId="$1"
  local index="$2"
  local problem_list="$3"

  local name=$(echo "$problem_list" | jq -r --arg contestId "$contestId" --arg index "$index" '.result.problems[] | select(.contestId == ($contestId | tonumber) and .index == $index) | .name')

  echo "$name"
}

problem_list=$(get_problem_list)

readme_content="#My Codeforces Solutions\n"
readme_content+="| Problem | Solution |\n"
readme_content+="|:--|:--|\n"

for file in "${cpp_files[@]}"; do
  problem_id="$file"
  num=${problem_id//[!0-9]/}
  letter=${problem_id//[0-9]/}
  
  problem_name=$(get_problem_name "$num" "$letter" "$problem_list")
  
  readme_content+="| [$problem_id](https://codeforces.com/problemset/problem/$num/$letter) | [$problem_name]($file.cpp) |\n"
done

echo -e "$readme_content" > README.md

git config --global advice.detachedHead false
git config user.email "sai.bulusu@gmail.com"
git config user.name "saibulusu"
git add .
git commit -m "Updating README.md"
git push
