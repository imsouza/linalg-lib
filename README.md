# LinAlg Lib

A Linear Algebra library for C programs

## Table of contents

- [Usage](#usage)
- [Run](#run)
- [Test](#test)
- [Todo](#todo)
- [License](#license)


## Usage

```
#include <stdio.h>
#include <stdlib.h>
#include "linalg.h"

int main () {
  ...
}
```

## Run

gcc <file.c> linalg.c -o exec

# Test

```$ make && make run```

Check for memory leaks:

```$ make valgrind```

## TODO

- Algorithms
	- [x] Matrix addition
	- [x] Matrix subtraction
	- [x] Matrix multiplication
	- [x] Gauss Elimination
	- [x] Transpose
	- [ ] LaPlace Expansion
	- [ ] Eigenvalues
	- [ ] Eigenvectors
	- [ ] Diagonalization
	- [ ] Characteristic Polynomial
	- [ ] Inverse
	- [ ] Adjoint

- Extra
  - [x] Configure preprocessor directives
  - [ ] Document all the code
  - [ ] Generate doxygen documentation
  - [x] Successfully passed the tests

## Author

Mateus Almeida

## Contributing

Feel free to make pull requests for code improvements

## License

This project is licensed under the [MIT](https://github.com/imsouza/linalg-lib/blob/main/LICENSE) License.