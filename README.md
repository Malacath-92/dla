# Dimensional analysis and linear algebra (dla)

<p align="center">
  <a href="https://isocpp.org/">
      <img src="https://img.shields.io/badge/language-C%2B%2B17-blue.svg">
  </a>
  <a href="https://ci.appveyor.com/project/Malacath-92/dla/branch/master">
      <img src="https://ci.appveyor.com/api/projects/status/jh4oxlm6i85ltqbm/branch/master?svg=true">
  </a>
  <a href="https://travis-ci.org/Malacath-92/dla">
      <img src="https://travis-ci.org/Malacath-92/dla.svg?branch=master">
  </a>
  <a href="https://github.com/Malacath-92/dla/actions">
      <img src="https://github.com/Malacath-92/dla/workflows/Github%20Actions%20CI/badge.svg">
  </a>
  <a href="https://opensource.org/licenses/MIT" >
      <img src="https://img.shields.io/apm/l/vim-mode.svg">
  </a>
</p>

**The library is a work in progress.**

Header only library for dimensional analysis and a basic set of linear algebra aimed at C++17 and higher.

The main focus of this library is to offer a complete and simple dimensional analysis tool, which is easily extensible to allow custom units without requiring template specializations of the user. Additionally it offers a basic linear algebra framework, including one- to four-dimensional vectors and matrices, that seamlessly works with the dimensional analysis and exposes some customisation points to the user.

Due to the current restrictions and rigidity of the dimensional analysis framework this library is not useable for scientific computing but can be used for e.g. game development, which is its main motivation.

## Requirements

* A C++17 conforming compiler
* CMake for compiling tests 
