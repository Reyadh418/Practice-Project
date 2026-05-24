# Practice-Project

A personal practice repository for experimenting with:
- **C programming** (small console programs / exercises)
- **HTML** (static pages / UI mockups)
- A bit of **Assembly** (alongside C)

> Repo: `Reyadh418/Practice-Project` (default branch: `master`)

---

## Repository structure

```
.
├── .gitignore
└── Practice/
    ├── .vscode/
    ├── Advanced/
    ├── C++Journey/
    ├── Web Static/
    │   ├── loginPage.html
    │   └── passwordRecoder.html
    ├── area_rectangle.c
    ├── asm.c
    ├── asm.s
    ├── calculator.c
    ├── codex1.html
    ├── guissing_game.c
    ├── helloWorld.c
    ├── largestNumber.c
    ├── markCounter.c
    ├── nested.c
    ├── pencil_sketch.html
    ├── portrait.html
    ├── reverseArray.c
    ├── reyad.c
    ├── sketch_generator.html
    ├── square_qube.c
    ├── sumDigit.c
    ├── sumDigits.c
    └── try.py
```

---

## What’s inside (high level)

### C practice programs (`Practice/*.c`)
A collection of small C files for practicing fundamentals (I/O, loops, conditions, arrays, basic math, etc.). Examples include:
- `helloWorld.c`
- `calculator.c`
- `largestNumber.c`
- `reverseArray.c`
- `sumDigit.c`, `sumDigits.c`

### Assembly experiments (`Practice/asm.s`, `Practice/asm.c`)
Small experiments combining C and Assembly.

### Static web pages (`Practice/*.html`, `Practice/Web Static/*.html`)
HTML pages and UI practice files, including:
- `Practice/Web Static/loginPage.html`
- `Practice/Web Static/passwordRecoder.html`
- `portrait.html`, `pencil_sketch.html`, etc.

---

## How to run

### Compile and run C files
From the repo root:

```bash
cd Practice
gcc helloWorld.c -o helloWorld
./helloWorld
```

If you’re on Windows, you can use MinGW-w64 (or WSL) and run the generated `.exe`.

### Open HTML files
Open any `.html` file in your browser, for example:
- `Practice/Web Static/loginPage.html`

---

## Notes
- This repo is primarily for learning and experimentation, so files may be independent and not part of a single “application”.
- There’s a `Practice/.vscode/` folder for editor configuration.

---

## License
No license file is currently included. If you want, add a LICENSE (MIT, Apache-2.0, etc.) to clarify how others may use this code.
