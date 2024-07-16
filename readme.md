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
build/configtool
```