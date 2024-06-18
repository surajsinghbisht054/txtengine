# txtengine
TXTEngine is a fast and lightweight Python module for searching and manipulating large text files. 
Written in Cython, it provides features similar to Linux text manipulation tools like grep, wc, etc.

### Features
- High Performance: Leveraging Cython for speed.
- Search Strings: Efficiently search for strings in large text files.
- Text Manipulation: Perform operations like counting words and lines.


### Example
```
(SELECT|COUNT) STRING1
(SELECT|COUNT) STRING1 && STRING2 ....
(SELECT|COUNT) STRING1 || STRING2 ....
(SELECT|COUNT) STRING1 && (STRING2 || STRING3)
```

### Installation
To install your package directly from GitHub using pip, use the following command format:

```
pip install git+https://github.com/surajsinghbisht054/txtengine.git
```


### Contributing
Contributions are welcome! Please submit a pull request or open an issue to discuss your ideas.

### License
This project is licensed under the MIT License. See the LICENSE file for details.
