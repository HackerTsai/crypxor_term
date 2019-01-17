# Crypxor Term
A terminal-based encrypt tool for Linux.
Crypxor Term is a terminal-based encrypt tool for Linux.
## Implementation
It's using XOR cipher, by user enter the key, a number, and use the key as seed of the pseudorandom number generator.
The gerator will generate a serie of numbers, and use it to perform XOR operations, and reach encryption.
## Installation
Clone the repository:

    git clone https://github.com/HackerTsai/crypxor_term.git
`make` it:

    cd crypxor_term
    make
    make install
Run command below to check is the installation successfully:

    crypxor --version
## Usage
`crypxor --version` to get version info.

`crypxor --help` to get usage info.

`crypxor file` will output a encrypted version `out.txt` of `file`. Or `--out filename` to specify the output file name.
