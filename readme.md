1. Use the docker container with VSCode devcontainer extension (or see .devcontainer for details)
2. Setup the cmake project

```
cmake -S sources -B build
```

3. Build the project

```
cmake --build build
```

4. Run the application

```
# read the file to stdout
build/mapexample -o examples/file.txt

# read the value from key 'one'
build/mapexample -o examples/file.txt -k one

# Write the value 'oneone.img' to key 'one'
build/mapexample -o examples/file.txt -k one -v aa


```
