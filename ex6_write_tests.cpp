#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

int passes = 0;
int failures = 0;
void check(bool condition, const std::string& message) {
    std::cout << (condition ? "  PASS  " : "  FAIL  ") << message << '\n';
    if (condition) ++passes; else ++failures;
}

fs::path stageFile(const fs::path& root, const std::string& name) {
    return root / ".minigit" / "stage" / name;
}

int main() {
    const fs::path root = "course/repo";

    check(stageFile(root, "notes.txt") == root / ".minigit" / "stage" / "notes.txt",
          "top-level file is staged in .minigit/stage");

    check(stageFile(root, "docs/notes.txt") == root / ".minigit" / "stage" / "docs" / "notes.txt",
          "sub-folder file keeps its folder");

    check(stageFile(root, "docs/notes.txt").filename() == "notes.txt",
          "filename is notes.txt");

    if (passes < 3) {
        std::cout << "  FAIL  write at least three passing checks (you have " << passes << ")\n";
        ++failures;
    }
    return failures == 0 ? 0 : 1;
}
