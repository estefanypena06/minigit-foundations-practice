## Exercise 1: Predict the output
- Prediction:
- a: `repo/.minigit/HEAD`
- b: `repo/HEAD`
- c: `notes.txt`
- d: `docs`
- e: `0`
- f: `.txt`

- Final Answer:
- a: `repo/.minigit/HEAD`
- b: `/HEAD`
- c: `notes.txt`
- d: `docs`
- e: `1` 
- f: `.txt`

## Exercise 2: Find the bug: lost newlines
- getline removes each `\n` and text += line doesn't put it back, so the new lines are lost and a\nb\n becomes ab

- You fix it by reading the whole file at once instead of line by line

- std::string readAll(const std::filesystem::path& file) {
    std::ifstream input(file);
    std::ostringstream contents;
    contents << input.rdbuf();
    return contents.str();
}

## Exercise 3: Find the bugs: two path mistakes
1: `root.string() + "/.minigit"` types the `/` by hand, so it breaks on Windows.
Fix: `return root / ".minigit";`

2: `/ "/HEAD"` has a `/` at the start, so it replaces the left side and gives just `/HEAD`.
Fix: `return metadataDirectory(root) / "HEAD";`

## Exercise 4: Fill in the blanks
1. !file.parent_path().empty()
2. create_directories
3. !output
4. !output.fail()