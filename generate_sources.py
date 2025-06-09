import os

def collect_files(source_dir, extensions):
    files = []

    for root, _, file_list in os.walk(source_dir):
        for file in file_list:
            if any(file.endswith(ext) for ext in extensions):
                rel_path = os.path.relpath(os.path.join(root, file)).replace("\\", "/")
                files.append(rel_path)

    files.sort()  # Keep order consistent
    return files

def generate_cmake_list(var_name, files, output_file):
    with open(output_file, "w") as f:
        f.write(f"set({var_name}\n")
        for file in files:
            f.write(f"    {file}\n")
        f.write(")\n")

    print(f"Generated {output_file} ({len(files)} files)")

if __name__ == "__main__":
    # Sources and headers for src/
    cpp_files = collect_files("src", [".cpp"])
    h_files = collect_files("include", [".h", ".hpp"])

    generate_cmake_list("SOURCES", cpp_files, "sources.cmake")
    generate_cmake_list("HEADERS", h_files, "headers.cmake")

    # Test sources
    test_cpp_files = collect_files("tests", [".cpp"])

    generate_cmake_list("TEST_SOURCES", test_cpp_files, "test_sources.cmake")
