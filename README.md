
# Data Structure modules in C

These are some of the Data Structure modules that could be useful for people that are going to work in the C program and need to work with some data. I created it to save time re-coding Linked Lists and other Data Structures whenever I work with C programming language. 

## Usage/Examples

```c
/**
* Download the header file and c file and 
* save them in your working directory.
* And include these in the files you are working.
*/
// For example... 
#include "LinkedList.h"

int main(){
    LinkedList* myList = NULL;
    myList = insertLL(1, 0, myList);
    myList = appendLL(4, myList);
    printLL(myList);
    return 0;
}
```

```console
1 -> 4 -> NIL
```


## Documentation

[C](https://devdocs.io/c/)



## 🔗 Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](www.linkedin.com/in/mathavanp)

