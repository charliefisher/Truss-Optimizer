# Truss Optimizer

Automatically optimizes a given truss design by reducing the total length of the members.Written for MTE 119 Truss Project(Winter 2019).

## Getting Started

This truss optimizer uses [Armadillo](http://arma.sourceforge.net/docs.html) licensed under [Apache License 2.0](http://arma.sourceforge.net/license.html). The library is included in this repository for convenience. In order to run the program, the ```blas``` and ```lapack``` dll files must be copied to the same directory as the .exe of the truss optimzier. The ```blas``` and ```lapack``` dll files are located in ```Truss Optimizer\armadillo-9.300.2\examples\lib_win64``` and are named ```blas_win64_MT.dll``` and ```lapack_win64_MT.dll```, respectively.

## How to Input a Truss

The input file must follow the format outlined below: 
<pre>
N<sub>joints</sub>	N<sub>members</sub>  
  
(Joint Locations)  
x<sub>J1</sub>	y<sub>J1</sub>	fixedX<sub>J1</sub> 	fixedY<sub>J1</sub> 	externalX<sub>J1</sub>	externalY<sub>J1</sub>  
x<sub>J2</sub>	y<sub>J2</sub>	fixedX<sub>J2</sub> 	fixedY<sub>J2</sub> 	externalX<sub>J2</sub>	externalY<sub>J2</sub>  
&#8942  
x<sub>J<sub>N</sub></sub>	y<sub>J<sub>N</sub></sub>	fixedX<sub>J<sub>N</sub></sub>		fixedY<sub>J<sub>N</sub></sub>		externalX<sub>J<sub>N</sub></sub>	externalY<sub>J<sub>N</sub></sub>  
  
(Member Connections)  
0	Connection<sub>1</sub>	Connection<sub>2</sub>  
1	Connection<sub>1</sub>	Connection<sub>2</sub>  
2	Connection<sub>1</sub>	Connection<sub>2</sub>  
&#8942  
N<sub>members</sub>	Connection<sub>1</sub>	Connection<sub>2</sub>
</pre> 
  
```fixedX``` and ```fixedY``` are boolean values are indicated by 1 for true and 0 for false.


## Authors

* **[Aidan Baksh](https://github.com/aidanbaksh)**
* **[Charlie Fisher](https://github.com/charliefisher)**