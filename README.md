# Triest
Implementation of the [Triest algorithms](https://www.kdd.org/kdd2016/papers/files/rfp0465-de-stefaniA.pdf) to compute approximations of global and local number of triangles in a graph, which is represented as a stream of edge insertions.

## Build

Clone the package

```bash
git clone https://github.com/normelius/triest.git
```
Go into the project and create build folder
```bash
cd triest/
mkdir build
```
Go into build folder and run cmake
```bash
cd build/
cmake ..
make
```

## Example
After building the project, run the example in the build folder
```python
./triest
```
See full example in the file example.cc, located in the root directory.

## Structure of data
In order to use the program, the data needs to be on the form below, where each node in the graph is represented as a number. Since the algorithm handles undirected graphs, the number doesn't have to be in increasing order.
```txt
0    1
0    2
0    3
0    4
1    2
10   12
21   2
22   2
```
## License
[MIT](https://choosealicense.com/licenses/mit/)
