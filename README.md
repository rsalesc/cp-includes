[![Actions Status](https://github.com/rsalesc/cp-includes/workflows/verify/badge.svg)](https://github.com/rsalesc/cp-includes/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://rsalesc.github.io/cp-includes/)

### Guidelines

- There will be no `class` usage in this library, only `struct` usages.
- Everything will be wrapped in `namespace lib`.
- Every file will include _only_ `bits/stdc++.h`.
- Only `cpp` files allowed.

### Template

```cpp
// #include "<FILENAME>"
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
}  // namespace lib

// end of #include "<FILENAME>"
```
