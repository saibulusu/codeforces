# Directory containing the .cpp files
DIRECTORY="./"  # You can change this to the specific directory path if needed

# Iterate through all .cpp files in the directory
for file in "$DIRECTORY"/*.cpp; do
  if [[ -f "$file" ]]; then  # Check if the file exists
    file_name=$(basename "$file")
    file_name="${file_name%.cpp}"
    echo "Processing $file_name..."
  else
    echo "No .cpp files found in $DIRECTORY."
  fi
done
