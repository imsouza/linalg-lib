# LinAlg Lib

A Linear Algebra library for C programs

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

Valgrind:

```$ make memcheck```

## TODO

- Algorithms
	- [x] Matrix addition
	- [x] Matrix subtraction
	- [x] Matrix multiplication
	- [x] Gaussian elimination
	- [x] Transpose
	- [ ] Laplace expansion
	- [ ] Eigenvalues
	- [ ] Eigenvectors
	- [ ] Diagonalization
	- [ ] Characteristic Polynomial
	- [ ] Inverse
	- [ ] Adjoint

- Extra
  - [x] Configure preprocessor directives
  - [x] Successfully passed the tests
  - [x] Fix memory leaks

## Author

Mateus Almeida

## Contributing

Feel free to make pull requests for code improvements

## License

This project is licensed under the [MIT](https://github.com/imsouza/linalg-lib/blob/main/LICENSE) License.