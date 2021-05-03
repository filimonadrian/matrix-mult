# Tema 2 - Matrix Multiplication

Sa se efectueze urmatoarea operatie cu matrice: `C = A * B * B' + A' * A`  
- A si B matrice patratice de double de dimensiune N * N
- A este superior triunghiulara

## Blas implementation

Pentru implementarea cu [BLAS](http://www.netlib.org/blas/) am folosit functiile `cblas_dtrmm`(double triunghiular matrix multiplication) si `cblas_dgemm`.

Am efectuat operatiile in ordinea in care ele apar: 
- AB = A * B, folosind proprietatea ca A este superior triunghiulara
- ABBt = AB * B', folosind inmultirea obisnuita(AB nu este superior triunghiulara)
- AtA = A' * A, folosind proprietatea ca A este superior triunghiulara
- la sfarsit, am adunat cele 2 matrice in matricea C

## NEOPT implementation

- implementarea neoptimala a operatiilor
- pentru realizarea ei, am inmultit matricele cu cele 3 for-uri clasice.
- la inmultirile cu matricea A (A * B si A' * A) am tinut cont de faptul ca A este `superior triunghiulara`, schimband range-ul pentru indexul liniilor/coloanelor ce se acceseaza din matricea A

# OTP implementation

- implementarea optimizata manual
- pentru a micsora timpul de rulare, am optimizat timpul de acces la memorie:
    - toate variabilele folosite(indecsii si variabile sum) sunt declarate ce keyword-ul `register`
    - pentru a face mai putine accese la memoria principala, suma se face in variabila `sum`, declarata ca `register`, accesandu-se o singura data adresa de memorie unde va fi stocat rezultatul


## Logic of the app

**normal matrix:**
```
     1 2 3
A  = 0 4 5
     0 0 6

     1 0 0
A' = 2 4 0
     3 5 6
```

**Liniarized matrix**

```
A  = [ 1 2 3  0 4 5  0 0 6 ]
A' = [ 1 0 0  2 4 0  3 5 6 ]
```


```

## Bibliography
- BLAS
    - http://www.netlib.org/blas/cblas.h
    - http://www.netlib.org/lapack/explore-html/de/da0/cblas_8h_source.html
    - https://www.gnu.org/software/gsl/doc/html/blas.html#c.gsl_blas_dtrmm