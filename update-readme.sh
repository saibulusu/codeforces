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

readme_content=""
for file in "${cpp_files[@]}"; do
  readme_content+="- [$file]\n"
done

echo "$readme_content"
