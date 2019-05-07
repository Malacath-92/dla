# Dimensional analysis and linear algebra (dla)
[![Build status](https://ci.appveyor.com/api/projects/status/jh4oxlm6i85ltqbm?svg=true)](https://ci.appveyor.com/project/Malacath-92/dla)

**The library is a work in progress.**

Header only library for dimensional analysis and a basic set of linear algebra aimed at C++17 and higher.

The main focus of this library is to offer a complete and simple dimensional analysis tool, which is easily extensible to allow custom units without requiring template specializations of the user. Additionally it offers a basic linear algebra framework, including one- to four-dimensional vectors and matrices, that seamlessly works with the dimensional analysis and exposes some customisation points to the user.

Due to the current restrictions and rigidity of the dimensional analysis framework this library is not useable for scientific computing but can be used for e.g. game development, which is its main motivation.

## Requirements

* A C++17 conforming compiler
* CMake for compiling tests 
